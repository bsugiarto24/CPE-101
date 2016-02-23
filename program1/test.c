#include <stdio.h>
#include "checkit.h"
#include "data.h"

void test_create_point(void){
   struct point p1 = create_point(1.5,2.5,3.5);
   checkit_double(p1.x,1.5);
   checkit_double(p1.y,2.5);
   checkit_double(p1.z,3.5);

   struct point p2 =  create_point(23.2,35.4,12.32);
   checkit_double(p2.x,23.2);
   checkit_double(p2.y,35.4);
   checkit_double(p2.z,12.32);
}


void test_create_vector(void){
   struct vector v =  create_vector(5.43,2.34,10.43);
   checkit_double(v.x,5.43);
   checkit_double(v.y,2.34);
   checkit_double(v.z,10.43);
      
   struct vector v2 =  create_vector(234.3,435.3,1.3);
   checkit_double(v2.x,234.3);
   checkit_double(v2.y,435.3);
   checkit_double(v2.z,1.3);
}

void test_create_ray(void){
   struct ray r = create_ray(create_point(2.3,4.3,2.1),create_vector(2.5,3.5,4.5));
   checkit_double(r.p.x, 2.3);
   checkit_double(r.p.y, 4.3);
   checkit_double(r.p.z, 2.1);
   checkit_double(r.dir.x,2.5);
   checkit_double(r.dir.y,3.5);
   checkit_double(r.dir.z,4.5);
   
   struct ray r2 = create_ray(create_point(3.4,4.5,2.5),create_vector(1.1,4.1,5.1));
   checkit_double(r2.p.x, 3.4);
   checkit_double(r2.p.y, 4.5);
   checkit_double(r2.p.z, 2.5);
   checkit_double(r2.dir.x,1.1);
   checkit_double(r2.dir.y,4.1);
   checkit_double(r2.dir.z,5.1);
}

void test_create_sphere(void){
   struct sphere s = create_sphere(create_point(1.9,3.9,7.9), 45.55);
   checkit_double(s.center.x,1.9);
   checkit_double(s.center.y,3.9);
   checkit_double(s.center.z,7.9);
   checkit_double(s.radius,45.55);

struct sphere s2 = create_sphere(create_point(5.8,9.8,1.8), 23.23);
   checkit_double(s2.center.x,5.8);
   checkit_double(s2.center.y,9.8);
   checkit_double(s2.center.z,1.8);
   checkit_double(s2.radius,23.23);

}

void test_cases(void)
{
   test_create_point();
   test_create_vector();
   test_create_ray();
   test_create_sphere();
}

int main(int argc, char **argv)
{
   test_cases();

   return 0;
}


