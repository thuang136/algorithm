#include <GL/freeglut.h>

#include <iostream>
#include <cstdio>
using namespace std;


void init()
{
    glClearColor(1.0,1.0,0.0,0.0);

    //����ԴƬ�ε���ɫ������Ѿ��洢��֡�������е����ص���ɫ�������
    glBlendFunc(GL_ONE,GL_ONE);

    // �������ָ����Ϻ�������Ҫ���û�Ϲ���
    glEnable(GL_BLEND);
}

void display()
{
    cout << "display" << endl;

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,1.0);
    glRectf(-0.5,-0.5,0.5,0.5);
    glFlush();

}

// �ڱ�׼�Ļ���У� ֡�������е���ɫ����Ƭ�ε���ɫ������ϣ������»���������ɫ

void keyboard(unsigned char key, int x, int y)
{
    cout << key << endl;

    switch(key)
    {
        case 'a' : case 'A':
            glBlendEquation(GL_FUNC_ADD);
            break;
        case 's' : case 'S':
            glBlendEquation(GL_FUNC_SUBTRACT);
            break;
        case 'r' : case 'R':
            glBlendEquation(GL_FUNC_REVERSE_SUBTRACT);
            break;
        case 'm' : case 'M':
            glBlendEquation(GL_MIN);
            break;
        case 'x' : case 'X':
            glBlendEquation(GL_MAX);
            break;
        case 27:
            exit(0);
    }

    glutPostRedisplay();

}

void reshape(int w, int h)
{
    glViewport(0,0,w,h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(-1.0,1.0,-1.0,1.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_SINGLE);

    glutInitWindowSize(500,500);

    glutCreateWindow("Temperature Shader");

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutKeyboardFunc(keyboard);

    glutMainLoop();

}


