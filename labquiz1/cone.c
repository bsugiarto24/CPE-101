/*
 *Bryan Sugiarto Section 5
 *Lab Quiz 1
 */

#include "cone.h"

struct cone create_cone(double r, double h){
   struct cone c;
   c.radius = r;
   c.height = h;
   return c;
}

double cone_volume(struct cone c){
   return 3.141592*c.radius*c.radius*c.height/3;
}

int has_greater_volume_than(struct cone c, double volume){
   return cone_volume(c)>volume;
}

struct cone max_of_three(struct cone c1,struct cone c2, struct cone c3){
   if(cone_volume(c1)>cone_volume(c2)){
      if(cone_volume(c1)>cone_volume(c3)){
         return c1;
      }else{
         return c3;
      }
  }else if(cone_volume(c2) > cone_volume(c3) ){
      return c2;
  }else{
      return c3;
  } 
}
