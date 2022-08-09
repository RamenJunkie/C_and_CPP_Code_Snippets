/* circle.c   Area and Circumference of a circle */
/* Computes the area and circumferance of a circle */
/* Produced by Josh Miller on 9-9-99 */

#include <stdio.h>
#define PI 3.141592654

main()
{
	float radius, area, circum;

	printf("\n \t AREA AND CIRCUMFERENCE OF A CIRCLE");

	printf("\n \n Input the radius of the circle: ");
	scanf("%f", &radius);

	area=PI*radius*radius;
	circum=2*PI*radius;

	printf("\n \n The area is equal to %f.", area);
	printf("\n The circumference is equal to %f", circum);

	printf("\n \n Produced by Josh Miller 1999 Chaosworks.");
}