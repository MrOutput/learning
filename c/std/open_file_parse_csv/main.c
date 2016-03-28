#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct data_size {
    unsigned int rows;
    unsigned int cols;
};

enum assignment_types {
    HOMEWORK, EXAM
};

typedef struct {
    float average;

    float *distribution;
} Statistics;

typedef struct {
    char *name;
    enum assignment_types type;

    float *grades;
    float weight;

    Statistics stats;
} Assignment;


void set_size(FILE *, struct data_size *);
void set_data(FILE *, Assignment *);

float calc_avg(unsigned int *, const unsigned int *);



int main(int argc, char const* argv[])
{
    if (argc == 1)
    {
        puts("specify csv file");
        return EXIT_FAILURE;
    }


    FILE *csv_file = fopen(*++argv, "r");

    if (!csv_file)
    {
        puts("error opening file");
        return EXIT_FAILURE;
    }


    
    struct data_size csv_size;

    set_size(csv_file, &csv_size);



    Assignment *assignments = NULL;

    assignments = (Assignment *) malloc(csv_size.cols * sizeof(Assignment));



    set_data(csv_file, assignments);




    free(assignments);
    fclose(csv_file);


    return EXIT_SUCCESS;
}



void set_size(FILE *f, struct data_size *s)
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

    s->rows -= (s->rows) ? 1 : 0; // subtract header row

    rewind(f);
}

void set_data(FILE *f, Assignment *a, unsigned int assignments_length)
{
    //while (there is an assignment)
    //    malloc size for assignment grades
    //    while (there is a line)
    //        if (first line);
    //            save field to name
    //            set assignment type
    //        else
    //            save field to grade
    //            increment grade pointer;
    //    rewind file
    //

    register unsigned int line_c, a_counter, i;

    assignment_counter = assignments_length;

    char *line = NULL;
    size_t size = 0;

    for (i = 0; i < assignments_length; i++)
    {
        a->grades = (float *) malloc(number of cols * sizeof(float));

        for (line_c = 0; getline(&line, &size, f) != EOF; line_c++)
            if (line_c == 0)
            {
                a->name = get_field(line, i + 1);
                a->type = 
    }
            


    register unsigned int line_c, field_c;

    char *line = NULL;
    size_t size = 0;

    char *field = NULL;

    for (line_c = 0; getline(&line, &size, f) != EOF; line_c++)
        if (line_c != 0)
            for (field_c = 0; (field = strtok((field_c == 0) ? line : NULL, ",")); field_c++)
                if (field_c != 0)
                    *a++ = atoi(field);

    rewind(f);
}

float calc_avg(unsigned int *d, const unsigned int *n)
{
    if (*n == 0)
        return 0.0;

    int sum = 0;
    int i;

    for (i = *n; i--; sum += *d++)
        ;

    return sum / (float) *n;
}
