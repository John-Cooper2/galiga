#ifndef GALAGA_H_INCLUDED
#define GALAGA_H_INCLUDED

#include <string>
#include <sstream>
#include <ctime>
#include "SDL_Plotter.h"

const int SCREEN_WIDTH = 1080;
const int SCREEN_HIEGHT = 1080;

void drawFromText(int x, int y, int size, int R, int G, int B, SDL_Plotter& g);
void printLetter(string, int x, int y, int size, SDL_Plotter& g);
void printText(string, int x, int y, int size, SDL_Plotter& g);

struct GlobalTimer
{
    int start;
    GlobalTimer();
    GlobalTimer(int startTime);

    int getRunTime();
    int getTimeSince(int since);
    int rng();
};

GlobalTimer::GlobalTimer()
{
    start = time(NULL);
}

GlobalTimer::GlobalTimer(int startTime)
{
    start = startTime;
}

int GlobalTimer::getRunTime()
{
    int t = time(NULL) - start;
    return t;
}

int GlobalTimer::getTimeSince(int since)
{
    int t = time(NULL) - since;
    return t;
}

int GlobalTimer::rng()
{
    srand(getRunTime());
    int randomNumber = rand();
    return randomNumber;
}

void drawFromText(int x, int y, int offsetX, int offsetY, int size, int R, int G, int B, SDL_Plotter& g)
{
    for(int sx = 0; sx < size; sx++){
        for(int sy = 0; sy < size; sy++){
            g.plotPixel(offsetX + size*x + sx, offsetY + size*y + sy, R, G, B);
        }
    }
}


void printLetter(string fname, int offsetX, int offsetY, int size, SDL_Plotter& g){
    ifstream input;
    char c;
    input.open(fname.c_str());

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
