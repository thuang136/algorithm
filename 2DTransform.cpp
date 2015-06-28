/*

Objects inside the clipping window are mapped to the viewport, and it is the viewport that is then positioned within the display window. the clipping window selects

what we want to see, the viewport indicates where it is to be viewed on the output device.

by changing the position of a viewport, we can view objects at different position on the display area of an output device. Multiple viewports can be
used to display  different sections of a scene at different screen positions, also , by varying the size of viewports, we can change the size and proportions of displayed objects.

we achieve zooming effects by successivley mapping different sized clipping windows onto a fixed-size viewport.as the clipping windows are made smaller, we zoom in on
some part of a scene to view details that are not shown with the larger clipping windows.

the mapping of a two-dimensional , world-coordinate scene description to device coordinates is called a two-dimensional viewing transformation. sometimes this transformation

is simply referred to as the window-to-viewport tranformation . but in general , viewing involves more than just the tranformation from clipping-window coordinates to viewport coordinate

once a world-coordinate scene has been constructed, we could set up a separate two-dimensional, viewing-coordinate reference frame for specifying the clipping window.but the clipping window

is often just defined in world coordinates, so viewing coordinates for two-dimensional applications are the same as world cooordinate.

to make the viewing process independent of the requirements of any output device, graphics system convert object description to normalized coordinate and applying the clipping routines.
some systems use normalized coordinates in the range from 0 to 1, and other use a normalized range from -1 to 1. depending upon the graphics library in use.at the final step of the viewing
transformation, the contents of the viewport are tranformed to positions withini the display window



another approach to two-dimensional viewing is to transform the clipping window into a normalized square,clip in normalized coordinates,and then transfer the scene description


从裁剪窗口 到 视口的变换

*/


#include<GL/freeglut.h>
#include<iostream>
#include<math.h>
using namespace std;

GLsizei winWidth = 800,winHeight = 800;


GLfloat xwcMin = 200.0, xwcMax = 600.0;
GLfloat ywcMin = 200.0, ywcMax = 600.0;


class wcPt2D {
    public:
        wcPt2D(GLfloat x, GLfloat y)
        {
            this->x = x;
            this->y = y;
        }
        GLfloat x,y;
};

typedef GLfloat Matrix3x3 [3][3];

Matrix3x3 matComposite;

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

void matrix3x3Print(Matrix3x3 mat)
{
    cout << "[";

    GLint row, col;
    for( row  = 0; row < 3; row++)
    {
        for( col = 0; col < 3; col++)
        {
            cout << mat[row][col] << " ";
        }

        cout << ";";
    }
    cout << "]" << endl;

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





void init()
{
    glClearColor(1.0,1.0,1.0,1.0);
}


void rectangle(wcPt2D corner1, wcPt2D corner2)
{
    GLfloat minX = std::min(corner1.x,corner2.x);
    GLfloat maxX = std::max(corner1.x,corner2.x);

    GLfloat minY = std::min(corner1.y,corner2.y);
    GLfloat maxY = std::max(corner1.y,corner2.y);

    glBegin(GL_LINE_LOOP);

    glVertex2f(minX,minY);
    glVertex2f(maxX,minY);
    glVertex2f(maxX,maxY);
    glVertex2f(minX,maxY);

    glEnd();
}

void point(wcPt2D p)
{
    glColor3f(0.0,0.0,1.0);
    glPointSize(4);
    glBegin(GL_POINTS);
    glVertex2f(p.x,p.y);
    glEnd();
}

void displayFunc()
{

    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0,0.0,0.0);

    wcPt2D p1(250.0f,250.0f);
    wcPt2D p2(400.0f,400.0f);

    rectangle(p1,p2);

    wcPt2D p(300.0f,300.0f);
    point(p);

    wcPt2D q1(450.0f,450.0f);
    wcPt2D q2(550.0f,550.0f);

    rectangle(q1,q2);

    glColor3f(1.0,0.0,0.0);
    matrix3x3SetIdentity(matComposite);

    scale2D((q2.x - q1.x)/(p2.x - p1.x), (q2.y - q1.y)/(p2.y - p1.y),p1);

    translate2D(q1.x - p1.x, q1.y - p1.y);

    matrix3x3Print(matComposite);

    transformVerts2D(1,&p);

    cout << p.x << " " << p.y << endl;

    point(p);

    glFlush();

}

void winReshapeFunc(GLint newWidth,GLint newHeight)
{
/*
    glViewport(0,0,newHeight,newHeight);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(xwcMin,xwcMax,ywcMin,ywcMax);
    */

    glViewport(0,0,newHeight,newHeight);
    // if we don't specify a clipping window in an application program, the default coordinate are (-1.0,-1.0) and (1.0,1.0)
    // the default clipping window is the normalized square centered on the coordinate origin with a side length of 2.0
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
    glutCreateWindow("bezier curve");

    init();
    glutDisplayFunc(displayFunc);
    glutReshapeFunc(winReshapeFunc);
    glutMainLoop();



}


