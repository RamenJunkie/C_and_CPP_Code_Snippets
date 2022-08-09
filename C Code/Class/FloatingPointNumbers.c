/* Float.c */
/* a program for choosing larger and small floating point numbers. */
/* Written by Josh Miller on 9-19-99 */

#include <stdio.h>

void main(void)
{
	float large, small, vary;
	int first=0;

	do
	{
	 printf("Please type a enter a number, a negative value will terminate the program. \n");
	 scanf("%f", &vary);
	
	 if(first==0)
	   {
	    first +=1;
	    large=small=vary;
	   }
	 else if(vary>large)
	    large=vary;
	 else if(vary<small)
	    small=vary;
	
	printf("The current lagest entered number is %f \n", large);
	printf("The current smallest entered number is %f \n", small);
	}
	while (vary>=0);
	printf("A negative value has been entered, terminating program. \n");
	printf("The lagest entered number was %f \n", large);
	printf("The smallest entered number was %f \n", small);
}


	