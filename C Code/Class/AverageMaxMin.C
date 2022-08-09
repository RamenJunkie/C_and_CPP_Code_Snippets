/* observe.c */
/* Computes the average, maximum, and minimum of a set of numbers. */
/* Written by Josh Miller on 10-28-99. */

#include <stdio.h>

void average(double x[], int n, double *ptr_mean, double *ptr_min, double *ptr_max);

void main(void)
{
 double mean, min, max;
 double x[25];
 int n, count;

 printf("\nHow many observations are there? \n");
 scanf("%d", &n);

 printf("Now enter the observations:\n");

 for(count=1; count<=n; count++)
 {
  printf("What is observation %d? \n", count);
  scanf("%lf", &x[count-1]);
 }

 average(x, n, &mean, &min, &max);

 printf("The average value for that set of data is: %lf \n", mean);
 printf("The maximum value in the data set is: %lf \n", max);
 printf("The minimum value in the data set is: %lf \n", min);
}

void average(double x[], int n, double *ptr_mean, double *ptr_min, double *ptr_max)
{
 int count;
 double xsum=x[0];

 *ptr_min=x[0];
 *ptr_max=x[0];

 for(count=1; count<n; count++)
 {
  xsum+=x[count];

  if(x[count]<*ptr_min)
   {
    *ptr_min=x[count];
   }

  if(x[count]>*ptr_max)
  {
   *ptr_max=x[count];
  }
 }

 *ptr_mean=(xsum/n);
}
