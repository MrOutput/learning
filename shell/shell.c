#include <unistd.h>
#define STDOUT 1
#define STDIN 0
#define OFFSET 0x20

static void print(char *buf, int size) {
    write(STDOUT, buf, size);
}

static void toupper(char *buf, int size) {
    register int i;

    for (i = 0; i < size; i++) {
        if (buf[i] >= 'a' && buf[i] <= 'z') {
            buf[i] -= OFFSET;
        }
    }
}

static int myread(int fd, char *buf, int size) {
    register int bytes;

    asm(
    "movq $0, %%rax\n"

    "movl %1, %%edi\n"
    "movq %2, %%rsi\n"
    "movl %3, %%edx\n"
    "syscall\n"

    "movq %%rax, %0"

    : "=r" (bytes)
    : "m" (fd), "m" (buf), "m" (size)
    : "%rax", "%rdi", "%rsi", "%rdx"
    );

    return bytes;
}

static int readAndTransform(char *buf, int size) {
    register int bytes;

    bytes = myread(STDIN, buf, size);
    toupper(buf, bytes);

    if (bytes > 1) {
        print(buf, bytes);
    }

    return (bytes != 0);
}

void myexit(int code) {
    asm(
    "movq $60, %%rax\n"
    "movq %0, %%rdi\n"
    "syscall"
    :
    : "m" (code)
    : "%rax", "%rdi"
    );
}

void _start() {
    char buf[100];
    register int size = sizeof buf;
    char prompt[] = "> ";

    do {
        print(prompt, sizeof prompt);
    } while (readAndTransform(buf, size));

    print("\n", 1);

    myexit(0);
}
