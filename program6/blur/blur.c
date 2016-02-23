//Bryan Sugiarto CPE 101-05 program6
#include <stdio.h>
#include <stdlib.h>
#include "blur.h"
#include "math.h"
#define OUTFILE_NAME "blurred.ppm"


struct point create_point(int col, int r){
   struct point p;
   p.row = r;
   p.col = col;
   return p;
}

struct color create_color(int x, int y, int z){
   struct color c;
   c.r = x;
   c.g = y;
   c.b = z;
   return c;
}

double convert_double(char const input[], double default_value){
   double d = 0;
   int x = sscanf(input,"%lf", &d);
   if (x==0)
      return default_value;
   else 
      return d;
} 

void check_errors(int argc, char*argv[]){
   if (argc < 1)
   {
      fprintf(stderr, "usage: prog file\n"); 
      exit(1);
   }
   else if (argc < 3)
   {
      fprintf(stderr, "usage: %s file <blur factor> \n", argv[0]);
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
//ROWANDCOLUMN
void print_header(FILE *in, FILE *out, int dim[]){
   char i; 
   int num=0;
   
   fscanf(in, "%c", &i);
   fprintf(out,"%c",i);

   fscanf(in, "%d", &num); 
   fprintf(out,"%d\n",num);

   fscanf(in, "%d", &num); 
   fprintf(out,"%d",num);
   dim[0]= num;

   if(dim[0]>500){
      fprintf(stderr, "image is too large");
      exit(1);
   }
   fscanf(in, "%d", &num); 
   fprintf(out," %d\n",num);
   if(dim[1]>500){
      fprintf(stderr, "image is too large");                      
      exit(1);
   }
   dim[1]= num;
   arrparam= num;

   fscanf(in, "%d", &num); 
   fprintf(out,"%d\n",num);
}

int blur_factor(char *argv[]){
   return convert_double(argv[2],0);
}

struct color blurred(struct color arr[][arrparam], int dim[], char *argv[], struct point p){
   int b = blur_factor(argv);
   int count =0;
   double red =0, blue =0, green =0;
   for(int i = -b; i<=b; i++){
      for(int j = -b; j<=b; j++){
         if(p.row+i>=0 && p.row+i<dim[1] && p.col+j>=0 && p.col+j<dim[0]){
            red+=arr[p.col+j][p.row+i].r;
            green+=arr[p.col+j][p.row+i].g;
            blue+=arr[p.col+j][p.row+i].b;
            count++;
         } 
      }
   }
   red/=count;
   green/=count;
   blue/=count;
   
   return create_color((int)red,(int)green,(int)blue);
}


void decode(int argc, char *argv[]){
   FILE *infile, *outfile;

   check_errors(argc,argv);

   infile = fopen(argv[1], "r");
   check_file(argv[1],infile);

   outfile = fopen(OUTFILE_NAME, "w");
   check_file(OUTFILE_NAME, outfile);
   
   int dim[2];
   print_header(infile,outfile, dim);  

   int numcol = dim[0];
   int numrow = dim[1];

   //ROWANDCOLUMN
   struct color arr[numcol][numrow];

   int r = 0;
   int g = 0;
   int b = 0;
   int row = 0;
   int column = 0;

   //inputs colors of pixels in array
   while (fscanf(infile,"%d%d%d", &r, &g, &b) != EOF)
   {
      struct color x = create_color(r,g,b);
      //ROWANDCOLUMN
      arr[column][row] = x;
      column++;
      if(column==numcol){
         column = 0;
         row++;
      }
   }

   
   //writes colors to file
   for(int r =0; r<numrow; r++)
   {
      for(int c = 0; c<numcol; c++){
         //ROWANDCOLUMN
         struct point p = create_point(c,r);

         struct color b = blurred(arr,dim,argv,p);
         fprintf(outfile,"%d\n%d\n%d\n", b.r, b.g, b.b);
      }
   }
   fclose(infile);
   fclose(outfile);

}


int main(int argc, char *argv[])
{
   decode(argc, argv);
   return 0;
}




