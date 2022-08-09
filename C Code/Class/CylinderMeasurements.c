/* cylinder.c */
/* Program for finding the volume and surface area of a Cylinder. */
#include <stdio.h>
#define PI 3.14159265
void main(void);
void main(void)
{
	float radius, height, volume, surfacearea;
	printf("\n Cylinder.c");
	printf("\n Computes volume and surface area of a cylinder.");
	printf("\n Enter radius of cylinder:");
	scanf("%f", &radius);
	printf("\n Enter height of cylinder:");
	scanf("%f", &height);
	volume = PI * radius * radius * height;
	surfacearea = 2.0 * PI * radius * (radius + height);
	printf("\n Volume of cylinder is: %10.4f", volume);
	printf("\n Surface area of cylinder: %10.4f", surfacearea);
	printf("/n /n Produced by Josh Miller 1999 Chaosworks.");
}
