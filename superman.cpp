/***********************************************************************
* Superman c++ file
* Author:
*    Jace Walton
* Summary: 
*    this file empiments all of the objects that need a constant orientation
*    IE everyting except the asteroids and kryptonite. 
*    This handles all the interacton between the user and superman
************************************************************************/

#include "superman.h"

/****************************************
 * default constuctor for Superman
 * this sets some variables when a superman object is made
 ***************************************/
Superman::Superman()
{
   v.setAngle(0);
   pt.setWrap(true);
   isHit = false;
   isDead = false;
}
/****************************************
 * this function calls draw superman for
 * uiDraw this enables draw to be called 
 * with no parpamiters needed.
 ***************************************/
void Superman::draw()
{
   drawSuperman(pt, v.getAngle());
}
/****************************************
 * how superman interacts with the other 
 * objects
 ***************************************/
void Superman::interact(const Interface *pUI, void *p)
{
   if (pUI->isRight())
      v.setAngle(getAngle() - 5);
   if (pUI->isLeft())
      v.setAngle(getAngle() + 5);
   if (pUI->isUp())
   {
      Velocity thrust(v);
      thrust.setVelocity(v.getAngle() - 90 , .5);
      v += thrust;
   }

   //superman enters hyperspace
   //he comes out in at a random point in a random direction
   //with the same velocity vector he had before
   //WATCHOUT!!!!!!!!!!!!!!!!!!!!!!
   //you could end up teleporting into an asteroid or worse!
   //Kryptonite!!!     use as only last resourse!
   if (pUI->isDown())   
   {
      pt.setX(pt.getX() + random(-400, 400));
      pt.setY(pt.getY() + random(-400, 400));
      v.setAngle(getAngle() + random(0, 360));
      isDead = false;
   }
}

/****************************************
 * how superman interacts with the other 
 * objects
 ***************************************/
void Superman::increment()
{
   pt.setX(pt.getX() + v.getDx());
   pt.setY(pt.getY() + v.getDy());
}

 /***********************************************************************
* Laser c++ file
* Author:
*    Jace Walton
*    Nathaniel Mason
* Summary: 
*    This program inplements the class inertia IE any object that moves 
*    and is drawn on the screen. 
************************************************************************/


/****************************************
 * default constructor for Laser class
 ***************************************/
Laser::Laser()
{
   frLive = 30;
   pt.setWrap(false);
   isHit = false;
   isDead = true;
   // pt.setX(420);
   //pt.setY(420);
}
/****************************************
 * calls drawLasers to for code symplicity
 ***************************************/
void Laser::draw()
{
   drawLasers(pt, v.getAngle());
}
/****************************************
 * this moves everythings up one frame
 * 
 ***************************************/
void Laser::increment()
{
   frLive--;
   if (frLive < 0)
      kill();
   pt.setX(pt.getX() + v.getDx());
   pt.setY(pt.getY() + v.getDy());
}
/****************************************
 * how Lasers interacts with the other 
 * objects
 ***************************************/
void Laser::interact(const Interface *pUI, void *p)
{

   
}

 /***********************************************************************
* Author:
*    Jace Walton
* Summary: 
*    This program inplements the class Missile 
*   
************************************************************************/


/*******************************************
 * Missile constructor
 *******************************************/
Missile::Missile()
{
   frLive = 90;
   pt.setWrap(true);
   isHit = false;
   isDead = false;
   pt.setX(random(300, 400));
   pt.setY(random(300, 400));
}

/*******************************************
 * Draws the missile
 *******************************************/
void Missile::draw()
{
   drawMissile(pt, v.getAngle());
}

/*******************************************
 * missile will follow superman
 *******************************************/
void Missile::increment()
{
   // frLive--;
   // if (frLive == 0)
   //    kill();

   v.setVelocity(v.getAngle() - 90, MISSILE_SPD);
   pt.setX(pt.getX() + v.getDx());
   pt.setY(pt.getY() + v.getDy());


}



 /***********************************************************************
* Author:
*    Jace Walton
*    Nathaniel Mason
* Summary: 
*    This program inplements the class Drone 
*   
************************************************************************/


/*******************************************
 * Missile constructor
 *******************************************/
Drone::Drone()
{
   frLive = 0;
   pt.setWrap(true);
   isHit = false;
   isDead = false;
   pt.setX(random(100, 300));
   pt.setY(random(100, 300));
}

/*******************************************
 * Draws the missile
 *******************************************/
void Drone::draw()
{
   drawDrone(pt, angle);
}

/*******************************************
 * missile will follow superman
 *******************************************/
void Drone::increment()
{
   frLive++;
   if (frLive % 90 == 0)
      v.setAngle(v.getAngle() + random(0, 360));


   
   Velocity thrust(v);
   thrust.setVelocity(v.getAngle() - 90 , .5);
   v += thrust;
   
   pt.setX(pt.getX() + v.getDx());
   pt.setY(pt.getY() + v.getDy());

   v.setVelocity(v.getAngle(), 5 );

  
   
}

