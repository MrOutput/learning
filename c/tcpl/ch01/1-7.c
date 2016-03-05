#include <stdio.h>

#define BAR_LENGTH 50

void printHg(int, int, int);
int calcBars(int, int, int);

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

void printHg(int occur, int DistroLen, int Hlength)
{
    int i;
    int bars = calcBars(occur, DistroLen, Hlength);

    printf("[");

    for (i = 0; i < BAR_LENGTH; i++, bars--)
        if (bars > 0)
            printf("|");
        else
            printf(" ");

    printf("]\n");
}

int calcBars(int occur, int DistroLen, int Hlength)
{
    return (occur * Hlength) / DistroLen;
}
