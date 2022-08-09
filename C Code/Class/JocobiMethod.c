/* jacobi.c */
/* Solves a system of equations using the Jacobi method. */
/* Created by Josh Miller on 12-2-99. */

#include <stdio.h>
#include <math.h>

void calc_solution(double coeff_array[6][6], double eqn_answer[], double solutions[], double error, FILE *outfile);

void main(void)
{
 FILE *infile, *outfile;
 char filename[50], outname[50];
 double error;
 double coeff_array[6][6];
 double eqn_answr[6];
 double solutions[6];
 int row=0, column=0, count;

 printf("\n \n \t \t Solving with Jacobi Method \n\n");
 printf("Please input the name of the file containing the coefficients of the equations. \n");
 gets(filename);

 printf("Please input the name of the file to output the results to.\n");
 gets(outname);

 printf("Please input the maximum amount of error. \n");
 scanf("%lf", &error);

 infile=fopen(filename,"r");
 outfile=fopen(outname,"w");

 if(infile==NULL||outfile==NULL)
  {
   printf("One of the files was invalid\n");
   exit();
  }

 for(row=0;row<6;row++)
 {
  for(column=0;column<6;column++)
  {
   fscanf(infile,"%lf", &coeff_array[row][column]);
  }
 }

 for(count=0;count<6;count++)
 {
  fscanf(infile,"%lf", &eqn_answr[count]);
 }

 calc_solution(coeff_array, eqn_answr, solutions, error, outfile);

 fclose(infile);
 fclose(outfile);

 printf("\nThank you the results have been stored in %s.\n\n", outname);
}

void calc_solution(double coeff_array[6][6], double eqn_answr[], double solutions[], double error, FILE *outfile)
{
 double current[6];
 double new_guess[6];
 int count, cnt, error_level;

 for(count=0;count<6;count++)
 {
  current[count]=eqn_answr[count]/coeff_array[count][count];
 }

 do
 {
  for(count=0;count<6;count++)
  {
   fprintf(outfile,"%lf  ", current[count]);
  }

  fprintf(outfile,"\n");
  error_level=0;

  for(count=0;count<6;count++)
  {
   new_guess[count]=eqn_answr[count];
   for(cnt=0;cnt<6;cnt++)
   {
    if(cnt!=count)
    {
     new_guess[count]-=(coeff_array[count][cnt]*current[cnt]);
    }
   }
   new_guess[count]=new_guess[count]/coeff_array[count][count];

   if(fabs(new_guess[count]-current[count])<error)
   {
    error_level++;
   }
  }

  for(count=0;count<6;count++)
  {
   current[count]=new_guess[count];
  }
 }
 while(error_level<6);
 
 for(count=0;count<6;count++)
 {
  fprintf(outfile,"%lf  ", current[count]);
 }
}
