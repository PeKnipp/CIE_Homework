/////////////////////////////////////////////////////////////
//
// Programmer: Peter Knipper
// Date: 04/21/2024
// Name: player.cpp
// Description: Defines functions for player class
//
/////////////////////////////////////////////////////////////


#include "player.h"

bool player::invinciblility = false;
unsigned int player::invinciblilityFramesDuration = 180;

//default constructor
player::player(){
    //set player name
    setName("player");
    invinciblility = false;
    invinciblilityFramesDuration = 180;
}

/////////////////////////////////////////////////////////////
// player::update
// Description: << updates position of player objects, calls the parent function to update the animation >>
// Inputs: << uses current x,y, speed, and dx, dy to determine new position >>
// Output: << modifies all positions in place >>
//
/////////////////////////////////////////////////////////////
void player::update(){
    //player movement
    //while holding space (thrust = true), accelerate in direction of angle
    if (thrust){
        setDx(getDx()+cos(getAngle()*DEGTORAD)*0.2);
        setDy(getDy()+sin(getAngle()*DEGTORAD)*0.2);
    }

        //while not holding space, gradually slow down
    else{
        setDx(getDx()*0.99);
        setDy(getDy()*0.99);
    }

    //set a maximum player speed
    int maxSpeed=15;

    //calculate player's current speed
    float speed = sqrt(getDx()*getDx()+getDy()*getDy());

    //compare current speed to the max
    if (speed>maxSpeed){
        setDx(getDx() * maxSpeed/speed);
        setDy(getDy() * maxSpeed/speed);
    }

    //set new location
    setX(getX()+getDx());
    setY(getY()+getDy());


    //if player goes offscreen, wrap around
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
}

/////////////////////////////////////////////////////////////
// player::draw
// Description: << Displays player object with invincibility shield to the screen, calls parent function for basic display >>
// Inputs: << uses private bool invincibility to determine if player needs shield displayed >>
// Output: << outputs images to the screen >>
//
/////////////////////////////////////////////////////////////
void player::draw(sf::RenderWindow &app) {

    Entity::draw(app);
    //add hitbox to entity
    CircleShape circle(getR());
    circle.setFillColor(Color(25,225,25,150));
    circle.setPosition(getX(),getY());

    //center hitbox on entity
    circle.setOrigin(getR(),getR());

    //uncomment below line to show hitboxes
    if (invinciblility == true) {
        app.draw(circle);
    }
}

bool player::hasThrust() const {
    return thrust;
}

void player::setThrust(bool thrust) {
    player::thrust = thrust;
}

bool player::isInvincible() {
    return invinciblility;
}

void player::setInvinciblility(bool invinciblility) {
    player::invinciblility = invinciblility;
}

unsigned int player::getInvinciblilityFramesDuration() {
    return invinciblilityFramesDuration;
}

void player::setInvinciblilityFramesDuration(unsigned int invinciblilityFramesDuration) {
    player::invinciblilityFramesDuration = invinciblilityFramesDuration;
}
