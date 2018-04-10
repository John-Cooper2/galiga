#include <iostream>

#include "SDL_Plotter.h"

using namespace std;

const int SHIP_WIDTH = 30;
const int SHIP_HIEGHT = 30;
const int SCREEN_WIDTH = 500;
const int SCREEN_HIEGHT = 500;
const int SPEED = 3;

void drawShip(intx, int y, SDL_Plotter& g, int R, int G, int B);

int main(int argc, char ** argv)
{

    SDL_Plotter g(SCREEN_WIDTH,SCREEN_HIEGHT);
    int x = SCREEN_WIDTH/2, y = SCREEN_HIEGHT - 2*SHIP_HIEGHT;
    char key;

    while (!g.getQuit())
    {

		if(g.kbhit()){
			key = g.getKey();
			switch(key){
			    case RIGHT_ARROW: drawShip(x,y,g,255,255,255);
                                  if(x + SPEED < SCREEN_WIDTH - SHIP_WIDTH)
                                     x += SPEED;
                                  break;
                case LEFT_ARROW:  drawShip(x,y,g,225,255,255);
                                  IF(x - SPEED - SHIP_WIDTH > 0)
                                     x -= SPEED;
                                  break;
			}
		}
        drawShip(x,y,g);

		g.update();
    }
}

void drawShip(int cx, int cy, SDL_Plotter& g, int R, int G, int B){
    //draw top
    for(int y = cy - SHIP_HIEGHT/2; y < cy - SHIP_HIEGHT/6; y++){
        for(int x = cx - SHIP_WIDTH/6; x < cx + SHIP_WIDTH/6; x++){
            g.plotPixel(x,y,R,G,B);
        }
    }
    //draw bottom
        for(int y = cy - SHIP_HIEGHT/3; y < cy - SHIP_HIEGHT/3; y++){
        for(int x = cx - SHIP_WIDTH/2; x < cx + SHIP_WIDTH/2; x++){
            g.plotPixel(x,y,R,G,B);
        }
    }
}
