
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/freeglut.h>

#include<iostream>
using namespace std;

#define VERTICES 0
#define INDICES 1

#define NUM_BUFFERS 2

#define BUFFER_OFFSET(bytes) ( (GLubyte*) NULL + (bytes))

GLuint buffers[NUM_BUFFERS];

float spin = 0.0f;

class wcPt3D
{
    public:
        GLfloat x,y,z;
};


typedef float Matrix4x4 [4][4];

Matrix4x4 matRot;

void matrix4x4SetIdentity(Matrix4x4 matIdent4x4)
{
    GLint row,col;
    for( row = 0; row < 4; row++)
    {
        for( col = 0; col < 4; col++)
        {
            matIdent4x4[row][col] = (row == col);
        }
    }
}

void matrix4x4PreMultiply(Matrix4x4 m1,Matrix4x4 m2)
{
   Matrix4x4 mat;
   GLint row,col;
   for( row = 0; row < 4; row++)
   {
       for( col = 0; col < 4; col++)
       {
           for(int k = 0; k < 4; k++)
           {
               mat[row][col] += m1[row][k] * m2[k][col];
           }
       }
   }

   for( row = 0; row < 4; row++)
   {
       for( col = 0 ; col < 4; col++)
       {
           m2[row][col] = mat[row][col];
       }
   }

}

void translate3D(GLfloat tx, GLfloat ty, GLfloat tz)
{
    Matrix4x4 matTrans;

    matrix4x4SetIdentity(matTrans);

    matTrans[0][3] = tx;
    matTrans[1][3] = ty;
    matTrans[2][3] = tz;
    matrix4x4PreMultiply(matTrans,matRot);

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

    glLoadIdentity();
    glRotatef(spin,0,1,0);
    gluLookAt(5.0,5.0,5.0,0.0,0.0,0.0,0.0,0.0,1.0);

    glTranslatef(0.0,0.0,-5.0);

    GLfloat vertices[][3] = {
            {-2.0,-2.0,-1.0},
            {2.0,-2.0,-1.0},
            {2.0,2.0,-1.0},
            {-2.0,2.0,-1.0},
            {-2.0,-2.0,1.0},
            {2.0,-2.0,1.0},
            {2.0,2.0,1.0},
            {-2.0,2.0,1.0}
        };

    GLubyte indices[][4] = {
            {0,3,2,1},
            {4,5,6,7},
            {2,3,7,6},
            {0,1,5,4},
            {2,6,5,1},
            {7,3,0,4}
        };

    glEnable(GL_DEPTH_TEST);
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3,GL_FLOAT,0,vertices);

    glDrawElements(GL_QUADS,24,GL_UNSIGNED_BYTE,indices);

    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glEnable(GL_POLYGON_OFFSET_FILL);
    glPolygonOffset(1.0,1.0);
    glColor3f(1.0,0.0,0.0);

    glDrawElements(GL_QUADS,24,GL_UNSIGNED_BYTE,indices);
    glDisable(GL_POLYGON_OFFSET_FILL);

    glPopMatrix();

    glutSwapBuffers();

}

void spinDisplay()
{
   spin += 1.0f;

   if( spin > 360.0f)
   {
       spin -= 360.0f;
   }

   glutPostRedisplay();
}

void reshape(int w, int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();
    gluPerspective(60.0,(GLfloat)w/(GLfloat)h,1.0,20.0);
    glMatrixMode(GL_MODELVIEW);


}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow(argv[0]);
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(spinDisplay);
    glutMainLoop();
    return 0;
}