#include <stdlib.h>
#include <cmath>
#include <GL/glut.h>

#include "./player.cpp"

Player *player;

void Draw();
void KeyDown(int key, int x, int y);

int main(int argc, char **argr)
{
    glutInit(&argc, argr);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Chicken Invaders");
    glutDisplayFunc(Draw);
    glutSpecialFunc(KeyDown);
    glutIdleFunc(Draw);

    // Setup main objects
    player = new Player();

    glClearColor(COLOR_BACKGROUND, 0);
    gluOrtho2D(0.0, 1000.0, 0.0, 1000.0);

    glutMainLoop();
    return 0;
}

void KeyDown(int key, int x, int y) {
    player->keyDown(key);
    glutPostRedisplay();
}

void Draw() {
    glClear(GL_COLOR_BUFFER_BIT);

    player->draw();

    glutSwapBuffers();
}