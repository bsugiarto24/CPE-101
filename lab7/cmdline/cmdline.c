//Bryan Sugiarto CPE101-05 Lab7

#include <stdio.h>

void print_all(int argc, char *argv[]){
   for(int i = 0; i<argc; i++){
      printf("arg %d: %s\n",i,argv[i]);
   }  
} 

int main(int argc, char *argv[]){
   print_all(argc, argv);
   return 1;
} 


