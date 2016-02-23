#include <stdio.h>
#include <stdlib.h>

#define OUTFILE_NAME "hidden.ppm"

void check_errors(int argc, char*argv[]){
   if (argc < 1)
   {
      fprintf(stderr, "usage: prog file\n"); 
      exit(1);
   }
   else if (argc < 2)
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



void print_header(FILE *in, FILE *out){
   char i; 
   int num=0;
   
   fscanf(in, "%c", &i);
   fprintf(out,"%c",i);

   fscanf(in, "%d", &num); 
   fprintf(out,"%d\n",num);

   fscanf(in, "%d", &num); 
   fprintf(out,"%d",num);

   fscanf(in, "%d", &num); 
   fprintf(out," %d\n",num);

   fscanf(in, "%d", &num); 
   fprintf(out,"%d\n",num);
}

void decode(int argc, char *argv[]){
   FILE *infile, *outfile;


   check_errors(argc,argv);

   infile = fopen(argv[1], "r");
   check_file(argv[1],infile);

   outfile = fopen(OUTFILE_NAME, "w");
   check_file(OUTFILE_NAME, outfile);

   print_header(infile,outfile);  
 
   int r = 0;
   int g = 0;
   int b = 0;
   
   while (fscanf(infile,"%d%d%d", &r, &g, &b) != EOF)
   {
      r*=10; 
      if(r>255)
         r=255;
      g = r;
      b = r;
      fprintf(outfile,"%d\n%d\n%d\n", r, g, b);
   }

   fclose(infile);
   fclose(outfile);

}


int main(int argc, char *argv[])
{
   decode(argc, argv);
   return 0;
}




