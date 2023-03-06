#include <stdlib.h>
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>

class DDALine{
private:
    float x0, y0, xe, ye;
public:
    DDALine(float x1, float y1, float x2, float y2)
    {
        x0 = x1;
        y0 = y1;
        xe = x2;
        ye = y2;

        // Algorithm
        float dy, dx, step, x, y, k, Xin, Yin;
        dx = xe - x0;
        dy = ye - y0;
        step=abs(dx)>abs(dy)?abs(dx):abs(dy);
        Xin = dx / step;
        Yin = dy / step;
        x = x0;
        y = y0;
        glBegin(GL_POINTS);
        glVertex2i(x, y);
        glEnd();
        for (k = 1; k <= step; k++){
            x = x + Xin;
            y = y + Yin;
            glBegin(GL_POINTS);
            glVertex2i(x, y);
            glEnd();
        }
        glutPostRedisplay();
    }    
};