#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define ESC "\x1B"
#define CSI ESC"["
#define AND ";"
#define BOLD "1"
#define RED "31"
#define YLW "33"
#define SGR_END "m"
#define DEF_FG "39"

void indent(int c)
{
    int i;
    for (i = 0; i < c; i++)
        printf("\t");
}

void whatever(int c, int i)
{
    indent(i), puts(CSI YLW SGR_END "what " CSI DEF_FG SGR_END  "{");
    if (c > 1)
        whatever(c-1, i+1);
    else
        indent(i+1), puts(CSI RED SGR_END "ever" CSI DEF_FG SGR_END);
    indent(i), puts("}");
}

int main(int argc, char *argv[])
{
    int c = getopt(argc, argv, "n:");
    if (argc == 3 && c == 'n')
        whatever(atoi(optarg), 0);
    else
        puts(CSI RED AND BOLD SGR_END "nope." CSI DEF_FG SGR_END);
    return 0;
}
