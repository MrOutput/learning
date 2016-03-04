#include <stdio.h>

main()
{
    int c;
    long int nl, ws, cc;

    while((c = getchar()) != EOF)
    {
        cc++;
        if (c == '\n')
            nl++;
        if (c == ' ' || c == '\n' || c == '\t')
            ws++;
    }

    printf("char count: %ld\n", cc);
    printf("newline count: %ld\n", nl);
    printf("whitespace count: %ld\n", ws);
}
