#include "DDA.cpp"
#include <stdlib.h>
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>

void myInit(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void display()
{
    // name: ADITHYA
    int yb1=200,yb2=240;

    glClear(GL_COLOR_BUFFER_BIT);

    // A
    DDALine(60,yb1,80,yb2);
    DDALine(80,yb2,100,yb1);
    DDALine(65,yb1+10,95,yb1+10);

    // D
    DDALine(130,yb1,130,yb2);
    DDALine(130,yb2,160,yb2-5);
    DDALine(160,yb2-5,160,yb1+5);
    DDALine(160,yb1+5,130,yb1);

    // I
    DDALine(190,yb1,190,yb2);

    // T
    DDALine(235,yb1,235,yb2);
    DDALine(220,yb2,250,yb2);

    // H
    DDALine(280,yb1,280,yb2);
    DDALine(280,yb1+20,310,yb1+20);
    DDALine(310,yb1,310,yb2);

    // Y
    DDALine(340,yb2,355,yb1+20);
    DDALine(355,yb1,355,yb1+20);
    DDALine(355,yb1+20,370,yb2);

    // A
    DDALine(400,yb1,420,yb2);
    DDALine(420,yb2,440,yb1);
    DDALine(405,yb1+10,435,yb1+10);

    glFlush();
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("DDA line drawing algorithm");
    myInit();
    glutDisplayFunc(display);
    glutMainLoop();
}