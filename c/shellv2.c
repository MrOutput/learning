#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

enum { BUFINIT = 16 };
int bufi;
int buflen;
char *buf;

void bufc(char c)
{
	if (bufi == buflen-1) {
		buflen *= 2;
		buf = realloc(buf, buflen);
	}
	buf[bufi] = toupper(c);
	buf[++bufi] = '\0';
}

void bufrst(void)
{
	if (buflen != BUFINIT) {
		buflen = BUFINIT;
		buf = realloc(buf, buflen);
	}
	bufi = 0;
}

int main(int argc, char *argv[])
{
	int c;

prompt:
	bufrst();
	printf("> ");

	while ((c = getchar()) != EOF) {
		if (c == '\n') {
			if (bufi > 0)
				puts(buf);
			goto prompt;
		}
		bufc(c);
	}

	printf("\n");
	return 0;
}
