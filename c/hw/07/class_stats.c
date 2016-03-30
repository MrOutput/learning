#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// structure that holds the statistics for an assignment
typedef struct
{
   int min, max, data_size;
   float mean, median, std_dev;
} Statistics ;

// sorts the values of an array in ascending order
void sort_a (int a[], int n)
{
   int i, j, temp;

   for (i = 0; i < n - 1; ++i)
      for (j = i + 1; j < n; ++j)
         if (a[i] > a[j]) 
         {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
         }
}

// calculates the mean of the elements of an array
float calculate_mean(const int *grades, int n)
{
   int i;
   float sum = 0.0;

   for (i = 0; i < n; i++)
      sum += grades[i];
   
   sum /= n;

   return sum;
}

// calculates the variance of the emelemts of an array
float calculate_variance(const int *grades, int n)
{
   int i;
   float sum = 0.0;
   float mean = calculate_mean(grades, n);


   for (i = 0; i < n; i++)
      sum += grades[i] * grades[i];
   
   sum = sum/n - mean*mean;

   return sum;
}

// calculates the median of the elemets of an arry
float calculate_median(const int *grades, int n)
{
   int i;
   int temp_array[n]; // temp array tp be manipulated
   float median;

   // copy oroginal array to the temp array 
   for (i = 0; i < n; i++)
      temp_array[i] = grades[i];

   sort_a(temp_array, n);

   if (n % 2 == 0)
      median = (temp_array[n/2] + temp_array[n/2-1])/2.0;
   else
      median = temp_array[n/2];

   return median;
}

// finds the maximum value of the elements of an array
int calculate_max(const int *grades, int n)
{
   int max = 0, i;
   for (i = 0; i < n; i++)   
      if (grades[i] >= max)
         max = grades[i];

   return max;

}


// finds the minimum value of the elements of an array
int calculate_min(const int *grades, int n)
{
   int min = 100, i;

   for (i = 0; i < n; i++)
      if (grades[i] <= min)
         min = grades[i];
   
   return min;
}

void display_grades_distribution(int m, const int grades_scale[11][m], Statistics stats[])
{

   int i;

   printf("\n");
   printf("\n");
   printf("%-25s", "Assignment #:");
   for (i = 0; i < m; i++)
      printf("%-10i", i+1);
   
   printf("\n");
   for (i = 0; i < 25; i++)
      printf("=");
   for (i = 0; i < 10*m; i++)
      printf("=");
   printf("\n");
   printf("\n");
   printf("%-25s", "Mean:");
   for (i = 0; i < m; i++)
      printf("%-10.2f", stats[i].mean);
   printf("\n");

   printf("%-25s", "Median :");
   for (i = 0; i < m; i++)
      printf("%-10.2f", stats[i].median);
   printf("\n");

   printf("%-25s", "Standard Deviation:");
   for (i = 0; i < m; i++)
      printf("%-10.2f", stats[i].std_dev);
   printf("\n");

   printf("%-25s", "Min:");
   for (i = 0; i < m; i++)
      printf("%-10d", stats[i].min);
   printf("\n");

   printf("%-25s", "Max:");
   for (i = 0; i < m; i++)
      printf("%-10d", stats[i].max);
   printf("\n");

   //printf("%-25s", "# of Students:");
   //for (i = 0; i < m; i++)
   //   printf("%-10d", stats[i].num_of_students);
   //printf("\n");

   for (i = 0; i < 25; i++)
      printf("=");
   for (i = 0; i < 10*m; i++)
      printf("=");
   printf("\n");
   printf("%-15s%-10s", "Scale", "Grade");
   for (i = 0; i < m; i++)
      printf("%-10s", "Count");
   printf("\n");
   for (i = 0; i < 25; i++)
      printf("=");
   for (i = 0; i < 10*m; i++)
      printf("=");
   printf("\n");
   printf("%-15s%-10s", ">= 93", "A");
   for (i = 0; i < m; i++)
      printf("%-10d", grades_scale[0][i]);
   printf("\n");

   printf("%-15s%-10s", "92 - 90", "A-");
   for (i = 0; i < m; i++)
      printf("%-10d", grades_scale[1][i]);
   printf("\n");

   printf("%-15s%-10s", "89 - 87", "B+");
   for (i = 0; i < m; i++)
      printf("%-10d", grades_scale[2][i]);
   printf("\n");
   
   printf("%-15s%-10s", "86 - 83", "B");
   for (i = 0; i < m; i++)
      printf("%-10d", grades_scale[3][i]);
   printf("\n");

   printf("%-15s%-10s", "82 - 80", "B-");
   for (i = 0; i < m; i++)
      printf("%-10d", grades_scale[4][i]);
   printf("\n");

   printf("%-15s%-10s", "79 - 77", "C+");
   for (i = 0; i < m; i++)
      printf("%-10d", grades_scale[5][i]);
   printf("\n");

   printf("%-15s%-10s", "76 - 73", "C");
   for (i = 0; i < m; i++)
      printf("%-10d", grades_scale[6][i]);
   printf("\n");

   printf("%-15s%-10s", "72 - 70", "C-");
   for (i = 0; i < m; i++)
      printf("%-10d", grades_scale[7][i]);
   printf("\n");

   printf("%-15s%-10s", "69 - 67", "D+");
   for (i = 0; i < m; i++)
      printf("%-10d", grades_scale[8][i]);
   printf("\n");

   printf("%-15s%-10s", "66 - 63", "D");
   for (i = 0; i < m; i++)
      printf("%-10d", grades_scale[9][i]);
   printf("\n");

   printf("%-15s%-10s", "< 63", "F");
   for (i = 0; i < m; i++)
      printf("%-10d", grades_scale[10][i]);
   printf("\n");

}


void get_data_size(FILE *f, int *s, int *a)
{
    int c;
    int col_flag = 0;

    *s = 0;
    *a = 0;

    while ((c = fgetc(f)) != EOF)
        if (c == '\n')
            col_flag = 1, ++*s;
        else if (col_flag == 0 && c == ',')
            ++*a;

    *s -= (*s > 0); // subtract header row if length

    rewind(f);
}


void get_data(FILE *f, const int s, const int a, int **grades) {
    char *line = NULL;
    char *field = NULL;

    size_t line_size = 0;


    int assignment_count;
    int line_count;
    int field_count;

    for (assignment_count = 0; assignment_count < a; assignment_count++)
    {
        for (line_count = 0; getline(&line, &line_size, f) != EOF; line_count++)
        {
            if (line_count != 0)
                for (field_count = 0; (field = strtok((field_count == 0) ? line : NULL, ",")); field_count++)
                {
                    if (field_count == assignment_count + 1)
                    {
                        **grades = atoi(field);
                        (*grades)++;
                        break;
                    }

                    (*grades)++;
                }
        }

        grades++;
        rewind(f);
    }

    rewind(f);
}


int bin_grades(int students, int assignments, int *grades[], int *grades_scale[]) {
    int i = 0, j = 0;

    int total_count = 0;

    for (j = 0; j < assignments; j++)
    {
        for (i = 0; i < students; i++)
        {
            if (grades[j][i] >= 93)
            {
                grades_scale[j][0]++;
                total_count++;
            }
            else if (grades[j][i]<= 92 && grades[j][i] >= 90)
            {
                grades_scale[j][1]++;
                total_count++;
            }
            else if (grades[j][i] <= 89 && grades[j][i] >= 87)
            {
                grades_scale[j][2]++;
                total_count++;
            }
            else if (grades[j][i] <= 86 && grades[j][i] >= 83)
            {
                grades_scale[j][3]++;
                total_count++;
            }
            else if (grades[j][i] <= 82 && grades[j][i] >= 80)
            {
                grades_scale[j][4]++;
                total_count++;
            }
            else if (grades[j][i] <= 79 && grades[j][i] >= 77)
            {
                grades_scale[j][5]++;
                total_count++;
            }
            else if (grades[j][i] <= 76 && grades[j][i] >= 73)
            {
                grades_scale[j][6]++;
                total_count++;
            }
            else if (grades[j][i] <= 72 && grades[j][i] >= 70)
            {
                grades_scale[j][7]++;
                total_count++;
            }
            else if (grades[j][i]<= 69 && grades[j][i] >= 67)
            {
                grades_scale[j][8]++;
                total_count++;
            }
            else if (grades[j][i] <= 66 && grades[j][i] >= 63)
            {
                grades_scale[j][9]++;
                total_count++;
            }
            else
            {
                grades_scale[j][10]++;
                total_count++;
            }
        }
    }

     if (total_count != students)
     {
        printf("You missied something\n");
        return -1;
     }

     return total_count;
}

// get stats
void get_stats(int num_students, int assignments, int **grades, Statistics *stats)
{
	int j;

    for(j = 0; j < assignments; j++)
    {
        stats[j].mean = calculate_mean(*grades, num_students);
        stats[j].std_dev = sqrtf(calculate_variance(*grades, num_students));
        stats[j].median = calculate_median(*grades, num_students);
        stats[j].min = calculate_min(*grades,num_students);    
        stats[j].max = calculate_max(*grades, num_students);
        stats[j].data_size = num_students * assignments;
    }
}
