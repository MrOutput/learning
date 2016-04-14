#include <unistd.h>

#define STDOUT 1

int main(int argc, char const* argv[])
{
    char digit[2] = "0\n";

    for (int i = 10; i--;) {
        digit[0] = '0' + i;
        write(STDOUT, &digit, sizeof digit);
    }

    return 0;
}
