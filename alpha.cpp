#include <GL/freeglut.h>

#include <iostream>
#include <cstdio>
using namespace std;

static int leftFirst = GL_TRUE;

void init()
{
    glEnable(GL_BLEND);

    //被处理片段 是 源片段， 已经处理在帧缓冲区中的像素是目标像素。

    //假定源和目标混合因子是(Sr,Sg,Sb,Sa) 和(Dr,Dg,Db,Da)
    //最终的RGBA混合颜色是通过下面的

    //由于alpha值都是0.75，因此源颜色的混合因子是0.75，而目标混合因子是1.0 - 0.75 = 0.25，
    //源片段看上去是半透明的，但是它们对最终颜色的影响大于目标片段对最终颜色的影响
    glBlendFunc(GL_ONE,GL_ONE_MINUS_SRC_ALPHA);

    glShadeModel(GL_FLAT);

    glClearColor(0.0,0.0,0.0,0.0);

}

void drawLeftTriangle()
{
    glBegin(GL_TRIANGLES);

    glColor4f(1.0,1.0,0.0,0.75);
    glVertex3f(0.1,0.9,0.0);
    glVertex3f(0.1,0.1,0.0);
    glVertex3f(0.7,0.5,0.0);

    glEnd();
}

void drawRightTriangle()
{
    glBegin(GL_TRIANGLES);

    glColor4f(0.0,1.0,1.0,0.75);

    glVertex3f(0.9,0.9,0.0);
    glVertex3f(0.3,0.5,0.0);
    glVertex3f(0.9,0.1,0.0);

    glEnd();

}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    if(leftFirst)
    {
        drawLeftTriangle();
        drawRightTriangle();
    }
    else
    {
        drawRightTriangle();
        drawLeftTriangle();
    }

    glFlush();
}


void reshape(int w, int h)
{
    glViewport(0,0,(GLsizei)w, (GLsizei)h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if( w <= h)
    {
        gluOrtho2D(0.0,1.0,0.0,1.0 * (GLfloat) h / (GLfloat)w );
    }
    else
    {
        gluOrtho2D(0.0,1.0 * (GLfloat)w /(GLfloat)h, 0.0, 1.0);
    }

}


void keyboard(unsigned char key, int x, int y)
{

    switch(key)
    {
        case 't':
        case 'T':
            leftFirst = !leftFirst;
            glutPostRedisplay();
            break;
        case 27:
            exit(0);
            break;
        default:
            break;
    }


}

int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(200,200);

    glutCreateWindow(argv[0]);

    init();

    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;


}





