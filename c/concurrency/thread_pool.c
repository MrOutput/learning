#include <stdio.h>
#include <pthread.h>

#define POOL_SIZE 4000

void loop(void) {
    for (int i = 1; i < 1000; i*=2) {
        printf("%d\n", i);
    }

    printf("thread finished");
}

int main(int argc, char const* argv[])
{
    pthread_t pool[POOL_SIZE];

    for (int i = 0; i < POOL_SIZE; i++) {
        pthread_create(&pool[i], NULL, (void *) loop, (void *) NULL);
    }

    for (int i = 0; i < POOL_SIZE; i++) {
        pthread_join(pool[i], (void **) NULL);
    }

    printf("Rafael says: Done.\n");

    return 0;
}
