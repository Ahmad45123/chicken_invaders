#include <stdlib.h>
#include <cmath>
#include <GL/glut.h>

class Player
{
public:
    double curX = 0;
    double curY = 0;

    void draw()
    {
        glBegin(GL_POLYGON);
        glColor3f(1, 0, 0);
        glVertex3f(0, 0, 0);
        glColor3f(0, 1, 0);
        glVertex3f(100, 0, 0);
        glColor3f(0, 0, 1);
        glVertex3f(50, 50, 0);
        glEnd();
    }
};