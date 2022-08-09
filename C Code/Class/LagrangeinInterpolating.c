/* regress.c */
/* This progra will create a regression line to fit any set of (X,Y) coordinates. */
/* Created by Josh Miller on 11-16-99. */

#include<stdio.h>

double lagrange_value(double xvals[], double yvals[], double eval_point, int n);

void main(void)
{
 int num_points, count, new_points, flag=1, cnt;
 double x_coord[50], y_coord[50], points[50], eval[50];

printf("\n\t\t Lagrangeian Interpolating Polynomial Program\n\n");

 do
 {
  printf("\nPlease input the number of Data points to fit the curve to.\n");
  scanf("%d", &num_points);

  if(num_points>50)
  {
   printf("Number of Data points must be less than 50.\n");
   flag=1;
  }
  else
  {
   flag=0;
  }  

 } 
 while(flag==1);

 for(count=0;count<num_points;count++)
 {
  printf("Please input the coordinates for point number %d.\n", count+1);
  printf("X:");
  scanf("%lf", &x_coord[count]);
  printf("\nY:");
  scanf("%lf", &y_coord[count]);
 }

 do
 {
  printf("\n\nPlease type the number of points to find the value of on the calculated curve.\n");
  scanf("%d", &new_points);

  if(new_points>50)
  {
   printf("Number of poitns must be less than 50.\n");
   flag=1;
  }
  else
  {
   flag=0;
  }
 }
 while(flag==1);

 for(count=0;count<new_points;count++)
 {
  printf("Enter the X coordinate of point %d.\n", count+1);
  scanf("%lf", &points[count]);
 
  eval[count]=lagrange_value(x_coord, y_coord, points[count], num_points);
 }

 printf("\n\nThe values for function at the inputed points are:\n");

 for(count=0;count<new_points;count+=5)
 {
  if(new_points-count>5)
  {
   printf("\nX-\t %l.4f \t %l.4f \t %l.4f \t %l.4f \t %l.4f"
    ,points[count],points[count+1],points[count+2],points[count+3],points[count+4]);
   printf("Y-\t %l.4f \t %l.4f \t %l.4f \t %l.4f \t %l.4f \n"
    ,eval[count],eval[count+1],eval[count+2],eval[count+3],eval[count+4]);
  }
  else
  {
   printf("\nX- \t ");

   for(cnt=count;cnt<new_points;cnt++)
   {
    printf("%lf \t",points[cnt]);
   }
   printf("\nY- \t ");
   
   for(cnt=count;cnt<new_points;cnt++)
   {
    printf("%lf \t",eval[cnt]);
   }
   count=51;
  }
 }
}

double lagrange_value(double xvals[], double yvals[], double eval_point, int n)
{
 int count, cnt;
 double total=0, LsubI=1;

 for(count=0;count<n;count++)
 {
  for(cnt=0;cnt<n;cnt++)
  {
   if(cnt!=count)
   {
    LsubI=LsubI*((eval_point-xvals[cnt])/(xvals[count]-xvals[cnt]));
   }
  }
  total+=LsubI*yvals[count];
  LsubI=1;
 }
 return total;
}





