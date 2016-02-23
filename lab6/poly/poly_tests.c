// Bryan Sugiarto CPE 101-05 Lab 6-POLY

#include "poly.h"
#include "checkit.h"

void test_add(void){
   double d[4] =  {3.2,6.5,5.1,3.9};
   double d2[3] = {4.3,1.8,2.3};
   double d3[3] = {4.1,3.4,3.6};
   double d4[1] = {1.5};

   double r[5];
   double r2[4];

   poly_add2(d, 3, d2 , 2 , r);
   poly_add2(d3, 2, d4 , 0 , r2);

   checkit_double(r[0],7.5);
   checkit_double(r[1],8.3);
   checkit_double(r[2],7.4);
   checkit_double(r[3],3.9);

   checkit_double(r2[0],5.6);
   checkit_double(r2[1],3.4);
   checkit_double(r2[2],3.6);

}

void test_mult(void){
   double d[3] = {1,3,2};
   double d2[2] = {1,1};
   double d3[5] = {4.3,-5.4,4.2,6.5,3.2};
   double d4[4] = {8.9,-8.2,7.3,8.3};

   double r[4];
   double r2[8];

   poly_mult2(d, 2, d2 , 1 , r);
   poly_mult2(d3, 4, d4 , 3 , r2);

   checkit_double(r[0],1);
   checkit_double(r[1],4);
   checkit_double(r[2],5);
   checkit_double(r[3],2);

   checkit_double(r2[0],38.27);
   checkit_double(r2[1],-83.32);
   checkit_double(r2[2],113.05);
   checkit_double(r2[3],19.68);
   checkit_double(r2[4],-38.98);
   checkit_double(r2[5],56.07);
   checkit_double(r2[6],77.31);
   checkit_double(r2[7],26.56);

}


void test_cases(void){
   test_add();
   test_mult();
}

int main(int argc, char **argv){
   test_cases();
   return 1;
}


