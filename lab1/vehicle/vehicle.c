#include "vehicle.h"

struct vehicle create_vehicle(int w, double g, int d, int r){
   struct vehicle v;
   v.numWheels = w;
   v.gas = g;
   v.doors = d;
   v.roof = r;
   return v;
}
