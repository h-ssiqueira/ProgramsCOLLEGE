#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

using namespace std;

sem_t mutex;

void *Thread(void *arg){
	char *ID = (char *) arg;
	sem_wait(&mutex);
	cout << "Thread " << ID << " entered in critical region" << endl;
	sleep(3);
	cout << "Thread " << ID << " leaving critical region" << endl;
	sem_post(&mutex);
	return 0;
}

int main(){
	sem_init(&mutex, 0, 1);
	pthread_t T1, T2;
	pthread_create(&T1,NULL,Thread,(void *)"A");
	pthread_create(&T2,NULL,Thread,(void *)"B");
	pthread_join(T1,NULL);
	pthread_join(T2,NULL);
	sem_destroy(&mutex);
	return 0;
}