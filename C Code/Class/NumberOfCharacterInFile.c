/***************************************************************/
/*  numchars.c  -- Number of Charachters in a File	       */
/*  This program determins the number of charachters in a file.*/
/*  It reads the file one character at a time until the end of */
/*  file (EOF) charachter is reached.			       */
/***************************************************************/
#include <stdio.h>
void main(void);

void main(void)
{
   char filename[81], ch;
   int count=0;
   FILE *file_ptr;

   printf("\n Number of charachters in a file");
   printf("\n Enter filename: ");
   gets(filename);

   file_ptr = fopen(filename,"r");
   if (  (file_ptr = fopen(filename,"r") ) == NULL )
      {
      printf("\n Could not open file ");
      exit(1);
      }
   while ( (ch = fget(file_ptr) )  != EOF)
      ++count;
   printf("\n Number of characters in file = %d", count);
}