// Bryan Sugiarto CPE 101-05 Lab4

#include <stdio.h>
#include "poly.h"
#include "checkit.h"

void poly_add2_test_cases(void)
{
   double poly1[3] = {2, 3.1, 2.7};
   double poly2[3] = {1.2, 2.4, 0};
   double result[3];

   poly_add2(poly1, poly2, result);

   checkit_double(result[0], 3.2);
   checkit_double(result[1], 5.5);
   checkit_double(result[2], 2.7);


   double poly3[3] = {-4.5, 2.3, 0};
   double poly4[3] = {-3.8, -2.9, 0};
   double result2[3];

   poly_add2(poly3, poly4, result2);

   checkit_double(result2[0], -8.3);
   checkit_double(result2[1], -.6);
   checkit_double(result2[2], 0);
}

void poly_mult2_test_cases(void)
{
   double poly1[3] = {3, 5.4, 2.7};
   double poly2[3] = {1.7, -2.9, 0};
   double result[5];

   poly_mult2(poly1, poly2, result);

   checkit_double(result[0], 5.1);
   checkit_double(result[1], .48);
   checkit_double(result[2], -11.07);
   checkit_double(result[3], -7.83);
   checkit_double(result[4], 0);

   double poly3[3] = {-2.54, 6.34, -4.54};
   double poly4[3] = {1.28, -3.2, 3.54};

   poly_mult2(poly3, poly4, result);

   checkit_double(result[0], -3.2512);
   checkit_double(result[1], 16.2432);
   checkit_double(result[2], -35.0908);
   checkit_double(result[3], 36.9716);
   checkit_double(result[4], -16.0716);

}

void test_cases(void){
   poly_add2_test_cases();
   poly_mult2_test_cases();
}

int main(int argc, char **argv){
   test_cases();
   return 0;
}

