/* program2.c */
/* Finds a root using the secant method. */
/* Created by Josh Miller on 10-14-99 */

#include <stdio.h>
#include <math.h>
double f(double x);
double next_guess(double last_guess, double sec_guess);

void main(void)
{
 double guessNew, guessMid, guessOld, error;
 int iterations, count=0;

 printf("\n\n\t\t\t Program2 \n\n");

 printf("Please an initial guess.\n");
 scanf("%lf", &guessMid);

 printf("Please give a second initial guess. \n");
 scanf("%lf", &guessOld);

 printf("Please input the maximum number of times to preform the test.\n");
 scanf("%d", &iterations);

 printf("Please input the maxumin allowed error. \n");
 scanf("%lf", &error);
 guessNew=guessMid;
 do
 {
  guessMid=guessNew;
  guessNew=next_guess(guessMid,guessOld);
  printf("X(n+1)= %lf, X= %lf, X(N-1)= %lf \n",guessNew, guessMid, guessOld);
  guessOld=guessMid;
  count++;
 }
 while((count<iterations)&&((fabs(guessNew-guessMid))>error));
 printf("\n There is a root at %lf.\n",guessNew);
 printf(" It took %d tries to come up with this value. \n", count);
}

double f(double x)
{
 return ((pow(x,3))-3*(pow(x,2))+x*log(x)+1);
}

double next_guess(double last_guess, double sec2last)
{
 return ((sec2last*(f(last_guess))-last_guess*(f(sec2last)))/(f(last_guess)-f(sec2last)));
}


