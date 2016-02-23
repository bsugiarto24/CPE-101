// Bryan Sugiarto CPE 101-05 Lab6 
 
#ifndef FOLD_H
#define FOLD_H

#include "point.h"


double sum(double const input[], int size); 

int index_of_smallest(double const input[], int size); 

double distance(struct point p1, struct point p2);

int nearest_origin(struct point const input[], int size);

#endif