#include<GL/freeglut.h>
#include<math.h>

void init()
{
    glClearColor(1.0,0.0,0.0,1.0);
    glShadeModel(GL_FLAT);
    glClearStencil(0);
    glEnable(GL_STENCIL_TEST);
}

void myReshape(GLsizei w, GLsizei h)
{
    glViewport(0,0,w,h);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);

}

void myDisplay()
{


    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    glLoadIdentity();

    glStencilFunc(GL_NEVER,0xff,0xff);

    glStencilOp(GL_INCR_WRAP,GL_INCR_WRAP,GL_INCR_WRAP);

    GLdouble dRadius = 0.5;

    glBegin(GL_LINE_LOOP);

    for(double angle =  0.0; angle < 3.1415926 * 2; angle+= 0.001)
    {
        glVertex2d(dRadius * cos(angle), dRadius * sin(angle));
    }

    glEnd();

    glStencilFunc(GL_NOTEQUAL,0x1,0x1);
    glStencilOp(GL_KEEP,GL_KEEP,GL_KEEP);

    glColor3f(0.0,1.0,1.0);

    glRectf(-0.8f,-0.8f,0.8f,0.8f);

    glutSwapBuffers();

}

int main(int argc, char** argv)
{
    glutInit(&argc,argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_STENCIL);

    glutInitWindowSize(400,400);

    glutInitWindowPosition(200,200);

    glutCreateWindow("stencil test");

    init();

    glutReshapeFunc(myReshape);
    glutDisplayFunc(myDisplay);

    glutMainLoop();

    return 0;
}


