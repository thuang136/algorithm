#include <GL/freeglut.h>

#include <iostream>
#include <cstdio>
using namespace std;

static int leftFirst = GL_TRUE;

void init()
{
    glEnable(GL_BLEND);

    //������Ƭ�� �� ԴƬ�Σ� �Ѿ�������֡�������е�������Ŀ�����ء�

    //�ٶ�Դ��Ŀ����������(Sr,Sg,Sb,Sa) ��(Dr,Dg,Db,Da)
    //���յ�RGBA�����ɫ��ͨ�������

    //����alphaֵ����0.75�����Դ��ɫ�Ļ��������0.75����Ŀ����������1.0 - 0.75 = 0.25��
    //ԴƬ�ο���ȥ�ǰ�͸���ģ��������Ƕ�������ɫ��Ӱ�����Ŀ��Ƭ�ζ�������ɫ��Ӱ��
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





