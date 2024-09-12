/////////////////////////////////////////////////////////////
//
// Programmer: Peter Knipper
// Date: 04/21/2024
// Name: Entity.h
// Description: Declares variables and functions for Entity class
//
/////////////////////////////////////////////////////////////

#ifndef ASTEROIDS_ENTITY_H
#define ASTEROIDS_ENTITY_H
#include <SFML/Graphics.hpp>
#include <time.h>
#include <list>
#include <cmath>
#include "Animation.h"


class Entity{
private:
    float x,y,dx,dy,R,angle;
    bool life;
    std::string name;
    Animation anim;

public:
    Entity();

    void settings(Animation &a,int X,int Y,float Angle=0,int radius=1);

    virtual void update();

    void draw(RenderWindow &app);

    virtual ~Entity();

    bool animIsEnd();

    float getX() const;

    void setX(float x);

    float getY() const;

    void setY(float y);

    float getDx() const;

    void setDx(float dx);

    float getDy() const;

    void setDy(float dy);

    float getR() const;

    void setR(float r);

    float getAngle() const;

    void setAngle(float angle);

    bool getLife() const;

    void setLife(bool life);

    const std::string &getName() const;

    void setName(const std::string &name);

    const Animation &getAnim() const;

    void setAnim(const Animation &anim);
};


#endif //ASTEROIDS_ENTITY_H
