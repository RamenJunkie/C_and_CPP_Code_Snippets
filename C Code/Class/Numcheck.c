/* Numcheck.c */
/* Takes a user defined munber of numbers and counts how many */
/* Positive numbers, negative numbers, and zeros are entered. */
/* Written by Josh Miller on 9-16-99 */

#include <stdio.h>

void main(void)
{
        float value;
        int numleft, minus=0, plus=0, zero=0;
        /* Value is the user entred value to be examined */
        /* Numleft is the number of times to preform the test */
        /* Minus, plus, and zero is th enumber of each that are entered */

        printf("Please type the number of valus you wish to test.\n");
        scanf("%d", &numleft);
        /* Defines teh number of tests to preform as entered by the user */

        printf("\n WARNING: Large values may cause errors in the results. \n");
        /* A warning the the user */

        while (numleft>0)
        {
                printf("Please type a numarical value.\n");
                scanf("%f", &value);
                /* Gets a value to test from the user. */

                if (value>0)
                   plus +=1;
                else if(value==0)
                   zero +=1;
                else if(value<0)
                   minus +=1;
                /* Preforms the test */

                numleft -=1;
        }
        printf("\n The final number of values are \n");
        printf("Positive numbers - %d \n", plus);
        printf("Zeros            - %d \n", zero);
        printf("Negative numbers - %d \n", minus);
	/* displays the results */
}

