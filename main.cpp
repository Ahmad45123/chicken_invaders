#include <vector>
#include <algorithm>
#include <GL/glut.h>

#include "./player.cpp"
#include "./chicken.cpp"
#include "./eggSystem.cpp"
#include "./bulletSystem.cpp"
#include "./powerUpSystem.cpp"

using namespace std;

bool hasWon = false;
bool hasLost = false;
Player *player;
Chicken *chicken;
EggSystem *eggSystem;
BulletSystem *bulletSystem;
PowerUp *powerUpSystem;

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
    glutTimerFunc(10, Timer, 0);
    glutIdleFunc(Draw);

    // Setup main objects
    player = new Player();
    chicken = new Chicken();
    eggSystem = new EggSystem(player, chicken);
    bulletSystem = new BulletSystem(player, chicken);
    powerUpSystem = new PowerUp(player);

    glClearColor(COLOR_BACKGROUND, 0);
    gluOrtho2D(0.0, 1000.0, 0.0, 1000.0);

    glutMainLoop();
    return 0;
}

void Timer(int tmp) {
    player->tick();
    chicken->tick();
    eggSystem->tick();
    bulletSystem->tick();
    powerUpSystem->tick();

    // Check game status
    if(player->health <= 0) {
        hasLost = true;
    }

    if(chicken->health <= 0) {
        hasWon = true;
    }

    glutPostRedisplay();
    glutTimerFunc(10, Timer, 0);
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

    if(hasLost) {
        glColor3f(1, 0, 0);
        drawString("You lost!", 450, 600);
        glutSwapBuffers();
        return;
    }

    if(hasWon) {
        glColor3f(0, 1, 0);
        drawString("You won :D", 450, 600);
        glutSwapBuffers();
        return;
    }

    player->draw();
    chicken->draw();
    eggSystem->draw();
    bulletSystem->draw();
    powerUpSystem->draw();

    // Draw healths.
    glPushMatrix();
    glTranslatef(20, 20, 0);
    glColor3f(1, 0, 0);  // Color Red
    for(int i = 0; i < player->health; i ++) {
        glPushMatrix();
        glTranslatef(i*35, 0, 0);
        drawHeart();
        glPopMatrix();
    }
    
    glPopMatrix();

    glutSwapBuffers();
}