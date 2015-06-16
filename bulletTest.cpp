/****************************************
 * UI TEST
 * Just a simple program to test the user
 * interface consisting of uiDraw and uiInteract
 ***************************************/


#include "point.h"
#include "uiInteract.h"
#include "uiDraw.h"
#include "bullet.h"
using namespace std;

Bullet::Bullet() : dead(false)
{
   pt.setX(pt.getXMin() + 10);
   pt.setY((pt.getYMax() - pt.getYMin()) / 2.0);

   vector.getMag();
   vector.getAngle();
};

void Bullet::draw()
{
}
void Bullet::advance()
{
   pt.setX(pt.getX() + 1);
   pt.setY(pt.getY() + 1);
}
void Bullet::isDead()
{
}
void Bullet::kill()
{
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

   // draw
   drawDot(pBullet->pt);

}


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
