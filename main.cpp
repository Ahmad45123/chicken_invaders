#include <stdlib.h>
#include <cmath>
#include <GL/glut.h>

#include "./player.cpp"

Player *player;

void Draw();
int main(int argc, char **argr)
{
    glutInit(&argc, argr);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Chicken Invaders");
    glutDisplayFunc(Draw);
    glutIdleFunc(Draw);

    // Setup main objects
    player = new Player();

    gluOrtho2D(0.0, 1000.0, 0.0, 1000.0);
    glutMainLoop();
    return 0;
}

void Draw(void)
{
    // Clear Color and Depth Buffers
    glClear(GL_COLOR_BUFFER_BIT);
    player->draw();
    glutSwapBuffers();
}