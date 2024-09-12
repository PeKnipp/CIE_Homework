/////////////////////////////////////////////////////////////
//
// Programmer: Peter Knipper
// Date: 04/21/2024
// Name: player.h
// Description: Declares variables and functions for player class
//
/////////////////////////////////////////////////////////////


#ifndef ASTEROIDS_PLAYER_H
#define ASTEROIDS_PLAYER_H
#include "Entity.h"
#include "constants.h"


class player: public Entity{
public:
    player();

    void update();

    void draw(sf::RenderWindow &app);

    bool hasThrust() const;

    void setThrust(bool thrust);

    static bool isInvincible();

    static void setInvinciblility(bool invinciblility);

    static unsigned int getInvinciblilityFramesDuration();

    static void setInvinciblilityFramesDuration(unsigned int invinciblilityFramesDuration);

private:
    bool thrust;
    static bool invinciblility;
    static unsigned int invinciblilityFramesDuration;
};


#endif //ASTEROIDS_PLAYER_H
