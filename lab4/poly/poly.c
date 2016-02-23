//Bryan Sugiarto CPE 101-05 Lab 4

#include <stdio.h>
#include "poly.h"

void poly_add2(double poly1[], double poly2[], double result[]){
   int i = 0;
   
   result[i] = poly1[i]+poly2[i];
   i++;
  
   result[i] = poly1[i]+poly2[i];
   i++;
      
   result[i] = poly1[i]+poly2[i];
}

void poly_mult2(double poly1[], double poly2[], double result[]){
   
      result[0] = poly1[0]*poly2[0];
      result[1] = poly1[0]*poly2[1]+poly1[1]*poly2[0];
      result[2] = poly1[1]*poly2[1]+poly1[2]*poly2[0]+poly1[0]*poly2[2];
      result[3] = poly1[2]*poly2[1]+poly1[1]*poly2[2];
      result[4] = poly1[2]*poly2[2];



}
