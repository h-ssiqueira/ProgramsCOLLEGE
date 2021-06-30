#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include <limits.h>
#define minnode 2
#define maxnode 100

/*
// Generate 10 random graphs with N nodes and K resources between N and 2N
// Read the graphs and print those who have deadlock
// Detect deadlock
*/

sem_t mutex, Empty, Full;
int count = 0,graphs = 0, cycles = 0; // Counter of graphs in buffer

// Structure of the edge
typedef struct resource{
	int k; // ID of resource
	struct graph *request; // Request node
	struct resource *next; // Next resource
}r;

// Structure of the node
typedef struct graph{
	int n; // ID of node
	bool visited;
	struct resource *K; // List of resource requests
	struct graph *next; // Next node
}g;

// Structure of the graph
typedef struct buffer{
	g *nodes; // Nodes of a graph
	struct buffer *next; // Next graph
}b;

// Create one node for the graph
void createnode(b **graph,int id){
	g *actual = calloc(1,sizeof(g)), *previous = NULL;
	if(!actual){
		printf("Error when allocating memory");
		exit(0);
	}
	actual->next = NULL;
	actual->n = id;
	actual->visited = false;
	actual->K = NULL;
	if(!(*graph)->nodes) // If the position in the list of graphs is null
		(*graph)->nodes = actual; // Insert the first node as the root of graph
	else{ // If the graph has nodes
		for(previous = (*graph)->nodes; previous->next != NULL; previous = previous->next) // Reach the latest node added
			continue;
		previous->next = actual; // Update the next node to latest node inserted
	}
}

// Create one connection between two graphs
void createresource(b **aux,g **node,int k,int i,int n){
	g *nod = NULL;
	r *resource1 = NULL;
	int j = 0,h = 0;
	resource1 = calloc(1,sizeof(r)); // Allocating an edge
	if(!resource1){
		printf("Error when allocating memory");
		exit(0);
	}
	resource1->next = (*node)->K;
	resource1->k = k;
	do{
		j = rand() % n; // Choosing randomly a node to make connection
	}while(j == i); // Not allowing loops
	for(nod = (*aux)->nodes; nod != NULL && h != j; nod = nod->next,h++)
		continue;
	resource1->request = nod; // Connecting the node with the edge
	(*node)->K = resource1; // Insert the resource in the beggining of list
}

// Create one graph
void allocategraph(b **buffer){
	b *aux = calloc(1,sizeof(b)), *prev;
	int n,i,k,totaledges;
	if(!aux){
		printf("Error when allocating memory");
		exit(0);
	}
	aux->next = NULL;
	n = minnode + rand() % (maxnode-minnode); // Select randomly the number of nodes
	for(i = 0; i < n; i++) // Create all nodes of the graph
		createnode(&aux,i);
	i = 0;
	totaledges = minnode + rand() % n; // Between minnode and n (minnode-maxnode)
	for(g *node = aux->nodes; node != NULL && totaledges > 0; node = node->next,i++){ // Create all edges of the graph
		//for(k = -1 + rand() % totaledges; k >= 0 && totaledges > 0; k--,totaledges--)
			createresource(&aux,&node,k,i,n);
			totaledges--;
	}
	if(!*buffer) // If the queue is null
		*buffer = aux; // Insert the first graph as the root of list
	else{ // If the queue has graphs
		for(prev = (*buffer); prev->next != NULL; prev = prev->next) // Reach the latest graph inserted
			continue;
		prev->next = aux; // Update the latest graph inserted
	}
	count++;
	graphs++;
}

// Print the whole graph
void printgraph(b *buffer){
	printf("In graph:");
	for(g *aux = buffer->nodes; aux != NULL; aux = aux->next){
		printf("\n\tNode %2d ",(aux->n));
		for(r *re = aux->K; re != NULL; re = re->next)
			printf("-> Resource %2d ",(re->request->n));
	}
	printf("\n\n\n");
}

// Remove (free) the first graph in buffer
void freegraph(b **buffer){
	b *second,*first;
	for(g *aux1 = (*buffer)->nodes, *aux2; aux1 != NULL; aux1 = aux2){
		aux2 = aux1->next;
		for(r *re1 = aux1->K, *re2; re1 != NULL; re1 = re2){
			re2 = re1->next;
			free(re1);
		}
		free(aux1);
	}
	second = (*buffer)->next;
	first = *buffer;
	free(first);
	*buffer = second;
	count--;
}

// Remove the buffer and all linked graphs
void freegraphs(b **buffer){
	for(b *glist1 = *buffer, *glist2; glist1 != NULL; glist1 = glist2){
		glist2 = glist1->next;
		for(g *aux1 = glist1->nodes, *aux2; aux1 != NULL; aux1 = aux2){
			aux2 = aux1->next;
			for(r *re1 = aux1->K, *re2; re1 != NULL; re1 = re2){
				re2 = re1->next;
				free(re1);
			}
			free(aux1);
		}
		free(glist1);
	}
	*buffer = NULL;
}

// Remove (free) the whole list
void freelist(b **list){
	for(b *glist1 = *list, *glist2; glist1 != NULL; glist1 = glist2){
		glist2 = glist1->next;
		free(glist1);
	}
	*list = NULL;
}

// Remove (free) the latest inserted partition of list (in the end of list)
void removelist(b ***list){
	b *aux,*prev;
	if(!**list)
		return;
	if((**list)->next == NULL){
		aux = **list;
		free(aux);
		**list = NULL;
	}
	else{
		for(prev = **list,aux = (**list)->next; aux->next != NULL; prev = aux, aux = aux->next)
			continue;
		prev->next = NULL;
		free(aux);
	}
}

// Insert a new partition in the list and check if has cycle
bool insertlist(b ***list,g ***node){
	b *new = calloc(1,sizeof(b)),*aux;
	bool duplicate = false;
	if(!new){
		printf("Error when allocating memory");
		exit(0);
	}
	new->next = NULL;
	new->nodes = **node;
	if(!(**node)->visited)
		(**node)->visited = true;
	if(!**list)
		**list = new;
	else{
		for(aux = **list; aux->next != NULL; aux = aux->next)
			if(aux->nodes == **node)
				duplicate = true;
		aux->next = new;
	}
	return duplicate;
}

// Print the cycle of the graph
void printlist(b *list){
	printf("\nFound a cycle denoted below:\n");
	for(b *aux = list; aux != NULL; aux = aux->next){
		printf("%2d",aux->nodes->n);
		if(aux->next != NULL)
			printf(" -> ");
		else
			printf(" ");
	}
	printf("\n");
}

// Check if has cycle
bool check(b **list, g **node){
	if(insertlist(&list,&(node))){ // Check if the node is in list and add to list
		printlist(*list); // An cycle found, print the cycle
		removelist(&list); // Remove the node inserted
		return true;
	}
	else{
		for(r *edge = (*node)->K; edge != NULL; edge = edge->next){ // Access the edges of the node
			if(check(&*list,&edge->request)){ // Check if has cycles
				removelist(&list); // Remove from list freeing memory
				return true;
			}
		}
		removelist(&list); // Remove the main node if has no cycles in edges or no edges
		return false;
	}
}

// Function for produce graphs
void *produce(void *arg){
	b **buffer = (b**)arg;
	for(int i = 0; i < 10000; i++){
		sem_wait(&Empty);
		sem_wait(&mutex);
		allocategraph(&*buffer);
		sem_post(&mutex);
		sem_post(&Full);
	}
	return 0;
}

// Function that detects cycle and print graph
void *consume(void *arg){
	b *list = NULL, **buffer = (b**)arg;
	for(int i = 0; i < 10000; i++){
		sem_wait(&Full);
		sem_wait(&mutex);
		for(g *aux = (*buffer)->nodes; aux != NULL; aux = aux->next){
			if(!aux->visited && check(&list,&aux)){ // Check if the node has been visited and check if has cycles
				printgraph(*buffer);
				printf("Graphs in buffer: %d\n",count);
				cycles++;
				break;
			}
		}
		freegraph(&(*buffer));
		sem_post(&mutex);
		sem_post(&Empty);
	}
	freelist(&list);
	return 0;
}

int main(){
	srand(time(NULL));
	b *buffer = NULL;
	pthread_t A,B;
	sem_init(&mutex, 0, 1);
	sem_init(&Empty, 0, 10);
	sem_init(&Full, 0, 0);
	// Thread A
	pthread_create(&A, NULL, produce, &buffer);
	// Thread B
	pthread_create(&B, NULL, consume, &buffer);

	pthread_join(A, NULL);
	pthread_join(B, NULL);

	printf("\n\nTotal of %d cycles in %d graphs\n", cycles, graphs);

	sem_destroy(&mutex);
	sem_destroy(&Empty);
	sem_destroy(&Full);
	freegraphs(&buffer);
	return 0;
}