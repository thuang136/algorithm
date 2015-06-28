
#include <GL/glew.h>
#include <GL/freeglut.h>
#include<cmath>

#include <iostream>
using namespace std;

#define VERTICES 0
#define INDICES 1
#define NUM_BUFFERS 2

GLuint buffers[NUM_BUFFERS];

#define BUFFER_OFFSET(offset) ((GLvoid*)NULL + offset)

int xRotate = 0;
int yRotate = 0;


void init()
{
    glClearColor(0.0,0.0,0.0,0.0);

    glShadeModel(GL_FLAT);



}

void display()
{
    glFrontFace(GL_CCW);

    //glEnable(GL_DEPTH_TEST);

    //glCullFace(GL_BACK);

    //glEnable(GL_CULL_FACE);

    /*多边形用轮廓表示  */
    //glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);



    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0,1.0,1.0);

    glLoadIdentity();

    gluLookAt(0.0,0.0,5.0,0.0,0.0,0.0,0.0,1.0,0.0);

    glScalef(1.0,1.0,1.0);

    cout << xRotate << " " << yRotate << endl;

    glRotatef(xRotate,1.0f,0.0f,0.0f);
    glRotatef(yRotate,0.0f,1.0f,0.0f);


    GLfloat cubeVerts[][3] = {
                    {-1.0,-1.0,-1.0},
                    {1.0,-1.0,-1.0},
                    {-1.0,1.0,-1.0},
                    {1.0,1.0,-1.0},
                    {-1.0,-1.0,1.0},
                    {1.0,-1.0,1.0},
                    {-1.0,1.0,1.0},
                    {1.0,1.0,1.0},

                };


     GLubyte cubeIndices[] = {
           0,2,3,1,
           0,4,6,2,
           0,1,5,4,
           4,5,7,6,
           1,3,7,5,
           2,6,7,3
     };


     glGenBuffers(NUM_BUFFERS,buffers);

     glBindBuffer(GL_ARRAY_BUFFER,buffers[VERTICES]);

     glBufferData(GL_ARRAY_BUFFER,sizeof(cubeVerts),cubeVerts,GL_STATIC_DRAW);

     glVertexPointer(3,GL_FLOAT,0,BUFFER_OFFSET(0));

     glEnableClientState(GL_VERTEX_ARRAY);



     glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,buffers[INDICES]);

     glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(cubeIndices),cubeIndices,GL_STATIC_DRAW);

     glDrawElements(GL_QUADS,24,GL_UNSIGNED_BYTE,BUFFER_OFFSET(0));




    glFlush();
}


void reshape(int w, int h)
{
    glViewport(0,0,(GLsizei)w, (GLsizei)h);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    gluPerspective(45.0,(GLdouble)w/(GLdouble)h,1.0,100);

    glMatrixMode(GL_MODELVIEW);
}


void keyboard(unsigned char key,int x,int y)
{

    switch(key)
    {

        case 'd':
            xRotate = (xRotate + 1) % 180;
            break;

        case 'w':
            yRotate = (yRotate + 1) % 180;
            break;

        default:
            break;

    }

    glutPostRedisplay();

}


int main(int argc, char** argv)
{
    glutInit(&argc,argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB );

    glutInitWindowSize(500,500);

    glutInitWindowPosition(100,100);

    glutCreateWindow(argv[0]);

    GLenum err = glewInit();

    if(GLEW_OK != err)
    {
        cout << "GLEW_OK not ok" << endl;
    }

    if(GLEW_ARB_vertex_program)
    {
        cout << "vertex program available" << endl;
    }

    init();

    glutDisplayFunc(display);

    glutReshapeFunc(reshape);

    glutKeyboardFunc(keyboard);

    glutMainLoop();

    return 0;


}
