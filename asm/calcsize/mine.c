#include <stdio.h>

//asm ver
int calcsize(int bytes, int balign);

/* the compiler cannot make assumptions unless
 * unsigned is specified
 */
unsigned int c_calcsize(unsigned int bytes, unsigned int balign) {
    unsigned int quo = bytes / balign;
    unsigned int rem = bytes % balign;

    if (rem != 0)
        quo++;

    return quo * balign;
}

int main(void)
{
    printf("calcsize: %d\n", calcsize(18, 16));
    printf("c_calcsize: %d\n", c_calcsize(18, 16));
    return 0;
}
