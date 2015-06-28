/*

通过把像素矩形数据存储在服务器端的缓冲区对象中，可以消除在渲染每一帧时都把数据从客户机内存传输到opengl服务器的开销

为了把一幅图像渲染为场景的背景，可以不调用glClear方法，而是改用缓冲区对象


与使用缓冲区对象存储顶点数据相比，像素缓冲区对象既可以读取，也可以写入，当从opengl提取像素数据时就会写入到缓冲区对象，例如调用

glReadPixel(), 或者 glGetTexImage() 提取一个纹理的纹理单元时


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
        当前光栅的位置就是开始绘制下一幅位图的屏幕位置。光栅位置的坐标被变换为屏幕坐标，就像以它为参数调用glVertex函数一样，(也就是说，用模型视图和投影矩阵进行变换)。在变换
        之后，它或者定义了视口中的一个有效的点，或者由于视景体的外部而被裁减掉，如果经过变换的点被裁减掉，当前的光栅位置就是无效的


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

