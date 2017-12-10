#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uint;

//asm ver
int calcsize(int bytes, int balign);

/* the compiler cannot make assumptions unless
 * unsigned is specified
 */
uint c_calcsize(uint bytes, uint balign) {
    uint quo = bytes / balign;
    uint rem = bytes % balign;

    if (rem != 0)
        quo++;

    return quo * balign;
}

int main(int argc, char **argv)
{
    if (argc < 3)
        return -1;
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    printf("%12s%5d\n", "calcsize: ", calcsize(a, b));
    printf("%12s%5d\n", "c_calcsize: ", c_calcsize(a, b));
    return 0;
}
