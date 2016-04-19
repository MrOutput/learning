#include <stdio.h>
#include <pthread.h>

#define TPOOL_SIZE 2
#define TOTAL_ITERATIONS 10000

void loop(void) {
    for (int i = 0; i < TOTAL_ITERATIONS / TPOOL_SIZE; i++) {
        for (int i = 1; i < 1000; i*=2) {
            printf("%d\n", i);
        }
    }

    printf("thread finished.\n");
}

int main(int argc, char const* argv[])
{
    pthread_t tpool[TPOOL_SIZE];

    for (int i = 0; i < TPOOL_SIZE; i++) {
        pthread_create(&tpool[i], NULL, (void *) loop, (void *) NULL);
    }

    for (int i = 0; i < TPOOL_SIZE; i++) {
        pthread_join(tpool[i], (void **) NULL);
    }

    printf("Rafael says: Done.\n");

    return 0;
}
