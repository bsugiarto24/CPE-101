#include <stdio.h>
#include "checkit.h"
#include "structs.h"
#include "funcs_structs.h"

void test_create_point(void){
   struct point p = create_point(1.3, 2.3);
   checkit_double(p.x,1.3);
   checkit_double(p.y,2.3);

   struct point p2 = create_point(23.3, 24.3);
   checkit_double(p2.x,23.3);
   checkit_double(p2.y,24.3);
}

void test_create_circle(void){
   struct circle c = create_circle(create_point(2.4,1.8), 33.3);
   checkit_double(c.p.x, 2.4);
   checkit_double(c.p.y, 1.8);
   checkit_double(c.radius, 33.3);

   struct circle c2 = create_circle(create_point(7.7,8.3), 3.3);
   checkit_double(c2.p.x, 7.7);
   checkit_double(c2.p.y, 8.3);
   checkit_double(c2.radius, 3.3);
}

void test_grow_circle(void){
   struct circle c = create_circle(create_point(2.4,1.8), 33.3);
   checkit_double(c.p.x, 2.4);
   checkit_double(c.p.y, 1.8);
   checkit_double(c.radius, 33.3);
   c = grow_circle(c,2);
   checkit_double(c.p.x, 2.4);
   checkit_double(c.p.y, 1.8);
   checkit_double(c.radius, 66.6);

   struct circle c2 = create_circle(create_point(7.7,8.3), 3.3);
   checkit_double(c2.p.x, 7.7);
   checkit_double(c2.p.y, 8.3);
   checkit_double(c2.radius, 3.3);
   c2 = grow_circle(c2,2.5); 
   checkit_double(c2.p.x, 7.7);
   checkit_double(c2.p.y, 8.3);
   checkit_double(c2.radius, 8.25);
}

void test_distance(void){
   struct point p = create_point(1,2);
   struct point p2 = create_point(5,5);
   struct point p3 = create_point(3.5,5.4);
   struct point p4 = create_point(4.3,7.6);

   checkit_double(distance(p,p2),5);
   checkit_double(distance(p3,p4),2.340940);
}

void test_circles_overlap(void){
   struct circle c = create_circle(create_point(0,0),4);
   struct circle c2 = create_circle(create_point(1,0),3);
   struct circle c3 = create_circle(create_point(4,5),1);
   struct circle c4 = create_circle(create_point(2,6),1);

   checkit_int(circles_overlap(c,c2),1);
   checkit_int(circles_overlap(c3,c4),0);
}

void test_cases(void)
{
   test_create_point();
   test_create_circle();
   test_grow_circle();
   test_distance();
   test_circles_overlap();
}

int main(int argc, char **argv)
{
   test_cases();

   return 0;
}
