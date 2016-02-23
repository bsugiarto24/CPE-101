//Bryan Sugiarto CPE 101-05 Lab 3

#include "conditional.h"

double min(double x,double y){
   if(x<y)
     return x;
   return y;
}

double max(double x,double y){
   if(x>y)
      return x;
   return y;
}

double max_of_three(double x, double y, double z){
   if(max(x,y)>z)
      return max(x,y);
   return z;
}

int rental_late_fee(int days){
   if(days>24)
      return 100;
   else if(days>15)
      return 19;
   else if(days>9)
      return 7;
   else if(days>0)
      return 5;
   else return 0;
}

