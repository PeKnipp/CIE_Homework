/////////////////////////////////////////////////////////////
//
// Programmer: Peter Knipper
// Date: 04/21/2024
// Name: Entity.cpp
// Description: Defines functions for Entity class
//
/////////////////////////////////////////////////////////////

#include "Entity.h"

//default constructor
Entity::Entity()
{
    //variable use to determine if Entity should be deleted
    life=1;
}

//detailed constructor, used to set variables
void Entity::settings(Animation &a,int X,int Y,float Angle,int radius){
    //animation
    anim = a;
    //position
    x=X;
    y=Y;
    //angular direction
    angle = Angle;
    //hitbox of Entity
    R = radius;
}

/////////////////////////////////////////////////////////////
// Entity::update
// Description: << virtual function used to updates positions of child objects, updates the private animation object >>
// Inputs: << uses private Animation anim >>
// Output: << modifies all animations in place >>
//
/////////////////////////////////////////////////////////////
void Entity::update(){
    anim.update();
};

/////////////////////////////////////////////////////////////
// Entity::draw
// Description: << Displays objects to the screen >>
// Inputs: << uses private Animation object anim >>
// Output: << outputs images to the screen >>
//
/////////////////////////////////////////////////////////////
void Entity::draw(sf::RenderWindow &app) {

    anim.spriteSetPos(x,y);
    anim.spriteSetRot(angle+90);
    app.draw(anim.getSprite());

    //add hitbox to entity
    CircleShape circle(R);
    circle.setFillColor(Color(255,0,0,150));
    circle.setPosition(x,y);

    //center hitbox on entity
    circle.setOrigin(R,R);

    //uncomment below line to show hitboxes
    //app.draw(circle);
}

//default destructor
Entity::~Entity(){}

/////////////////////////////////////////////////////////////
//
// Description: << checks if private animation varible anim is at the end of its animation >>
// Inputs: << uses private variable anim >>
// Output: << outputs bool that is true if anim is at the end of its animation and false if not >>
//
/////////////////////////////////////////////////////////////
bool Entity::animIsEnd() {
    return anim.isEnd();
}

float Entity::getX() const {
    return x;
}

void Entity::setX(float x) {
    Entity::x = x;
}

float Entity::getY() const {
    return y;
}

void Entity::setY(float y) {
    Entity::y = y;
}

float Entity::getDx() const {
    return dx;
}

void Entity::setDx(float dx) {
    Entity::dx = dx;
}

float Entity::getDy() const {
    return dy;
}

void Entity::setDy(float dy) {
    Entity::dy = dy;
}

float Entity::getR() const {
    return R;
}

void Entity::setR(float r) {
    R = r;
}

float Entity::getAngle() const {
    return angle;
}

void Entity::setAngle(float angle) {
    Entity::angle = angle;
}

bool Entity::getLife() const {
    return life;
}

void Entity::setLife(bool life) {
    Entity::life = life;
}

const std::string &Entity::getName() const {
    return name;
}

void Entity::setName(const std::string &name) {
    Entity::name = name;
}

const Animation &Entity::getAnim() const{
    return anim;
}

void Entity::setAnim(const Animation &anim) {
    Entity::anim = anim;
};