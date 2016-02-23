#ifndef STRUCTS_H
#define STRUCTS_H

struct point{
   double x;
   double y;
};

struct circle{
   struct point p;
   double radius;
};

struct point create_point(double x, double y);

struct circle create_circle(struct point, double r);

#endif

