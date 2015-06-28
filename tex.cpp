#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/freeglut.h>

#include<iostream>
#include<math.h>



void init()
{
    glClearColor(0.0,0.0,0.0,0.0);
    glShadeModel(GL_FLAT);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,1.0);

    GLint k;
    GLubyte texLine[16];

    for( k = 0 ; k <=2 ; k+= 2)
    {
        texLine[4*k] = 0;
        texLine[4*k + 1] = 255;
        texLine[4*k + 2] = 0;
        texLine[4*k + 3] = 255;
    }

    for( k = 1 ; k <=3 ; k+= 2)
    {
        texLine[4*k] = 255;
        texLine[4*k + 1] = 0;
        texLine[4*k + 2] = 0;
        texLine[4*k + 3] = 255;
    }

    glTexParameteri(GL_TEXTURE_1D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);

    glTexParameteri(GL_TEXTURE_1D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);

    glTexImage1D(GL_TEXTURE_1D,0,GL_RGBA,4,0,GL_RGBA,GL_UNSIGNED_BYTE,texLine);

    float v1[3] = { 10.0f, 200.0f,0.0f};
    float v2[3] = { 200.0f,200.0f,0.0f};

    glEnable(GL_TEXTURE_1D);

    glBegin(GL_LINES);

    glTexCoord1f(-2.0);

    glVertex3fv(v1);

    glTexCoord1f(2.0);

    glVertex3fv(v2);

    glEnd();


    glDisable(GL_TEXTURE_1D);




    glFlush();

}



void reshape(int w, int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(0,w,0,h);


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


