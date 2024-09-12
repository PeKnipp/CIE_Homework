/////////////////////////////////////////////////////////////
//
// Programmer: Peter Knipper
// Date: 04/21/2024
// Name: UFO.h
// Description: Declares variables and functions for UFO class
//
/////////////////////////////////////////////////////////////

#ifndef ASTEROIDS_UFO_H
#define ASTEROIDS_UFO_H
#include "Entity.h"
#include "constants.h"
#include <SFML/Audio.hpp>

class UFO: public Entity {
public:
    UFO();

    void update();

    virtual ~UFO();

    static int loadSounds();

    bool onLeft() const;

    void setSide(bool side);

    static bool isOnScreen();

    static void setOnScreen(bool onScreen);

    static int getTimerUfo();

    static void setTimerUfo(int timerUfo);

    static void countdown();

private:
    bool side = 0;
    static int timerUFO;
    static bool onScreen;
    static SoundBuffer n1;
    static Sound approachingUFO;
};


#endif //ASTEROIDS_UFO_H
