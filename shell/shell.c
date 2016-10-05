#define STDOUT 1
#define STDIN 0
#define OFFSET 0x20

static void toupper(char *buf, int size) {
    register int i;

    for (i = 0; i < size; i++) {
        if (buf[i] >= 'a' && buf[i] <= 'z') {
            buf[i] -= OFFSET;
        }
    }
}

static int write(int fd, char *buf, int size) {
    register int bytes;

    asm(
    "syscall"

    : "=a" (bytes)
    : "D" (fd), "S" (buf), "d" (size), "a" (1)
    : "rcx", "r11", "memory", "cc"
    );

    return bytes;
}

static void print(char *buf, int size) {
    write(STDOUT, buf, size);
}

static int read(int fd, char *buf, int size) {
    register int bytes;

    asm(
    "syscall"

    : "=a" (bytes)
    : "D" (fd), "S" (buf), "d" (size), "a" (0)
    : "rcx", "r11", "memory", "cc"
    );

    return bytes;
}

static int readAndTransform(char *buf, int size) {
    register int bytes;

    bytes = read(STDIN, buf, size);
    toupper(buf, bytes);

    if (bytes > 1) {
        print(buf, bytes);
    }

    return (bytes != 0);
}

void myexit(int code) {
    asm(
    "syscall"
    :
    : "a" (60), "D" (0)
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
