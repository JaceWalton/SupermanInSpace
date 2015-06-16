/****************************************
 * Header file for all non asteroids IE
 * things dont constanly rotate
 * declairs prototypes and defines inline
 * funcitions 
 ***************************************/
#ifndef _SUPERMAN_            
#define _SUPERMAN_
#include "inertia.h"
#include "point.h"
#include "uiInteract.h"
#include "uiDraw.h"
#include "velocity.h"
#include <iostream>    //for cout to debug and find errors 
using namespace std;

#define MISSILE_SPD 5
class Superman : public Inertia
{                                    
  public:
   Superman();
   void draw();  
   void interact(const Interface *pUI, void *p);
   void increment();
   bool hit()                                     { isHit = true;       }
   bool kill()                                    { isDead = true;      }

   //getters
   bool  getIsDead()                              { return isDead;      }
   Point getPt()                                  { return pt;          }
   float getX()                                   {return pt.getX();    }
   float getY()                                   {return pt.getY();    }   
   int   getAngle()                               { return v.getAngle();}
  protected:
   Point pt;
   Velocity thrust;
   Velocity v;
   bool isHit;
   bool isDead;
   int frLive;
   
};
#endif //_SUPERMAN_


/****************************************
 * Header file for Laser
 * declairs prototypes and defines inline
 * funcitions 
 ***************************************/

#ifndef _LASER_
#define _LASER_
class Laser : public Superman
{
  public:
   Laser();
   void draw();  
   bool hit()                                    { isHit  = true; }
   void regenerate()                         { isDead = false; frLive = 30;}
   void kill()                                   { isDead = true; }
   Velocity setVelocity(int a, float sp)         { v.setVelocity(a, sp);}
   void increment();
   void interact(const Interface *pUI, void *p);

   //getters
   bool getIsDead()                              { return isDead;}
   Point getPt()                                 { return pt;    }

   //setters
   void setAngle(int a)                          { v.setAngle(a);}
   void setX(float a)                            { pt.setX(a);   }
   void setY(float a)                            { pt.setY(a);   }
   
  private:
   Point pt;
   Velocity v;
   
};
#endif // _LASER_


/****************************************
 * Header file for Missile
 * declairs prototypes and defines inline
 * funcitions 
 ***************************************/

#ifndef _MISSILE_
#define _MISSILE_
class Missile : public Superman
{
  public:
   Missile();
   void draw();
   void interact(const Interface *pUI, void *p) {               }
   void increment();
   bool hit()                                   { isHit  = true;}
   void kill()                                  { isDead = true;}

   //getter    Game needs to compair missile's point to superman's for homming
   Point getPt()                                { return pt;    }

   //setter
   void setAngle(int theta)                     { v.setAngle(theta);}
   
  private:
   Point pt;
   Velocity v;
   
};

#endif //_MISSILE_


/****************************************
 * Header file for Drone
 * declairs prototypes and defines inline
 * funcitions 
 ***************************************/

#ifndef _DRONE_
#define _DRONE_
class Drone : public Superman
{
  public:
   Drone();
   void draw();
   void interact(const Interface *pUI, void *p) {               }
   void increment();
   bool hit()                                   { isHit  = true;}
   void kill()                                  { isDead = true;}
   
   //getter
   Point getPt()                                { return pt;    }

   //setter
   void setAngle(int theta)                     { angle = theta;}
   
  private:
   int angle;
   Point pt;
   Velocity v;
};

#endif //_DRONE_
