#include ".././line-drawing/DDA.cpp"
#include<algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>

// Clipping window coordinates
int w_x0=150,w_y0=100,w_x1=450,w_y1=400;

// Starting and ending point of line
int xs=30,ys=30,xe=500,ye=480;

void myInit(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void dispPoint(int x,int y){
    glPointSize(5);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glPointSize(1);
}

void liangBarsky(){
    double u1=0.0,u2=1.0;
    double dx=xe-xs,dy=ye-ys;
    double p1=-dx,p2=dx,p3=-dy,p4=dy;
    double q1=xs-w_x0,q2=w_x1-xs,q3=ys-w_y0,q4=w_y1-ys;
    double r1=q1/p1,r2=q2/p2,r3=q3/p3,r4=q4/p4;

    u1=std::max({0.0,r1,r3});
    u2=std::min({1.0,r2,r4});

    glColor3f(255, 0,0);

    // Start
    dispPoint(xs+u1*dx,ys+u1*dy);

    // End
    dispPoint(xs+u2*dx,ys+u2*dy);
}


void display(){
    // Clipping window

    glColor3f(0, 255, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    DDALine(w_x0,w_y0,w_x0,w_y1);
    DDALine(w_x1,w_y0,w_x1,w_y1);
    DDALine(w_x0,w_y0,w_x1,w_y0);
    DDALine(w_x0,w_y1,w_x1,w_y1);

    glColor3f(0, 0, 255);


    // Actual line
    dispPoint(xs,ys);
    dispPoint(xe,ye);

    DDALine(xs,ys,xe,ye);
    liangBarsky();

    glFlush();
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Liang-Barsky line clipping algorithm");
    myInit();
    glutDisplayFunc(display);
    glutMainLoop();
}