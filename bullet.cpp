#include <stdlib.h>
#include <cmath>
#include <GL/glut.h>

#include "./util.cpp"

class Bullet
{
public:
    double curX = 0;
    double curY = 0;
    bool alive = true;

    Bullet(double x, double y) {
        curX = x;
        curY = y;
    }

    void tick() {
        if(!alive) return;
        curY += 4;
        if(curY >= 1000) {
            alive = false;
        }
    }

    void draw() {
        glPushMatrix();
        glTranslatef(curX, curY, 0);

        glColor3f(1.00, 0.95, 0.00);
        drawRect(0, 0, 5, 10);

        glPopMatrix();
    }
};