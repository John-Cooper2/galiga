#ifndef GALAGA_H_INCLUDED
#define GALAGA_H_INCLUDED

#include <string>
#include <sstream>
#include "SDL_Plotter.h"

const int SHIP_HIEGHT = 100;
const int SHIP_WIDTH = 100;
const int SCREEN_WIDTH = 1080;
const int SCREEN_HIEGHT = 1080;
const int SHIP_SIZE = 3;
const int BULLET_SPEED = 2;

void drawFromText(int x, int y, int size, int R, int G, int B, SDL_Plotter& g);
void drawFighterBullet(int cx, int cy, SDL_Plotter& g);
void eraseFighterBullet(int cx, int cy, SDL_Plotter& g);
void shoot(int x, int y);
void printLetter(string, int x, int y, int size, SDL_Plotter& g);
void printText(string, int x, int y, int size, SDL_Plotter& g);

void drawFromText(int x, int y, int offsetX, int offsetY, int size, int R, int G, int B, SDL_Plotter& g)
{
    for(int sx = 0; sx < size; sx++){
        for(int sy = 0; sy < size; sy++){
            g.plotPixel(offsetX + size*x + sx, offsetY + size*y + sy, R, G, B);
        }
    }
}

void drawFighterBullet(int cx, int cy, SDL_Plotter& g)
{
    for(int y = cy - 20; y < cy; y++){
        for(int x = cx - 5; x < cx; x++){
            g.plotPixel(x,y,255, 20, 20);
        }
    }
}

void eraseFighterBullet(int cx, int cy, SDL_Plotter& g)
{
    for(int y = cy - 20; y < cy; y++){
        for(int x = cx - 5; x < cx; x++){
            g.plotPixel(x,y,0,0,0);
        }
    }
}

void shoot(int x, int y, SDL_Plotter& g)
{
    while (y>20)
    {
        eraseFighterBullet(x+45,y,g);
        y-=BULLET_SPEED;
        drawFighterBullet(x+45,y,g);
        g.update();
    }
    if (y <= 20)
        eraseFighterBullet(x+45,y,g);
}


void printLetter(string fname, int offsetX, int offsetY, int size, SDL_Plotter& g){
    ifstream input;
    char c;
    input.open(fname.c_str());

    if(!input){
        cout<< "ERROR: Text File Not Open" << endl;
    }
    int row, col;

    input>> col >> row;
    for(int y = 0; y < col; y++){
        for(int x = 0; x < row; x++){
            input >> c;
            if( c == '1' ){
                drawFromText(x,y,offsetX,offsetY,size,255,255,255,g);
            }
        }
    }
    input.close();

}

void printText(string text, int offsetX, int offsetY, int size, SDL_Plotter& g)
{
    for (unsigned int i = 0; i < text.size(); i++)
    {
        char c = text[i];
        stringstream ss;
        ss << "./font/" << c << ".txt";
        printLetter(ss.str(), offsetX, offsetY, size, g);
        offsetX += size*11;
        ss.clear();
        ss.str("");
    }
}

#endif // GALAGA_H_INCLUDED
