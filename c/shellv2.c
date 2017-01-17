#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define HIST_SZ 5

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
	char *buf[HIST_SZ];
} hist;

void addhist()
{
	if (hist.n == HIST_SZ) {
		free(hist.buf[HIST_SZ-1]);
		memmove(hist.buf+1, hist.buf, (sizeof(char *) * (HIST_SZ-1)));
	} else if (hist.n > 0) {
		memmove(hist.buf+1, hist.buf, (sizeof(char *) * hist.n));
		hist.n++;
	}
	hist.buf[0] = strdup(input.buf);
}

int main(int argc, char *argv[])
{
	int c;

prompt:
	bufrst();
	printf("> ");

	while ((c = getchar()) != EOF) {
		switch (c) {
		case '\n':
			if (input.i > 0) {
				bufc('\0');
				addhist();
			}
			goto prompt;
		default:
			bufc(c);
		}
	}

	printf("\n");
	return 0;
}
