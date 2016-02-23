//Bryan Sugiarto CPE 101-05 Lab 5

#include "point.h"
#include "fold.h"
#include "checkit.h"


void test_sum(void){
   double d[4] = {4.3,3.1,-7.6,6.5};
   double d2[2] = {-7.6,2.2};
   double d3[1];

   checkit_double(sum(d,4),6.3);
   checkit_double(sum(d2,2),-5.4);
   checkit_double(sum(d3,0),0);
}

void test_index_of_smallest(void){
   double d[4] = {4.2,12.3,-7.4,6.345};
   double d2[5] = {2.3,43.4,3.2,66.7,5.4};
   double d3[1];
   double d4[4] = {5.4,6.6,7.4,0};

   checkit_int(index_of_smallest(d,4),2);
   checkit_int(index_of_smallest(d2,5),0);
   checkit_int(index_of_smallest(d4,4),3);
   checkit_int(index_of_smallest(d3,0),-1);
}

void test_nearest_origin(void){
   struct point d[4] = {create_point(5.6,3.4),create_point(4.5,5.9),
                        create_point(-1.2,2.1),create_point(-3.2,1.24)};
   struct point d2[2] = {create_point(3.23,2.43),create_point(3.12,2.44)};
   struct point d3[1];

   checkit_double(nearest_origin(d,4),2);
   checkit_double(nearest_origin(d2,2),1);
   checkit_double(nearest_origin(d3,0),-1);

}

void test_cases(void){
   test_sum();
   test_index_of_smallest();
   test_nearest_origin();
}

int main(int argc, char **argv){
   test_cases();
   return 1;
}


