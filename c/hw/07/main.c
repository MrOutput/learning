/* Name: Rafael Cepeda
 * Date: 2016-03-24
 * Desc: Read from data from file
 */


#include <stdio.h>
#include <stdlib.h>
#include "class_stats.h"

int main(const int argc, char *argv[])
{


   if (argc < 2)
   {
      fprintf(stderr, "Please input a csv file name\n");
      exit(1);
   }
   
   
   // file pointer
   FILE *fin;
   printf("the input file name is %s\n",  argv[1]);

   // open file in read mode
   fin = fopen(argv[1], "r");
   if(fin == NULL) 
   {
      perror("Error in opening input file\n");
      return(-1);
   }
   
   
   
   int num_students, num_assignments, i, j,  total_count;
   
   // get size of data
   get_data_size(fin, &num_students, &num_assignments);




   // allocate memory
   int **grades = (int **)malloc(num_assignments * sizeof(int *));
   for (i = 0; i < num_assignments; i++)
   {
      grades[i] = (int *)malloc(num_students * sizeof(int));
      if (grades[i] == NULL)
      {
         fprintf(stderr, "Not enough memory to allocate\n");
         exit(1);
      }
   }
   
   int **grades_scale = (int **)malloc(num_assignments * sizeof(int *));
   for (i = 0; i  < num_assignments; i++)
   {
      grades_scale[i] = (int *) malloc(11 * sizeof(int));
      if (grades_scale[i] == NULL)
      {
         fprintf(stderr, "Not enough memory to allocate\n");
         exit(1);
      }
   }

   
   Statistics stats[num_assignments];


   // intialize arrays
   for (i = 0; i < num_assignments; i++)
      for (j = 0; j < num_students; j++)
         grades[i][j] = 0;
   
   
   for (i = 0; i < num_assignments; i++)
      for (j = 0; j < 11; j++)
         grades_scale[num_assignments][11] = 0;
   
   
   
   // get grades
   get_data(fin, num_students, num_assignments, grades);
   
   
   // bin grades
   total_count = bin_grades(num_students , num_assignments, grades, grades_scale);

   if (total_count == -1)
   {
      printf("Error\n");

      return -1;
   }

   // get stats
   get_stats(num_students, num_assignments, grades, stats);

   // display resutls
   display_grades_distribution(num_assignments, grades_scale, stats);

   return 0;
}
