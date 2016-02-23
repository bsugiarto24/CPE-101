#include "structs.h"

#ifndef FUNCS_STRUCS_H
#define FUNCS_STRUCS_H

struct circle grow_circle(struct circle c, double scale);

double distance(struct point start, struct point end);

int circles_overlap(struct circle c1, struct circle c2);

#endif



