#include <stdio.h>
#include <string.h>

char *reverse(char[]);

main()
{
    char test[] = "Rafael Leonidas Cepeda";

    puts(test);
    puts(reverse(test));

    return 0;
}

char *reverse(char s[])
{
    int i = strlen(s),
        j = 0;

    char a[i + 1];

    while (i--)
        if (s[i] != '\0')
            a[j++] = s[i];

    a[j + 1] = '\0';

    return a;
}
