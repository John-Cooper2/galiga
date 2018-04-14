#include <iostream>
#include <fstream>
#include "Galaga.h"
#include "Fighter.h"

using namespace std;

int main(int argc, char ** argv)
{

    SDL_Plotter g(SCREEN_WIDTH, SCREEN_HIEGHT);
    Fighter f;
    char key;

    for (int x = 0; x < SCREEN_WIDTH; x++)
        for (int y = 0; y < SCREEN_HIEGHT; y++)
            g.plotPixel(x,y,0,0,0);

    while (!g.getQuit())
    {
        int mx, my;
        if(g.getMouseMotion(mx, my))
        {
            f.eraseFighter(g);
            f.x = mx;
            f.drawFighter(g);
        }
        if(g.getMouseClick(mx, my))
            shoot(f.x,f.y,g);
		//if(g.kbhit()){
			//key = g.getKey();
			//switch(key){
			    //case RIGHT_ARROW: f.eraseFighter(g);
                                  //if(f.x + FIGHTER_SPEED < SCREEN_WIDTH - 90)
                                     //f.x += FIGHTER_SPEED;
                                  //break;
                //case LEFT_ARROW:  f.eraseFighter(g);
                                  //if(f.x - FIGHTER_SPEED - 10 > 0)
                                     //f.x -= FIGHTER_SPEED;
                                  //break;
                //case UP_ARROW:    shoot(f.x,f.y,g);
			//}
		//}
        g.update();
    }
    return 0;
}
