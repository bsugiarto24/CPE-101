// Bryan Sugiarto CPE101-05 Lab 8

#include <stdio.h>
#include "convert.h"
#include "checkit.h"

void test(void){
   
   char a[] = {'4','5','.','6',0};
   char b[] = {'c','a','6',0};
   
   double d= 0;
   double e = 1.2;
 
   d = convert_double(a,d);
   checkit_double(d,45.6); 
   e = convert_double(b,e);
   checkit_double(e,1.2);   
  

}


int main(int argc, char **argv){
   test();
   return 1;
}
