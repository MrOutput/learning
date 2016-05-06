#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

#define IMG_DIR "./images"

int main(int argc, char const* argv[])
{
    DIR *imgsp = opendir(IMG_DIR);
    struct dirent *imgp = NULL;

    // read files in images directory
    while ((imgp = readdir(imgsp)) != NULL) {
        printf("%s\n", imgp->d_name);

        /* open each file, and read the contents */
        // set filepath
        size_t fpathsize = strlen(IMG_DIR) + 1 + strlen(imgp->d_name) + 1;
        char fpath[fpathsize];
        snprintf(fpath, fpathsize, "%s/%s", IMG_DIR, imgp->d_name);

        // open and process data
        FILE *imgdatap = fopen(fpath, "r");

        char *linep = NULL;
        size_t lsize = 0;
        while (getline(&linep, &lsize, imgdatap) != EOF) {
            // tokenize and parse line
            char *tokenp = NULL;
            for (char *ln = linep; ; ln = NULL) {
                if ((tokenp = strtok(ln, " ")) == NULL) {
                    break;
                }
                // do something with token

                printf("%8d ", atoi(tokenp));
            }
        }

        fclose(imgdatap);
    }

    closedir(imgsp);

    return 0;
}
