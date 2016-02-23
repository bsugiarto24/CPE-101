//Bryan Sugiarto Section 5
#include <stdio.h>
#include "checkit.h"
#include "vector_math.h"
#include "data.h"
#include "commandline.h"

void test_input_spheres(){
   
   char *argv[2] = {"a.out",
                    "sphere.in"};

   struct sphere s[2];
   int count[1];
   input_spheres(argv, s, count);
  
   checkit_double(s[0].center.x,1);
   checkit_double(s[0].center.y,1);
   checkit_double(s[0].center.z,0);
   checkit_double(s[0].radius,2);
   checkit_double(s[0].c.r,1);
   checkit_double(s[0].c.g,0);
   checkit_double(s[0].c.b,1);
   checkit_double(s[0].finish.ambient,.2);
   checkit_double(s[0].finish.diffuse,.4);
   checkit_double(s[0].finish.specular,.5);
   checkit_double(s[0].finish.roughness,.05);
   
   checkit_double(s[1].center.x,8);
   checkit_double(s[1].center.y,-10);
   checkit_double(s[1].center.z,110);
   checkit_double(s[1].radius,100);
   checkit_double(s[1].c.r,.2);
   checkit_double(s[1].c.g,.2);
   checkit_double(s[1].c.b,.6);
   checkit_double(s[1].finish.ambient,.4);
   checkit_double(s[1].finish.diffuse,.8);
   checkit_double(s[1].finish.specular,0);
   checkit_double(s[1].finish.roughness,.05);

}

void test_input_eye(){
   char *argv[6] = {"a.out",
                    "filename",
                    "-eye",
                    "3.5","4.2","5.4"};
   
   struct point e = input_eye(6,argv);
   checkit_double(e.x,3.5);
   checkit_double(e.y,4.2);
   checkit_double(e.z,5.4);


   char *argv1[5] = {"a.out",
                   "filename",
                   "-eye","5.5","7.2"};
   
   struct point e1 = input_eye(5,argv1);
   checkit_double(e1.x,5.5);
   checkit_double(e1.y,7.2);
   checkit_double(e1.z,-14);


   char *argv2[3] = {"a.out",
                   "filename",
                   "-eye"};
   
   struct point e2 = input_eye(3,argv2);
   checkit_double(e2.x,0);
   checkit_double(e2.y,0);
   checkit_double(e2.z,-14);

   char *argv3[6] = {"a.out",
                   "filename",
                   "-eye","3","-light","3"};
   
   struct point e3 = input_eye(6,argv3);
   checkit_double(e3.x,3);
   checkit_double(e3.y,0);
   checkit_double(e3.z,-14);
}


void test_input_ambient(){
   char *argv[6] = {"a.out",
                    "filename",
                    "-eye",
                    "3.5","4.2","5.4"};
   
   struct color e = input_ambient(6,argv);
   checkit_double(e.r,1);
   checkit_double(e.g,1);
   checkit_double(e.b,1);


   char *argv1[5] = {"a.out",
                   "filename",
                   "-ambient",".5",".2"};
   
   struct color e1 = input_ambient(5,argv1);
   checkit_double(e1.r,.5);
   checkit_double(e1.g,.2);
   checkit_double(e1.b,1);


   char *argv2[4] = {"a.out",
                   "filename",
                   "-ambient",".2"};
   
   struct color e2 = input_ambient(4,argv2);
   checkit_double(e2.r,.2);
   checkit_double(e2.g,1);
   checkit_double(e2.b,1);

   char *argv3[6] = {"a.out",
                   "filename",
                   "-ambient",".4",".3",".1"};
   
   struct color e3 = input_ambient(6,argv3);
   checkit_double(e3.r,.4);
   checkit_double(e3.g,.3);
   checkit_double(e3.b,.1);
}

void test_input_view(){
   char *argv[6] = {"a.out",
                    "filename",
                    "-ambient",
                    "3.5","4.2","5.4"};
   
   struct view e = input_view(6,argv);
   checkit_double(e.min_x,-10);
   checkit_double(e.max_x,10);
   checkit_double(e.min_y,-7.5);
   checkit_double(e.max_y,7.5);
   checkit_double(e.width,1024);
   checkit_double(e.height,768);

   char *argv1[6] = {"a.out",
                    "filename",
                    "-view",
                    "3.5","4.2","5.4"};
   
   struct view e1 = input_view(6,argv1);
   checkit_double(e1.min_x,3.5);
   checkit_double(e1.max_x,4.2);
   checkit_double(e1.min_y,5.4);
   checkit_double(e1.max_y,7.5);
   checkit_double(e1.width,1024);
   checkit_double(e1.height,768);

   char *argv2[6] = {"a.out",
                    "filename",
                    "-view",
                    "4.1","-eye","5.4"};
   
   struct view e2 = input_view(6,argv2);
   checkit_double(e2.min_x,4.1);
   checkit_double(e2.max_x,10);
   checkit_double(e2.min_y,-7.5);
   checkit_double(e2.max_y,7.5);
   checkit_double(e2.width,1024);
   checkit_double(e2.height,768);

   char *argv3[11] = {"a.out",
                    "filename",
                    "-view","4.1","5.4","2.3","4.8","21","44",
                    "-eye","5.4"};
   
   struct view e3 = input_view(11,argv3);
   checkit_double(e3.min_x,4.1);
   checkit_double(e3.max_x,5.4);
   checkit_double(e3.min_y,2.3);
   checkit_double(e3.max_y,4.8);
   checkit_int(e3.width,21);
   checkit_int(e3.height,44);
}

void test_input_light(){
   char *argv[6] = {"a.out",
                    "filename",
                    "-ambient",
                    "3.5","4.2","5.4"};
   
   struct light e = input_light(6,argv);
   checkit_double(e.p.x,-100);
   checkit_double(e.p.y,100);
   checkit_double(e.p.z,-100);
   checkit_double(e.color.r,1.5);
   checkit_double(e.color.g,1.5);
   checkit_double(e.color.b,1.5);

   char *argv1[6] = {"a.out",
                    "filename",
                    "-light",
                    "3.51","4.12","5.14"};
   
   struct light e1 = input_light(6,argv1);
   checkit_double(e1.p.x,3.51);
   checkit_double(e1.p.y,4.12);
   checkit_double(e1.p.z,5.14);
   checkit_double(e1.color.r,1.5);
   checkit_double(e1.color.g,1.5);
   checkit_double(e1.color.b,1.5);

   char *argv2[9] = {"a.out",
                    "filename",
                    "-light",
                    "3.51","4.12","5.14",
                    ".2",".43",".65"};
   
   struct light e2 = input_light(9,argv2);
   checkit_double(e2.p.x,3.51);
   checkit_double(e2.p.y,4.12);
   checkit_double(e2.p.z,5.14);
   checkit_double(e2.color.r,.2);
   checkit_double(e2.color.g,.43);
   checkit_double(e2.color.b,.65);

   char *argv3[9] = {"a.out",
                    "filename",
                    "-light",
                    "3.51","4.12","5.14",
                    ".2","-ambient",".65"};
   
   struct light e3 = input_light(9,argv3);
   checkit_double(e3.p.x,3.51);
   checkit_double(e3.p.y,4.12);
   checkit_double(e3.p.z,5.14);
   checkit_double(e3.color.r,.2);
   checkit_double(e3.color.g,1.5);
   checkit_double(e3.color.b,1.5);
}

void test_equalToFlag(){
   char *argv[8] = {"a.out",
                    "filename",
                    "-ambient","3.5",
                    "-light","5.4",
                    "-eye", "-view"};
   
   checkit_int(equalToFlag(8,argv,1),0);
   checkit_int(equalToFlag(8,argv,3),0);
   checkit_int(equalToFlag(8,argv,4),1);
   checkit_int(equalToFlag(8,argv,5),0);
   checkit_int(equalToFlag(8,argv,6),1);
}


int main(int argc, char **argv)
{
   
   test_input_eye();
   test_input_ambient();
   test_input_view();
   test_input_light();
   test_equalToFlag();
   test_input_spheres();
   
   return 0;
}

