#include <stdio.h>
#include "checkit.h"
#include "funcs.h"

void test_square(void){
   checkit_double(square(3),9.0);
   checkit_double(square(1.2),1.44);
}

void test_f(void){
   checkit_double(f(1), 9.0);
   checkit_double(f(.5),2.75);
}

void test_g(void){
   checkit_double(g(1,3),10.0);
   checkit_double(g(2.5,1.1),7.46);
}

void test_hypotenuse(void){
   checkit_double(hypotenuse(3,4),5);
   checkit_double(hypotenuse(3.45,1.2),3.652738699);
}

void test_is_positive(void){
   checkit_int(is_positive(-3),0);
   checkit_int(is_positive(2),1);
}

void test_cases(void)
{
   test_square();
   test_f();
   test_g();
   test_hypotenuse();
   test_is_positive();
}


int main(int argc, char **argv)
{
   test_cases();

   return 0;
}
