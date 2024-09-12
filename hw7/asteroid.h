/////////////////////////////////////////////////////////////
//
// Programmer: Peter Knipper
// Date: 04/21/2024
// Name: asteroid.h
// Description: Declares functions for asteroid class
//
/////////////////////////////////////////////////////////////

#ifndef ASTEROIDS_ASTEROID_H
#define ASTEROIDS_ASTEROID_H
#include "Entity.h"
#include "constants.h"

class asteroid: public Entity {
public:
    asteroid();

    void update();

    virtual ~asteroid();

    static unsigned int getAsteroidCount();

    static void setAsteroidCount(unsigned int asteroidCount);

private:
    static unsigned int asteroidCount;
};

#endif //ASTEROIDS_ASTEROID_H
