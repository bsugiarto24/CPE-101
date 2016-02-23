//Bryan Sugiarto CPE 101-05 Program4

#include <stdio.h>
#include "checkit.h"
#include "vector_math.h"
#include "data.h"
#include "collisions.h"
#include "cast.h"

void test_cast_all(int argc, char **argv){
   
   struct light l = create_light(create_point(-100,100,-100),
                                 create_color(1.5,1.5,1.5));

   
   struct sphere s[2]={create_sphere(create_point(1,1,0),
                                     2,
                                     create_color(0,0,1),
                                     create_finish(.2,.4,.5,.05)),
		       create_sphere(create_point(.5,1.5,-3),
                                     .5,
                                     create_color(1,0,0),
                                     create_finish(.4,.4,.5,.05))};

/*   struct sphere s[2]={create_sphere(create_point(1,1,0),
                                     2,
                                     create_color(1,0,1),
                                     create_finish(.2,.4,.5,.05)),
		       create_sphere(create_point(8,-10,110),
                                     100,
                                     create_color(.2,.2,.6),
                                     create_finish(.4,.8,0,.05))};*/


   cast_all_rays(-10,10,-7.5,7.5,1024,768,create_point(0,0,-14),
                 s,2,create_color(1,1,1),l);
   
//          cast_all_rays(.05859357,.44921857, 2.03125,
  //               2.421875,20,20,create_point(0,0,-14),
    //          s,2,create_color(1,1,1),l);

}

void test_cases(int argc, char **argv)
{
   test_cast_all(argc, argv);
}

int main(int argc, char **argv)
{
   test_cases(argc, argv);
   return 0;
}

