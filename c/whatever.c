#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>

#define ESC "\x1B"
#define CSI ESC"["
#define AND ";"
#define BOLD "1"
#define RED "31"
#define YLW "33"
#define SGR_END "m"
#define DEF_FG "39"

void addline(char *src, int tabs)
{
    int i;
    for (i = 0; i < tabs; i++)
        printf("\t");
    puts(src);
}

void whatever(int c, int i)
{
    addline(CSI YLW SGR_END "what " CSI DEF_FG SGR_END  "{", i);
    if (c > 1)
        whatever(c-1, i+1);
    else
        addline(CSI RED SGR_END "ever" CSI DEF_FG SGR_END, i+1);
    addline("}", i);
}

int isnum(char *s)
{
    for (; *s != '\0'; s++)
        if (isdigit(*s) == 0) 
            return 0;
    return 1;
}

int main(int argc, char *argv[])
{
    int c = getopt(argc, argv, "n:");
    int n;
    if (argc == 3 && c == 'n' && isnum(optarg) && (n = atoi(optarg)) > 0)
        whatever(n, 0);
    else
        puts(CSI RED AND BOLD SGR_END "nope." CSI DEF_FG SGR_END);
    return 0;
}
