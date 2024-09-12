/////////////////////////////////////////////////////////////
//
// Programmer: Peter Knipper
// Date: 04/21/2024
// Name: bullet.cpp
// Description: Defines functions for bullet class
//
/////////////////////////////////////////////////////////////

#include "bullet.h"

//default constructor
bullet::bullet(){
    //set name
    setName("bullet");
}

/////////////////////////////////////////////////////////////
// bullet::update
// Description: << updates position of bullet objects, deletes bullet object if offscreen, calls the parent function to update the animation >>
// Inputs: << uses current x,y and dx, dy to determine new position >>
// Output: << modifies all positions in place >>
//
/////////////////////////////////////////////////////////////
void bullet::update(){
    //update speed
    setDx(cos(getAngle()*DEGTORAD)*6);
    setDy(sin(getAngle()*DEGTORAD)*6);

    // angle+=rand()%6-3;
    //update position
    setX(getX()+getDx());
    setY(getY()+getDy());

    //schedule for deletion if offscreen
    if (getX()>W || getX()<0 || getY()>H || getY()<0) {
        setLife(0);
    }

    Entity::update();
}