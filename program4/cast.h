//Bryan Sugiarto CPE 101-05 HW4


#ifndef CAST_H
#define CAST_H

#define  MAX_SPHERES 10000
#define  MAX_COLOR 255

#include "data.h"

struct color cast_ray(struct ray r, struct sphere spheres[], int num_spheres,
                      struct color a, struct light l, struct point eye);

double min(double x, double y);

void cast_all_rays(double min_x, double max_x, double min_y, double max_y,
 int width, int height, struct point eye, struct sphere spheres[],
   int num_spheres, struct color a, struct light light);

double distance(struct point p, struct point p1);

void printColor(struct color c);

#endif

