#include "bresenham.cpp"
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
    BresenhamLine(60,yb1,80,yb2);
    BresenhamLine(80,yb2,100,yb1);
    BresenhamLine(65,yb1+10,95,yb1+10);

    // D
    BresenhamLine(130,yb1,130,yb2);
    BresenhamLine(130,yb2,160,yb2-5);
    BresenhamLine(160,yb2-5,160,yb1+5);
    BresenhamLine(160,yb1+5,130,yb1);

    // I
    BresenhamLine(190,yb1,190,yb2);

    // T
    BresenhamLine(235,yb1,235,yb2);
    BresenhamLine(220,yb2,250,yb2);

    // H
    BresenhamLine(280,yb1,280,yb2);
    BresenhamLine(280,yb1+20,310,yb1+20);
    BresenhamLine(310,yb1,310,yb2);

    // Y
    BresenhamLine(340,yb2,355,yb1+20);
    BresenhamLine(355,yb1,355,yb1+20);
    BresenhamLine(355,yb1+20,370,yb2);

    // A
    BresenhamLine(400,yb1,420,yb2);
    BresenhamLine(420,yb2,440,yb1);
    BresenhamLine(405,yb1+10,435,yb1+10);

    glFlush();
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Bresenham line drawing algorithm");
    myInit();
    glutDisplayFunc(display);
    glutMainLoop();
}