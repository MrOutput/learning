#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct dynbuf {
	int len;
	int i;
	char *buf;
};
struct dynbuf input;

void chgbuf(struct dynbuf *b, int len)
{
	b->len = len;
	b->buf = realloc(b->buf, len);
}

void bufc(char c)
{
	if (input.i == input.len-1)
		chgbuf(&input, input.len*2);
	input.buf[input.i++] = c;
}

void bufrst(void)
{
	int init = 16;
	if (input.len != init)
		chgbuf(&input, (init));
	input.i = 0;
}

struct {
	int n;
	char *buf[5];
} hist;

void addhist()
{
	if (hist.n > 0) {
		if (hist.n == 5)
			free(hist.buf[4]);
		//shift hist.buf over 1 element
		memmove(hist.buf+1, hist.buf, (sizeof(char *) * hist.n));
	}
	int len = input.i+1;
	char *cmd = malloc(len);
	memcpy(cmd, input.buf, len);
	hist.buf[0] = cmd;
	hist.n++;
}

int main(int argc, char *argv[])
{
	int c;

prompt:
	bufrst();
	printf("> ");

	while ((c = getchar()) != EOF) {
		if (c == '\n') {
			if (input.i > 0) {
				bufc('\0');
				puts(input.buf);
				addhist();
			}
			goto prompt;
		}
		bufc(toupper(c));
	}

	printf("\n");
	return 0;
}
