#ifndef FIGHTER_H_INCLUDED
#define FIGHTER_H_INCLUDED
#include "GALAGA.H"

const int FIGHTER_SPEED = 15;
const int FIGHTER_SIZE = 3;

struct Fighter{
    int x, y;
    Fighter();
    Fighter(int fx, int fy);

    void drawFighter(SDL_Plotter& g);
    void eraseFighter(SDL_Plotter& g);
};

Fighter::Fighter()
{
    x = SCREEN_WIDTH/2;
    y = SCREEN_HIEGHT - 2*SHIP_HIEGHT;
}

Fighter::Fighter(int fx, int fy)
{
    x = fx;
    y = fy;
}

void Fighter::drawFighter(SDL_Plotter& g){
    int offsetX = x;
    int offsetY = y;
    ifstream input;
    char c;
    input.open("fighter.txt");
    for(int y = 0; y < 21; y++){
        for(int x = 0; x < 29; x++){
            input >> c;
            switch (c){
                case '0': drawFromText(x,y,offsetX,offsetY,FIGHTER_SIZE,255,255,255,g);
                        break;
                case '1': drawFromText(x,y,offsetX,offsetY,FIGHTER_SIZE,255,192,0,g);
                        break;
                case '2': drawFromText(x,y,offsetX,offsetY,FIGHTER_SIZE,255,235,156,g);
                        break;
                case '3': drawFromText(x,y,offsetX,offsetY,FIGHTER_SIZE,0,102,255,g);
                        break;
                case '4': drawFromText(x,y,offsetX,offsetY,FIGHTER_SIZE,155,194,230,g);
                        break;
                case '5': drawFromText(x,y,offsetX,offsetY,FIGHTER_SIZE,219,219,219,g);
                        break;
                case '6': drawFromText(x,y,offsetX,offsetY,FIGHTER_SIZE,89,89,89,g);
                        break;
                case '7': drawFromText(x,y,offsetX,offsetY,FIGHTER_SIZE,165,165,165,g);
                        break;
                case '8': drawFromText(x,y,offsetX,offsetY,FIGHTER_SIZE,0,0,0,g);
                        break;
                case '9': drawFromText(x,y,offsetX,offsetY,FIGHTER_SIZE,38,38,38,g);
                        break;
            }
        }
    }
    input.close();
}

void Fighter::eraseFighter(SDL_Plotter& g){
    int offsetX = x;
    int offsetY = y;
    ifstream input;
    char c;
    input.open("fighter.txt");
    for(int y = 0; y < 21; y++){
        for(int x = 0; x < 29; x++){
            input >> c;
            if( c != 'X' ){
                drawFromText(x,y,offsetX,offsetY,FIGHTER_SIZE,0,0,0,g);
            }
        }
    }
    input.close();
}

#endif // FIGHTER_H_INCLUDED
