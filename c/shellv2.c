#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define HIST_SZ 5

struct dynbuf {
	int len;
	int i;
	char *buf;
} input;

static void chgbuf(struct dynbuf *b, int len)
{
	b->len = len;
	b->buf = realloc(b->buf, len);
}

static void bufc(char c)
{
	if (input.i == input.len-1)
		chgbuf(&input, input.len*2);
	input.buf[input.i++] = c;
}

static void bufrst(void)
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

static void addhist()
{
	if (hist.n < HIST_SZ)
		hist.n++;
	else
		free(hist.buf[HIST_SZ-1]);
	memmove(hist.buf+1, hist.buf, (sizeof(char *) * (HIST_SZ-1)));
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
