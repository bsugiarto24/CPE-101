// Bryan Sugiarto CPE 101-05 Lab 3
#include <stdio.h>
#include "checkit.h"
#include "logic.h"

void test_is_even(void)
{
   checkit_int(is_even(2),1);
   checkit_int(is_even(5),0);
}

void test_is_between(void)
{
   checkit_int(is_between(1,0,3),1);
   checkit_int(is_between(5,5,33),0);
   checkit_int(is_between(4,3,4),0);
   checkit_int(is_between(4,73,233),0);
}

void test_in_an_interval(void)
{
   checkit_int(in_an_interval(0),0);
   checkit_int(in_an_interval(2),1);
   checkit_int(in_an_interval(4),1);
   checkit_int(in_an_interval(9),0);
   checkit_int(in_an_interval(11),0);
   checkit_int(in_an_interval(12),0);
   checkit_int(in_an_interval(13),1);
   checkit_int(in_an_interval(19),1);
   checkit_int(in_an_interval(24),0);
   checkit_int(in_an_interval(47),0);
   checkit_int(in_an_interval(56),1);
   checkit_int(in_an_interval(92),0);
   checkit_int(in_an_interval(97),0);
   checkit_int(in_an_interval(101),1);
   checkit_int(in_an_interval(102),1);
   checkit_int(in_an_interval(103),1);
   checkit_int(in_an_interval(104),0);
}

void test_cases(void)
{
   test_is_even();
   test_is_between();
   test_in_an_interval();
}

int main(int argc, char **argv)
{
   test_cases();

   return 0;
}
