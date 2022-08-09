/* sumnum.c */
/* Reads user valued numbers and adds them */
/* Stops at a negative number */
/* Written by Josh Miller 9-16-99 */

#include <stdio.h>

void main(void)
{
        int number=0, sum;

        while(number >=0)
        {
           printf("\n \n Please type an integer value. \n");
           scanf("%d", &number);

           sum=sum+number;

           if(number>=0)
           {
            printf("The sum of all the imputed numbers is %d.", sum);
           }
           else
            printf("A negative value has been entered program will now terminate");
        }
}
