/****************************************
 * Header file Laser 
 * declairs prototypes and defines inline
 * functions of the program.
 ***************************************/

#ifndef _Asteroid_
#define _Asteroid_

#include "inertia.h"
#include "point.h"
#include "uiInteract.h"
#include "uiDraw.h"
#include "velocity.h"
using namespace std;

class Asteroid : public Inertia
{
  public:
   Asteroid();
   void draw()                                   {               }  
   bool hit()                                    { isHit  = true;}
   void kill()                                   { isDead = true;}
   void increment()                              {               }
   void interact(const Interface *pUI, void *p)  {               }
   Point getPt()                                 { return pt;    }
  protected:
   Point pt;
   int angle;
   Velocity v;
   bool isHit;
   bool isDead;
   int direction;
   float speed;
   
};

class LgAst : public Asteroid
{
  public:
   LgAst();
   void draw();  
   bool hit()                                    { isHit  = true;}
   void kill()                                   { isDead = true;}
   void interact()                               {               }             
   void increment();
  private:
   Point pt;
   int angle;
   Velocity v;
   bool isHit;
   bool isDead; 
};

class MedAst : public Asteroid
{
  public:
   MedAst();
   void draw();  
   bool hit()                                    { isHit  = true;}
   void kill()                                   { isDead = true;}
   void interact()                               {               }
   void increment();
  private:
   Point pt;
   int angle;
   Velocity v;
   bool isHit;
   bool isDead; 
};

class SmAst : public Asteroid
{
  public:
   SmAst();
   void draw();  
   bool hit()                                    { isHit  = true;}
   void kill()                                   { isDead = true;}
   void interact()                               {               }
   void increment();
  private:
   Point pt;
   int angle;
   Velocity v;
   bool isHit;
   bool isDead; 
};

class Kryptonite : public Asteroid
{
  public:
   Kryptonite();
   void draw();  
   bool hit()                                    { isHit  = true;  }
   void kill()                                   { isDead = true;  }
   bool getIsKrypt()                             { return isKrypt; }
   void interact()                               {                 }
   void increment();
  private:
   bool isKrypt;
   Point pt;
   int angle;
   Velocity v;
   bool isHit;
   bool isDead; 
};

#endif // _Asteroid_
