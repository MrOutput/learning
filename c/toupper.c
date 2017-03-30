#include <unistd.h>

void to_upper(char *str) {
    for (; *str != '\0'; str++)
        if (*str > 'a' && *str < 'z')
            *str -= ' ';
}

int main()
{
    char message[] = "Hello, World!\n";
    to_upper(message);
    write(STDOUT_FILENO, message, sizeof message);
    return 0;
}
