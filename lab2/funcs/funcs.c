#include "funcs.h"
#include "math.h"

double square(double in){
   return in*in;
}

double f(double x){
   return 7*x*x+2*x;
}

double g(double x, double y){
   return x*x+y*y;
}

double hypotenuse(double a, double b){
   return sqrt(a*a+ b*b);
}

int is_positive(int x){
   return x>0;
}

