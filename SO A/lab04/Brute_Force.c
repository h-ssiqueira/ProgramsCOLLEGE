#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <pthread.h>
#include <math.h>
#include <unistd.h>
//#include <time.h>
#define SIZE_KEY 8
#define THREAD_MAX 4

static char secret_key[SIZE_KEY];
//bool found = false; // problema: região crítica

void GenerateSecretKey(char *k);
bool SecretKeyTest(char *key);
void *SecretKeySearch(void *args);


int main(){
	//srand(time(NULL)); // Problema da geração de chave: sem essa linha ela se torna fixa
	GenerateSecretKey(secret_key);
    // Caso sem threads
	//SecretKeySearch((void *)"AZ1");

    // Caso 2 threads
    /*
	pthread_t AtoM, NtoZ;
	pthread_create(&AtoM, NULL, SecretKeySearch, (void *)"AM1");
	pthread_create(&NtoZ, NULL, SecretKeySearch, (void *)"NZ2");
	pthread_join(AtoM,NULL);
	pthread_join(NtoZ,NULL);
	*/
    // Caso 4 threads
    /*
    pthread_t AtoG, HtoN, OtoT, UtoZ;
	pthread_create(&AtoG, NULL, SecretKeySearch, (void *)"AG1");
	pthread_create(&HtoN, NULL, SecretKeySearch, (void *)"HN2");
    pthread_create(&OtoT, NULL, SecretKeySearch, (void *)"OT3");
	pthread_create(&UtoZ, NULL, SecretKeySearch, (void *)"UZ4");
	pthread_join(AtoG,NULL);
	pthread_join(HtoN,NULL);
    pthread_join(OtoT,NULL);
    pthread_join(UtoZ,NULL);
    */
	// Caso nº de threads definido

	pthread_t thread[THREAD_MAX];
	char start_end[3];
	start_end[3] = 0;
	start_end[0] = 65;
	start_end[1] = ceil(26 / THREAD_MAX) + start_end[0];
	for(int i = 0; i < THREAD_MAX; i++){
		start_end[2] = i + 49;
		pthread_create(&thread[i], NULL, SecretKeySearch, (void *)start_end);
		sleep(1); // Necessidade de colocar um sleep para que não haja conflito de atualização do start_end
		start_end[0] = start_end[1] + 1;
		start_end[1] += ceil(26 / THREAD_MAX)+1;
	}
	for(int i = 0; i < THREAD_MAX; i++){
		pthread_join(thread[i], NULL);
	}

	return 0;
}

void GenerateSecretKey(char *k){
	static const char letters[] = "abcdefghijklmnopqrstuvwxyz";
	static const int len = sizeof(letters) - 1;
	for(int i = 0; i < SIZE_KEY; i++)
		k[i] = letters[rand() % len];
	k[SIZE_KEY] ^= k[SIZE_KEY];
}

bool SecretKeyTest(char *key){
	if(strcmp(key,secret_key) != 0)
		return false;
	printf("Congratulations, you discovered the secret key: %s\n",key);
	//found = true;
	return true;
}

void *SecretKeySearch(void *args){
	char key[SIZE_KEY], *arg = (char *)args;
	int i;
	long count = 0;
	printf("%s\t%s\n",(char *)args,arg); // Strings condizem
	key[SIZE_KEY] ^= key[SIZE_KEY];
	key[0] = arg[0] + 32;
    for(i = SIZE_KEY-1; i > 0; i--)
        key[i] = 97;
	while(!SecretKeyTest(key) /*&& !found*/){
		//GenerateSecretKey(key); // Problema da aleatoriedade: chave pode se repetir e não testa todas as possibilidades
		//printf("Testing key %s\n", key); // Problema da exibição: o SO demora muito tempo para exibir na tela
		i = SIZE_KEY-1;
		key[i]++;
		while(key[i] == 123 && i > 0){
			key[i--] -= 26;
			key[i]++;
		}
		if(key[0] == arg[1] + 33 || key[0] >= 123)
            return 0;
		count++;

		if(count % 1000000000 == 0){
			printf("Thread %s: %ld hundred million tries done\n",arg,count / 1000000000); // O nome da thread não condiz com o armazenado em arg ou args (primeiro print desta função)
		}

	}
	exit(0);
}