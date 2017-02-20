#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HIST_SZ 5

struct {
	int n;
	char *buf[HIST_SZ];
} hist;

static void addhist(char *s)
{
	if (hist.n < HIST_SZ)
		hist.n++;
	else
		free(hist.buf[HIST_SZ-1]);
	memmove(hist.buf+1, hist.buf, (sizeof(char *) * (HIST_SZ-1)));
	hist.buf[0] = strdup(s);
}

int main(int argc, char *argv[])
{
	char *input = NULL;
	size_t len = 0;
	for (;;) {
		printf("> ");
		getline(&input, &len, stdin);
		addhist(input);
	}
	return 0;
}
