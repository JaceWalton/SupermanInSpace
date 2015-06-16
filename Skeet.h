/***********************************************************************
 * Header File:
 *    Skeet: Implements the class Skeet and includes any libraries needed 
 * Author:
 *    Jace Walton
 * Summary:
 *    Everything we need to know about implementing skeetshooter, including
 *    drawing and interacting.
 ************************************************************************/

#ifndef SKEET_H
#define SKEET_H

#include <string>     // To display text on the screen
#include "point.h"    // Where things are drawn
using std::string;

class Skeet
{
  Public:
   Skeet();
   draw();
   interact();
   advance();
  Private:
   float rifle;
   float bird;
   int bullets;
   bool hit;
   bool miss;  
};

#endif // SKEET_H
