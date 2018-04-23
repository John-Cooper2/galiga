#ifndef UPDATEHANDLER_H_INCLUDED
#define UPDATEHANDLER_H_INCLUDED

#include "GALAGA.H"
#include "bullet.h"
#include "entity.h"

void customUpdate(vector<Bullet> bullets, vector<Entity> enemies);

void customUpdate(Entity f, vector<Bullet> bullets, vector<Entity> enemies, SDL_Plotter& g) {
    f.drawEntity(g);

    cout << "Bullets size: " + bullets.size() << endl;;
    for(int i = 0; i < bullets.size(); i++) {

        Bullet b = bullets[i];
        bullets.erase(bullets.begin() + i);
        b.eraseFighterBullet(g);
        b.y -= BULLET_SPEED;
        b.drawFighterBullet(g);
        bullets.push_back(b);

        for(int j = 0; j < enemies.size(); j++) {

            Entity enemy = enemies[j];
            // TODO: update position, if want?

            bool isHit = false;
            // TODO: collision logic

            if(isHit) {
                // TODO: remove bullet and enemy from vectors, erase both, increment score
                b.eraseFighterBullet(g);

                bullets.erase(bullets.begin() + i);
                enemies.erase(enemies.begin() + j);


            }
        }
    }

    g.update();
}

#endif // UPDATEHANDLER_H_INCLUDED
