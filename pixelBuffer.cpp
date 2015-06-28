/*

ͨ�������ؾ������ݴ洢�ڷ������˵Ļ����������У�������������Ⱦÿһ֡ʱ�������ݴӿͻ����ڴ洫�䵽opengl�������Ŀ���

Ϊ�˰�һ��ͼ����ȾΪ�����ı��������Բ�����glClear���������Ǹ��û���������


��ʹ�û���������洢����������ȣ����ػ���������ȿ��Զ�ȡ��Ҳ����д�룬����opengl��ȡ��������ʱ�ͻ�д�뵽�����������������

glReadPixel(), ���� glGetTexImage() ��ȡһ�����������Ԫʱ


*/

#include <GL/glew.h>
#include <GL/freeglut.h>

#include <iostream>
using namespace std;

#define BUFFER_OFFSET(bytes)  ((GLubyte*)NULL + (bytes))

#define checkImageWidth 64

#define checkImageHeight 64

GLubyte checkImage [checkImageWidth][checkImageHeight][3];


static GLdouble zoomFactor = 1.0;
static GLint height;

static GLuint pixelBuffer;


void makeCheckImage()
{
    int i,j,c;

    for(i = 0 ; i < checkImageHeight; i++)
    {
       for(j = 0 ; j < checkImageWidth; j++)
       {
           c = ((( i & 0x8) == 0 ) ^ (( j & 0x8) == 0 )) * 255;

           checkImage[i][j][0] = (GLubyte)c;
           checkImage[i][j][1] = (GLubyte)c;
           checkImage[i][j][2] = (GLubyte)c;
       }
    }

}

void init()
{
    glewInit();
    glClearColor(0.0,0.0,0.0,0.0);

    glShadeModel(GL_FLAT);

    makeCheckImage();

    glGenBuffers(1,&pixelBuffer);
    glBindBuffer(GL_PIXEL_UNPACK_BUFFER, pixelBuffer);
    glBufferData(GL_PIXEL_UNPACK_BUFFER,3 * checkImageWidth * checkImageHeight, checkImage,GL_STATIC_DRAW);

}


void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    /*
        ��ǰ��դ��λ�þ��ǿ�ʼ������һ��λͼ����Ļλ�á���դλ�õ����걻�任Ϊ��Ļ���꣬��������Ϊ��������glVertex����һ����(Ҳ����˵����ģ����ͼ��ͶӰ������б任)���ڱ任
        ֮�������߶������ӿ��е�һ����Ч�ĵ㣬���������Ӿ�����ⲿ�����ü�������������任�ĵ㱻�ü�������ǰ�Ĺ�դλ�þ�����Ч��


    */
    glRasterPos2i(0,0);

    glBindBuffer(GL_PIXEL_UNPACK_BUFFER,pixelBuffer);

    glDrawPixels(checkImageWidth,checkImageHeight,GL_RGB,GL_UNSIGNED_BYTE,BUFFER_OFFSET(0) );

    glFlush();

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

    glutCreateWindow("Pixel Buffer");

    init();


    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();
    return 0;


}

