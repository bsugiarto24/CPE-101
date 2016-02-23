//Bryan Sugiarto CPE101-05 Labquiz2

#include "rect.h"
#include "checkit.h"

void test(void){

   struct point p1 = create_point(1,3);
   struct point p2 = create_point(3,6);
   struct point p3 = create_point(5,0);
   struct point p4 = create_point(7,1);

   checkit_int(p1.x,1);
   checkit_int(p2.y,6);

   struct rect r1 = create_rect(p1, 3,2);
   struct rect r2 = create_rect(p2, 4,1);
   struct rect r3 = create_rect(p3,1,1);
   struct rect r4 = create_rect(p4,1,1);
      
   checkit_int(r1.w, 3);
   checkit_int(r2.h, 1);

   checkit_double(distance(p1,p3),5);
   
   struct rect r[3] = {r1,r2,r3};
   checkit_int(largest_rect(r,3),0);
   
   struct point p[2];
   closest_corners(r1,r2,p);
   checkit_int(p[0].x,4);
   checkit_int(p[0].y,5);   
   checkit_int(p[1].x,3);
   checkit_int(p[1].y,6);

   struct point pt[2];
   closest_corners(r2,r3,pt);
   checkit_int(pt[0].x,3);
   checkit_int(pt[0].y,6);
   checkit_int(pt[1].x,5);
   checkit_int(pt[1].y,1);

   struct point pts[2];
   closest_corners(r3,r4,pts);
   checkit_int(pts[0].x,6);
   checkit_int(pts[0].y,1);
   checkit_int(pts[1].x,7);
   checkit_int(pts[1].y,1);


}

int main(){
   test();
   return 1;
}
