#ifndef CHICKEN_FILE
#define CHICKEN_FILE

#include <stdlib.h>
#include <cmath>
#include <GL/glut.h>

#include "./util.cpp"

class Chicken
{
public:
    double health = 10;
    int curX = 5;
    int curY = 735;
    bool movingRight = true;

    void tick() {
        if(movingRight) {
            curX += 5;
            if(curX == 780) {
                movingRight = false;
            }
        } else {
            curX -= 5;
            if(curX == 5) {
                movingRight = true;
            }
        }
    }

    void draw() {
        glPushMatrix();

        glTranslatef(curX, curY, 0);
        if(!movingRight) {
            glScalef(-1, 1, 1);
            glTranslatef(-200, 0, 0);
        }

        glColor3f(0.41, 0.35, 0.32); // Main body
        drawCircle(100, 100, 100);

        // draw beak
        glColor3f(1.00, 0.66, 0.13);
        drawRect(170, 100, 55, 25);

        // draw hat
        glColor3f(1.00, 0.21, 0.22);
        glBegin(GL_POLYGON);
        glVertex2f(100, 230);
        glVertex2f(18, 160);
        glVertex2f(182, 160);
        glEnd();

        // draw eyes
        glColor3f(0.19, 0.03, 0.03);
        drawRect(120, 100, 25, 50);

        // draw Health
        glColor3f(1.00, 1.00, 1.00);
        drawRect(0, 235, 200.0, 20);
        glColor3f(1.00, 0.00, 0.00);
        drawRect(2, 237, ((health/10.0)*200.0)-4, 20-4);

        glPopMatrix();
    }
};

#endif