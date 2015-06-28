#include<iostream>

#include <GL/freeglut.h>


void init(void)

{

    glClearColor(0.0, 0.0, 0.0, 0.0);//���ñ�����ɫΪ��ɫ

glShadeModel(GL_SMOOTH);//����Ϊ�⻬����ģʽ

}


void myDisplay(void)

{

glClear(GL_COLOR_BUFFER_BIT);// ���������ΪԤ�ȵ�����ֵ,����ɫ



//glTranslatef(0.8, 0.0, 0.0);//ƽ�ƺ�������ʱ���Բ���


glBegin(GL_TRIANGLES);//��ʼ��������


glColor3f(1.0, 0.0, 0.0);//���õ�һ������Ϊ��ɫ

glVertex2f(-1.0, -1.0);//���õ�һ�����������


glColor3f(0.0, 1.0, 0.0);//���õڶ�������Ϊ��ɫ

glVertex2f(0.0, -1.0);//���õڶ������������


glColor3f(0.0, 0.0, 1.0);//���õ���������Ϊ��ɫ

glVertex2f(-0.5, 1.0);//���õ��������������


glEnd();//�����ν���


glFlush();//ǿ��OpenGL����������ʱ��������

}


void myReshape(GLsizei w, GLsizei h)

{

glViewport(0, 0, w, h);//�����ӿ�


glMatrixMode(GL_PROJECTION);//ָ����ǰ����ΪGL_PROJECTION

glLoadIdentity();//����ǰ�����û�Ϊ��λ��


if (w <= h)

gluOrtho2D(-1.0, 1.5, -1.5, 1.5*(GLfloat)h / (GLfloat)w);//�����ά����ͶӰ����

else

gluOrtho2D(-1.0, 1.5*(GLfloat)w / (GLfloat)h, -1.5, 1.5);

glMatrixMode(GL_MODELVIEW);//ָ����ǰ����ΪGL_MODELVIEW

}


int main(int argc, char ** argv)

{

/*��ʼ��*/

glutInit(&argc, argv);

glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);//�����塢RGBģʽ

glutInitWindowSize(400, 400);

glutInitWindowPosition(200, 200);

glutCreateWindow("������");//���ڱ���


init();

    /*��������ʾ*/

glutReshapeFunc(myReshape);//���ڴ�С�����ı�ʱ��ȡ����Ϊ

glutDisplayFunc(myDisplay);//��ʾ����ͼ��


glutMainLoop();//ѭ��

return(0);

}

