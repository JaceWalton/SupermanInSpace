/***********************************************************************
 * Header File:
 *    Skeet: Implements the class Bird and includes any libraries needed 
 * Author:
 *    Jace Walton
 * Summary:
 *    Everything we need to know about Bird, including
 *    drawing and moving.
 ************************************************************************/

#ifndef BIRD_H
#define BIRD_H

#include <string>     // To display text on the screen
#include "point.h"    // Where things are drawn
using std::string;

class Bird
{
  Public:
   Bird();
   regenerate();
   draw();
   advance();
   isDead();
   kill();
  Private:
   float vector;
   bool dead;  
};

#endif // Bird_H
