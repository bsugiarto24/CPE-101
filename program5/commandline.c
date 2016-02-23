//Bryan Sugiarto cpe101-05 hw5

#include "data.h"
#include "commandline.h"
#include <stdio.h>
#include <string.h>

double convert_double(char const input[], double default_value){
   double d = 0;
   int x = sscanf(input,"%lf", &d);
   
   if (x==0)
      return default_value;
   else 
      return d;
} 

int equalToFlag(int argc, char*in[], int index){
    int arr[4];
    int eye = -1;
    int view =-1;
    int light = -1;
    int ambient = -1;
    int i =0;
    while(i<argc){
      if(strcmp(in[i],"-light")== 0)
         light = i;
      if(strcmp(in[i],"-eye")== 0)
         eye = i;
      if(strcmp(in[i],"-view")== 0)
         view = i;
      if(strcmp(in[i],"-ambient")== 0)
         ambient = i;
      i++;
   }

   arr[0] = eye;
   arr[1] = view;
   arr[2] = light;
   arr[3] = ambient;

   for(int j = 0; j<4; j++){
      if(arr[j]==index){
         return 1;
      }
   }
   return 0;
}


struct point input_eye(int argc, char *in[]){
   int i = 0;
   while(strcmp(in[i],"-eye")!= 0){
      if(i>=argc-1)
         return create_point(0,0,-14);
      i++;
   }
   double x = 0;
   double y = 0;
   double z = -14;
 
      if(i+1<argc && !equalToFlag(argc,in,i+1))
         x = convert_double(in[i+1],0);
      else
         return create_point(x,y,z);

      if(i+2<argc && !equalToFlag(argc,in,i+2))
         y = convert_double(in[i+2],0);
      else
         return create_point(x,y,z);

      if(i+3<argc && !equalToFlag(argc,in,i+3))
         z = convert_double(in[i+3],-14);
      else
         return create_point(x,y,z);
   
   

   return create_point(x,y,z);
}


struct color input_ambient(int argc, char *in[]){
   int i = 0;
   while(strcmp(in[i],"-ambient")!= 0){
      if(i>=argc-1)
         return create_color(1,1,1);
      i++;
   }
   double x = 1;
   double y = 1;
   double z = 1;
   
   if(i+1<argc && !equalToFlag(argc,in,i+1))
      x = convert_double(in[i+1],1);
    else
         return create_color(x,y,z);

   if(i+2<argc&& !equalToFlag(argc,in,i+2))
      y = convert_double(in[i+2],1);
    else
         return create_color(x,y,z);

   if(i+3<argc&& !equalToFlag(argc,in,i+3))
      z = convert_double(in[i+3],1);
    else
         return create_color(x,y,z);

   return create_color(x,y,z); 
}

struct view input_view(int argc, char *in[]){
   int i = 0;
   while(strcmp(in[i],"-view")!= 0){
      if(i>=argc-1)
         return create_view(-10,10,-7.5,7.5,1024,768);
      i++;
   }
   double minx = -10;
   double maxx = 10;

   double miny = -7.5;
   double maxy = 7.5;

   int width = 1024;
   int height = 768;

   if(i+1<argc && !equalToFlag(argc,in,i+1))
      minx = convert_double(in[i+1],-10);
   else
         return create_view(minx,maxx,miny,maxy,width,height);

   if(i+2<argc && !equalToFlag(argc,in,i+2))
      maxx = convert_double(in[i+2],10);
   else
         return create_view(minx,maxx,miny,maxy,width,height);

   if(i+3<argc && !equalToFlag(argc,in,i+3))
      miny = convert_double(in[i+3],-7.5);
   else
         return create_view(minx,maxx,miny,maxy,width,height);

   if(i+4<argc && !equalToFlag(argc,in,i+4))
      maxy = convert_double(in[i+4],7.5);
   else
         return create_view(minx,maxx,miny,maxy,width,height);

   if(i+5<argc && !equalToFlag(argc,in,i+5))
      width = convert_double(in[i+5],1024);
   else
         return create_view(minx,maxx,miny,maxy,width,height);

   if(i+6<argc && !equalToFlag(argc,in,i+6))
      height = convert_double(in[i+6],768);
   else
         return create_view(minx,maxx,miny,maxy,width,height);

   return create_view(minx,maxx,miny,maxy,width,height);
}


struct light input_light(int argc, char *in[]){
   int i = 0;
   while(strcmp(in[i],"-light")!= 0){
      if(i>=argc-1)
         return create_light(create_point(-100,100,-100),create_color(1.5,1.5,1.5));
      i++;
   }
   double x = -100;
   double y = 100;
   double z = -100;
   
   double r = 1.5;
   double g = 1.5;
   double b = 1.5;

   if(i+1<argc && !equalToFlag(argc,in,i+1))
      x = convert_double(in[i+1],-100);
   else 
      return create_light(create_point(x,y,z),create_color(r,g,b)); 
 
   if(i+2<argc && !equalToFlag(argc,in,i+2))
      y = convert_double(in[i+2],100);
   else 
      return create_light(create_point(x,y,z),create_color(r,g,b)); 

   if(i+3<argc && !equalToFlag(argc,in,i+3))
      z = convert_double(in[i+3],-100);
   else 
      return create_light(create_point(x,y,z),create_color(r,g,b)); 

   if(i+4<argc && !equalToFlag(argc,in,i+4))
      r = convert_double(in[i+4],1.5);
   else 
      return create_light(create_point(x,y,z),create_color(r,g,b)); 
   
   if(i+5<argc && !equalToFlag(argc,in,i+5))
      g = convert_double(in[i+5],1.5);
   else 
      return create_light(create_point(x,y,z),create_color(r,g,b)); 

   if(i+6<argc && !equalToFlag(argc,in,i+6))
      b = convert_double(in[i+6],1.5);
   else 
      return create_light(create_point(x,y,z),create_color(r,g,b)); 

   return create_light(create_point(x,y,z),create_color(r,g,b)); 
}


void input_spheres(char **argv, struct sphere s[], int c[]){

   c[0] = 0;
   FILE *fp;
   fp= fopen(argv[1],"r");
  
   if (fp == NULL) {
       perror("usage: a.out <filename> [-eye x y z] [-view min_x max_x min_y max_y width height] [-light x y z r g b] [-ambient r g b]\n");
   }

   double x, y,z, radius,r,g, b,a,d, sp, ro;
   int index = 0;   

   while (fscanf(fp, "%lf %lf%lf %lf%lf %lf%lf %lf%lf %lf%lf ", 
                       &x, &y, &z,&radius, &r, &g,&b, &a, &d,&sp, &ro) != EOF &&
                 index<10000) {
      struct sphere sphere =  create_sphere(create_point(x,y,z),
                                            radius,
                                            create_color(r,g,b),
                                            create_finish(a,d,sp,ro));
      s[index] = sphere;
      index++;
   }
   c[0] = index;
   fclose(fp);

}
