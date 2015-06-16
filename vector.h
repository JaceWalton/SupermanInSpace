/***********************************************************************
 * Header File:
 *    Vector: Implements the class Vector and includes any libraries needed 
 * Author:
 *    Jace Walton
 * Summary:
 *    Everything we need to know about implementing Vecotr.
 ************************************************************************/

#ifndef VECTOR_H
#define VECTOR_H

#include <string>     // To display text on the screen
#include "point.h"    // Where things are drawn
using std::string;

class Vector
{
  Public:
   void getPoint();
   void getDx();
   void getDy();
   void getMag();
   void getAngle();
   void setDx();
   void setDy();
   void advance();
   void difference();
  Private:
   float point;
   float dx;
   float dy;
 };

#endif // SKEET_H
