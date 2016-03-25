#ifndef CLASS_STATS
#define CLASS_STATS

// structure that holds the statistics for an assignment
typedef struct
{
   int min , max, data_size;
   float mean , median , std_dev ;
} Statistics ;


// sorts the values of an array in ascending order
void sort_a (int *data , int size) ;

// calculates the mean of the elements of an array
float calculate_mean (const int *data, int size);

// calculates the variance of the emelemts of an array
float calculate_variance (const int *data , int size);

// calculates the median of the elemets of an array
float calculate_median (const int *data , int size );

// finds the maximum value of the elements of an array
int calculate_max ( const int *data , int size);

// finds the minimum value of the elements of an array
int calculate_min ( const int *data , int size);

// gets the size of the data from file. 
void get_data_size(FILE *fp, int *students, int *assignments);

// gets the data from a file. 
void get_data ( FILE *fp, const int students, const int assignments, int **grades);

// bin the grades
int bin_grades (int students,  int assignments, int **grades, int **grades_scale) ;

// get stats
void get_stats (int students , int assignments, int **grades, Statistics *stats );

// print the grades
void display_grades_distribution (int assignments , int **grades_scale , Statistics *stats );

#endif
