/***************************************************************/
/*  copy1.c  -- Copies a File				       */
/*  This program copies a file.  It reads the contents of the  */
/*  file one charachter at a time and writes it to a new file. */
/***************************************************************/
#include <stdio.h>

void main(void)
{
   int ch;
   char infile_name[81],outfile_name[81];
   FILE *infile_ptr, *outfile_ptr;

   printf("\n Input filename? ");
   scanf("%s", infile_name);

   printf("\n Output filename? ");
   scanf("%s", outfile_name);

   infile_ptr = fopen(infile_name,"r");
   if ( infile_ptr == NULL)
      {
      printf("\n Cannot open input file");
      exit(1);
      }

   outfile_ptr = fopen(outfile_name,"r");
   if ( outfile_ptr == NULL)
      {
      printf("\n Cannot open output file");
      exit(1);
      }

   while ( (ch = fgetc(infile_ptr)) != EOF)
      fputc(ch,outfile_ptr);

   fclose(infile_ptr);
   fclose(outfile_ptr);
   printf("\n File copied successfully !");
}