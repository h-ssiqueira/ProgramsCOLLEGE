#include <iostream>
#include <pthread.h>
using namespace std;
// sudo apt-get install libpthread-stubs0-dev
// g++ main.cpp -pthread -std=c++11

void *thread(void *arg);

int main(){
	pthread_t x,y;

	cout << "Creating thread X" << endl;
	pthread_create(&x, NULL, thread, (void *)("X"));
	cout << "Creating thread Y" << endl;
	pthread_create(&y, NULL, thread, (void *)("Y"));

	pthread_join(x,NULL);
	pthread_join(y,NULL);
	cout << "Program finished" << endl;
	return 0;
}

void *thread(void *arg){
	cout << "Hello thread " << (const char *) arg << endl;
	return 0;
}