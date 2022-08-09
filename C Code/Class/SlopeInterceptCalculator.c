/* interplt.c -- Linear Interpolation */
/* Computes slope and intercept of a line given 2 points. */
/* It also computes the y coordinate of a point for an x coordinate. */
/* Created by Josh Miller 9-9-99 */

#include <stdio.h>

main()
{
	float x1,y1,x2,y2;
	float m,c;
	float x,y;

	print f("\n \t LINEAR INTERPOLATION");

	printf("\n Enter x and y coordinates of the first point.");
	scanf("%f %f", &x1, &y1);
	printf("\n Enter x and y coordinates of the second point.");
	scanf("%f %f", &x2, &y2);
	printf("\n Enter the x coordinate of the point to be interpolated.");
	scanf("%f", &x);

	m=(y2-y1)/(x2-x1);
	c=(y1*x2-y2*x1)/(x2-x1);
	y=m*x+c;

	printf("\n The slope of the line is %f.", m);
	printf("\n The intercept of the line is %f.", c);
	printf("\n The Y coordinate of the x coordinate %f is %f", x, y);

	printf("/n /n Produced by Josh Miller 1999 Chaosworks.");
}