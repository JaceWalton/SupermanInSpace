/***********************************************************************
 * Header File:
 *    Bullet: Implements the class Bullet and includes any libraries needed 
 * Author:
 *    Jace Walton
 * Summary:   
 *    Everything we need to know about Bullets, including
 *    drawing and moving.
 ************************************************************************/

#ifndef BULLET_H
#define BULLET_H

#include <string>     // To display text on the screen
#include "point.h"    // Where things are drawn
using std::string;

class Bullet
{
  public:
   Bullet();
   void fire(float angle);
   void draw(); 
   void advance();
   void isDead();
   void kill();
  private:
   Vector vector;
   bool dead;
   Point pt;

};

#endif // BULLET_H
