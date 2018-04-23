#ifndef BULLET_H_INCLUDED
#define BULLET_H_INCLUDED

#include "Galaga.h"
#include "entity.h"
#include <ctime>

const int BULLET_SPEED = 10;
const int BULLET_SIZE = 2;

const int STAR_SPEED = 1;

int SCORE = 0;

struct Bullet{
    int x, y, id;
    bool hasHitbox;
    Bullet();
    Bullet(int bid, int bx, int by, bool hitbox);

    void drawFighterBullet(SDL_Plotter& g);
    void eraseFighterBullet(SDL_Plotter& g);
    void drawStar(SDL_Plotter& g);
    void eraseStar(SDL_Plotter& g);
    void shoot(int shootX, int shootY, SDL_Plotter& g, Entity enemies[], int size);
};

Bullet::Bullet()
{
    id = 1;
    x = 500;
    y = 800;
    hasHitbox = true;
}

Bullet::Bullet(int bid, int bx, int by, bool hitbox)
{
    id = bid;
    x = bx;
    y = by;
    hasHitbox = hitbox;
}

void Bullet::drawFighterBullet(SDL_Plotter& g)
{
    int offsetX = x;
    int offsetY = y;
    ifstream input;
    char c;
    input.open("./sprites/bullet.txt");
    for(int y = 0; y < 18; y++){
        for(int x = 0; x < 9; x++){
            input >> c;
            switch (c){
                case '0': drawFromText(x,y,offsetX,offsetY,BULLET_SIZE,255,255,255,g);
                        break;
                case '1': drawFromText(x,y,offsetX,offsetY,BULLET_SIZE,255,94,98,g);
                        break;
                case '2': drawFromText(x,y,offsetX,offsetY,BULLET_SIZE,255,159,162,g);
                        break;
            }
        }
    }
    input.close();
}

void Bullet::eraseFighterBullet(SDL_Plotter& g)
{
    int offsetX = x;
    int offsetY = y;
    ifstream input;
    char c;
    input.open("./sprites/bullet.txt");
    for(int y = 0; y < 18; y++){
        for(int x = 0; x < 9; x++){
            input >> c;
            if( c != 'X' ){
                drawFromText(x,y,offsetX,offsetY,BULLET_SIZE,0,0,0,g);
            }
        }
    }
    input.close();
}

void Bullet::drawStar(SDL_Plotter& g)
{
    g.plotPixel(x,y,255,255,255);
}

void Bullet::eraseStar(SDL_Plotter& g)
{
    g.plotPixel(x,y,0,0,0);
}

void Bullet::shoot(int shootX, int shootY, SDL_Plotter& g, Entity enemies[], int size)
{
    x = shootX;
    y = shootY;
    if (id == 1)
    {
        x+=35;
        y-=36;

        while(y-10>0)
        {
            // Detect bullet collisions with enemy
            for(int i = 0; i < size; i++) {
                // The static values her for collision boxes probably need to be adjusted
                if(enemies[i].isAlive && y < enemies[i].y + 30 && enemies[i].y < y + 30 && x < enemies[i].x + 30 && enemies[i].x < x + 30) {
                    enemies[i].isAlive = false;
                    enemies[i].eraseEntity(g);
                    SCORE++;
                    break;
                }
            }

            eraseFighterBullet(g);
            y-=BULLET_SPEED;
            drawFighterBullet(g);
            g.update();
        }
        eraseFighterBullet(g);
    }
    if (id == 2)
    {
        while(y<SCREEN_HIEGHT)
        {
            eraseStar(g);
            y+=STAR_SPEED;
            drawStar(g);
            g.update();
        }
        if(y == SCREEN_HIEGHT)
        {
            eraseStar(g);
        }
    }
}
#endif // BULLET_H_INCLUDED
