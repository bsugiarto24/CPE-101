//Bryan Sugiarto CPE101-05 Lab7
#include <stdio.h>
#include "string.h"

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

int length(char const in[]){
   int i = 0;
   while(in[i]!= 0){ i++;}
   return i;
}

void str_rot_13(char const input[], char result[]){
   int end = length(input);
   for(int i = 0; input[i]!= 0; i++){
      result[i] = char_rot_13(input[i]);
   }
      result[end] =0;
}

void str_cat_101(char const input1[], char const input2[], char result[]){

   int s1 = length(input1);
   int s2 = length(input2);
   for(int i = 0; i<s1+1; i++){
      result[i] = input1[i];
   }
   for(int i = s1; i<s1+s2; i++){
      result[i] = input2[i-s1];
   }  
    
   result[s1+s2] = 0;
}



