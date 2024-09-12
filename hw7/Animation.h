/////////////////////////////////////////////////////////////
//
// Programmer: Peter Knipper
// Date: 04/21/2024
// Name: Animation.h
// Description: Declares variables and functions for Animation class
//
/////////////////////////////////////////////////////////////

#ifndef ASTEROIDS_ANIMATION_H
#define ASTEROIDS_ANIMATION_H
#include <SFML/Graphics.hpp>
#include <time.h>
#include <list>
#include <cmath>

using namespace sf;

class Animation {
public:
    Animation();

    Animation (Texture &t, int x, int y, int w, int h, int count, float Speed);

    void update();

    bool isEnd();

    float getFrame() const;

    void setFrame(float frame);

    float getSpeed() const;

    void setSpeed(float speed);

    const Sprite &getSprite() const;

    void setSprite(const Sprite &sprite);

    const std::vector<IntRect> &getFrames() const;

    void setFrames(const std::vector<IntRect> &frames);

    void spriteSetPos(int x, int y);

    void spriteSetRot(float angle);

private:
    float Frame, speed;
    Sprite sprite;
    std::vector<IntRect> frames;
};


#endif //ASTEROIDS_ANIMATION_H
