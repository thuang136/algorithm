#include<GL/freeglut.h>
#include<math.h>

GLsizei winWidth = 600,winHeight = 600;

GLfloat xwcMin = 0.0, xwcMax = 225.0;
GLfloat ywcMin = 0.0, ywcMax = 225.0;

class wcPt2D {
    public:
        GLfloat x,y;
};

typedef GLfloat Matrix3x3 [3][3];

Matrix3x3 matComposite;

const GLdouble pi = 3.14159;

void init()
{
    glClearColor(1.0,1.0,1.0,1.0);
}

void matrix3x3SetIdentity(Matrix3x3 matIdent3x3)
{
    GLint row, col;

    for( row  = 0; row < 3; row++)
    {
        for( col = 0; col < 3; col++)
        {
            matIdent3x3[row][col] = (row == col);
        }
    }


}

void matrix3x3PreMultiply(Matrix3x3 m1, Matrix3x3 m2)
{
    GLint row, col;

    Matrix3x3 matTemp;

    for( row = 0; row < 3; row++)
    {
       for( col = 0; col < 3; col++)
       {
           matTemp[row][col] = m1[row][0] * m2[0][col] + m1[row][1] * m2[1][col] + m1[row][2] * m2[2][col];
       }
    }

    for( row = 0; row < 3; row++)
    {
       for( col = 0; col < 3; col++)
       {
           m2[row][col] = matTemp[row][col];
       }
    }
}

void triangle(wcPt2D *verts)
{
    GLint k;

    glBegin(GL_TRIANGLES);

    for( k = 0; k < 3; k++)
    {
        glVertex2f(verts[k].x,verts[k].y);
    }

    glEnd();
}


void scale2D (GLfloat sx, GLfloat sy, wcPt2D fixedPt)
{
    Matrix3x3 matScale;

    matrix3x3SetIdentity(matScale);

    matScale[0][0] = sx;
    matScale[0][2] = (1 - sx) * fixedPt.x;
    matScale[1][1] = sy;
    matScale[1][2] = (1 - sy) * fixedPt.y;

    matrix3x3PreMultiply(matScale,matComposite);
}

void translate2D(GLfloat tx,GLfloat ty)
{
    Matrix3x3 matTrans;

    matrix3x3SetIdentity(matTrans);

    matTrans[0][2] = tx;
    matTrans[1][2] = ty;

    matrix3x3PreMultiply(matTrans,matComposite);
}

void rotate2D(wcPt2D pivotPt,GLfloat theta)
{
    Matrix3x3 matRotate;

    matrix3x3SetIdentity(matRotate);

    matRotate[0][0] = cos(theta);
    matRotate[0][1] = -sin(theta);
    matRotate[0][2] = pivotPt.x * ( 1 - cos(theta) ) + pivotPt.y * sin(theta);

    matRotate[1][0] = sin(theta);
    matRotate[1][1] = cos(theta);
    matRotate[1][2] = pivotPt.y * (1 - cos(theta) ) - pivotPt.x * sin(theta);

    matrix3x3PreMultiply(matRotate,matComposite);
}

void transformVerts2D(GLint nVerts,wcPt2D *verts)
{
    GLint k;
    GLfloat temp;

    for(k = 0; k < nVerts; k++)
    {
       temp = matComposite[0][0] * verts[k].x + matComposite[0][1] * verts[k].y + matComposite[0][2];
       verts[k].y = matComposite[1][0] * verts[k].x + matComposite[1][1] * verts[k].y + matComposite[1][2];
       verts[k].x = temp;
    }

}

void displayFcn()
{
    GLint nVerts = 3;

    wcPt2D verts[3] = { {50.0,25.0},{150.0,25.0},{100,100} };

    wcPt2D centroidPt;

    GLdouble theta = pi/4.0;

    GLint k, xSum = 0, ySum = 0;

    for( k = 0; k < nVerts; k++)
    {
        xSum += verts[k].x;
        ySum += verts[k].y;
    }

    centroidPt.x = GLfloat(xSum) / GLfloat(nVerts);
    centroidPt.y = GLfloat(ySum) / GLfloat(nVerts);

    wcPt2D fixedPt,pivotPt;
    fixedPt = centroidPt;
    pivotPt.x = 0.0f;
    pivotPt.y = 0.0f;

    glClear(GL_COLOR_BUFFER_BIT);


    glColor3f(0.0,0.0,1.0);

    triangle(verts);



    matrix3x3SetIdentity(matComposite);

    GLfloat sx = 0.5;
    GLfloat sy = 0.5;


    //scale2D(sx,sy,fixedPt);

    translate2D(100,0);

    rotate2D(pivotPt,theta);

    transformVerts2D(3,verts);

    glColor3f(1.0,0.0,0.0);
    triangle(verts);


    glFlush();



}

void winReshapeFunc(GLint newWidth, GLint newHeight)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(xwcMin,xwcMax,ywcMin,ywcMax);

    glClear(GL_COLOR_BUFFER_BIT);


}



int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50,50);
    glutInitWindowSize(winWidth,winHeight);
    glutCreateWindow("transform");

    init();
    glutDisplayFunc(displayFcn);
    glutReshapeFunc(winReshapeFunc);
    glutMainLoop();
}