/*
 *Bryan Sugiarto Section 5
 *Lab Quiz 1
 */

#include <stdio.h>
#include "checkit.h"
#include "cone.h"

void test_create_cone(void){
   struct cone c = create_cone(2,3.4);
   checkit_double(c.radius,2);
   checkit_double(c.height,3.4);

   struct cone c2 = create_cone(34.2,2.3);
   checkit_double(c2.radius,34.2);
   checkit_double(c2.height, 2.3);

   struct cone c3 = create_cone(5,6);
   checkit_double(c3.radius,5);
   checkit_double(c3.height,6);
}

void test_cone_volume(void){
   struct cone c = create_cone(5,4);
   checkit_double(cone_volume(c),104.71973333);

   struct cone c2 = create_cone(7.4,4.5);
   checkit_double(cone_volume(c2),258.05036688);
}

void test_has_greater_volume_than(void){
   struct cone c = create_cone(2.4,3.5);
   checkit_int(has_greater_volume_than(c,100),0);

   struct cone c2 = create_cone(7.4,8.5);
   checkit_int(has_greater_volume_than(c2,100),1);
}

void test_max_of_three(void){
   struct cone c = create_cone(2,5);
   struct cone c2 = create_cone(4.7,1.9);
   struct cone c3 = create_cone(5.2,10);
   struct cone max = max_of_three(c,c2,c3);
   checkit_double(max.radius,5.2);
   checkit_double(max.height,10);

   struct cone d = create_cone(23.2,5);
   struct cone d2 = create_cone(4.1,1.3);
   struct cone d3 = create_cone(5.8,1.6);
   struct cone max2 = max_of_three(d,d2,d3);
   checkit_double(max2.radius,23.2);
   checkit_double(max2.height,5);

   struct cone a = create_cone(2.8,5.3);
   struct cone a2 = create_cone(4.6,.34);
   struct cone a3 = create_cone(34.8,14.6);
   struct cone max3 = max_of_three(a,a2,a3);
   checkit_double(max3.radius,34.8);
   checkit_double(max3.height,14.6);

}

void test_cases(void){
   test_create_cone();
   test_cone_volume();
   test_has_greater_volume_than();
   test_max_of_three();
}


int main(){
  test_cases();
  return 0;
}

