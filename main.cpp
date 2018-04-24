#include <iostream>
#include <fstream>
#include <string>
#include "Galaga.h"
#include "Entity.h"
#include "Bullet.h"

using namespace std;

int main(int argc, char ** argv)
{

    SDL_Plotter g(SCREEN_WIDTH, SCREEN_HIEGHT);
    GlobalTimer globalTime;
    Entity f;
    //Entity ship(2,200,200);
    Bullet b;

    int ENEMY_DIRECTION = 1;
    Entity enemies[5];
    for(unsigned i = 0; i < (sizeof(enemies)/sizeof(*enemies)); i++) {
        enemies[i] = Entity(2, i * 50, i * 50);
    }

    //Bullet star(2,rand(),0,false);
    char key;
    g.initSound("./sounds/lasershot.mp3");

    //draws background
    for (int x = 0; x < SCREEN_WIDTH; x++)
        for (int y = 0; y < SCREEN_HIEGHT; y++)
            g.plotPixel(x,y,0,0,0);

    while (!g.getQuit())
    {
        /*int mx, my;
        if(g.getMouseMotion(mx, my))
        {
            f.eraseFighter(g);
            f.x = mx;
            f.drawFighter(g);
        }
        if(g.getMouseClick(mx, my))
            shoot(f.x,f.y,g);
        */
		if(g.kbhit()){
			key = g.getKey();
			switch(key){
			    case RIGHT_ARROW:       f.eraseEntity(g);
                                        if(f.x + FIGHTER_SPEED < SCREEN_WIDTH - 90)
                                            f.x += FIGHTER_SPEED;
                                        break;
                case LEFT_ARROW:        f.eraseEntity(g);
                                        if(f.x - FIGHTER_SPEED - 10 > 0)
                                            f.x -= FIGHTER_SPEED;
                                        break;
                case ' ':               g.playSound("./sounds/lasershot.mp3");
                                        b.shoot(f.x, f.y, g, enemies, (sizeof(enemies)/sizeof(*enemies)));
                                        break;
                case RIGHT_AND_SPACE:   g.playSound("./sounds/lasershot.mp3");
                                        b.shoot(f.x,f.y,g, enemies, (sizeof(enemies)/sizeof(*enemies)));
                                        break;
                case LEFT_AND_SPACE:    g.playSound("./sounds/lasershot.mp3");
                                        b.shoot(f.x,f.y,g, enemies, (sizeof(enemies)/sizeof(*enemies)));
                                        break;
			}
		}

		// Get score into string and print it
		char buffer[10];
		printText("Score " + string(itoa(SCORE, buffer, 10)), 100, 100, 2, g);

		// Draw fighter
		f.drawEntity(g);

		// Get the first and last enemies to use later
        Entity firstEnemy = enemies[0];
        Entity lastEnemy = enemies[sizeof(enemies)/sizeof(*enemies) - 1];

		// Loop through enemies, draw them and update their positions
		for(unsigned i = 0; i < (sizeof(enemies)/sizeof(*enemies)); i++) {
            // Draw enemy if it is alive
            if(enemies[i].isAlive) {
                enemies[i].eraseEntity(g);
            }

            // Check if enemies are running into the edges of the screen, reverse them if they are
            if((lastEnemy.x + lastEnemy.speed * ENEMY_DIRECTION) > SCREEN_WIDTH - 50) {
                ENEMY_DIRECTION *= -1;
            }
            else if((firstEnemy.x + firstEnemy.speed * ENEMY_DIRECTION) < 0) {
                ENEMY_DIRECTION *= -1;
            }

            // Update current enemy's position
            enemies[i].x += enemies[i].speed * ENEMY_DIRECTION;

            // Erase enemy if it is alive
            if(enemies[i].isAlive) {
                enemies[i].drawEntity(g);
            }
		}

		//ship.drawEntity(g);
		//star.shoot(globalTime.rng()%1000,0,g);

		// Update the plotter
        g.update();

    }
    return 0;
}
