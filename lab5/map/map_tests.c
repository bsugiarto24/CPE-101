//Bryan Sugiarto CPE 101-05 Lab 5

#include "map.h"
#include "checkit.h"

void test_square_all(void){
   double arr[4] = {4.3,5.2,2.3,4};
   double arr2[2] = {1,5.6};
   
   double test[4];
   double test2[2];

   square_all(arr,4, test);
   square_all(arr2,2, test2);
   
   checkit_double(test[0],18.49);
   checkit_double(test[1],27.04);
   checkit_double(test[2],5.29);
   checkit_double(test[3],16);

   checkit_double(test2[0],1);
   checkit_double(test2[1],31.36);

}

void test_add_n_all(void){
   double arr[5] = {3,2.3,4.9,64.4,4.1};
   double arr2[3] = {4,1.2,4.8};
      
   double test[5];
   double test2[3];
   
   add_n_all(8.7,arr,5, test);
   add_n_all(1,arr2,3, test2);

   checkit_double(test[0],11.7);
   checkit_double(test[1],11);
   checkit_double(test[2],13.6);
   checkit_double(test[3],73.1);
   checkit_double(test[4],12.8);

   checkit_double(test2[0],5);
   checkit_double(test2[1],2.2);
   checkit_double(test2[2],5.8);
}

void test_distance_all(void){
   struct point arr[3] = {create_point(4.5,7.6), create_point(3.2,5),create_point(2.1,9.3)};
   struct point arr2[2] = {create_point(1,2),create_point(4.3,1.2)};
   
   double test[3];
   double test2[2];
   
   distance_all(arr,3, test);
   distance_all(arr2, 2, test2);

   checkit_double(test[0],8.832327);
   checkit_double(test[1],5.936328832);
   checkit_double(test[2],9.534149149);

   checkit_double(test2[0],2.236067977);
   checkit_double(test2[1],4.4643028);
}

void test_cases(void){
   test_square_all();
   test_add_n_all();
   test_distance_all();
}

int main(int argc, char **argv){
   test_cases();
   return 1;
}

