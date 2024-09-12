/////////////////////////////////////////////////////////////
//
// Programmer: Peter Knipper
// Date: 04/21/2024
// Name: asteroid.cpp
// Description: Defines functions for asteroid class
//
/////////////////////////////////////////////////////////////

#include "asteroid.h"

//static count
int unsigned asteroid::asteroidCount = 0;

//default constructor
asteroid::asteroid(){
    //set name and random speed
    setDx(rand()%8-4);
    setDy(rand()%8-4);
    setName("asteroid");
    asteroidCount++;
}

/////////////////////////////////////////////////////////////
// asteroid::update
// Description: << updates position of asteroid objects, calls the parent function to update the animation >>
// Inputs: << uses current x,y and dx, dy to determine new position >>
// Output: << modifies all positions in place >>
//
/////////////////////////////////////////////////////////////
void asteroid::update(){
    //update position
    setX(getX()+getDx());
    setY(getY()+getDy());

    //wrap around screen
    if (getX()>W) {
        setX(0);
    }

    if (getX()<0) {
        setX(W);
    }

    if (getY()>H) {
        setY(0);
    }

    if (getY()<0) {
        setY(H);
    }

    Entity::update();
}

//default constructor
asteroid::~asteroid(){
    asteroidCount--;
}

unsigned int asteroid::getAsteroidCount() {
    return asteroidCount;
}

void asteroid::setAsteroidCount(unsigned int asteroidCount) {
    asteroid::asteroidCount = asteroidCount;
}
