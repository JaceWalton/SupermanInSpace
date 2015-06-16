#ifndef _Velocity_
#define _Velocity_
#include <cmath>
#include <algorithm>
#include "point.h"
using namespace std;


class Velocity : public Point
{

  public:
   Velocity(float dx = 0, float dy = 0, int angle = 0, int speed = 0);
   Velocity(Velocity & velocityOrig);
   ~Velocity();
   const float getDx()  const { return dx; };
   const float getDy()  const { return dy; };
   const int getAngle() const {return angle;};
   const int getSpeed() const {return speed;};
   // void setX(int a)         { x = a;      }       
   // void setY(int a)         { y = a;      }
   void setVelocity(int angle, float speed);
   //void setDy();
   void setAngle(int NewAngle);
   void setSpeed(int speed);
   float minimumDistance(Velocity a, Velocity b);
   void operator  += (Velocity & rhs);
   Velocity operator + (Velocity & v);
   Velocity operator - (Velocity & v);
  
   
  private:
   Point point;
   float dx;
   float dy;
   int angle;
   int speed;
   // int x;
   //int y;
};       

#endif

