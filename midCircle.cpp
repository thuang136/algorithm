#include<GL/freeglut.h>
#include<iostream>
using namespace std;

class screenPt
{

public:
    screenPt()
    {
        x = y = 0;
    }

    void setCoords(GLint xCoordValue, GLint yCoordValue)
    {
        x = xCoordValue;
        y = yCoordValue;
    }

    GLint getx() const
    {
        return x;
    }

    GLint gety() const
    {
        return y;
    }

    void incrementx()
    {
        x++;
    }

    void decrementy()
    {
        y--;
    }

private:
    GLint x,y;

};

void setPixel(GLint xCoord,GLint yCoord)
{
    glBegin(GL_POINTS);
        glColor3f(1.0,0.0,0.0);
        glVertex2i(xCoord,yCoord);
    glEnd();
}

void circlePlotPoints(GLint xc, GLint yc, screenPt circPt)
{
   setPixel(xc + circPt.getx(), yc + circPt.gety());
   setPixel(xc - circPt.getx(), yc + circPt.gety());
   setPixel(xc + circPt.getx(), yc - circPt.gety());
   setPixel(xc - circPt.getx(), yc - circPt.gety());

   setPixel(xc + circPt.gety(), yc + circPt.getx());
   setPixel(xc - circPt.gety(), yc + circPt.getx());
   setPixel(xc + circPt.gety(), yc - circPt.getx());
   setPixel(xc - circPt.gety(), yc - circPt.getx());
}

void circleMidpoint(GLint xc, GLint yc,GLint radius)
{
    screenPt circPt;

    GLint p = 1 - radius;

    circPt.setCoords(0,radius);

    while(circPt.getx() < circPt.gety())
    {
        circPt.incrementx();

        if( p < 0)
        {
           p += 2 * circPt.getx() + 1;
        }
        else
        {
            circPt.decrementy();
            p += 2 * (circPt.getx() - circPt.gety()) + 1;
        }

        circlePlotPoints(xc,yc,circPt);

    }

}

void init()
{
    glClearColor(0.0,0.0,0.0,0.0);
    glShadeModel(GL_SMOOTH);
}

void myReshape(GLsizei w, GLsizei h)
{
    glViewport(0,0,w,h);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    if( w <= h)
    {
        gluOrtho2D( -400.0 , 400 , -400 * (GLfloat)h/(GLfloat)w, 400 * (GLfloat)h/(GLfloat)w );
    }
    else
    {
        gluOrtho2D( -400.0 * (GLfloat)w/(GLfloat)h, 400.0 * (GLfloat)w/(GLfloat)h, -400.0,400.0);
    }

    glMatrixMode(GL_MODELVIEW);

}

void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);

    circleMidpoint(100,100,50);

    glFlush();
}

int main(int argc ,char** argv)
{
   //circleMidpoint(100,100,50);
   glutInit(&argc, argv);

   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

   glutInitWindowSize(400,400);

   glutInitWindowPosition(200,200);

   glutCreateWindow("mid point circle");



   init();

   glutReshapeFunc(myReshape);

   glutDisplayFunc(myDisplay);

   glutMainLoop();

   return 0;
}



































































