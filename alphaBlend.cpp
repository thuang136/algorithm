#include <GL/freeglut.h>

#include <iostream>
#include <cstdio>
using namespace std;


void init()
{
    glClearColor(1.0,1.0,0.0,0.0);

    //控制源片段的颜色如何与已经存储在帧缓冲区中的像素的颜色进行组合
    glBlendFunc(GL_ONE,GL_ONE);

    // 不管如何指定混合函数，总要启用混合功能
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

// 在标准的混合中， 帧缓冲区中的颜色与新片段的颜色进行组合，产生新缓冲区的颜色

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


