//Bryan Sugiarto Section 5
#include <stdio.h>
#include "checkit.h"
#include "vector_math.h"
#include "data.h"
#include "collisions.h"

void test_sphere_intersection_point(void){

   struct ray r = create_ray(create_point(0,0,0),create_vector(1.3,0,0));
   struct sphere s = create_sphere(create_point(2.5,0,0),1.2);
   struct maybe_point test = sphere_intersection_point(r,s);
   checkit_double(test.p.x,1.3);
   checkit_double(test.p.y,0);
   checkit_double(test.p.z,0);
   checkit_int(test.isPoint,1);
   
   struct ray r2 = create_ray(create_point(-2.4,-2.9,-4.4),create_vector(-1,0,0));
   struct sphere s2 = create_sphere(create_point(2.3,5.7,8.2),1);
   struct maybe_point test2 = sphere_intersection_point(r2,s2);
   checkit_int(test2.isPoint,0);
   
   
   struct ray r3 = create_ray(create_point(-4.3,0,4.7),create_vector(3.5,0,0));
   struct sphere s3 = create_sphere(create_point(2.1,0,0),4.7);
   struct maybe_point test3 = sphere_intersection_point(r3,s3);
   checkit_int(test3.isPoint,1); 
   

   struct ray r4 = create_ray(create_point(1.2,-5.4,4.2),create_vector(1.1,1.2,1.3));
   struct sphere s4 = create_sphere(create_point(4.7,6.4,2.2),13.5);
   struct maybe_point test4 = sphere_intersection_point(r4,s4);
   checkit_double(test4.p.x,9.871860);
   checkit_double(test4.p.y,4.060210);
   checkit_double(test4.p.z,14.448561);
   checkit_int(test4.isPoint,1);
}

void test_find_intersection_points(void){
   struct sphere s1 = create_sphere(create_point(4.2,0,0),1.3);
   struct sphere s2 = create_sphere(create_point(2.6,0,0),5.4);
   struct ray r = create_ray(create_point(-23.2,0,0),create_vector(.2,0,0));
   struct sphere spheres[2] = {s1,s2};
   struct sphere hit[2];
   struct point pts[2];
   checkit_int(find_intersection_points(spheres,2,r,hit,pts),2);
   checkit_double(pts[0].x, 2.9);
   checkit_double(pts[0].y, 0);
   checkit_double(pts[0].z, 0);
   checkit_double(pts[1].x, -2.8);
   checkit_double(pts[1].y, 0);
   checkit_double(pts[1].z, 0);
   checkit_double(hit[0].center.x, 4.2);
   checkit_double(hit[0].center.y, 0);
   checkit_double(hit[0].center.z, 0);
   checkit_double(hit[0].radius, 1.3);
   checkit_double(hit[1].center.x, 2.6);
   checkit_double(hit[1].center.y, 0);
   checkit_double(hit[1].center.z, 0);
   checkit_double(hit[1].radius, 5.4);

   struct sphere s3 = create_sphere(create_point(4.5,1.4,3.2),1.8);
   struct sphere s4 = create_sphere(create_point(2,4.3,5.4),3.2);
   struct sphere s5 = create_sphere(create_point(2.9,3.4,2.1),2.3);
   struct ray r2 = create_ray(create_point(1,1.3,.5),create_vector(1.3,1.4,1.8));
   struct sphere spheres2[3] = {s3,s4,s5};
   struct sphere hit2[3];
   struct point pts2[3];
   checkit_int(find_intersection_points(spheres2,3,r2,hit2,pts2),2);

   checkit_double(pts2[0].x, 2.489528);
   checkit_double(pts2[0].y, 2.904107);
   checkit_double(pts2[0].z, 2.562423);  
   checkit_double(pts2[1].x, 1.492227);
   checkit_double(pts2[1].y, 1.830091);
   checkit_double(pts2[1].z, 1.181545);

   checkit_double(hit2[0].center.x, 2);
   checkit_double(hit2[0].center.y, 4.3);
   checkit_double(hit2[0].center.z, 5.4);
   checkit_double(hit2[0].radius, 3.2);
   checkit_double(hit2[1].center.x, 2.9);
   checkit_double(hit2[1].center.y, 3.4);
   checkit_double(hit2[1].center.z, 2.1);
   checkit_double(hit2[1].radius, 2.3);

}

void test_sphere_normal_at_point(void){
   struct sphere s = create_sphere(create_point(4.2,3.5,6.5),5.715767665);
   struct point p = create_point(5.3,2.4,5.4);
   struct vector v = sphere_normal_at_point(s,p);
   checkit_double(v.x,.57735);
   checkit_double(v.y,-.57735);
   checkit_double(v.z,-.57735);

   struct sphere s2 = create_sphere(create_point(1.2,0,0),4.45);
   struct point p2 = create_point(6.65,0,0);
   struct vector v2 = sphere_normal_at_point(s2,p2);
   checkit_double(v2.x,1);
   checkit_double(v2.y,0);
   checkit_double(v2.z,0);



}


void test_cases(void)
{
   test_sphere_intersection_point();
   test_find_intersection_points();
   test_sphere_normal_at_point();
}

int main(int argc, char **argv)
{
   test_cases();
   return 0;
}

