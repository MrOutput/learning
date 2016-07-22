#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("specify file\n");
        return 1;
    }

    char *f_path = argv[1];
    FILE *f_in = fopen(f_path, "r");
    if (f_in == NULL) {
        printf("error opening file\n");
        return 1;
    }

    char msg[] = "FILE CONTENTS:\n"
                 "===================================\n";
    printf(msg);

    char *line = NULL;
    size_t size = 0;
    while (getline(&line, &size, f_in) != EOF) {
        printf("%s", line);
    }

    free((void *) line);
    fclose(f_in);
    return 0;
}
