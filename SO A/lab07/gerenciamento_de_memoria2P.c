#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define max 4096

int memory[max];

typedef struct list{
	short info[2];
}node;

// Allocate a partition of memory
int *mallocMem(unsigned size){ // Return the pointer to allocated memory partition
	int *i, j;
	node *actual = (node *) memory, *prev;
	do{
		if(actual->info[0] == -1){
			prev = actual;
			if(actual->info[2] >= size){ // Found a free region
				for(i = memory + actual->info[1], j = size; j > 0; i++, j--){
					if(i >= memory + max) // If the pointer bypass the memory region
						return NULL;
					*i = 2; // Allocated region receives 2
				}
				if(prev->info[2] > size+2 && (!(i + 3 >= memory + max) || (!(i + 3 >= prev->info[3] + memory) && prev->info[3] != 0))){ // If the region is bigger than the size and has space for a new region
					actual = (node *) memory + actual->info[1] + size;
					actual->info[0] = -1; // Set the new region as free
					actual->info[1] = prev->info[1] + size + 2; // Set the initial position of new region
					actual->info[2] = prev->info[2] - (size + 2); // Set the remaining size of memory
					actual->info[3] = prev->info[3]; // Next node of linked list is the next from previous node
					prev->info[0] = 1; // Set the previous region as allocated
					prev->info[2] = size; // Update the size of region
					prev->info[3] = prev->info[1] + size; // Set the position of next node
					return (int *) prev + 2;
				}
				else if(i + 2 >= memory + max || size == prev->info[2] || (i + 2 >= prev->info[3] + memory && prev->info[3] != 0)){ // If the partition has the same size as required or the remaining region is less than 3, won't be possible to create a new region, then the allocated region is the same indicated in node (internal fragmentation)
					prev->info[0] = 1;
					return (int *) prev + 2;
				}
			}
		}
		actual = (node *) memory + actual->info[3];
	}while(actual != (node *) memory);
	return NULL;
}

// Free memory in a specific partition
void freeMem(int *ptr, unsigned size){ // Free memory, where *ptr is a pointer to allocated partition
	if(!ptr)
		return;
	int *aux,j;
	node *i = (node *) memory, *prev = NULL, *next;
	do{
		//i++;
		if(memory + i->info[1] != ptr){ // Check if the pointer is not in the partition
			prev = i;
			i = (node *) memory + i->info[3];
		}
		else{
			for(aux = ptr, j = 0; j < size; aux++,j++) // Zero all positions
				*aux = 0;
			i->info[0] = -1; // Set the partition as free
			// previous - i - next
			next = (node *)aux;
			if(prev && next < (node *) memory + max && prev->info[0] == -1 && next->info[0] == -1){ // Both adjacent
				prev->info[2] += i->info[2] + next->info[2] + 4;
				prev->info[3] = next->info[3];
				i->info[0] = i->info[1] = i->info[2] = i->info[3] = next->info[0] = next->info[1] = next->info[2] = next->info[3] = 0;
			}
			else if(next < (node *) memory + max && next->info[0] == -1){ // Free partition on right
				i->info[2] += next->info[2] + 2;
				i->info[3] = next->info[3];
				next->info[0] = next->info[1] = next->info[2] = next->info[3] = 0;
			}
			else if(prev && prev->info[0] == -1){ // Free partition on left
				prev->info[2] += i->info[2] + 2;
				prev->info[3] = i->info[3];
				i->info[0] = i->info[1] = i->info[2] = i->info[3] = 0;
			}
			return;
		}
	}while(i != (node *) memory);
}

// Return the size of free memory
int getFreeMem(){ // Return the total of free bytes
	int sum = 0;
	node *ptr = (node *) memory;
	do{
		if(ptr->info[0] == -1) // If the node indicates that partition is free
			sum += ptr->info[2]; // To increment the total number of free spaces
		ptr = (node *) memory + ptr->info[3];
	}while(ptr != (node *) memory);
	return sum;
}

// Print all allocated partitions with the size of each one
void printAllocated(){
	node *i = (node *) memory;
	do{
		if(i->info[0] == 1) // If the node indicates that next partition is allocated
			printf("Partition %d (%d positions)\n", i->info[1], i->info[2]);
		i = (node *) memory + i->info[3];
	}while(i != (node *) memory);
}

// Display all positions of memory
void showMem(){
	int *i;
	node *j = (node *) memory;
	do{
		printf("|%d %d| |%d %d| ", j->info[0], j->info[1], j->info[2], j->info[3]); // 2 positions in memory
		for(i = memory + j->info[1]; i != memory + j->info[3] && i != memory + max; i++)
			printf("%d ", *i);
		j = (node *) memory + j->info[3];
	}while(j != (node *) memory);
}

// Get the position of the node in memory
int *getPos(int addr, int *size){
	node *ptr = (node *) memory;
	do{
		if(ptr->info[1] + memory == addr + memory){ // Check if the input address is the beggining of the partition
			*size = ptr->info[2];
			return addr + memory;
		}
		ptr = (node *) memory + ptr->info[3];
	}while(ptr != (node *) memory);
	*size = 0;
	return NULL;
}

int main(){
	int op = 1, *i, *ptr = NULL, addr;
	node *prt;
	unsigned size = 0;
	bool done = true;
	prt = (node*) memory;
	prt->info[0] = -1; // First node of linked list indicating that the whole memory is free
	prt->info[1] = 2;
	prt->info[2] = max - 2;
	prt->info[3] = 0;
	for(i = (memory + 2); i < (memory + max); i++)
		*i ^= *i; // Zero all positions of memory

	do{
		printf("\n\nThere are %d free positions in memory.\n\n0 - Exit.\n1 - Allocate memory.\n2 - Free memory.\n3 - Print memory.\n-> ", getFreeMem());
		scanf("%d", &op);

		switch(op){
			case 1:
				if(getFreeMem() == 0){
					printf("\n\nMemory full!\n\n");
					break;
				}
				do{
					printf("\nSelect the size of memory which will be allocated:\n-> ");
					scanf("%d", &size);
					if(size < 1 || size > getFreeMem())
						printf("\n\nPlease select a size between 1 and %d.\n\n", getFreeMem());
				}while(size < 1 || size > getFreeMem());
				// Allocate and create the node for linked list if necessary
				ptr = mallocMem(size);
				ptr ? printf("\n\nMemory allocated with success in address %ld.\n\n", (ptr - memory)) : printf("\n\nFailed to allocate memory (out of memory).\n\n");
				break;
			case 2:
				// Print the linked list and let the user choose the partition to liberate
				if(getFreeMem() == max - 2){
					printf("\n\nNo partitions allocated.\n\n");
					break;
				}
				do{
					printf("Choose the address of partition to be freed:\n");
					printAllocated();
					printf("\n-> ");
					scanf("%d", &addr);
					if(addr < 1 || addr > max)
						printf("\n\nPlease insert a valid partition.\n\n");
				}while(addr < 1 || addr > max);
				ptr = getPos(addr,&size);
				freeMem(ptr,size);
				ptr ? printf("\n\nMemory freed with success.\n\n") : printf("\n\nFailed to free memory (address error).\n\n");
				break;
			case 3:
				printf("\n\n\n");
				showMem();
				printf("\n\n\n");
				break;
		}
	}while(op != 0);
	return 0;
}