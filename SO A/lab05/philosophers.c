#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>
#define T 0 // Thinking
#define H 1 // Hungry
#define E 2 // Eating

int *State, *ThreadID, philosophers, timeThinkingmin, timeThinkingmax, timeEatingmin, timeEatingmax;
sem_t mutex;
sem_t *philosophersm;

int Left(int p);
int Right(int p);
void Think();
void Eat();
void* Philosopher(void* p);
void TakeForks(int f);
void ReturnForks(int f);
void Check(int t);

int main(int argc, char *argv[]){
	if(argc != 6){
		printf("Program without the correct parameters of inicialization (%d != 6), please try again.", argc);
		return 0;
	}
	srand(time(NULL)); // Atribuição de um número realmente aleatório
	philosophers = atoi(argv[1]);
	timeThinkingmin = atoi(argv[2]);
	timeThinkingmax = atoi(argv[3]);
	timeEatingmin = atoi(argv[4]);
	timeEatingmax = atoi(argv[5]);
	State = calloc(philosophers,sizeof(int));
	ThreadID = malloc(philosophers * sizeof(int));
	philosophersm = malloc(philosophers * sizeof(sem_t));
	sem_init(&mutex, 0, 1);
	pthread_t TH[philosophers];
	printf("0 - Thinking\t1 - Hungry\t2 - Eating\n\n");
	for(int i = 0; i < philosophers; i++){
		ThreadID[i] = i;
		sem_init(&(philosophersm[i]), 0, 0);
		pthread_create(&TH[i], NULL, Philosopher, &ThreadID[i]);
	}
	for(int i = 0; i < philosophers; i++)
		pthread_join(TH[i], NULL);
	sem_destroy(&mutex);
	free(State);
	free(ThreadID);
	free(philosophersm);
	return 0;
}

int Left(int p){
	return (p + philosophers - 1) % philosophers;
}

int Right(int p){
	return (p+1) % philosophers;
}

void Think(){
	int time = rand() % (timeThinkingmax - timeThinkingmin);;
	sleep(time + timeThinkingmin); // Tempo para pensar
}

void Eat(){
	int time = rand() % (timeEatingmax - timeEatingmin);
	sleep(time + timeEatingmin); // Comendo
}

void* Philosopher(void* p){
	int a = 0;
	while(a != 100){ // Para que não fique em loop infinito
		Think(); // Filósofo pensando
		TakeForks(*((int *)p)); // Pega os garfos
		for(int i = 0; i < philosophers; i++)
			printf("F%d - %d\t",ThreadID[i]+1, State[i]); // Printa o estado atual de todos os filósofos
		printf("\n");
		//if(State[*(int *)p] == E){
		Eat(); // Filósofo comendo
		ReturnForks(*((int *)p)); // Retorna os garfos à mesa
		//}
		a++;
	}
	return 0;
}

void TakeForks(int f){
	sem_wait(&mutex); // Entra na região crítica
	State[f] = H; // Filósofo com fome
	Check(f); // Checa se há dois garfos disponíveis
	sem_post(&mutex); // Sai da região crítica
	sem_wait(&(philosophersm[f])); // Coloca para esperar
}

void ReturnForks(int f){ // Se estiver comendo, retorna os garfos à mesa
	sem_wait(&mutex); // Entrando em uma região crítica
	State[f] = T; // Filósofo pensando
	Check(Left(f)); // Verifica se o da esquerda pode comer
	Check(Right(f)); // Verifica se o da direita pode comer
	sem_post(&mutex); // Sai da região crítica
}

void Check(int t){
	if(State[t] == H && State[Left(t)] != E && State[Right(t)] != E){ // Checa disponibilidade dos garfos e se o filósofo está com fome
		State[t] = E; // Para que ele possa comer
		sem_post(&(philosophersm[t])); // Coloca para comer
	}
}