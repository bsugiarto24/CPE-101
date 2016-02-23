/*
 *Bryan Sugiarto
 *Lab Quiz 2
 */

#include <stdio.h>
#include "math.h"
#include "rect.h"

struct point create_point(int x, int y){
   struct point p;
   p.x = x;
   p.y = y;
   return p;
}
  
struct rect create_rect(struct point ll, int w,	int h){
   struct rect r;
   r.ll = ll;
   r.w = w;
   r.h = h;
   return r;
}

double distance(struct point p1, struct point p2){
   return sqrt(pow(p1.x-p2.x,2)+pow(p1.y-p2.y,2));
}
 
int rectArea(struct rect r){
   return r.w*r.h;
}

int largest_rect(struct	rect rects[], int size){
   if(size==0){
      return -1;
   }
   int index=0;
   int area=0;
   for(int i =0; i<size; i++){
      if(rectArea(rects[i])>area){
         area = rectArea(rects[i]);
         index = i;
      }
   } 
   return index;
}

void rectCorners(struct rect r, struct point p[]){
   p[0] = r.ll;
   p[1] = create_point(r.ll.x,r.ll.y+r.h);
   p[2]	= create_point(r.ll.x+r.w,r.ll.y+r.h);
   p[3]	= create_point(r.ll.x+r.w,r.ll.y);
}

void closest_corners(struct rect r1, struct rect r2, struct point p[]){
   int index1 = 0;
   int index2 = 0;  
   
   struct point r1points[4];
   rectCorners(r1,r1points);

   struct point r2points[4];
   rectCorners(r2,r2points);

   int d = distance(r1points[0],r2points[0]);
    
   for(int i = 0; i<4; i++){
      for(int j =0; j<4; j++){
        if(d > distance(r1points[i],r2points[j])){
           index1 = i;
           index2 = j;
           d = distance(r1points[i], r2points[j]);
        }
      }
   }

   p[0] = r1points[index1];
   p[1] = r2points[index2];
}

