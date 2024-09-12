/////////////////////////////////////////////////////////////
//
// Programmer: Peter Knipper
// Date: 04/21/2024
// Name: UFO.cpp
// Description: Defines functions for UFO class
//
/////////////////////////////////////////////////////////////

#include "UFO.h"

bool UFO::onScreen = false;
int UFO::timerUFO = 1200;
SoundBuffer UFO::n1;
Sound UFO::approachingUFO;

//default constructor
UFO::UFO() {
    setName("UFO");
    side = (rand()%2);
    onScreen = true;

    if (side){
        setDx(5);
    }

    if(!side){
        setDx(-5);
    }

    approachingUFO.play();
}

/////////////////////////////////////////////////////////////
// UFO::update
// Description: << updates position of UFO objects, calls the parent function to update the animation >>
// Inputs: << uses current x and dx, to determine new position >>
// Output: << modifies all positions in place >>
//
/////////////////////////////////////////////////////////////
void UFO::update() {
    //update position
    setX(getX()+getDx());

    //schedule for deletion if offscreen
    if (getX()>W || getX()<0 || getY()>H || getY()<0) {
        setLife(0);
    }
}

//default destructor
UFO::~UFO(){
    onScreen = false;
    timerUFO = 1200;
    approachingUFO.stop();
}

/////////////////////////////////////////////////////////////
// loadSounds
// Description: << loads the sounds for the UFO >>
// Inputs: << uses "sounds/lost_in_space_danger.ogg" to set soundbuffer n1, uses n1 to set the approachingUFO sound>>
// Output: << modifies all sounds in place; returns 0 on success and EXIT_FAILURE on failure >>
//
/////////////////////////////////////////////////////////////
int UFO::loadSounds(){
    n1.loadFromFile("sounds/lost_in_space_danger.ogg");
    if (!n1.loadFromFile("sounds/lost_in_space_danger.ogg")){
        return -1;
    }

    approachingUFO.setBuffer(n1);
    approachingUFO.setLoop(true);
    return 0;
}

bool UFO::onLeft() const {
    return side;
}

void UFO::setSide(bool side) {
    UFO::side = side;
}

bool UFO::isOnScreen() {
    return onScreen;
}

void UFO::setOnScreen(bool onScreen) {
    UFO::onScreen = onScreen;
}

int UFO::getTimerUfo() {
    return timerUFO;
}

void UFO::setTimerUfo(int timerUfo) {
    timerUFO = timerUfo;
}

/////////////////////////////////////////////////////////////
// countdown
// Description: << decrements the timer >>
// Inputs: << uses timerUFO >>
// Output: << modifies in place >>
//
/////////////////////////////////////////////////////////////
void UFO::countdown(){
    if (timerUFO > 0) {
        timerUFO--;
    }
}

