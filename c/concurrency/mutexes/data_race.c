#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int balance = 100;

void test(void) {
    pthread_mutex_lock(&mutex);
    printf("Making withdraw\n");
    balance -= 50;
    printf("balance is:\t\t%4d\n", balance);
    pthread_mutex_unlock(&mutex);
}

int main(int argc, char const* argv[])
{
    printf("Starting balance:\t%4d\n", balance);
    pthread_t a, b;

    pthread_create(&a, NULL, (void *) test, NULL);
    pthread_create(&b, NULL, (void *) test, NULL);

    pthread_join(a, NULL);
    pthread_join(b, NULL);

    printf("Done.\n");

    return 0;
}
