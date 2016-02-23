#include "funcs_structs.h"
#include "structs.h"
#include "math.h"

struct circle grow_circle(struct circle c, double scale){
   struct circle cir = create_circle(c.p, c.radius*scale);
   return cir;
}

double distance(struct point start, struct point end){
   return sqrt((start.x-end.x)*(start.x-end.x)+(start.y-end.y)*(start.y-end.y));
}

int circles_overlap(struct circle c1, struct circle c2){
   double d = distance(c1.p, c2.p);
   return(d<=c1.radius+c2.radius);   
}
