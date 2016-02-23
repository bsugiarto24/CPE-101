//Bryan Sugiarto CPE 101-05 HW5

#include <stdio.h>
#include "commandline.h"
#include "vector_math.h"
#include "data.h"
#include "collisions.h"
#include "cast.h"

void cast_all(char *argv[], int argc){

   struct light l = input_light(argc, argv);
   struct view v = input_view(argc,argv);
   struct point eye = input_eye(argc, argv); 
   struct color ambient = input_ambient(argc,argv);

   /*printf("light p: %lf %lf %lf\n", l.p.x,l.p.y,l.p.z);
   printf("light c: %lf %lf %lf\n", l.color.r,l.color.g,l.color.b);

  
   printf("eye: %lf %lf %lf\n", eye.x,eye.y,eye.z);

  
   printf("ambient: %lf %lf %lf\n", ambient.r,ambient.g,ambient.b);

   
   printf("view: %lf %lf\n", v.min_x,v.max_x);
   printf("view: %lf %lf\n", v.min_y,v.max_y);
   printf("view:  %d %d\n",v.width,v.height);*/
 

   int count[1] = {0};
 
   struct sphere s[MAX_SPHERES];
   

   for(int i =0; i< MAX_SPHERES; i++){
      s[i] = create_sphere(create_point(0,0,0),0,create_color(0,0,0),
                             create_finish(0,0,0,0));
   }
   input_spheres(argv, s, count);
   
   /*struct sphere s1 = s[0];
   struct sphere s2 = s[1];
   printf("%lf %lf %lf\n", s1.center.x,s1.center.y,s1.center.z);
   printf("%lf\n", s1.radius);
   printf("%lf %lf %lf\n", s1.c.r,s1.c.g,s1.c.b);
   printf("%lf %lf\n", s1.finish.ambient,s1.finish.diffuse);
   printf("%lf %lf\n\n", s1.finish.specular,s1.finish.roughness);
   

   printf("%lf %lf %lf\n", s2.center.x,s2.center.y,s2.center.z);
   printf("%lf\n", s2.radius);
   printf("%lf %lf %lf\n", s2.c.r,s2.c.g,s2.c.b);
   printf("%lf %lf\n", s2.finish.ambient,s2.finish.diffuse);
   printf("%lf %lf\n", s2.finish.specular,s2.finish.roughness);


   printf("%d\n", count[0]);*/
   
   
   cast_all_rays(v.min_x,v.max_x,v.min_y,v.max_y,v.width,v.height,eye,s,count[0],ambient,l);


}

int main(int argc, char **argv)
{
   cast_all(argv, argc);
   return 0;
}

