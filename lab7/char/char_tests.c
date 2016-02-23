//Bryan Sugiarto CPE101-05 Lab7

#include "checkit.h"
#include "char.h"

void test_lower(void){
   checkit_int(is_lower_101('c'),1);
   checkit_int(is_lower_101('C'),0);
   checkit_int(is_lower_101('3'),0);
}


void test_rot13(void){
   checkit_char(char_rot_13('c'),'p');
   checkit_char(char_rot_13('T'),'G');
   checkit_char(char_rot_13('a'),'n');
}

void test_cases(void){
   test_lower();
   test_rot13();
}

int main(int argc, char **argv){
   test_cases();
   return 1;
}


