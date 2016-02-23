#include <stdio.h>
#include "line.h"

struct line2d create_line2d(double x12, double y12, double x22, double y22){
   struct line2d l;
   l.x1 = x12;
   l.x2 = x22;
   l.y1 = y12;
   l.y2 = y22;
   return l;
}


