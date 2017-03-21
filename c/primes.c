#include <stdio.h>
#include <stdbool.h>

__attribute__ ((pure)) inline bool has_divisor(unsigned long long num)
{
    unsigned long long i;
    for (i = 2; i < num; ++i) {
        if (num % i == 0) {
            return true;
        }
    }
    return false;
}

__attribute__ ((noreturn)) void main(void)
{
    unsigned long long i;
    for (i = 0; true; ++i) {
        if (has_divisor(i) == false) {
            printf("%lld\n", i);
        }
    } 
}
