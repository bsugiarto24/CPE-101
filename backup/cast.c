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


struct color cast_ray(struct ray r, struct sphere spheres[], int num_spheres){
   struct sphere hit[num_spheres];
   struct point intersection[num_spheres];
   for(int i =0; i< num_spheres&& i<MAX_SPHERES; i++){
      intersection[i] = create_point(100000,100000,100000);
      hit[i] = create_sphere(create_point(0,0,0),1,create_color(1,1,1));
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
      return hit[index].c;     
   }
}


void printColor(struct color c){
   int m = MAX_COLOR;
   int a = m * c.r;
   int b = m * c.g;	
   int d = m * c.b;
   printf("%d\n%d\n%d\n",a,b, d);
}


void cast_all_rays(double min_x, double max_x, double min_y, double max_y,      
 int width, int height, struct point eye, struct sphere spheres[],              
   int num_spheres){
   printf("P3 \n");
   printf("%d %d \n", width,height);
   printf("255 \n");
  
   for(double j = max_y; j > min_y; j-=(max_y-min_y)/height){

      for(double i = min_x; i < max_x; i+=(max_x-min_x)/width){
   
         struct ray r = create_ray(eye,
                        vector_from_to(eye,create_point(i,j,0)));
         struct color c =cast_ray(r, spheres, num_spheres);
         printColor(c);
       }
   }
}


