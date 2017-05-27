#include <stdio.h>
#include <ctype.h>

#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

enum states { INIT, RED, YELLOW, GREEN, ERROR };

enum states transitions[4][3] = {
/*              RED    YELLOW  GREEN */
/* INIT     */{ RED,   YELLOW, GREEN } ,
/* RED      */{ ERROR, ERROR,  GREEN },
/* YELLOW   */{ RED,   ERROR,  ERROR },
/* GREEN    */{ ERROR, YELLOW, ERROR }
};

__attribute__ ((pure)) enum states charstate(int c)
{
    c = tolower(c);
    switch (c) {
    case 'r': return RED;
    case 'y': return YELLOW;
    case 'g': return GREEN;
    default : return ERROR;
    }
}

__attribute__ ((pure)) enum states transition(enum states s, int c)
{
    int i = charstate(c);
    return (i == ERROR) ? ERROR : transitions[s][i-1];
}

int main(void)
{
    if (isatty(STDOUT_FILENO) == 0) {
        exit(EXIT_FAILURE);
    }

    struct termios t;
    tcgetattr(STDOUT_FILENO, &t);

    int linebufd = ((t.c_lflag & ICANON) > 0);
    if (linebufd) {
        t.c_lflag ^= ICANON;
        tcsetattr(STDOUT_FILENO, TCSANOW, &t);
    }


    enum states state = INIT;

    printf("Traffic light sequence: ");
    int c;
    while ((state != ERROR) && ((c = getchar()) != EOF)) {
        state = transition(state, c);
    }
    printf("\n");
    if (state == ERROR) {
        puts("Invalid sequence.");
    }

    return 0;
}
