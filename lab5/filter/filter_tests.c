//Bryan Sugiarto CPE 101-05 Lab 5

#include "point.h"
#include "filter.h"
#include "checkit.h"


void test_are_positive(void){
   double arr[5] = {-3,2.3,4.9,64.4,4.1};
   double arr2[3] = {4,-1.2,0};

   double test[5];
   double test2[3];

   checkit_int(are_positive(arr, 5, test),4);
   checkit_int(are_positive(arr2,3, test2),1);

   checkit_double(test[0],2.3);
   checkit_double(test[1],4.9);
   checkit_double(test[2],64.4);
   checkit_double(test[3],4.1);

   checkit_double(test2[0],4);
}


void test_are_greater_than(void){
   double arr[5] = {4.3,7.8,-3.2,8,3};
   double arr2[3] = {4.2,-1.2,-.6};

   double test[5];
   double test2[3];

   checkit_int(are_greater_than(2,arr,5, test),4);
   checkit_int(are_greater_than(-.6,arr2,3, test2),1);

   checkit_double(test[0],4.3);
   checkit_double(test[1],7.8);
   checkit_double(test[2],8);
   checkit_double(test[3],3);

   checkit_double(test2[0],4.2);
}

void test_are_in_first_quadrant(void){
   struct point arr[3] = {create_point(3.6,8),create_point(4.3,0),
                          create_point(0,7.6)};
   struct point arr2[2] = {create_point(-5.4,-2.1),create_point(-5.4,2.1)};

   struct point test[3];
   struct point test2[2];

   checkit_int(are_in_first_quadrant(arr,3, test),1);
   checkit_int(are_in_first_quadrant(arr2,2, test2),0);

   checkit_double(test[0].x,3.6);
   checkit_double(test[0].y,8);

}



void test_cases(void){
   test_are_positive();
   test_are_greater_than();
   test_are_in_first_quadrant();
}

int main(int argc, char **argv){
   test_cases();
   return 1;
}

