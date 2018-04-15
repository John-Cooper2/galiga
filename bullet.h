#ifndef BULLET_H_INCLUDED
#define BULLET_H_INCLUDED

const int BULLET_SPEED = 2;

struct Bullet{
    int x, y, id;
    Bullet();
    Bullet(int bid, int bx, int by);

    void drawFighterBullet(SDL_Plotter& g);
    void eraseFighterBullet(SDL_Plotter& g);
    void shoot(int shootX, int shootY, SDL_Plotter& g);
};

Bullet::Bullet()
{
    id = 1;
    x = 500;
    y = 800;
}

Bullet::Bullet(int bid, int bx, int by)
{
    id = bid;
    x = bx;
    y = by;
}

void Bullet::drawFighterBullet(SDL_Plotter& g)
{
    for(int i = x - 5; i < x; i++){
        for(int j = y - 20; j < y; j++){
            g.plotPixel(i,j,255, 20, 20);
        }
    }
}

void Bullet::eraseFighterBullet(SDL_Plotter& g)
{
    for(int i = y - 5; i < y; i++){
        for(int j = x - 20; j < x; j++){
            g.plotPixel(i,j,0,0,0);
        }
    }
}

void Bullet::shoot(int shootX, int shootY, SDL_Plotter& g)
{
    x = shootX;
    y = shootY;
    if (id == 1)
    {
        x+=46;
        while(y>20)
        {
            drawFighterBullet(g);
            y-=BULLET_SPEED;
            eraseFighterBullet(g);
        }
        if (y<=20)
        {
            eraseFighterBullet(g);
        }
    }
}


#endif // BULLET_H_INCLUDED
