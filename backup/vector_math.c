// Bryan Sugiarto Section 5

#include "vector_math.h" 
#include "data.h" 
#include "math.h"

struct vector scale_vector(struct vector v, double scalar){
   return create_vector(v.x*scalar,v.y*scalar, v.z*scalar);    
}

double dot_vector(struct vector v1, struct vector v2){
   return v1.x*v2.x +v1.y*v2.y+v1.z*v2.z;
}

double length_vector(struct vector v){
   return sqrt(v.x*v.x+v.y*v.y+v.z*v.z);
}

struct vector normalize_vector(struct vector v){
   double l = length_vector(v);
   return create_vector(v.x/l,v.y/l,v.z/l);
}

struct vector difference_point(struct point p1, struct point p2){
    return create_vector(p1.x-p2.x,p1.y-p2.y,p1.z-p2.z);
}
   
struct vector difference_vector(struct vector v1, struct vector v2){
    return create_vector(v1.x-v2.x,v1.y-v2.y,v1.z-v2.z);
}

struct point translate_point(struct point p, struct vector v){
   return create_point(p.x+v.x,p.y+v.y,p.z+v.z);
}

struct vector vector_from_to(struct point from, struct point to){
    return create_vector(to.x-from.x,to.y-from.y,to.z-from.z);
}
