 /***********************************************************************
* Author:
*    Jace Walton
*    Nathaniel Mason
* Summary: 
*    This program inplements the class Game this is where all the magic
*    happens, Game mearly ties everything together. 
*   
************************************************************************/

#include "game.h"
#include <list>
/******************************************
 * Game constructor
 ******************************************/
Game::Game()
{
   std::list <Inertia*> objects;
   laser = new Laser[AMMO];
   lgAst = new LgAst;
   kryptonite = new Kryptonite;
   
   //objects.push_back(new LgAst);
}

/******************************************
 * draws superman
 ******************************************/
void Game::draw()
{
   /*     we tryed to used an itorator loop but this did not work
          so we when back to creating each pointer........
   for (list<Inertia*>::iterator it = objects.begin(); it != objects.end();
        it++)
   {
      (*it)->draw();
   }*/
   
   if(!superman.getIsDead())
      superman.draw();
   if(!laser->getIsDead())
      laser->draw();
   if(!missile.getIsDead())
      missile.draw();
   
   lgAst->draw();
   
   //medAst.draw();
   //smAst.draw();
   kryptonite->draw();
   drone.draw();
   cout << superman.getIsDead() << endl;
   
}

/******************************************
 * increment does something
 ******************************************/
void Game::increment()
{
   if (missile.getIsDead())
      if (collision(superman.getPt(), missile.getPt()))
         superman.kill();
   
   // if (collision(superman.getPt(), kryptonite->getPt()))
   //   superman.kill();
   
   if (collision(kryptonite->getPt(), laser->getPt()))
      kryptonite->kill();
   
   if (collision(missile.getPt(), laser->getPt()))
      missile.kill();
   
   if(!missile.getIsDead())
      missile.increment();
   drone.increment();
   if(!laser->getIsDead())
      laser->increment();

   if(!superman.getIsDead())
   {
      superman.increment();
      if(!missile.getIsDead())
         aimMissile();
      aimDrone();
   }
   
   lgAst->increment();

   //medAst->increment();
   //smAst->increment();
   kryptonite->increment();
   //if (laser->getIsDead())
      // delete laser;
}

/******************************************
 * a quick and dirty was of handling collision
 ******************************************/
bool Game::collision(Point pt1, Point pt2)
{


   // // if the distance between superman and the missile
   // // is less than 70 superman is killed
   // int maxX = max(pt2.getX(), pt1.getX());
   // int minX = min(pt2.getX(), pt1.getX());
   // int adj  = maxX - minX;

   // int maxY = max(pt2.getY(), pt1.getY());
   // int minY = min(pt2.getY(), pt1.getY());
   // int ops  = maxY - minY;

   // int dist = sqrt(adj * adj + ops * ops);
   int distBetwixt;
   int xDist = abs(pt1.getX() - pt2.getX());
   int yDist = abs(pt1.getY() - pt2.getY());
   distBetwixt = sqrt(xDist * xDist + yDist * yDist);
  
   if (distBetwixt < 70)
      return true;
   else
      return false;

}

/*******************************************
 * Handles misslie direction
 *******************************************/
void Game::aimMissile()
{
  
   Point pt = superman.getPt();
   Point pt2 = missile.getPt();
   int a = pt.getX() - pt2.getX();   // the x distance between pt and pt2
   int o = pt.getY() - pt2.getY();   // the y distance between pt and pt2
   int angle = atan2(o, a) * 180 / 3.1415;  //tan is oposite over adjacent

   missile.setAngle(angle - 90);     // oriention was diff for superman
}

/*******************************************
 * Handles Drone direction
 * same as Missile but the drone is not homming
 *******************************************/
void Game::aimDrone()
{
   
   Point pt = superman.getPt();
   Point pt2 = drone.getPt();
   int a = pt.getX() - pt2.getX();  
   int o = pt.getY() - pt2.getY();  
   int angle = atan2(o, a) * 180 / 3.1415;

   drone.setAngle(angle - 90);
}

/******************************************
 * how the user interacts with the programs
 ******************************************/
void Game::interact(const Interface *pUI, void *p)
{
   // if(!superman.getIsDead())
      superman.interact(pUI, p);

   //laser->interact(pUI, p);
   if (pUI->isSpace())
   {
      laser->regenerate();
      //laser set to supermans angle so it will go in his direction
      laser->setAngle(superman.getAngle());
      //laser set to be above superman so it does not appear IN him
      laser->setX(superman.getX() + (cos(superman.getAngle()-90)*PI/180)*51);
      laser->setY(superman.getY() + (sin(superman.getAngle()-90)*PI/180)*51);
      //uses supermans angle to get his same dx & dy to copy his movements
      laser->setVelocity(superman.getAngle() - 90, 20);
   }
   
}

/*********************************************
 * CALLBACK
 * The main interaction loop of the engine.
 * This gets called from OpenGL.  It give us our
 * interface pointer (where we get our events from)
 * as well as a void pointer which we know is our
 * game class.
 *********************************************/
void callBack(const Interface *pUI, void *p)
{
   Game *game = (Game *)p;
   game->draw();
   game->interact(pUI, p);
   game->increment();
  

   return;
}
/*********************************
 * Just initialize the Game class
 * and call the display engine.
 *********************************/
int main(int argc, char ** argv)
{
   Interface ui(argc, argv, "Superman in Space"); // initialize OpenGL
   Game game;                                     // initialize the game state
   ui.run(callBack, &game);                       // set everything into action

   return 0;
}
