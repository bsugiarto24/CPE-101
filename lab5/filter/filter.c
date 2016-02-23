//Bryan Sugiarto CPE 101-05 Lab 5

#include "point.h"
#include "filter.h"

int are_positive(double const input[], int size, double result[]){
   int j = 0;
   for(int i = 0; i<size; i++){
      if (input[i]>0){
         result[j] = input [i];
         j++;
      }
   }
   return j;
}

int are_greater_than(double n, double const input[], int size, double result[]){
   int j = 0;
   for(int i = 0; i<size; i++){
      if (input[i]>n){
         result[j] = input [i];
       	 j++;
      }
   }
   return j;
}


int are_in_first_quadrant(struct point const input[], int size, struct point result[]){
   int j = 0;
   for(int i = 0; i<size; i++){
      if (input[i].x>0 && input[i].y>0){
         result[j] = input [i];
       	 j++;
      }
   }
   return j;
}





