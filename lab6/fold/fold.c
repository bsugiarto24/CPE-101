// Bryan Sugiarto CPE 101-05 Lab 6

#include "fold.h"
#include "point.h"
#include "math.h"

double sum(double const input[], int size){
   double s = 0;
   for(int i = 0; i<size;i++){
      s+= input[i];
   }
   return s;
}

int index_of_smallest(double const input[], int size){
   int s = 0;
   if(size ==0)
      return -1;  
   for( int i = 0; i<size; i++){
      if(input[s]>input[i])
         s = i;
   }
   return s;
} 

double distance(struct point p1, struct point p2){
   return sqrt(pow(p1.x-p2.x,2)+pow(p1.y-p2.y,2));
}

int nearest_origin(struct point const input[], int size){
   int s = 0;
   struct point o = create_point(0,0);
   if(size==0)
      return -1;
   for(int i = 0; i<size; i++){
      if( distance(input[s],o) > distance(input[i],o))
         s = i;
   }
   return s;
}


