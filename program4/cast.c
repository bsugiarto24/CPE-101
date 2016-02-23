//Bryan Sugiarto CPE 101-05 HW4

#include <stdio.h>
#include "cast.h"
#include "data.h"
#include "vector_math.h"
#include "collisions.h"
#include "math.h"



double distance( struct point p1, struct point p2){
   return sqrt(pow(p1.x-p2.x,2)+pow(p1.y-p2.y,2)+pow(p1.z-p2.z,2));
}

struct color addAmbience(struct sphere s,  struct color ambient){
   struct color sp = s.c;
   struct finish finish = s.finish;
   return create_color(sp.r*finish.ambient*ambient.r,
                       sp.g*finish.ambient*ambient.g,
                       sp.b*finish.ambient*ambient.b);
}


struct color cast_ray(struct ray r, struct sphere spheres[], 
                      int num_spheres, struct color a, struct light l, 
                      struct point eye){
   struct sphere hit[num_spheres];
   struct point intersection[num_spheres];
   for(int i =0; i< num_spheres&& i<MAX_SPHERES; i++){
      intersection[i] = create_point(100000,100000,100000);
      hit[i] = create_sphere(create_point(0,0,0),1,create_color(1,1,1),
                             create_finish(1,1,1,1));
   }   
  
    
 if(find_intersection_points(spheres,num_spheres, r,hit, intersection)==0){
      return create_color(1.0,1.0,1.0);
   }else{
      int index =0;
      double shortest = 10000000;
      for(int i = 0; i< num_spheres ; i++){
         if(shortest>distance(r.p,intersection[i])){
            index = i;
            shortest = distance(r.p,intersection[i]);
         }
      }
        
      struct point inter = intersection[index]; 
      struct vector N = sphere_normal_at_point(hit[index],inter);
      struct vector N2 = scale_vector(N,.01);
      struct point Pe = translate_point(inter, N2);

      struct vector Ldir = normalize_vector(vector_from_to(Pe,l.p));
      double dot = dot_vector(N,Ldir);

      struct color c = hit[index].c;
      struct finish f = hit[index].finish;
      double amb = f.ambient;
      double d = hit[index].finish.diffuse;
      double sp = hit[index].finish.specular;
      double rough = hit[index].finish.roughness;

      struct ray check = create_ray(Pe,Ldir);
      struct vector ref = difference_vector(Ldir,scale_vector(N,2*dot));   
      struct vector Vdir = normalize_vector(vector_from_to(eye, Pe));
      double intensity = dot_vector(ref,Vdir);
  

      if(find_intersection_points(spheres,num_spheres, check ,hit, intersection)!=0)
         return create_color(c.r*amb*a.r,c.g*amb*a.g,c.b*amb*a.b); 

  
      if(intensity>0 && dot>0) {

         /*printf("*** %.6f\n", c.r*amb*a.r+dot*c.r*d*l.color.r+
                             l.color.r*sp*pow(intensity,1/rough));*/

         return create_color(c.r*amb*a.r+dot*c.r*d*l.color.r+
                             l.color.r*sp*pow(intensity,1/rough), 
                             c.g*amb*a.g+dot*c.g*d*l.color.g+
                             l.color.g*sp*pow(intensity,1/rough),
                             c.b*amb*a.b+dot*c.b*d*l.color.b+
                             l.color.b*sp*pow(intensity,1/rough));    

      } 
    
     if(dot>0)
         return create_color(c.r*amb*a.r+dot*c.r*d*l.color.r,  
                             c.g*amb*a.g+dot*c.g*d*l.color.g, 
                             c.b*amb*a.b+dot*c.b*d*l.color.b);  
     
  
         return create_color(c.r*amb*a.r,c.g*amb*a.g,c.b*amb*a.b);


  }
}

double min(double x, double y){
   if(x>y)
      return y;
   return x;
}
void printColor(struct color c){
   int m = MAX_COLOR;
   int a = min(m * c.r, 255);
   int b = min(m * c.g, 255);	
   int d = min(m * c.b, 255);
   printf("%d\n%d\n%d\n",a,b, d);
}


void cast_all_rays(double min_x, double max_x, double min_y, double max_y,      
 int width, int height, struct point eye, struct sphere spheres[],              
   int num_spheres, struct color a, struct light light){
   printf("P3 \n");
   printf("%d %d \n", width,height);
   printf("255 \n");
  
   for(double j = max_y; j > min_y; j-=(max_y-min_y)/height){

      for(double i = min_x; i < max_x; i+=(max_x-min_x)/width){
   
         struct ray r = create_ray(eye,
                        vector_from_to(eye,create_point(i,j,0)));
         struct color c =cast_ray(r, spheres, num_spheres,a,light,eye);
         printColor(c);
       }
   }
}


