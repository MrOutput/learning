#include <stdio.h>

void copy(char f[], char t[])
{
    int i = 0;
    while((t[i] = f[i]) != '\0')
        i++;
}

int main(void)
{
    char test[] = "rafael cepeda";
    char test2[sizeof test];
    copy(test, test2);
    puts(test);
    puts(test2);
    return 0;
}
