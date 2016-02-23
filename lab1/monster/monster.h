#ifndef MONSTER_H
#define MONSTER_H

struct monster{
   int numEyes;
   int numArms;
   double height;
   int numTails;
};
struct monster create_monster(int numEyes, int numArms, double height, int numTails);
 
#endif
