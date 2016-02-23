// Bryan Sugiarto CPE101-05 Lab 8

#include <stdio.h>
#include "convert.h"


double convert_double(char const input[], double default_value){
   double d = 0;
   int x = sscanf(input,"%lf", &d);
   
   if (x==0)
      return default_value;
   else 
      return d;

} 
