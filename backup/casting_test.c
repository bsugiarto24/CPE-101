//Bryan Sugiarto CPE 101-05 Program4

#include <stdio.h>
#include "checkit.h"
#include "vector_math.h"
#include "data.h"
#include "collisions.h"
#include "cast.h"

void test_cast_all(void){

   struct sphere s[2]={create_sphere(create_point(1,1,0),2,create_color(0,0,1)),
		       create_sphere(create_point(.5,1.5,-3),.5,create_color(1,0,0))};

    cast_all_rays(-10, 10, -7.5, 7.5,
      1024, 768 ,create_point(0,0,-14), s,2);

}

void test_cases(void)
{
   test_cast_all();
}

int main(int argc, char **argv)
{
   test_cases();
   return 0;
}

