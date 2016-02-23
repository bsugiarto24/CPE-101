//Bryan Sugiarto CPE 101-05 Lab8

#include <stdio.h>
#include "point.h"

void print(struct point p){
   if(p.x>0 && p.y>0)
      printf("(%f,%f)\n",p.x,p.y); 
}


int main(int argc, char *argv[]){   

   FILE *fp;
   fp= fopen(argv[1],"r");
  
   if (fp == NULL) {
         perror("Can't open input file!\n");
   }

   double x, y;
   
   while (fscanf(fp, "%lf %lf", &x, &y) != EOF) {
      struct point p =  create_point(x,y);
      print(p);
   }

   fclose(fp);
}

