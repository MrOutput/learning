#include <stdio.h>
#include <string.h>

void copy(char from[], char to[]);

main() {
    char test[] = "rafael cepeda";

    char test2[strlen(test)];

    copy(test, test2);

    puts(test);
    puts(test2);

    return 0;
}

void copy(char f[], char t[])
{
    int i = 0;
    while((t[i] = f[i]) != '\0')
        i++;
}
