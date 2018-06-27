#include <stdio.h>
#include <ctype.h>

#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

enum state { ZERO, ONE, TWO, THREE, FOUR, FIVE, ERROR };
enum symbol { GREEN, RED, YELLOW };

//(r|yr)?gyr(gyr)*
enum state transitions[6][3] = {
	// G      R       Y
	{ ONE,   TWO,   THREE },//0
	{ ERROR, ERROR, FOUR  },//1
	{ ONE,   ERROR, ERROR },//2
	{ ERROR, TWO,   ERROR },//3
	{ ERROR, FIVE,  ERROR },//4
	{ ONE,   ERROR, ERROR } //5
};

__attribute__ ((pure)) int charstate(int c)
{
    c = tolower(c);
    switch (c) {
    case 'r': return RED;
    case 'y': return YELLOW;
    case 'g': return GREEN;
    default : return ERROR;
    }
}

__attribute__ ((pure)) enum state transition(enum state s, int c)
{
    int i = charstate(c);
    return (i == ERROR) ? ERROR : transitions[s][i];
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


    enum state s = ZERO;

    printf("Traffic light sequence: ");
    int c;
    while (s != ERROR &&
	   (c = getchar()) != EOF &&
	   !iscntrl(c)) {
        s = transition(s, c);
    }
    printf("\n");
    if (s != FIVE || s == ERROR) {
        puts("Invalid sequence.");
    }

    return 0;
}
