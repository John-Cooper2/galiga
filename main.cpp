#include <iostream>
#include <fstream>

#include "SDL_Plotter.h"

using namespace std;

const int SHIP_WIDTH = 30;
const int SHIP_HIEGHT = 30;
const int SCREEN_WIDTH = 750;
const int SCREEN_HIEGHT = 750;
const int SPEED = 5;

void drawShip(int x, int y, SDL_Plotter& g, int R, int G, int B);
void printLetter(string, int x, int y, int size, SDL_Plotter& g);

int main(int argc, char ** argv)
{

    SDL_Plotter g(SCREEN_WIDTH, SCREEN_HIEGHT);
    int x = SCREEN_WIDTH/2, y = SCREEN_HIEGHT - 2*SHIP_HIEGHT;
    char key;
    g.initSound("ahem_x.wav");

    while (!g.getQuit())
    {
        printLetter("A.txt", 150, 150, 3, g);

		if(g.kbhit()){
			key = g.getKey();
			switch(key){
			    case RIGHT_ARROW: drawShip(x, y, g, 255, 255, 255);
                                  if(x + SPEED < SCREEN_WIDTH - SHIP_WIDTH)
                                     x += SPEED;
                                    g.playSound("ahem_x.wav");
                                  break;
                case LEFT_ARROW:  drawShip(x, y, g, 255, 255, 255);
                                  if(x - SPEED - SHIP_WIDTH > 0)
                                     x -= SPEED;
                                  break;
			}
		}
        drawShip(x, y, g, 220, 20, 20);

		g.update();
    }
}

void drawShip(int cx, int cy, SDL_Plotter& g, int R, int G, int B){
    //draw top
    for(int y = cy - SHIP_HIEGHT/2; y < cy - SHIP_HIEGHT/6; y++){
        for(int x = cx - SHIP_WIDTH/6; x < cx + SHIP_WIDTH/6; x++){
            g.plotPixel(x,y,R, G, B);
        }
    }
    //draw bottom
    for(int y = cy - SHIP_HIEGHT/3; y < cy - SHIP_HIEGHT/3; y++){
        for(int x = cx - SHIP_WIDTH/2; x < cx + SHIP_WIDTH/2; x++){
            g.plotPixel(x,y,R, G, B);
        }
    }
}

void printLetter(string fname, int offsetX, int offsetY, int size, SDL_Plotter& g){
    ifstream input;
    char c;
    input.open(fname.c_str());

    if(!input){
        cout<< "ERROR: File Not Open" << endl;
    }
    int row, col;

    input>> col >> row;
    for(int y = 0; y < col; y++){
        for(int x = 0; x < row; x++){
            input >> c;
            if( c == '1' ){
                for(int sx = 0; sx < size; sx++){
                    for(int sy = 0; sy < size; sy++){
                        g.plotPixel(offsetX + size*x + sx, offsetY + size*y + sy, 0, 0, 0);
                    }
                }
            }
        }
    }
    input.close();

}










