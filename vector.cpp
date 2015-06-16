/****************************************
 * UI TEST
 * Just a simple program to test the user
 * interface consisting of uiDraw and uiInteract
 ***************************************/


#include "point.h"
#include "uiInteract.h"
#include "uiDraw.h"
#include "vector.h"
using namespace std;


void Vector::getPoint()
{
}
void Vector::getDx()
{
}
void Vector::getDy()
{
}
void Vector::getMag()
{
}
void Vector::getAngle()
{
}
void Vector::setDx()
{
}
void Vector::setDy()
{
}
void Vector::advance()
{
}
void Vector::difference()
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

/*
   Vector * pVector = (Vector *)p;  // cast the void pointer into a known type

   pBullet->pt.setX(0);
   pBullet->pt.setY(0);   

   // draw
   drawDot(pBullet->pt);
*/
}


/*********************************
 * Main is pretty sparse.  Just initialize
 * my ball type and call the display engine.
 * That is all!
 *********************************/
int main(int argc, char ** argv)
{
   Interface ui(argc, argv, "Skeet");  // initialize OpenGL
   Vector vector;                           // initialize the game state
   ui.run(callBack, &vector);             // set everything into action

   return 0;
}
