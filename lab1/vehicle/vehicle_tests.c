#include <stdio.h>
#include "checkit.h"
#include "vehicle.h"

void test_cases(void)
{
   struct vehicle v = create_vehicle(4,13.3, 2, 0);
   checkit_int (v.numWheels, 4);
   checkit_double (v.gas, 13.3);
   checkit_int (v.doors, 2);
   checkit_int (v.roof, 0);

}

int main(int argc, char **argv)
{
   test_cases();

   return 0;
}
