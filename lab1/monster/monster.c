#include <stdio.h>
#include "monster.h"

struct monster create_monster(int eyes, int arms, double h, int tails){

   struct monster m;
   m.numEyes = eyes;
   m.numArms = arms;
   m.height = h;
   m.numTails = tails;
   return m;
}

