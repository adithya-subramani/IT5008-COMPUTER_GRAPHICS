#include ".././line-drawing/DDA.cpp"
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

int getRegCode(int x,int y){
    int rc=0;
    if(x<w_x0) rc+=1;
    if(x>w_x1) rc+=2;
    if(y<w_y0) rc+=4;
    if(y>w_y1) rc+=8;
    return rc;
}

void dispPoint(int x,int y){
    glPointSize(5);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glPointSize(1);
}

void cohenSutherland(){
    // 1. Get regional code
    int s_rc= getRegCode(xs,ys);
    int e_rc= getRegCode(xe,ye);

    // 2. Perform 'OR' operation
    int r_or = s_rc | e_rc ;
    if(r_or){
        int r_and = s_rc & e_rc;
        if(r_and) return; // Line is considered invisible
        else{
            // Line needs to be clipped
            double m = (ye-ys)/double(xe-xs);
            glColor3f(255, 0,0);
            if(r_or&1) dispPoint(w_x0,ys + m*(w_x0-xs)); // Intersection on left side
            if(r_or&2) dispPoint(w_x1,ys + m*(w_x1-xs)); // Intersection on right side
            if(r_or&4) dispPoint(xe + (w_y0-ye)/m,w_y0); // Intersection on bottom side
            if(r_or&8) dispPoint(xe + (w_y1-ye)/m,w_y1); // Intersection on top side
            return;
        }
    }
    else return; // Point lies completely inside clipping window
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
    cohenSutherland();

    glFlush();
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Cohen-Sutherland line clipping algorithm");
    myInit();
    glutDisplayFunc(display);
    glutMainLoop();
}