//Bryan Sugiarto CPE 101-05 HW 3

#include "data.h"
#ifndef COLLISIONS_H
#define COLLISIONS_H

struct maybe_point{
   struct point p; 
   int isPoint;
};

struct maybe_point sphere_intersection_point(struct ray r, struct sphere s);

int find_intersection_points(struct sphere spheres[], int num_spheres, struct ray r,
    struct sphere hit_spheres[], struct point intersection_points[]);

struct vector sphere_normal_at_point(struct sphere s, struct point p);

#endif
