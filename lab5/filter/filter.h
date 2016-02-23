//Bryan Sugiarto CPE 101-05 Lab 5

#include "point.h"

#ifndef FILTER_H
#define FILTER_H

int are_positive(double const input[], int size, double result[]); 

int are_greater_than(double n, double const input[], int size, double result[]); 

int are_in_first_quadrant(struct point const input[], int size, struct point result[]); 

#endif
