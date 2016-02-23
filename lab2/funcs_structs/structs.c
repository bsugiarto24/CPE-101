#include "structs.h"

struct point create_point(double x, double y){
   struct point p;
   p.x = x;
   p.y = y;
   return p;
}

struct circle create_circle(struct point p, double r){
   struct circle c;
   c.p = p;
   c.radius = r;
   return c;
}
