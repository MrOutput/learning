#include <stdio.h>
#include <dirent.h>
#include <string.h>

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
            printf("LINE: %s\n", linep);
        }

        fclose(imgdatap);
    }

    closedir(imgsp);

    return 0;
}
