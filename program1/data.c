#include "data.h"

struct point create_point(double x, double y, double z){
   struct point p;
   p.x = x;
   p.y = y;
   p.z = z;
   return p;
}
struct vector create_vector(double x, double y, double z){
   struct vector v;
   v.x = x;
   v.y = y;
   v.z = z;
   return v;
}
struct ray create_ray(struct point p, struct vector dir){
   struct ray r;
   r.p = p;
   r.dir = dir;
   return r;
}
struct sphere create_sphere(struct point center, double radius){
   struct sphere s;
   s.center = center;
   s.radius = radius;
   return s;
}
