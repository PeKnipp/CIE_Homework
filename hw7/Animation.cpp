/////////////////////////////////////////////////////////////
//
// Programmer: Peter Knipper
// Date: 04/21/2024
// Name: Animation.cpp
// Description: Defines functions for Animation class
//
/////////////////////////////////////////////////////////////

#include "Animation.h"

//default constructor
Animation::Animation(){}

//detailed constructor
Animation::Animation (Texture &t, int x, int y, int w, int h, int count, float Speed){
    Frame = 0;
    speed = Speed;

    //iterate through animation frames
    for (int i=0;i<count;i++) {
        //add frame to list
        frames.push_back(IntRect(x + i * w, y, w, h));

        //add texture to sprite
        sprite.setTexture(t);

        //center sprite
        sprite.setOrigin(w / 2, h / 2);

        //set sprite to first frame of animation
        sprite.setTextureRect(frames[0]);
    }
}

/////////////////////////////////////////////////////////////
// update
// Description: << sets animation object to the next frame of the animations >>
// Inputs: << uses Frame and speed to determine next frame of animation >>
// Output: << moves the sprite texture rectangle to the next frame >>
//
/////////////////////////////////////////////////////////////
void Animation::update(){
    //increment frame
    Frame += speed;
    int n = frames.size();

    //if at end of loop, reset to frame 0
    if (Frame >= n) {
        Frame -= n;
    }

    //move to next frame
    if (n>0) {
        sprite.setTextureRect( frames[int(Frame)] );
    }
}

/////////////////////////////////////////////////////////////
// isEnd
// Description: << Checks if animation is at the last frame >>
// Inputs: << uses Frame and speed >>
// Output: << returns a bool that is true if frame + speed is out of range of the frames list, and false if not >>
//
/////////////////////////////////////////////////////////////
bool Animation::isEnd(){
    return Frame+speed>=frames.size();
}

float Animation::getFrame() const {
    return Frame;
}

void Animation::setFrame(float frame) {
    Frame = frame;
}

float Animation::getSpeed() const {
    return speed;
}

void Animation::setSpeed(float speed) {
    Animation::speed = speed;
}

const Sprite &Animation::getSprite() const {
    return sprite;
}

void Animation::setSprite(const Sprite &sprite) {
    Animation::sprite = sprite;
}

const std::vector<IntRect> &Animation::getFrames() const {
    return frames;
}

void Animation::setFrames(const std::vector<IntRect> &frames) {
    Animation::frames = frames;
}

/////////////////////////////////////////////////////////////
// spriteSetPos
// Description: << sets the position of the private sprite object.  >>
// Inputs: << x, int, the horizontal position of the sprite; y, int, the vertical position of the sprite >>
// Output: << modifies sprite position in place >>
//
/////////////////////////////////////////////////////////////
void Animation::spriteSetPos(int x, int y) {
    sprite.setPosition(x,y);
}

/////////////////////////////////////////////////////////////
// spriteSetRot
// Description: << sets the rotation of the private sprite object >>
// Inputs: << angle, float, the angle at which the sprite should be displayed >>
// Output: << modifies sprite angle in place >>
//
/////////////////////////////////////////////////////////////
void Animation::spriteSetRot(float angle){
    sprite.setRotation(angle);
}