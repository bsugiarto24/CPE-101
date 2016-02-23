#include <stdio.h>
#include <stdlib.h>

#define OUTFILE_NAME "detabbed"
#define TAB_STOP_SIZE 8
#define NUM_ARGS 2
#define FILE_ARG_IDX 1

void check_errors(int argc, char*argv[]){
   if (argc < 1)
   {
      fprintf(stderr, "usage: prog file\n"); 
      exit(1);
   }
   else if (argc < NUM_ARGS)
   {
      fprintf(stderr, "usage: %s file\n", argv[0]);
      exit(1);
   }
}

void check_file(char *filename, FILE *f){
   if (f == NULL)
   {
      perror(filename);
      exit(1);
   }
}

void detab(int argc, char *argv[]){
   FILE *infile, *outfile;
   char c;
   int character_count = 0;
   int i;
   int num_spaces;

   check_errors(argc,argv);

   infile = fopen(argv[1], "r");
   check_file(argv[1],infile);

   outfile = fopen(OUTFILE_NAME, "w");
   check_file(OUTFILE_NAME, outfile);

   while (fscanf(infile, "%c", &c) != EOF)
   {
      if (c == '\t')
      {
         num_spaces = TAB_STOP_SIZE - (character_count % TAB_STOP_SIZE);

         for (i = 0; i < num_spaces; i++)
         {
            fprintf(outfile, " ");
         }
         character_count = character_count + num_spaces;
      }
      else if (c == '\n')
      {
         fprintf(outfile, "\n");
         character_count = 0;
      }
      else
      {
         fprintf(outfile, "%c", c);
         character_count = character_count + 1;
      }
   }

   fclose(infile);
   fclose(outfile);

}


int main(int argc, char *argv[])
{
   detab(argc, argv);
   return 0;
}




