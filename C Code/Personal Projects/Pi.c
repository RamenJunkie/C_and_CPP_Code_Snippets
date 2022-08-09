/* PI.c */
/* Computes PI to lots of decimals */
/* Written by Josh Miller 9-20-99 */

#include <stdio.h>
#include <math.h>

void main(void)
{
 double pie=0;
 float val=0;

 while(val>-1)
  {
  printf("The current value of PI is %1.25lf \n", pie);
  pie=pie+4*(pow(-1,val))*(1/(2*val+1));
  val++;
  }
}