//Bryan Sugiarto Section 5
#include <stdio.h>
#include "checkit.h"
#include "vector_math.h"
#include "data.h"

void test_scale_vector(void){
   struct vector v = create_vector(1.1, 2.2,3.3);
   struct vector s = scale_vector(v,2);
   checkit_double(s.x,2.2);
   checkit_double(s.y,4.4);
   checkit_double(s.z,6.6);

   struct vector v2 = create_vector(1, 2.3,11.3);
   struct vector s2 = scale_vector(v2,2.5);
   checkit_double(s2.x,2.5);
   checkit_double(s2.y,5.75);
   checkit_double(s2.z,28.25);
}

void test_dot_vector(void){
   struct vector v = create_vector(1.1, 2.2,3.3);
   struct vector v2 = create_vector(2.2,4.3,4.1);
   checkit_double(dot_vector(v,v2),25.41);
   struct vector v3 = create_vector(1, 2.5,5);
   struct vector v4 = create_vector(2.2,4,6.1);
   checkit_double(dot_vector(v3,v4),42.7);
}

void test_length_vector(void){
   struct vector v = create_vector(1,2,3);
   struct vector v2 = create_vector(2.5,3.4,7.5);
   checkit_double(length_vector(v), 3.741657);
   checkit_double(length_vector(v2), 8.6058);
}

void test_normalize_vector(void){
   struct vector v = normalize_vector(create_vector(12,3,5));
   struct vector v2 = normalize_vector(create_vector(1.3,4.3,2.1));
   checkit_double(v.x,.8994380);
   checkit_double(v.y, .224859);
   checkit_double(v.z, .374766);
   checkit_double(v2.x,.26215858);
   checkit_double(v2.y, .8671399);
   checkit_double(v2.z, .4234869);
}

void test_difference_point(void){
   struct vector v = difference_point(create_point(1,3,5),create_point(4,5,7));
   checkit_double(v.x,-3);
   checkit_double(v.y,-2);
   checkit_double(v.z,-2);
   struct vector v2 = difference_point(create_point(3.4,3.2,4.3),create_point(3.5,2.6,1.7));
   checkit_double(v2.x,-.1);
   checkit_double(v2.y,.6);
   checkit_double(v2.z, 2.6);
}

void test_difference_vector(void){
   struct vector v = create_vector(9,8,7);
   struct vector v2 = create_vector(10,5,6);
   struct vector d = difference_vector(v,v2);
   checkit_double(d.x,-1);
   checkit_double(d.y,3);
   checkit_double(d.z,1);
   
   struct vector v3 = create_vector(3.5,9.3,5.3);
   struct vector v4 = create_vector(1.3,5.5,6.2);
   struct vector d2 = difference_vector(v3,v4);
   checkit_double(d2.x,2.2);
   checkit_double(d2.y,3.8);
   checkit_double(d2.z,-.9);
}

void test_translate_point(void){
   struct vector v = create_vector(3,2,7);
   struct point p = translate_point(create_point(4,8,5),v);
   checkit_double(p.x,7);
   checkit_double(p.y,3);
   checkit_double(p.z,1);

   struct vector v2 = create_vector(2.3,8.3,5.2);
   struct point p2 = translate_point(create_point(4.3,6.3,5.9),v2);
   checkit_double(p2.x,6.6);
   checkit_double(p2.y,14.6);
   checkit_double(p2.z,11.1);
}

void test_vector_from_to(void){
   struct point p = create_point(3,2,4);
   struct point p2 = create_point(6,5,3);
   struct vector v = vector_from_to(p,p2);
   checkit_double(v.x,3);
   checkit_double(v.y,3);
   checkit_double(v.z,-1);

   struct point p3 = create_point(4.2,5.8,5.2);
   struct point p4 = create_point(1.2,8.3,5.2);
   struct vector v2 = vector_from_to(p3,p4);
   checkit_double(v2.x,-3);
   checkit_double(v2.y,2.5);
   checkit_double(v2.z,0);
}

void test_cases(void)
{
   test_scale_vector();
   test_dot_vector();
   test_length_vector();
   test_normalize_vector();
   test_difference_point();
   test_difference_vector();
   test_difference_point();
   test_vector_from_to();
}

int main(int argc, char **argv)
{
   test_cases();
   return 0;
}

