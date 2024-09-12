#include <SFML/Graphics.hpp>
#include <time.h>
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

    //create sprites for the background, platforms, and user character
    Sprite sBackground(t1), sPlat(t2), sPers(t3);

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

    //run program while the window is open. end program once the window is closed
    while (app.isOpen()){
        Event e;
        while (app.pollEvent(e)){
            if (e.type == Event::Closed) {
                app.close();
            }
        }

        //move character left and right
        if (Keyboard::isKeyPressed(Keyboard::Right)){
            x+=3;
        }

        if (Keyboard::isKeyPressed(Keyboard::Left)){
            x-=3;
        }

        //create gravity
        dy+=.2;
        y+=dy;
        if (y>500){
            dy=-10;
        }

        //scroll the screen, move offscreen platforms to the top in a random location
	    if (y<h) {
            for (int i = 0; i < 10; i++) {
                y = h;
                plat[i].setY(plat[i].getY() - dy);

                if (plat[i].getY() > 533) {
                    plat[i].setY(0);
                    plat[i].setX(rand() % 400);
                }
            }
        }
        //make the player character jump when contacting a platform (if falling)
	    for (int i=0;i<10;i++) {
            if ((x + 50 > plat[i].getX()) && (x + 20 < plat[i].getX() + 68) && (y + 70 > plat[i].getY()) && (y + 70 < plat[i].getY() + 14) && (dy > 0)) {
                dy = -10;
            }
        }

        //set the position of player character
	    sPers.setPosition(x,y);

        //show in the background, player character, and initial platforms
        app.draw(sBackground);
        app.draw(sPers);
        for (int i=0;i<10;i++){
            sPlat.setPosition(plat[i].getX(),plat[i].getY());
            app.draw(sPlat);
        }

        //end the current frame
        app.display();
    }
    return 0;
}
