#include <stdio.h>

main()
{
    int c, nl;

    while((c = getchar()) != EOF)
    {
        if (c == '\n')
            nl++;

        putchar(c);
    }

    printf("newline count: %d\n", nl);
}
