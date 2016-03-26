#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct csv_size {
    unsigned int rows;
    unsigned int cols;
};

void set_size(FILE *, struct csv_size *);
void set_data(FILE *, int *);



int main(int argc, char const* argv[])
{
    FILE *csv_file = fopen("./grades.csv", "r");
    
    struct csv_size csv_size;

    set_size(csv_file, &csv_size);
    const unsigned int DATA_SIZE = (csv_size.rows > 0) ? csv_size.rows * csv_size.cols - 1 : 0;

    printf("rows %d, cols %d, total data size %d\n", csv_size.rows, csv_size.cols, DATA_SIZE);


    int dist[DATA_SIZE];
    set_data(csv_file, dist);

    int i;
    for (i = 0; i < DATA_SIZE; i++)
        printf("%d ", dist[i]);
    printf("\n");


    fclose(csv_file);
    return 0;
}

void set_size(FILE *f, struct csv_size *s)
{
    int c;
    register int col_flag = 0;

    s->rows = 0;
    s->cols = 0;

    while ((c = fgetc(f)) != EOF)
        if (c == '\n')
            col_flag = 1, s->rows++;
        else if (col_flag == 0 && c == ',')
            s->cols++;

    s->rows -= 1; // subtract header row

    rewind(f);
}

void set_data(FILE *f, int *d)
{
    register unsigned int line_c, field_c;

    char *line = NULL;
    size_t size = 0;

    char *field = NULL;

    for (line_c = 0; getline(&line, &size, f) != EOF; line_c++)
        if (line_c != 0)
            for (field_c = 0; (field = strtok((field_c == 0) ? line : NULL, ",")); field_c++)
                if (field_c != 0)
                    *d++ = atoi(field);

    rewind(f);
}
