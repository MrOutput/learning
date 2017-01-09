#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int bufi;
struct buf {
	int len;
	char *val;
};
struct buf inbuf;

void chgbuf(struct buf *b, int len)
{
	b->len = len;
	b->val = realloc(b->val, len);
}

void bufc(char c)
{
	if (bufi == inbuf.len-1)
		chgbuf(&inbuf, inbuf.len*2);
	inbuf.val[bufi] = toupper(c);
	inbuf.val[++bufi] = '\0';
}

void bufrst(void)
{
	int init = 16;
	if (inbuf.len != init)
		chgbuf(&inbuf, init);
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
				puts(inbuf.val);
			goto prompt;
		}
		bufc(c);
	}

	printf("\n");
	return 0;
}
