#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <time.h>
#include <string>
using namespace sf;

class point{
    public:
        point(): x(0), y(0){}
        void setX(int newX){x = newX;}
        void setY(int newY){y = newY;}
        int getX() const {return x;}
        int getY() const {return y;}

    private:
        int x;
        int y;
};

int main()
{
    //seed random number generation
    srand(time(0));

    //set the size of the window, give it a title, and display it
    RenderWindow app(VideoMode(400, 533), "Doodle Game!");
    app.setFramerateLimit(60);

    //load necessary textures
    Texture t1,t2,t3;
    t1.loadFromFile("images/background.png");
    if (!t1.loadFromFile("images/background.png")) {
        return EXIT_FAILURE;
    }

    t2.loadFromFile("images/platform.png");
    if (!t2.loadFromFile("images/platform.png")) {
        return EXIT_FAILURE;
    }

    t3.loadFromFile("images/doodle.png");
    if (!t3.loadFromFile("images/doodle.png")) {
        return EXIT_FAILURE;
    }

    //load sound buffers
    //sound from https://en.wikipedia.org/wiki/File:Wilhelm_Scream.ogg; public domain
    SoundBuffer s1;
    s1.loadFromFile("sounds/Wilhelm_Scream.ogg");
    if (!s1.loadFromFile("sounds/Wilhelm_Scream.ogg")){
        return EXIT_FAILURE;
    }

    //load fonts
    //all fonts from 1001freefonts.com
    Font f1;
    f1.loadFromFile("fonts/folktale/Folktale.ttf");
    if (!f1.loadFromFile("fonts/folktale/Folktale.ttf")){
        return EXIT_FAILURE;
    }

    Font f2;
    f2.loadFromFile("fonts/bloodlust/bloodlust.ttf");
    if (!f2.loadFromFile("fonts/bloodlust/bloodlust.ttf")){
        return EXIT_FAILURE;
    }

    //create sprites
    Sprite sBackground(t1), sPlat(t2), sPers(t3);

    //create sounds
    Sound deathSound(s1);

    //create text
    Text welcomeScreen;
    welcomeScreen.setFont(f1);
    welcomeScreen.setFillColor(Color::Black);
    welcomeScreen.setCharacterSize(30);
    welcomeScreen.setString("PRESS THE S KEY TO START");
    welcomeScreen.setPosition(0, 215);


    Text currentScore;
    currentScore.setFont(f1);
    currentScore.setFillColor(Color::Black);
    currentScore.setCharacterSize(32);

    Text gameOver;
    gameOver.setFont(f2);
    gameOver.setFillColor(Color::Red);
    gameOver.setCharacterSize(64);
    gameOver.setString("GAME OVER");
    gameOver.setPosition(100, 215);

    //create boolean to ensure sounds only play once
    bool deathSoundPlayed = false;

    //create kill boolean that will stop game processes if user dies
    bool kill = false;
    bool start = false;

    //declare an array for twenty points corresponding to platforms
    point plat[20];

    //randomly set the location of each platform
    for (int i=0;i<10;i++){
        plat[i].setX(rand()%400);
        plat[i].setY(rand()%533);
    }

    //initialize starting location for player character and max height
	int x=100,y=100,h=200;
    float dx=0,dy=0;

    //initialize score
    int currScore = -100;

    //run program while the window is open
    while (app.isOpen()){

        //end program once the window is closed
        Event e;
        while (app.pollEvent(e)){
            if (e.type == Event::Closed) {
                app.close();
            }
        }

        //wait for user to press s before starting the game
        while (!start){
            app.draw(sBackground);
            app.draw(welcomeScreen);
            app.display();
            if (Keyboard::isKeyPressed(Keyboard::S)){
                start = true;
            }
        }

        //stop player from moving character after game over
        if (!kill) {

            //move character left and right
            if (Keyboard::isKeyPressed(Keyboard::Right)) {
                x += 3;
            }

            if (Keyboard::isKeyPressed(Keyboard::Left)) {
                x -= 3;
            }

            //scroll around screen
            if (x + 35 < 0){
                x = 365;
            }

            if (x + 35 > 400){
                x = -35;
            }
        }

        //create gravity
        dy += .2;
        y += dy;

        //screen scroll
        if (y < h) {

            //increment score by the increase in height
            currScore += h-y;

            //move the platforms down
            for (int i = 0; i < 10; i++) {
                y = h;
                plat[i].setY(plat[i].getY() - dy);

                //move offscreen platforms to top and place them randomly
                if (plat[i].getY() > 533) {
                    plat[i].setY(0);
                    plat[i].setX(rand() % 400);
                }
            }
        }

        //make the player character jump when contacting a platform (if falling)
        for (int i = 0; i < 10; i++) {
            if ((x + 50 > plat[i].getX()) && (x + 20 < plat[i].getX() + 68) && (y + 70 > plat[i].getY()) &&
                (y + 70 < plat[i].getY() + 14) && (dy > 0)) {
                dy = -10;
            }
        }

        //set the score
        currentScore.setString("Score: " + std::to_string(currScore));

        //set the position of player character
	    sPers.setPosition(x,y);

        //show the background, player character, and initial platforms
        app.draw(sBackground);
        app.draw(sPers);
        for (int i=0;i<10;i++){
            sPlat.setPosition(plat[i].getX(),plat[i].getY());
            app.draw(sPlat);
        }
        app.draw(currentScore);


        //add kill floor at bottom of screen
        if (y + 60 >= 533  || kill == true){

            //show final screen
            app.draw(gameOver);

            //flip kill switch
            kill = true;

            //play death sound effect
            if (!deathSoundPlayed){
                deathSound.play();
                deathSoundPlayed = true;
            }

            //restart game
            if(Keyboard::isKeyPressed(Keyboard::R)){

                //unflip kill switches
                kill = false;
                deathSoundPlayed = false;

                //reset current score
                currScore = 0;

                //randomly set the location of each platform
                for (int i=0;i<10;i++){
                    plat[i].setX(rand()%400);
                    plat[i].setY(rand()%533);
                }

                //initialize starting location for player character and max height
                x=100,y=100,h=200;
                dx=0,dy=0;
            }
        }

        //end the current frame
        app.display();
    }
    return 0;
}
