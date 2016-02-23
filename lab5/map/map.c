// Bryan Sugiarto CPE 101-05 Lab 5

#include "map.h"
#include "math.h"

void square_all(double const input[], int size, double result[]){
   for(int i = 0; i<size; i++){
      result[i] = input[i]*input[i];
   }
}

void add_n_all(double n, double const input[], int size, double result[]){
   for(int i = 0; i<size; i++){
      result[i] = input[i]+n;
   }
} 

void distance_all(struct point const input[], int size, double result[]){
   for(int i = 0; i<size; i++){
      result[i] = sqrt(pow(input[i].x,2)+ pow(input[i].y,2));
   }
} 
