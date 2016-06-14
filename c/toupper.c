#include <unistd.h>
#define OFFSET 0x20

void to_upper(char str[], size_t len) {
    for (int i = 0; i < len; i++) {
        if (str[i] > 'a' && str[i] < 'z') {
            str[i] -= OFFSET;
        }
    }
}

int main()
{
    char message[] = "Hello, World!\n";
    to_upper(message, sizeof message);

    write(STDOUT_FILENO, message, sizeof message);

    return 0;
}
