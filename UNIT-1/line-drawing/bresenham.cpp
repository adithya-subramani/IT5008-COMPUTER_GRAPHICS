#include <stdlib.h>
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>

class BresenhamLine{
public:
    BresenhamLine(float x1, float y1, float x2, float y2)
    {
        // Algorithm
        int dx, dy, i, e;
        int incx, incy, inc1, inc2;
        int x,y;

        dx = x2-x1;
        dy = y2-y1;

        if (dx < 0) dx = -dx;
        if (dy < 0) dy = -dy;
        incx = 1;
        if (x2 < x1) incx = -1;
        incy = 1;
        if (y2 < y1) incy = -1;
        x = x1; y = y1;
        if (dx > dy) {
            glBegin(GL_POINTS);
            glVertex2i(x, y);
            glEnd();
            e = 2 * dy-dx;
            inc1 = 2*(dy-dx);
            inc2 = 2*dy;
            for (i=0; i<dx; i++) {
                if (e >= 0) {
                    y += incy;
                    e += inc1;
                }
                else
                    e += inc2;
                x += incx;
                glBegin(GL_POINTS);
                glVertex2i(x, y);
                glEnd();
            }

        } else {
            glBegin(GL_POINTS);
            glVertex2i(x, y);
            glEnd();
            e = 2*dx-dy;
            inc1 = 2*(dx-dy);
            inc2 = 2*dx;
            for (i=0; i<dy; i++) {
                if (e >= 0) {
                    x += incx;
                    e += inc1;
                }
                else
                    e += inc2;
                y += incy;
                glBegin(GL_POINTS);
                glVertex2i(x, y);
                glEnd();
            }
        }
        glutPostRedisplay();
    }    
};