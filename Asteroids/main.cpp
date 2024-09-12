/////////////////////////////////////////////////////////////
//
// Programmer: Peter Knipper
// Date: 04/22/2024
// Name: main.cpp
// Description: An asteroids game
//
// EXTRA CREDIT ADDITION: added invincibility frames on player respawn
// EXTRA CREDIT ADDITION: refactored code to proper formatting
// EXTRA CREDIT ADDITION: separated classes into separate files
// EXTRA CREDIT ADDITION: implemented principle of least privilege in all classes
//
// UFO image from "https://www.flaticon.com/free-icons/spaceship" created by Wendy-G
// sound from http://www.rosswalker.co.uk/movie_sounds/lost_in_space.htm for educational use
/////////////////////////////////////////////////////////////
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <time.h>
#include <list>
#include <cmath>

#include "constants.h"
#include "Animation.h"
#include "Entity.h"
#include "asteroid.h"
#include "bullet.h"
#include "player.h"
#include "UFO.h"

using namespace sf;

/////////////////////////////////////////////////////////////
// isCollide
// Description: << Determines if two entities have collided by comparing their positions to their hitboxes >>
// Inputs: << a, entity pointer; b, entity pointer >>
// Output: << a boolean value that will be true if the entities have collided and false if not. >>
//
/////////////////////////////////////////////////////////////
bool isCollide(Entity *a,Entity *b){
    return  (b->getX() - a->getX())*(b->getX() - a->getX())
           +(b->getY() - a->getY())*(b->getY() - a->getY())
           <(a->getR() + b->getR())*(a->getR() + b->getR());
}

int main() {
    //set random seed
    srand(time(0));

    //display window and set the rate at which frames are changed
    RenderWindow app(VideoMode(W, H), "Asteroids!");
    app.setFramerateLimit(60);

    //load all textures
    Texture t1, t2, t3, t4, t5, t6, t7, t8;
    t1.loadFromFile("images/spaceship.png");
    if (!t1.loadFromFile("images/spaceship.png")){
        return EXIT_FAILURE;
    }

    t2.loadFromFile("images/background.jpg");
    if (!t2.loadFromFile("images/background.jpg")){
        return EXIT_FAILURE;
    }

    t3.loadFromFile("images/explosions/type_C.png");
    if (!t3.loadFromFile("images/explosions/type_C.png")){
        return EXIT_FAILURE;
    }

    t4.loadFromFile("images/rock.png");
    if (!t4.loadFromFile("images/rock.png")){
        return EXIT_FAILURE;
    }

    t5.loadFromFile("images/fire_blue.png");
    if (!t5.loadFromFile("images/fire_blue.png")){
        return EXIT_FAILURE;
    }

    t6.loadFromFile("images/rock_small.png");
    if (!t6.loadFromFile("images/rock_small.png")){
        return EXIT_FAILURE;
    }

    t7.loadFromFile("images/explosions/type_B.png");
    if (!t7.loadFromFile("images/explosions/type_B.png")){
        return EXIT_FAILURE;
    }

    t8.loadFromFile("images/smallerUFO.png");
    if (!t8.loadFromFile("images/smallerUFO.png")){
        return EXIT_FAILURE;
    }

    t1.setSmooth(true);
    t2.setSmooth(true);

    //set background image
    Sprite background(t2);

    //instantiate animation objects
    Animation sExplosion(t3, 0, 0, 256, 256, 48, 0.5);
    Animation sRock(t4, 0, 0, 64, 64, 16, 0.2);
    Animation sRock_small(t6, 0, 0, 64, 64, 16, 0.2);
    Animation sBullet(t5, 0, 0, 32, 64, 16, 0.8);
    Animation sPlayer(t1, 40, 0, 40, 40, 1, 0);
    Animation sPlayer_go(t1, 40, 40, 40, 40, 1, 0);
    Animation sExplosion_ship(t7, 0, 0, 192, 192, 64, 0.5);
    Animation sUFO(t8, 0, 0, 64, 64, 1, 0);

    UFO::loadSounds();
    if (UFO::loadSounds() < 0){
        return EXIT_FAILURE;
    }

    //create list of entities
    std::list<Entity *> entities;

    //add entities to list
    //add 15 asteroids objects to entity list
    for (int i = 0; i < 15; i++) {
        //create asteroid object
        asteroid *a = new asteroid();

        //set hitbox, random position and direction
        a->settings(sRock, rand() % W, rand() % H, rand() % 360, 25);

        //add to entity list
        entities.push_back(a);
    }

    //add player object to entity list
    player *p = new player();

    //set hitbox, default position and direction
    p->settings(sPlayer, 200, 200, 0, 20);

    //add to entity list
    entities.push_back(p);

    /////main loop/////
    while (app.isOpen()) {

        //create event logic
        Event event;
        while (app.pollEvent(event)) {

            //if window closed, close the program
            if (event.type == Event::Closed) {
                app.close();
            }

            //player inputs
            if (event.type == Event::KeyPressed) {

                //shoot on spacebar press
                if (event.key.code == Keyboard::Space) {
                    //create new bullet object
                    bullet *b = new bullet();

                    //set the direction and hitbox of bullet
                    b->settings(sBullet, p->getX(), p->getY(), p->getAngle(), 10);

                    //add to entity list
                    entities.push_back(b);
                }
            }
        }

        //turn player clockwise on right arrow key press
        if (Keyboard::isKeyPressed(Keyboard::Right)) {
            p->setAngle(p->getAngle() + 3);
        }

        //turn player counterclockwise on left arrow key press
        if (Keyboard::isKeyPressed(Keyboard::Left)) {
            p->setAngle(p->getAngle() - 3);
        }

        //speed up on up arrow key press
        if (Keyboard::isKeyPressed(Keyboard::Up)) {
            p->setThrust(true);
        }

        //slow down while up is not being pressed
        else p->setThrust(false);

        //check for collisions between important entities
        for (auto a: entities) {
            for (auto b: entities) {

                //bullet-asteroid interactions
                if (a->getName() == "asteroid" && b->getName() == "bullet") {
                    if (isCollide(a, b)) {

                        //schedule both entities for deletion
                        a->setLife(false);
                        b->setLife(false);

                        //create explosion entity
                        Entity *e = new Entity();

                        //set position and name of explosion
                        e->settings(sExplosion, a->getX(), a->getY());
                        e->setName("explosion");

                        //add to entity list
                        entities.push_back(e);

                        //create two smaller asteroids
                        for (int i = 0; i < 2; i++) {

                            //if asteroids are already small, dont create new asteroids
                            if (a->getR() == 15) {
                                continue;
                            }

                            //create asteroid object
                            Entity *e = new asteroid();

                            //set hitbox and random direction
                            e->settings(sRock_small, a->getX(), a->getY(), rand() % 360, 15);
                            entities.push_back(e);
                        }
                    }
                }

                //player-asteroid collision
                if (a->getName() == "player" && b->getName() == "asteroid") {
                    if (isCollide(a, b)) {
                        if (!player::isInvincible()) {

                            //schedule asteroid for deletion
                            b->setLife(false);

                            //create explosion entity
                            Entity *e = new Entity();

                            //set position and name
                            e->settings(sExplosion_ship, a->getX(), a->getY());
                            e->setName("explosion");

                            //add to entity list
                            entities.push_back(e);

                            //respawn player at center screen
                            p->settings(sPlayer, W / 2, H / 2, 0, 20);
                            p->setDx(0);
                            p->setDy(0);
                            p->setInvinciblility(true);
                            p->setInvinciblilityFramesDuration(180);
                        }
                    }
                }

                //bullet-UFO interactions
                if (a->getName() == "UFO" && b->getName() == "bullet") {
                    if (isCollide(a, b)) {

                        //schedule both entities for deletion
                        a->setLife(false);
                        b->setLife(false);

                        //create explosion entity
                        Entity *e = new Entity();

                        //set position and name of explosion
                        e->settings(sExplosion_ship, a->getX(), a->getY());
                        e->setName("explosion");

                        //add to entity list
                        entities.push_back(e);
                    }
                }

                //player-UFO collision
                if (a->getName() == "player" && b->getName() == "UFO") {
                    if (isCollide(a, b)) {
                        if(!player::isInvincible()) {
                            //schedule ufo for deletion
                            b->setLife(false);

                            //create explosion entity
                            Entity *e = new Entity();

                            //set position and name

                            e->settings(sExplosion_ship, a->getX(), a->getY());
                            e->setName("explosion");

                            //add to entity list
                            entities.push_back(e);

                            //respawn player at center screen
                            p->settings(sPlayer, W / 2, H / 2, 0, 20);
                            p->setDx(0);
                            p->setDy(0);
                            p->setInvinciblility(true);
                            p->setInvinciblilityFramesDuration(180);
                        }
                    }
                }
            }
        }

        //change player animation while accelerating
        if (p->hasThrust()) {
            p->setAnim(sPlayer_go);
        }

        //revert player animation while not accelerating
        else p->setAnim(sPlayer);

        //schedule all explosion entities for deletion
        for (auto e: entities) {
            if (e->getName() == "explosion") {
                if (e->animIsEnd()) {
                    e->setLife(0);
                }
            }
        }

        //spawn UFO (10% chance after 30 seconds)
        if (rand() % 10 == 0 && !UFO::isOnScreen() && UFO::getTimerUfo() == 0) {

            //create new UFO object
            UFO *u = new UFO();

            //set hitbox, random direction and position
            //50% chance to spawn on left or right
            if (u->onLeft()) {
                u->settings(sUFO, 0, rand() % H, -90, 25);
            }
            else u->settings(sUFO, W, rand() % H, -90, 25);

            //add to entity list
            entities.push_back(u);
        }
        //decrease countdown
        else UFO::countdown();


        //spawn new asteroids
        if (asteroid::getAsteroidCount() == 0){
            for (int i = 0; i < 15; i++) {
                //create asteroid object
                asteroid *a = new asteroid();

                //set hitbox, random position and direction
                a->settings(sRock, rand() % W, rand() % H, rand() % 360, 25);

                //add to entity list
                entities.push_back(a);
            }
        }

//        //spawn new asteroids old way
//        if (rand() % 150 == 0) {
//            //create new asteroid object
//            asteroid *a = new asteroid();
//
//            //set hitbox, random direction, and position
//            a->settings(sRock, 0, rand() % H, rand() % 360, 25);
//
//            //add to entity list
//            entities.push_back(a);
//        }

        //iterate through entity list
        for (auto i = entities.begin(); i != entities.end();) {
            Entity *e = *i;

            //update entity position and animation
            e->update();

            //check iFrames
            if (e->getName() == "player"){
                if (player::getInvinciblilityFramesDuration() == 0){
                    player::setInvinciblility(false);
                }

                if(player::isInvincible() == true){
                    player::setInvinciblilityFramesDuration(player::getInvinciblilityFramesDuration()-1);
                }
            }

            //delete destroyed entities
            if (e->getLife() == false) {

                i = entities.erase(i);
                delete e;
            }
            else i++;
        }

        //spawn background
        app.draw(background);

        //spawn entities
        for (auto i: entities) {
            if(i->getName() == "player"){
                p = static_cast<player*>(i);
                p->draw(app);
            }
            i->draw(app);
        }

        //show all entities
        app.display();

    }

    return 0;
}
