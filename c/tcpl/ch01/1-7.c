#include <stdio.h>

#define BAR_LENGTH 50

void printHg(int occur, int DistroLen, int Hlength);
int calcBars(int occur, int DistroLen, int Hlength);

main()
{
    int c, ws, nc;

    ws = nc = 0;

    while((c = getchar()) != EOF)
    {
        nc++;

        if (c == ' ' || c == '\n' || c == '\t')
            ws++;
    }

    printf("\nWhitespace characters: %4d\tTotal characters: %4d\n", ws, nc);
    printHg(ws, nc, BAR_LENGTH);
}

void printHg(int o, int dl, int hl)
{
    int i;
    int b = calcBars(o, dl, hl);

    printf("[");

    for (i = 0; i < hl; i++, b--)
        if (b > 0)
            printf("|");
        else
            printf(" ");

    printf("]\n");
}

int calcBars(int o, int dl, int hl)
{
    return (o * hl) / dl;
}
