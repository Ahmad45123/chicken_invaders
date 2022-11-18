#include <iostream>
#include <vector>
#include <algorithm>

#include "./player.cpp"
#include "./chicken.cpp"
#include "./bullet.cpp"

using namespace std;

class BulletSystem {
    public:
    Player *player;
    Chicken *chicken;
    vector<Bullet*> bullets;

    BulletSystem(Player *pl, Chicken *chick) {
        player = pl;
        chicken = chick;
    }

    void tick() {
        vector<int> deadBullets;
        for(int i = 0; i < bullets.size(); i++) {
            bullets[i]->tick();
            if(!bullets[i]->alive) deadBullets.push_back(i);
        }
        reverse(deadBullets.begin(), deadBullets.end());
        for(int x : deadBullets) bullets.erase(bullets.begin() + x);

        // Check if bullet hits
        for(int i = 0; i < bullets.size(); i++) {
            if(distanceBetweenPoints(bullets[i]->curX, bullets[i]->curY, chicken->curX+100, chicken->curY+100) <= 100) {
                if(bullets[i]->curY >= chicken->curY && bullets[i]->curY <= chicken->curY + 100) {
                    bullets[i]->alive = false;
                    chicken->health--;
                }
            }
        }
    }

    long lastShot = 0;
    void keyPress(char key) {
        if(key == ' ') {
            if(glutGet(GLUT_ELAPSED_TIME) - lastShot > 500) {
                bullets.push_back(new Bullet(player->curX + 35, player->curY + 75));
                lastShot = glutGet(GLUT_ELAPSED_TIME);
            }
        }
    }

    void draw() {
        for(Bullet *bullet : bullets) {
            bullet->draw();
        }
    }
};