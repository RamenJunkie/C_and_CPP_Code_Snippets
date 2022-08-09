/* Game.c */
/* Woring prototype of Dragon Slayer Alpha. */
/* Designed, written, and programed by Josh Miller. */
/* Produced by Chaosworks, a division of Millersoft. */
/* Work began on 10-22-99. */
/* Work done on 10-22-99: Began work on movement system. */
/* Work done on 10-23-99: Completed the movement system. */
/*						  Begam work on location descriptions. */
/*						  Began work on direction descriptions. */
/*						  Completed East directional descriptions. */
/* Work done on 11-04-99: Moved Location descriptions to a seperate function */

#include <stdio.h>

int location(int posit);
void position_description(int posit);

void main(void)
{
 int posit=121;

 do
 {
 position_description(posit);
 posit=location(posit);
 }
 while(1==1);
}

/* The Following Function is used to compute the new position of the player.*/
/* It takes into account invalid directions. */
int location(int posit)
{
 int flag, newposit, check;
 char dir, garbage;
 int voide[53]={1,2,3,4,5,6,7,8,9,10,13,16,20,21,23,27,28,30,37,40,42,43,47,49,50,51,60,70,73,74,80,84,90,100,101,102,110,113,120,130,133,139,140,141,142,143,144,145,146,147,148,149,150};


 printf("\n\nWhich direction would you like to go? \n");

 do
 {
  scanf("%c %c", &garbage, &dir);
  flag=0;
  switch(dir)
  {
   case'N':
    newposit=posit-10;
    break;
   case'n':
    newposit=posit-10;
    break;
   case'S':
    newposit=posit+10;
    break;
   case's':
    newposit=posit+10;
    break;
   case'E':
    newposit=posit+1;
    break;
   case'e':
    newposit=posit+1;
    break;
   case'W':
    newposit=posit-1;
    break;
   case'w':
    newposit=posit-1;
    break;
   default:
    newposit=1;
    break;
  }
   
    for(check=0;check<53;check++)
	{
	 if(newposit==voide[check])
	 {
      printf("Invalid Direction, please choose again. \n");
      flag=1;
	 }
    }
 }
 while(flag==1);

 return newposit;
}

void position_description(int posit)
{
 int check;
 int path[9]={98,99,106,107,108,115,116,124,125};
 int forest[21]={14,15,24,25,26,35,36,44,45,46,55,56,57,59,66,67,68,69,78,79,89};
 int field[43]={52,53,54,61,62,63,64,65,71,72,75,76,77,81,82,83,85,86,87,88,91,92,93,94,95,96,97,103,104,105,109,114,117,118,119,126,127,128,134,135,136,127};
 

 printf("\n---------------------------------");
 printf("\n Your current position is %d. \n", posit);
  
 for(check=0;check<9;check++)
 {
  if(posit==path[check])
  {
   printf("\nYou are traveling on a dirt road. \n \n");
  }
 }
 for(check=0;check<21;check++)
 {
  if(posit==forest[check])
  {
   printf("\nYou are standing in a forest. \n \n");
  }
 }
  for(check=0;check<43;check++)
 {
  if(posit==field[check])
  {
   printf("\nYou are standing in an open field. \n \n");
  }
 }

 if((posit==15)||(posit==26)||(posit==36)||(posit==46))
  printf("There is a castle wall to the East. \n");

 if((posit==72)||(posit==84)||(posit==137)||(posit==128))
  printf("There is a pond to the East. \n");
 
 if((posit==114)||(posit==105)||(posit==97)) 
  printf("There is a road to the East. \n");

 if((posit==54)||(posit==65)||(posit==77)||(posit==88))
  printf("There is a forest to the East. \n");

 if((posit==59)||(posit==69)||(posit==79)||(posit==89)||(posit==109)||(posit==119)||(posit==129))
  printf("There are steep mountains blocking the way to the East.\n");

 if(posit==109)
  printf("The path through the mountains has been blocked by a landslide.\n");
 
 if(posit==57)
  printf("The castle entrance is to the East. \n");

 if((posit==26)||(posit==57)||(posit==59))
  printf("There is a castle wall to the North. \n");
}




