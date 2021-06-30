#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

using namespace std;

#define N params.total_philosophers
#define LEFT (i+N-1)%N
#define RIGHT (i+1)%N

enum tState {
    THINKING,
    HUNGRY,
    EATING
};

struct tParams {
    int min_time_eating;
    int max_time_eating;
    int min_time_thinking;
    int max_time_thinking;
    int total_philosophers;

    tParams() : min_time_eating(1), max_time_eating(3), min_time_thinking(1),
            max_time_thinking(3), total_philosophers(1) {
    }

    void print() {
         cout << "min_time_eating = " << min_time_eating
             << "\nmax_time_eating = " << max_time_eating
             << "\nmin_time_thinking = " << min_time_thinking
             << "\nmax_time_thinking = " << max_time_thinking
             << "\ntotal_philosophers = " << total_philosophers << endl;
    }
};

tState* state;
sem_t *s;
sem_t mutex;
tParams params;

void Config(int argc, const char *argv[]) {
    switch (argc) {
        case 6:
            params.max_time_eating = stoi(argv[5]);
        case 5:
            params.min_time_eating = stoi(argv[4]);
        case 4:
            params.max_time_thinking = stoi(argv[3]);
        case 3:
            params.min_time_thinking = stoi(argv[2]);
        case 2:
            params.total_philosophers = stoi(argv[1]);
            break;
        default:
            cout << "philosophers total_philosophers min_time_eating max_time_eating min_time_thinking max_time_thinking" << endl;
            exit(1);
    }
}

void eat(int i) {
    cout << "Thread " << i << " is eating" << endl;
    sleep(params.min_time_eating + rand() % params.max_time_eating);
}

void think(int i) {
    cout << "Thread " << i << " is thinking" << endl;
    sleep(params.min_time_thinking + rand() % params.max_time_thinking);
}

void test(int i) {
    if (state[i] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING) {
        state[i] = EATING;
        sem_post(&(s[i]));
    }
}

void take_forks(int i) {
    sem_wait(&mutex);
    state[i] = HUNGRY;
    test(i);
    sem_post(&mutex);
    sem_wait(&(s[i]));
}

void put_forks(int i) {
    sem_wait(&mutex);
    state[i] = THINKING;
    test(LEFT);
    test(RIGHT);
    sem_post(&mutex);
}

void philosopher(int i) {
    while (true) {
        think(i);
        take_forks(i);
        eat(i);
        put_forks(i);
    }
}

void init_threads() {
    int total = params.total_philosophers;

    state = new tState[total];
    s = new sem_t[total];

    for (int i = 0; i < total; i++) {
        sem_init(&(s[i]), 0, 0);
        state[i] = THINKING;
    }

    sem_init(&mutex, 0, 1);
}

void free_threads() {
    int total = params.total_philosophers;
    for (int i = 0; i < total; i++) {
        sem_destroy(&(s[i]));
        state[i] = THINKING;
    }

    sem_destroy(&mutex);

    delete state;
    delete s;
}

void* run_thread(void* arg) {
    philosopher(*(long*) arg);
}

int main(int argc, const char *argv[]) {
    try {
        Config(argc, argv);
    } catch (...) {
        cout << "philosophers total_philosophers min_time_eating max_time_eating min_time_thinking max_time_thinking" << endl;
        return 1;
    }

    init_threads();
    pthread_t threads[params.total_philosophers];
    long ids[params.total_philosophers];

    for (int i = 0; i < params.total_philosophers; i++) {
        ids[i] = i;
        pthread_create(&(threads[i]), NULL, run_thread, &(ids[i]));
    }

    for (int i = 0; i < params.total_philosophers; i++)
        pthread_join(threads[i], NULL);

    free_threads();
    return 0;
}
