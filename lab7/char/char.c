//Bryan Sugiarto CPE101-05 Lab7

#include "char.h"

int is_lower_101(char c){
   return (c>='a'&& c<='z');
}

char char_rot_13(char c){
   if(c>='A'&& c<='M')
      return c+13;
   else if(c>='M' && c<='Z')
      return c-13;
   else if(c>='a'&& c<='m')
      return c+13;
   else if(c>='m' && c<='z')
      return c-13;
   else 
      return c;
}


