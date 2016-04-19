#include <stdio.h>

#define TPOOL_SIZE 10000

int main(int argc, char const* argv[])
{
    for (int i = 0; i < TPOOL_SIZE; i++) {
        for (int i = 1; i < 1000; i*=2) {
            printf("%d\n", i);
        }

        printf("nonthread finished.\n");
    }

    printf("Rafael says: Done.\n");

    return 0;
}
