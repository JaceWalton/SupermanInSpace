/****************************************
 * Header file Game 
 * declairs prototypes and defines inline
 * functions of the Game class.
 ***************************************/
#ifndef _GAME_
#define _GAME_

#include "inertia.h"
#include "point.h"
#include "uiInteract.h"
#include "superman.h"
#include "velocity.h"
#include "asteroid.h"
#include <list>
#include <iostream>

#define PI 3.1451
#define AMMO 5

using namespace std;

class Game 
{
  public:
   Game();
   void draw();  
   void increment();
   void interact(const Interface *pUI, void *p);
   void aimMissile();
   void aimDrone();
   bool collision(Point pt1, Point pt2);
  private:
   Point point;
   Velocity velocity;
   Superman superman;
   Drone drone;
   Missile missile;
   //these were to be pointer so we could create and deleate them
   //as we need but this was easier said than done. 
   Laser  *laser;
   LgAst  *lgAst;;
   MedAst *medAst;
   SmAst  *smAst;
   Kryptonite *kryptonite;
   std::list <Inertia*> objects; // unable to figure out list of objects...
};

#endif 
