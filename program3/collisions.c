//Bryan Sugiarto CPE 101-05 HW 3

#include "data.h"
#include "vector_math.h"
#include "collisions.h"
#include "math.h"

struct maybe_point sphere_intersection_point(struct ray r, struct sphere s){
   struct maybe_point p;
   double A = dot_vector(r.dir,r.dir);
   double B = 2 * dot_vector(difference_point(r.p,s.center), r.dir);
   double C = dot_vector(difference_point(r.p,s.center),
              difference_point(r.p, s.center)) - s.radius*s.radius;

   double E = (-B+sqrt(B*B-4*A*C))/2/A;
   double F = (-B-sqrt(B*B-4*A*C))/2/A;

   if((E>0&& F>0)){
      p.isPoint = 1;
      if(E>F)
          p.p = translate_point(r.p, scale_vector(r.dir,F));
      else
          p.p = translate_point(r.p, scale_vector(r.dir,E));
    
   }else if((E>0||F>0)){
      p.isPoint = 1;
      if(E>0)
           p.p = translate_point(r.p, scale_vector(r.dir,E));
      else
          p.p = translate_point(r.p, scale_vector(r.dir,F));
     
   }else{
       p.isPoint =0;
       p.p = create_point(0,0,0);
   }

   return p;
}

int find_intersection_points(struct sphere spheres[], int num_spheres, struct ray r,
   struct sphere hit_spheres[], struct point intersection_points[]){
   int hit = 0;
   for(int i =0; i<num_spheres; i++){
      struct maybe_point point = sphere_intersection_point(r, spheres[i]);
      
      if(point.isPoint ==1){
         hit_spheres[hit] = spheres[i];
         intersection_points[hit] = point.p;
         hit++;
      }
   }
   return hit;
}

struct vector sphere_normal_at_point(struct sphere s, struct point p){
   struct vector v = vector_from_to(s.center,p);
   return normalize_vector(v);
}
