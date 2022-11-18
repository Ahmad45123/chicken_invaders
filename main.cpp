#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <GL/glut.h>

#include "./player.cpp"
#include "./chicken.cpp"
#include "./eggSystem.cpp"
#include "./bulletSystem.cpp"

using namespace std;

Player *player;
Chicken *chicken;
EggSystem *eggSystem;
BulletSystem *bulletSystem;

void Draw();
void Timer(int tmp);
void KeyDown(int key, int x, int y);
void KeyDown(unsigned char key, int x, int y);

int main(int argc, char **argr)
{
    glutInit(&argc, argr);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Chicken Invaders");
    glutDisplayFunc(Draw);
    glutSpecialFunc(KeyDown);
    glutKeyboardFunc(KeyDown);
    glutTimerFunc(30, Timer, 0);
    glutIdleFunc(Draw);

    // Setup main objects
    player = new Player();
    chicken = new Chicken();
    eggSystem = new EggSystem(player, chicken);
    bulletSystem = new BulletSystem(player, chicken);

    glClearColor(COLOR_BACKGROUND, 0);
    gluOrtho2D(0.0, 1000.0, 0.0, 1000.0);

    glutMainLoop();
    return 0;
}

void Timer(int tmp) {
    chicken->tick();
    eggSystem->tick();
    bulletSystem->tick();

    glutPostRedisplay();
    glutTimerFunc(30, Timer, 0);
}

void KeyDown(int key, int x, int y) {
    player->keyDown(key);
    glutPostRedisplay();
}
void KeyDown(unsigned char key, int x, int y) {
    bulletSystem->keyPress(key);
    glutPostRedisplay();
}

void Draw() {
    glClear(GL_COLOR_BUFFER_BIT);

    player->draw();
    chicken->draw();
    eggSystem->draw();
    bulletSystem->draw();

    glutSwapBuffers();
}