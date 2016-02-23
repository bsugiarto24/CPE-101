#include <stdio.h>
#include "checkit.h"
#include "monster.h"

void test_cases(void)
{
   struct monster l= create_monster(2,3,4.5,6);
   
   checkit_int(l.numEyes, 2);
   checkit_int(l.numArms,3);
   checkit_double(l.height, 4.5);
   checkit_int(l.numTails, 6);
}

int main(int argc, char **argv)
{
   test_cases();

   return 0;
}
