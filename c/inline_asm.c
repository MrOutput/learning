void close(char code) {
    asm("movq $60, %%rax;"
        "movq %0, %%rdi;"
        "syscall;"
        : :"m"(code)
        );
}

int str_len(char *s) {
    int c = 0;
    for (; *s != '\0'; c++, s++)
        ;
    return c;
}

void print(char *s, int len) {
    asm("movq $1, %%rax;"
        "movq $1, %%rdi;"
        "movq %0, %%rsi;"
        "movq %1, %%rdx;"
        "syscall;"
        : :"m"(s), "m"(len)
        );
}

int _start() {
    char msg[] = "rafael leonidas cepeda";
    int len = str_len(msg);
    print(msg, len);

    close(len);
}
