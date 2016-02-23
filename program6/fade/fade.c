#include <stdio.h>
#include <stdlib.h>
#include "fade.h"
#include "math.h"
#define OUTFILE_NAME "faded.ppm"

struct point create_point(int x, int y){
   struct point p;
   p.row = x;
   p.col = y;
   return p;
}

double distance(struct point p1, struct point p2){
   double x1 = (p1.row-p2.row)*(p1.row-p2.row);
   double y1 = (p1.col-p2.col)*(p1.col-p2.col);
   return sqrt(x1+y1);
}

double convert_int(char const input[], int default_value){
   int d = 0;
   int x = sscanf(input,"%d", &d);
   
   if (x==0){
      fprintf(stderr,"can't scan");
      exit(1);
   }else
      return d;
} 

double radius(char*argv[]){
   return convert_int(argv[4],0);
}

double scale(struct point c, struct point p, char*argv[]){
   double x = ((double)radius(argv) - distance(c,p)) / (double)radius(argv);
   if(x<.2)
      return .2;
   return x;
}

struct point input_point(char*argv[]){
   return create_point(convert_int(argv[2],0),convert_int(argv[3],0));
}


void check_errors(int argc, char*argv[]){
   if (argc < 1)
   {
      fprintf(stderr, "usage: prog file\n"); 
      exit(1);
   }
   else if (argc < 5)
   {
      fprintf(stderr, "usage: %s file <row> <column> <radius> \n", argv[0]);
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


int print_header(FILE *in, FILE *out){
   char i; 
   int cols =0;
   int num=0;
   
   fscanf(in, "%c", &i);
   fprintf(out,"%c",i);

   fscanf(in, "%d", &num); 
   fprintf(out,"%d\n",num);

   fscanf(in, "%d", &num); 
   fprintf(out,"%d",num);
   cols = num;
    
   fscanf(in, "%d", &num); 
   fprintf(out," %d\n",num);

   fscanf(in, "%d", &num); 
   fprintf(out,"%d\n",num);

   return cols;

}

void fade(int argc, char *argv[]){
   FILE *infile, *outfile;

   check_errors(argc,argv);

   infile = fopen(argv[1], "r");
   check_file(argv[1],infile);

   outfile = fopen(OUTFILE_NAME, "w");
   check_file(OUTFILE_NAME, outfile);

   int colsinfile = print_header(infile,outfile);  
 
   int r = 0;
   int g = 0;
   int b = 0;
   int row = 0;
   int column = 0;
   struct point c = input_point(argv);

   while (fscanf(infile,"%d%d%d", &r, &g, &b) != EOF)
   {
      
      struct point x = create_point(row,column);
      double s = scale(x,c,argv);
      r=r*s;
      g=g*s;
      b=b*s;
      
      column++;
      if(column==colsinfile){
         column = 0;
         row++;
      }
      fprintf(outfile,"%d\n%d\n%d\n", r, g, b);
   }

   fclose(infile);
   fclose(outfile);

}


int main(int argc, char *argv[])
{
   fade(argc, argv);
   return 0;
}
