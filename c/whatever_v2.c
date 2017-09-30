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
#define RESET "0"

char what[] = CSI YLW SGR_END "what " CSI DEF_FG SGR_END "{\n";
char ever[] = CSI RED SGR_END "ever\n" CSI DEF_FG SGR_END;
char end[] = "}\n";

char *buf = NULL;

void addline(char *src, int tabs)
{
    for (; tabs > 0; tabs--, buf++)
        *buf = '\t';
    for (; *src != '\0'; src++, buf++)
        *buf = *src;
    *buf = '\0';
}

void whatever(int c, int i)
{
    addline(what, i);
    if (c > 1)
        whatever(c-1, i+1);
    else
        addline(ever, i+1);
    addline(end, i);
}

size_t calcsize(unsigned int n)
{
    int size = 0;
    int i;
    for (i = 1; i <= n; i++)
        size += 2*i + sizeof(what) + sizeof(end) - 4;
    size += n + sizeof(ever);
    return size;
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
    if (argc == 3 && c == 'n' && isnum(optarg) && (n = atoi(optarg)) > 0) {
        char *orig = buf = malloc(calcsize(n));
        whatever(n, 0);
        fputs(orig, stdout);
        //free(orig);
    } else
        puts(CSI RED AND BOLD SGR_END "nope." CSI RESET SGR_END);
    return 0;
}
