// Bryan Sugiarto Program 2 Section 5

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
struct color create_color(double r, double g, double b){
   struct color c;
   c.r = r;
   c.b = b;
   c.g = g;
   return c; 
}

struct finish create_finish(double ambient, double diff,double s, double r){
   struct finish f;
   f.ambient = ambient;
   f.diffuse = diff;
   f.specular = s;
   f.roughness = r;
   return f;
}

struct sphere create_sphere(struct point center, double radius,
                            struct color c, struct finish f){
   struct sphere s;
   s.center = center;
   s.radius = radius;
   s.c = c;
   s.finish =f;
   return s;
}

struct light create_light(struct point p, struct color color){
   struct light l;
   l.p = p;
   l.color = color;
   return l;
}

struct view create_view(double min_x,double max_x,double min_y,double max_y,
                        int width,int height){  
   struct view v;   
   v.min_x = min_x;
   v.min_y = min_y;
   v.max_x = max_x;
   v.max_y = max_y;
   v.width = width;
   v.height = height;
   return v;
}




