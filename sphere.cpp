
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/freeglut.h>

#include<iostream>
#include<math.h>

#define PI 3.1415926

using namespace std;

void drawSphere(int x, int y, int z,float radius)
{

   int longitudeLine =  20;

   int latitudeLine = 20;

   double longitude = -PI / 2;


   for(int i = 0 ; i <=  longitudeLine ; i++)
   {
       longitude += i * PI / longitudeLine;

       double latitude = -PI;

       glBegin(GL_LINES);

       for(int j = 0; j <= latitudeLine; j++)
       {
           latitude += j * PI * 2 / latitudeLine;

           float xCoord = radius * cos(longitude) * cos(latitude);

           float yCoord = radius * cos(longitude) * sin(latitude);

           float zCoord = radius * sin(longitude);

           glVertex3f(xCoord,yCoord,zCoord);

       }

       glEnd();


   }

}


void init()
{
    glClearColor(0.0,0.0,0.0,0.0);
    glShadeModel(GL_FLAT);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,1.0);
    glPushMatrix();


    drawSphere(0,0,0,3.0);

    glPopMatrix();

    glFlush();

}



void reshape(int w, int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();
    gluPerspective(60.0,(GLfloat)w/(GLfloat)h,1.0,20.0);
    glMatrixMode(GL_MODELVIEW);


    glLoadIdentity();
    //glRotatef(spin,0,1,0);

    gluLookAt(5.0,5.0,5.0,0.0,0.0,0.0,0.0,1.0,0.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow(argv[0]);
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}


