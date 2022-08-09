/* Thisprogram will convert a temperature supplied by the user */
/* from degrees Fahrenheit to degrees Celsius */
/* It was created by Josh Miller on 8-26-99 */

#include <stdio.h>

void main(void)
{
     float celsius, fahrenheit;
     printf("Please enter the current temperature in degrees Fahrenheit.\n");
     scanf("%f", &fahrenheit);
     celsius= ((fahrenheit-32)*5.0)/9.0;
     printf("The Fahrenheit temperature %f, is equal to the Celsius temperature is: \n \t \t \t \t \t \t \t %f \n", fahrenheit, celsius);
}
