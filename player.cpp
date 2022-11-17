#include <stdlib.h>
#include <cmath>
#include <GL/glut.h>

#include "./util.cpp"

class Player
{
public:
    double curX = 500;
    double curY = 500;

    void draw() {
        glPushMatrix();
        glColor3f(COLOR_SHIP);

        drawRect(0, 0, 100, 200);

        glPopMatrix();
    }
};