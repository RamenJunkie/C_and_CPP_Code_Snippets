/* e2theX.c */
/* E program for calculating e^x using a Taylor series */
/* Written by Josh Miller on 9-23-99 */

#include <stdio.h>
#include <math.h>

void main(void)
{
 float X, N, e2x, nth_term;
 char again, garbage;
 int repeat;

do
{
 printf("\n Please input the value of X for the function \n");
 scanf("%f", &X);

 N=1;
 e2x=1;
 nth_term=1;
 do
 {
 nth_term*=(X/N);
 e2x+=nth_term;
 N++;
 }
 while ((fabs(nth_term))>.000001);

 printf("\n The values of e to the %f power is equal to: %f \n", X, e2x);

 printf("Would you like to do a second calculation? <y,n> \n");
 scanf("%c %c", &garbage, &again);

 switch(again)
  {
        case 'y':
              repeat=1;
              break;
        case 'Y':
              repeat=1;
              break;
        case 'n':
              repeat=0;
              break;
        case 'N':
              repeat=0;
              break;
        default:
              repeat=0;
  }
}
while(repeat>0);

printf("\n End of program \n");
}

/* The estimated value of e^.1 is 1.105171 */
/* The estimated value of e^1 is 2.718282 */
/* The estimated value of e^5 is 148.413177 */

