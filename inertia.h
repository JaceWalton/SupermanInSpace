/****************************************
 * Header file for Inerita 
 * This is class has mostly pure vurtual  
 * this prevents the slicing problem. 
 ***************************************/

#ifndef _Inertia_
#define _Inertia_

#include "point.h"
#include "uiInteract.h"
#include "uiDraw.h"
using namespace std;

class Inertia
{
  public:
   Inertia()      {};
   virtual bool hit()        = 0;
   virtual void draw()       = 0;
   virtual void interact(const Interface *pUI, void *p)   = 0;
   virtual void increment()  = 0;
  protected:
   bool isDead;
   bool isHit;
   //Velocity v;
   Point pt;
   // int angle;
};
#endif // _Inertia_
