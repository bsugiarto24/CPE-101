#include <stdio.h>
#include "checkit.h"
#include "line.h"

void test_cases(void)
{
   struct line2d l =  create_line2d(1.5,2.5,3.5,4.5);
 
   checkit_double(l.x1,1.5);
   checkit_double(l.y1,2.5);
   checkit_double(l.x2,3.5);
   checkit_double(l.y2,4.5);
}

int main(int argc, char **argv)
{
   test_cases();

   return 0;
}
