//Bryan Sugiarto CPE101-05 Lab7

#include <stdio.h>
#include "checkit.h"
#include "string.h"

void test_str_rot13(void){
   char a[5] = {'a','b','C','E',0};
   char b[5]; 
   str_rot_13(a,b);
   checkit_string(b,"noPR");
   char c[6] = {'A','G','v','z','O',0};
   char d[6]; 
   str_rot_13(c,d);
   checkit_string(d,"NTimB");


}


void test_cat_101(void){
   char cat[4] = {'c','A','t',0};
   char fish[5] = {'F','i','s','H',0};
   char catfish[8];

   str_cat_101(cat,fish,catfish); 
   checkit_string(catfish,"cAtFisH"); 
  
   char d[5] = {'P','a','N','n',0};
   char e[7] = {'H','a','N','D','L','e',0};
   char f[11];
   str_cat_101(d,e,f);
   checkit_string(f,"PaNnHaNDLe");
}

void test_cases(void){
   test_str_rot13();
   test_cat_101();
}

int main(int argc, char **argv){
   test_cases();
   return 1;
}

