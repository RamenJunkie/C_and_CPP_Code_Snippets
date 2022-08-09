/* Thisprogram will convert a temperature supplied by the user */
/* from degrees Celsius to degrees Fahrenheit */
/* It was created by Josh Miller on 8-26-99 */

#include <stdio.h>

void main(void)
{
     float celsius, fahrenheit;
     printf("Please enter the current temperature in degrees Celsius.\n");
     scanf("%f", &celsius);
     fahrenheit= ((9.0*celsius)/5.0)+32.0;
     printf("The Celsius temperature %f, is equal to the Fahrenheit temperature is: \n \t \t \t \t \t \t \t %f \n", celsius, fahrenheit);
}
