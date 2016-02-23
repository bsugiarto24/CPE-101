//Bryan Sugiarto Section 5
#include <stdio.h>
#include "checkit.h"
#include "vector_math.h"
#include "data.h"
#include "collisions.h"
#include "cast.h"

void test_cast_ray(void){
   struct sphere s[2];
   struct color c1 = create_color(1,0,.3);
   s[0] = create_sphere(create_point(1.4,2.6,0), 2, c1);
   s[1] = create_sphere(create_point(4.5, 5, 0), 1,c1);

   struct ray r = create_ray(create_point(0,0,0), 
                             create_vector(1.4,2.6,0));

   struct ray r2 = create_ray(create_point(-123.2,-4,-.3),
                             create_vector(1.3,-2.9,-.3));

   struct ray r3 = create_ray(create_point(-4.5,-4.3,0),
                             create_vector(-23,-100,-100));

   checkit_int(cast_ray(r,s,2).r, 1);
   checkit_int(cast_ray(r,s,2).g, 0);
   checkit_int(cast_ray(r,s,2).b, .3);

   checkit_int(cast_ray(r2,s,2).r, 1);
   checkit_int(cast_ray(r2,s,2).g, 1);
   checkit_int(cast_ray(r2,s,2).b, 1);

   checkit_int(cast_ray(r3,s,2).r, 1);
   checkit_int(cast_ray(r3,s,2).g, 1);
   checkit_int(cast_ray(r3,s,2).b, 1);

}

void test_cast_all_rays(void){
   struct color	c = create_color(.3,.5,.9);

   struct sphere s[2];
   s[0] = create_sphere(create_point(1,1,0), 2,c);
   s[1] = create_sphere(create_point(.5, 1.5, -3.0), .5,c);
   struct point eye = create_point(0,0,-14);
   
   cast_all_rays(-10,10,-7.5,7.5,1024,768,eye,s,2);

}

void test_distance(void){
   struct point s[3];
   s[0] = create_point(1,1,0);
   s[1] = create_point(1,0,0);
   s[2] = create_point(2.3,4.4,-1.3);
    
   checkit_double(distance(s[1],s[2]),4.768648);
   checkit_double(distance(s[1],s[0]),1);

}

void test_printColor(void){
   struct color	c = create_color(.3,.5,.9);
   struct color c2 = create_color(1,0,1.0);
   printColor(c);
   printColor(c2);  
}

void test_cases(void)
{
   test_cast_ray();
   test_distance();
   test_printColor();
//   test_cast_all_rays();
}

int main(int argc, char **argv)
{
   test_cases();
   return 0;
}

