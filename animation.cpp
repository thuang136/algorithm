#include<GL/freeglut.h>
#include<math.h>

static GLfloat spin = 0.0;

GLsizei winWidth = 600,winHeight = 600;

typedef GLfloat Matrix3x3 [3][3];

Matrix3x3 matComposite;

const GLdouble pi = 3.14159;


class wcPt2D {
    public:
        GLfloat x,y;
};

GLfloat xwcMin = 0.0, xwcMax = 225.0;
GLfloat ywcMin = 0.0, ywcMax = 225.0;


void init()
{
    glClearColor(0.0,0.0,0.0,0.0);
    glShadeModel(GL_FLAT);
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


void rectangle(wcPt2D *verts)
{
    GLint k;

    glBegin(GL_QUADS);

    for( k = 0; k < 4; k++)
    {
        glVertex2f(verts[k].x,verts[k].y);
    }

    glEnd();
}

void transformVerts2D(GLint nVerts,wcPt2D *verts)
{
    GLint k;
    GLfloat temp;

    wcPt2D centerPt;
    float half_width = fabs((verts[0].x - verts[2].x)/2);
    float half_height = fabs((verts[0].y - verts[2].y)/2);
    centerPt.x = (verts[0].x + verts[2].x)/2;
    centerPt.y = (verts[0].y + verts[2].y)/2;

    wcPt2D transformPt;

    for(k = 0; k < nVerts; k++)
    {
       temp = matComposite[0][0] * centerPt.x + matComposite[0][1] * centerPt.y + matComposite[0][2];
       transformPt.y = matComposite[1][0] * centerPt.y + matComposite[1][1] * centerPt.y + matComposite[1][2];
       transformPt.x = temp;
    }

    verts[0].x = transformPt.x - half_width;
    verts[0].y = transformPt.y - half_height;

    verts[1].x = transformPt.x + half_width;
    verts[1].y = transformPt.y - half_height;

    verts[2].x = transformPt.x + half_width;
    verts[2].y = transformPt.y + half_height;

     verts[3].x = transformPt.x - half_width;
    verts[3].y = transformPt.y + half_height;

}

void displayFcn()
{
    wcPt2D verts[4] = { {0.0,0.0},{10.0,0.0},{10.0,10.0},{0.0,10.0} };

    glClear(GL_COLOR_BUFFER_BIT);

    matrix3x3SetIdentity(matComposite);

    translate2D(xwcMax/4,ywcMax/4);

    wcPt2D pivotPt;
    pivotPt.x = xwcMax/2;
    pivotPt.y = ywcMax/2;

    GLdouble theta = spin/360.0 * 2 * pi;

    rotate2D(pivotPt,theta);

    transformVerts2D(4,verts);

    glColor3f(1.0,1.0,1.0);
    rectangle(verts);

    glutSwapBuffers();
}

void winReshapeFunc(GLint newWidth, GLint newHeight)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(xwcMin,xwcMax,ywcMin,ywcMax);

    glClear(GL_COLOR_BUFFER_BIT);


}

void spinDisplay()
{
    spin = spin + 2.0;
    if(spin > 36.0)
    {
        spin -= 360.0;
    }

    glutPostRedisplay();

}

int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(50,50);
    glutInitWindowSize(winWidth,winHeight);
    glutCreateWindow("transform animation");

    init();
    glutDisplayFunc(displayFcn);
    glutReshapeFunc(winReshapeFunc);
    glutIdleFunc(spinDisplay);
    glutMainLoop();
}

