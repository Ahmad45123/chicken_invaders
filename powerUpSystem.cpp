#include <vector>
#include <algorithm>

#include "./player.cpp"

using namespace std;

class PowerUp {
    public:
    Player *player;
    
    bool isExisting = false;
    double curX = 100;
    double curY = 100;

    PowerUp(Player *pl) {
        player = pl;
    }

    int lastUpdate = 0;
    void tick() {
        if(rand() % 1000 <= 5 && glutGet(GLUT_ELAPSED_TIME) - lastUpdate >= 3000 && !player->isProtected) {
            isExisting = true;
            lastUpdate = glutGet(GLUT_ELAPSED_TIME);
            curX = 100 + rand() % 700;
            curY = 100 + rand() % 700;
        }

        if(isExisting) {
            if(curX >= player->curX && curX <= player->curX + 70) {
                if(curY >= player->curY && curY <= player->curY + 75) {
                    isExisting = false;
                    player->startProtection();
                }
            }
        }
    }

    void draw() {
        if(!isExisting) return;

        glPushMatrix();
        glTranslatef(curX, curY, 0);
        glColor3f(0.00, 1.00, 0.23);
        glBegin(GL_LINE_LOOP);
        glVertex2f(0, 0);
        glVertex2f(5, 15);
        glVertex2f(0, 15);
        glVertex2f(5, 30);
        glVertex2f(14, 30);
        glVertex2f(10, 15);
        glVertex2f(15, 15);
        glEnd();
        glPopMatrix();
    }
};