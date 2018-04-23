#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED
#include "Galaga.h"

const int FIGHTER_SPEED = 15;
const int FIGHTER_SIZE = 3;

const int BOSS_SPEED = 15;
const int BOSS_SIZE = 8;

const int SHIP_SPEED = 1;
const int SHIP_SIZE = 3;

struct Entity{
    int x, y, id, speed, drawSize;
    bool isAlive;
    Entity();
    Entity(int eid, int ex, int ey);

    void drawEntity(SDL_Plotter& g);
    void eraseEntity(SDL_Plotter& g);

    void drawFighter(SDL_Plotter& g);
    void eraseFighter(SDL_Plotter& g);

    void drawShip(SDL_Plotter& g);
    void eraseShip(SDL_Plotter& g);

    void drawBoss(SDL_Plotter& g);
    void eraseBoss(SDL_Plotter& g);
};

Entity::Entity()
{
    id = 1;
    x = SCREEN_WIDTH/2;
    y = SCREEN_HIEGHT - 200;
    isAlive = true;
}

Entity::Entity(int eid, int ex, int ey)
{
    id = eid;
    x = ex;
    y = ey;

    if(id == 1) {
        speed = FIGHTER_SPEED;
        drawSize = FIGHTER_SIZE;
    }
    else if(id == 2) {
        speed = SHIP_SPEED;
        drawSize = SHIP_SIZE;
    }
    else if(id == 3) {
        speed = BOSS_SPEED;
        drawSize = BOSS_SIZE;
    }

    isAlive = true;
}

void Entity::drawFighter(SDL_Plotter& g){
    int offsetX = x;
    int offsetY = y;
    ifstream input;
    char c;
    input.open("./sprites/fighter.txt");
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

void Entity::eraseFighter(SDL_Plotter& g){
    int offsetX = x;
    int offsetY = y;
    ifstream input;
    char c;
    input.open("./sprites/fighter.txt");
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

void Entity::drawBoss(SDL_Plotter& g){
    int offsetX = x;
    int offsetY = y;
    ifstream input;
    char c;
    input.open("./sprites/boss1.txt");
    for(int y = 0; y < 31; y++){
        for(int x = 0; x < 29; x++){
            input >> c;
            switch (c){
                case '1': drawFromText(x,y,offsetX,offsetY,BOSS_SIZE,24,94,93,g);
                        break;
                case '2': drawFromText(x,y,offsetX,offsetY,BOSS_SIZE,84,130,53,g);
                        break;
                case '3': drawFromText(x,y,offsetX,offsetY,BOSS_SIZE,146,208,80,g);
                        break;
                case '4': drawFromText(x,y,offsetX,offsetY,BOSS_SIZE,185,76,76,g);
                        break;
                case '5': drawFromText(x,y,offsetX,offsetY,BOSS_SIZE,142,0,47,g);
                        break;
                case '6': drawFromText(x,y,offsetX,offsetY,BOSS_SIZE,226,152,137,g);
                        break;
            }
        }
    }
    input.close();
}

void Entity::eraseBoss(SDL_Plotter& g){
    int offsetX = x;
    int offsetY = y;
    ifstream input;
    char c;
    input.open("./sprites/boss1.txt");
    for(int y = 0; y < 21; y++){
        for(int x = 0; x < 29; x++){
            input >> c;
            if( c != 'X' ){
                drawFromText(x,y,offsetX,offsetY,BOSS_SIZE,0,0,0,g);
            }
        }
    }
    input.close();
}

void Entity::drawShip(SDL_Plotter& g){
    int offsetX = x;
    int offsetY = y;
    ifstream input;
    char c;
    input.open("./sprites/ship.txt");
    for(int y = 0; y < 11; y++){
        for(int x = 0; x < 19; x++){
            input >> c;
            switch (c){
                case '0': drawFromText(x,y,offsetX,offsetY,SHIP_SIZE,64,64,64,g);
                        break;
                case '1': drawFromText(x,y,offsetX,offsetY,SHIP_SIZE,91,155,213,g);
                        break;
                case '2': drawFromText(x,y,offsetX,offsetY,SHIP_SIZE,204,255,255,g);
                        break;
                case '3': drawFromText(x,y,offsetX,offsetY,SHIP_SIZE,201,201,201,g);
                        break;
                case '4': drawFromText(x,y,offsetX,offsetY,SHIP_SIZE,165,165,165,g);
                        break;
                case '5': drawFromText(x,y,offsetX,offsetY,SHIP_SIZE,153,153,153,g);
                        break;
                case '6': drawFromText(x,y,offsetX,offsetY,SHIP_SIZE,128,128,128,g);
                        break;
                case '7': drawFromText(x,y,offsetX,offsetY,SHIP_SIZE,89,89,89,g);
                        break;
                case '8': drawFromText(x,y,offsetX,offsetY,SHIP_SIZE,115,115,115,g);
                        break;
                case '9': drawFromText(x,y,offsetX,offsetY,SHIP_SIZE,0,229,240,g);
                        break;
            }
        }
    }
    input.close();
}

void Entity::eraseShip(SDL_Plotter& g){
    int offsetX = x;
    int offsetY = y;
    ifstream input;
    char c;
    input.open("./sprites/ship.txt");
    for(int y = 0; y < 21; y++){
        for(int x = 0; x < 29; x++){
            input >> c;
            if( c != 'X' ){
                drawFromText(x,y,offsetX,offsetY,SHIP_SIZE,0,0,0,g);
            }
        }
    }
    input.close();
}

void Entity::drawEntity(SDL_Plotter& g)
{
    if (id == 1)
        drawFighter(g);
    else if (id == 2)
        drawShip(g);
    else if (id == 3)
        drawBoss(g);
}

void Entity::eraseEntity(SDL_Plotter& g)
{
    if (id == 1)
        eraseFighter(g);
    else if (id == 2)
        eraseShip(g);
    else if (id == 3)
        eraseBoss(g);
}

#endif // ENTITY_H_INCLUDED
