/***********************************************************************
 * Header File:
 *    Skeet: Implements the class Rifle and includes any libraries needed 
 * Author:
 *    Jace Walton
 * Summary:
 *    Everything we need to know about rilfe, including
 *    drawing and rotating.
 ************************************************************************/

#ifndef RIFLE_H
#define RIFLE_H

#include <string>     // To display text on the screen
#include "point.h"    // Where things are drawn
using std::string;

class Rifle
{
  Public:
   Rifle();
   move();
   draw();
   getAngle();
  Private:
   float angle;
};

#endif // BULLET_H
