###############################################################
# Program:
#     Project 4 Asteroids
#     Brother Helfrich, CS165
# Author:
#     Nathaniel Mason
#     Jace Walton
# Summary:
#     Nathaniel Mason: I worked on the velocity cpp and header 
#     files and I worked on the asteroids cpp and header files
#     specifically handleing the drawing and movement(increment).
#     I also worked on drawing the drone and worked on it movement
#     and I worked somewhat on superman and kryptonites movement
#     and drawing. Lastly I worked somewhat on the game.cpp file
#     working on putting the objects on screen and calling their
#     movement and I worked on the callback function as well. In
#     uiDraw.cpp I worked on drawing the drone and worked somewhat
#     in the superman, kryptonite, missile functions and how the get
#     Dx and Dy.
#
#     Jace Walton: I did most of the drawing apart from the Drone
#     I also designed to algorythm for the homing missle and how the
#     missile points at superman. also how to dorne moves an points as 
#     superman. as well as the "collsion" which just stops drawing him.
#     I have found that deleating a pointer causes a segmentation fault
#     I could not figure this out so we left is as is.
#     and most of the Game class as far as we could the origial plan but was 
#     unable to figur out how to used pointer to create the objects.
#
#     Extra Credit: We changed our ship to Superman and fires lasers.
#     We also have krptonite, a drone and a homing missile.
#
#     Estimated: 40.0 hrs
#     Actual:    60.0 hrs
#       pointers to objects and collision.  
###############################################################

###############################################################
# Programs:
#   
#    Superman In Space:  this is the game executable  
###############################################################

SupermanInSpace : uiDraw.o uiInteract.o point.o superman.o game.o asteroid.o velocity.o
	g++ -o SupermanInSpace uiDraw.o uiInteract.o point.o superman.o game.o asteroid.o velocity.o -lglut -lGLU

#	tar -cf SupermanInSpace.tar *.h *.cpp makefile

###############################################################
# Individual files
#    uiDraw.o      Draw polygons on the screen and do all OpenGL graphics
#    uiInteract.o  Handles input events
#    point.o       The position on the screen
#    superman.o    all movebles that are not asteroids
#    asteroid.o    all asteroids
#    velocity.o    the velocity vectors
#    game.o        the game to impliment the rules
###############################################################
uiInteract.o : uiInteract.cpp uiInteract.h point.h
	g++ -c uiInteract.cpp

uiDraw.o : uiDraw.cpp uiDraw.h point.h
	g++ -c uiDraw.cpp

point.o : point.cpp point.h
	g++ -c point.cpp

superman.o : superman.cpp superman.h velocity.h point.h uiInteract.h uiDraw.h
	g++ -c superman.cpp

asteroid.o : asteroid.cpp asteroid.h velocity.h point.h uiInteract.h uiDraw.h
	g++ -c asteroid.cpp

velocity.o : velocity.cpp velocity.h
	g++ -c velocity.cpp

game.o : game.cpp game.h velocity.h inertia.h point.h uiInteract.h
	g++ -c game.cpp
###############################################################
# General rules
###############################################################
clean :
	rm superman *.o *.tar

all : SupermanInSpace

