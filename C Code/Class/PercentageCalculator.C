/* intpct.c */
/* Finds the percent of p(n) < n. */
/* Written by Josh Miller on 10-7-99 */

#include <stdio.h>
int p(int n);
float factorfind(int low, int high);

main()
{
 int lw, hgh;
 float pct;

 printf("\n \n Input the low value. \n");
 scanf("%d", &lw);

 printf("Input the high value. \n");
 scanf("%d", &hgh);

 pct=factorfind(lw,hgh);

 pct *=100;

 printf("The percentage of sums less than the number is %f. \n \n", pct);
}

float factorfind(int low, int high)
{
 float less;
 int high2=high, sum;

 for(;low=high;high--)
 {
  sum=p(high);
  if(sum<high)
   less++;
 }
 return (less/(high2-low));
}

int p(int n)
{
 int sum=0, num;

 for(num=1; num<n; num++)
  {
   if((n % num)==0)
    sum+=num;
  }

 return sum;
}

