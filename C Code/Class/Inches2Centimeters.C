/* In2cm.c */
/*  A program for converting Inches to Centimeters */
/* Written by Josh Miller on 9-2-99 */

#include <stdio.h>

void main(void)
{
        float inches, centimeters, meters;

        printf("\n Please type the number of inches. \n");
        printf("Inches = ");
        scanf("%f", &inches);

        centimeters=2.54*inches;
        meters=centimeters/100;

        printf("\n %8.4f inches is approximately equal to %8.4f centimeters and %8.4f meters. \n \n \n", inches, centimeters, meters);
}





