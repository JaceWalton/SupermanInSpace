 /***********************************************************************
* Author:
*    Jace Walton
*    Nathaniel Mason
* Summary: 
*    This program inplements the class asteroid 
*   
************************************************************************/

#include "asteroid.h"

/***********************************************************************
 *  Constructor for all our asteroids. Sets isHit and isDead to false.
 *
 ***********************************************************************/
Asteroid::Asteroid()
{
   isHit = false;
   isDead = false;
}


 /***********************************************************************
* Summary: 
*    This program inplements the class LgAst
************************************************************************/

/***********************************************************************
 * Constructor for our Large Asteroids.
 ***********************************************************************/
LgAst::LgAst()

{
   speed = random(3, 7);
   direction = random(0, 360);
   pt.setWrap(true);
   isHit = false;
   isDead = false;
   pt.setX(-400);
   pt.setY(random(-400, 400));
   
}

/***********************************************************************
 * draw draws our Large Asteroid to the screen.
 ***********************************************************************/
void LgAst::draw()
{
   drawAsteroidLrg(pt, v.getAngle());
  
}

/***********************************************************************
 * increment handles Large Asteroids movement
 ***********************************************************************/
void LgAst::increment()
{
   v.setAngle(v.getAngle() + speed);

   v.setVelocity(direction, speed);
      
   pt.setX(pt.getX() + v.getDx());
   pt.setY(pt.getY() + v.getDy());

}

 /***********************************************************************
* Author:
*    Jace Walton
*    Nathaniel Mason
* Summary: 
*    This program inplements the class MedAst
************************************************************************/

/***********************************************************************
 * Constructor for our Medium Asteroids.
 ***********************************************************************/
MedAst::MedAst()
{
   speed = random(3, 7);
   direction = random(0, 360);
   pt.setWrap(true);
   isHit = false;
   isDead = false;
   pt.setX(-400);
   pt.setY(random(-400, 400));
}

/***********************************************************************
 * draw draws our Medium Asteroid to the screen.
 ***********************************************************************/
void MedAst::draw()
{
   drawAsteroidMed(pt, v.getAngle());
}

/***********************************************************************
 * increment handles Medium Asteroids movement
 ***********************************************************************/
void MedAst::increment()
{
   v.setAngle(v.getAngle() + speed);

   v.setVelocity(direction, speed);
      
   pt.setX(pt.getX() + v.getDx());
   pt.setY(pt.getY() + v.getDy());

}

 /***********************************************************************
* Author:
*    Jace Walton
*    Nathaniel Mason
* Summary: 
*    This program inplements the class SmAst
************************************************************************/

/***********************************************************************
 * Constructor for our Small Asteroids.
 ***********************************************************************/
SmAst::SmAst()
{
   speed = random(3, 7);
   direction = random(0, 360);
   pt.setWrap(true);
   isHit = false;
   isDead = false;
   pt.setX(-400);
   pt.setY(random(-400, 400));
}

/***********************************************************************
 * draw draws our Small Asteroid to the screen.
 ***********************************************************************/
void SmAst::draw()
{
   drawAsteroidSml(pt, v.getAngle());
}

/***********************************************************************
 * increment handles Small Asteroids movement
 ***********************************************************************/
void SmAst::increment()
{
   v.setAngle(v.getAngle() + speed);

   v.setVelocity(direction, speed);
      
   pt.setX(pt.getX() + v.getDx());
   pt.setY(pt.getY() + v.getDy());
   
}

 /***********************************************************************
* Author:
*    Jace Walton
*    Nathaniel Mason
* Summary: 
*    This program inplements the class Kryptonite
************************************************************************/

/***********************************************************************
 * Constructor for our Kryptonite.
 ***********************************************************************/
Kryptonite::Kryptonite()
{
   speed = random(3, 5 );
   direction = random(0, 360);
   isKrypt = true;              //if isKrypt then superman will be damaged
                                // by asteroids else he can punch them
   pt.setWrap(true);
   isHit = false;
   isDead = false;
   pt.setX(-400);
   pt.setY(random(-400, 400));
               
}

/***********************************************************************
 * draw draws our Kryptonite to the screen.
 ***********************************************************************/
void Kryptonite::draw()
{
   drawKryptonite(pt, v.getAngle());
}

/***********************************************************************
 * increment handles Kryptonites movement
 ***********************************************************************/
void Kryptonite::increment()
{
   v.setAngle(v.getAngle() + 2);

   v.setVelocity(direction, speed);
      
   pt.setX(pt.getX() + v.getDx());
   pt.setY(pt.getY() + v.getDy());
}

