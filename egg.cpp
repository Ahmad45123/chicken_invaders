#include <cmath>
#include <GL/glut.h>

#include "./util.cpp"

class Egg
{
public:
    double curX = 0;
    double curY = 0;
    bool alive = true;

    Egg(double x, double y) {
        curX = x;
        curY = y;
    }

    void tick() {
        if(!alive) return;
        curY -= 3;
        if(curY <= 0) {
            alive = false;
        }
    }

    void draw() {
        glPushMatrix();
        glTranslatef(curX, curY, 0);

        // Draw ellipse
        glColor3f(0.94, 0.92, 0.84);
        glBegin(GL_POLYGON);
        for(int i = 0; i < 360; i++) {
            float degInRad = i * 3.14159 / 180;
            glVertex2f(cos(degInRad) * 6, sin(degInRad) * 8);
        }
        glEnd();

        glPopMatrix();
    }
};