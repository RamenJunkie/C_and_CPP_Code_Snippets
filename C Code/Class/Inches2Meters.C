/* In2m.c */
/*  A program for converting Inches to Meters and Centimeters */
/* Written by Josh Miller on 9-2-99 */

#include <stdio.h>

void main(void)
{
        float inches, centimeters;
        int meters;

        printf("\n Please type the number of inches. \n");
        printf("Inches = ");
        scanf("%f", &inches);

        meters=inches*.0254;
        centimeters=2.54*inches;
        centimeters=centimeters-(meters*100);

        printf("\n %8.4f inches is approximately equal to %i meters and %8.4f centimeters. \n", inches, meters, centimeters);
}





