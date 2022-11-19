#ifndef PLAYER_FILE
#define PLAYER_FILE

#include <GL/glut.h>

#include "./util.cpp"

class Player
{
public:
    double curX = 450;
    double curY = 450;
    int health = 3;
    bool isProtected = false;
    int protectionTimer = 0;

    void startProtection() {
        isProtected = true;
        protectionTimer = glutGet(GLUT_ELAPSED_TIME) + 6000;
    }

    bool isKeyDown[256] = {0};
    void specialKeyDown(int c) {
        isKeyDown[c] = true;
    }

    void specialKeyUp(int c) {
        isKeyDown[c] = false;
    }

    void tick() {
        if(isProtected && glutGet(GLUT_ELAPSED_TIME) > protectionTimer) {
            isProtected = false;
        }

        if(isKeyDown[GLUT_KEY_LEFT] && curX > 0) {
            curX -= 3;
        }
        if(isKeyDown[GLUT_KEY_RIGHT] && curX < 900) {
            curX += 3;
        }
        if(isKeyDown[GLUT_KEY_UP] && curY < 600) {
            curY += 3;
        }
        if(isKeyDown[GLUT_KEY_DOWN] && curY > 0) {
            curY -= 3;
        }
    }

    void draw() {
        glPushMatrix();
        glTranslatef(curX, curY, 0);

        if(isProtected) {
            glColor3f(0.00, 1.00, 0.23);
        }

        // Draw ship body
        if(!isProtected) glColor3f(0.25, 0.32, 0.32);
        drawRect(20, 0, 30, 60);

        glBegin(GL_POLYGON); // top thing
        glVertex2f(20, 60);
        glVertex2f(50, 60);
        glVertex2f(35, 75);
        glEnd();

        if(!isProtected) glColor3f(0.67, 0.13, 0.13);
        glBegin(GL_POLYGON); // wings
        glVertex2f(20, 10);
        glVertex2f(20, 40);
        glVertex2f(0, 10);
        glEnd();

        glBegin(GL_POLYGON);
        glVertex2f(50, 10);
        glVertex2f(50, 40);
        glVertex2f(70, 10);
        glEnd();

        glColor3f(0.13, 0.75, 0.99); // 8orfet elkyada
        drawCircle(35, 35, 7);

        glPopMatrix();
    }
};

#endif