/////////////////////////////////////////////////////////////
//
// Programmer: Peter Knipper
// Date: 04/21/2024
// Name: bullet.h
// Description: Declares functions for bullet class
//
/////////////////////////////////////////////////////////////

#ifndef ASTEROIDS_BULLET_H
#define ASTEROIDS_BULLET_H
#include "Entity.h"
#include "constants.h"

class bullet: public Entity{
public:
    bullet();

    void update();
};


#endif //ASTEROIDS_BULLET_H
