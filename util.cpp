#ifndef UTIL_FILE
#define UTIL_FILE

#include <GL/glut.h>
#include <cmath>
#include <string>

using namespace std;

#define COLOR_BACKGROUND 0.1, 0.0, 0.1

void drawRect(int x, int y, int w, int h)
{
  glBegin(GL_POLYGON);
  glVertex2f(x, y);
  glVertex2f(x + w, y);
  glVertex2f(x + w, y + h);
  glVertex2f(x, y + h);
  glEnd();
}

void drawCircle(int x, int y, float r)
{
  glPushMatrix();
  glTranslatef(x, y, 0);
  GLUquadric *quadObj = gluNewQuadric();
  gluDisk(quadObj, 0, r, 50, 50);
  glPopMatrix();
}

void drawHeart()
{
  glBegin(GL_POLYGON);
  for (double t = 0; t <= 6; t += 0.001)
  {
    double sn = sin(t);
    double cs = cos(t);
    double x = 16 * sn * sn * sn;
    double y = 13 * cos(t) - 5 * cos(2 * t) - 2 * cos(3 * t) - cos(4 * t);
    glVertex2f(x, y);
  }
  glEnd();
}

void drawString(string str, int x, int y, bool small = false) {
  glPushMatrix();
  glRasterPos2i(x, y);
  for( size_t i = 0; i < str.size(); ++i ) {
      glutBitmapCharacter(small ? GLUT_BITMAP_TIMES_ROMAN_10 : GLUT_BITMAP_TIMES_ROMAN_24, (int)str[i] );
  }
  glPopMatrix();
}

double distanceBetweenPoints(int x1, int y1, int x2, int y2)
{
  return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

#endif