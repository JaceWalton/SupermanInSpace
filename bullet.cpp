/****************************************
 * UI TEST
 * Just a simple program to test the user
 * interface consisting of uiDraw and uiInteract
 ***************************************/


#include "point.h"
#include "uiInteract.h"
#include "uiDraw.h"
#include "Bullet.h"
#include "vector.h"
using namespace std;


int Bullet::Bullet()

void Bullet::fire(int angle)
{
   x = xMax -10;
   y = yMin +20;

   dx.vector = -cos(angle) * speedBullet;
   dy.vector =  sin(angle) * speedBullet;
   dead = false;
}


/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface *pUI, void * p)
{
	
   Bullet * pBullet = (Bullet *)p;  // cast the void pointer into a known type
  

   pBullet->pt.setX(0);
   pBullet->pt.setY(0);

   

  
   // fire bullet
   if (pUI->isSpace())
      Bullet::fire(vector++);
        
   //draw bullet
   drawDot(pBullet->pt); /*position*/
}










// set the bounds of the drawing rectangle
float Point::xMin = -400.0;
float Point::xMax =  400.0;
float Point::yMin = -400.0;
float Point::yMax =  400.0;

/*********************************
 * Main is pretty sparse.  Just initialize
 * my ball type and call the display engine.
 * That is all!
 *********************************/
int main(int argc, char ** argv)
{
	Interface ui(argc, argv, "Skeet");  // initialize OpenGL
   Bullet bullet;                           // initialize the game state
   ui.run(callBack, &bullet);             // set everything into action

   return 0;
}
