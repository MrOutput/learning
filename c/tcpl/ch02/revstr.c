#include <stdio.h>
#include <string.h>

void reverse(char *s)
{
    int i = 0;
    int j = strlen(s) - 1;
    char temp;

    while (*s != '\0') {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++, s++, j--;
    }
}

int main(void)
{
    char *msg = "Rafael Leonidas Cepeda";
    reverse(msg);
    puts(msg);
    return 0;
}
