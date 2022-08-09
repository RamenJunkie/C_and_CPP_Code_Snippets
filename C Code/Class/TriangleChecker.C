/* This program is for testing if 3 lines of */
/* lenghts a,b,and c will form a triangle. */
/* Written by Josh Miller on 9-9-99 */

#include <stdio.h>
#include <math.h>

void main(void)
{
        float sidea, sideb, sidec;

        printf("\n Please imput the lengths of sides a, b, and c. \n");
        printf("Be sure all three lines are of the same units. \n");
        scanf("%f %f %f", &sidea, &sideb, &sidec);

        if((fabs(sidea-sideb)<sidec)&&(sidec<sidea+sideb))
        printf("\n The lines a, b, and c, will form a triangle \n");
        else
        printf("\n The lines a, b, and c, will not for a triangle \n ");
}





