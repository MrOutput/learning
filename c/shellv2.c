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

void bufprint(void)
{
	if (bufi > 0) {
		fputs_unlocked(buf, stdout);
		fputs_unlocked("\n", stdout);
	}
}

int main(int argc, char *argv[])
{
	char *prompt = "> ";
	int c;

prompt:
	bufrst();
	fputs_unlocked(prompt, stdout);

	while ((c = fgetc_unlocked(stdin)) != EOF) {
		if (c == '\n') {
			bufprint();
			goto prompt;
		}
		bufc(c);
	}

	fputs_unlocked("\n", stdout);
	return 0;
}
