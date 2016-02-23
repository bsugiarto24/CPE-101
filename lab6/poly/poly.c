//Bryan Sugiarto CPE 101-05 Lab 6

#include "poly.h"

void poly_add2(double const poly1[], int degree1, double const poly2[],
 int degree2, double result[])
{
int d;
if(degree1>degree2)
   d = degree1;
else 
   d = degree2;

for(int i =0; i<=d ; i++){
   result[i] = 0;
   if(i<=degree1)
      result[i] = result[i]+ poly1[i];
   if(i<=degree2)
      result[i] = result[i]+ poly2[i];
   }
}
void poly_mult2(double const poly1[], int degree1, double const poly2[]
      , int degree2, double result[])
{
for(int i =0 ; i<= degree1+degree2; i++){
   result[i] =0;
}

for(int i =0; i<=degree1 ; i++)
   {
   for(int j= 0; j<=degree2; j++)
      {
         result[i+j] = result[i+j]+ poly1[i]*poly2[j];
      }
   
   }

}




