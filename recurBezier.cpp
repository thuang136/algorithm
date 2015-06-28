#include<GL/freeglut.h>
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

template<class T, unsigned int R, unsigned int C>

class MTVariable
{

public:
    T m[R][C];

    friend std::ostream& operator << (std::ostream& os, const MTVariable<T,R,C> & v)
    {
        os << '[';

        unsigned int c, r;
        for( r = 0; r < R ; ++r)
        {
            os.width(2);
            for( c = 0 ; c < C-1; ++c)
            {
                os << v.m[r][c] << " ";
            }

            os << v.m[r][c] << ";";
        }

        os << ']';
        return os;

    }

    void identity()
    {
        for( unsigned int c = 0; c < C; c++)
        {
            for(unsigned int r = 0; r < R; ++r)
            {
                if( r == c)
                {
                    m[r][c] = 1;
                }
                else
                {
                    m[r][c] = 0;
                }
            }
        }
    }

    MTVariable<T,R,C> operator+ (const MTVariable<T,R,C>& a) const
    {
        MTVariable<T,R,C> res;
        for(unsigned int c = 0; c < C; ++c)
        {
            for(unsigned int r = 0; r < R; ++r)
            {
                res.m[r][c] = m[r][c] + a.m[r][c];
            }
        }
        return res;
    }

    MTVariable<T,R,C> operator*( const T& a)const
    {
        MTVariable<T,R,C> res;
        for(unsigned int c = 0; c < C; ++c)
        {
            for(unsigned int r = 0; r < R; ++r)
            {
                res.m[r][c] = m[r][c] * a;
            }
        }
    }
};

template< class T>
class MTVariable<T,2,1>
{
    public:
        union {
            T m[2][1];
            struct {
                T x,y;
            };
        };

    MTVariable<T,2,1> operator+( const MTVariable<T,2,1>& a)const
    {
        MTVariable<T,2,1> res;
        res.m[0][0] = m[0][0] + a.m[0][0];
        res.m[1][0] = m[1][0] + a.m[1][0];
        return res;
    }

    MTVariable<T,2,1> operator*(const T& a)const
    {
        MTVariable<T,2,1> res;
        res.m[0][0] = m[0][0] * a;
        res.m[1][0] = m[1][0] * a;
        return res;
    }

};

typedef MTVariable<float,2,1> Vec2;

typedef std::vector<Vec2>  Vector_Vec2;


GLsizei winWidth = 600,winHeight = 600;

GLfloat xwcMin = -225.0, xwcMax = 225.0;
GLfloat ywcMin = -225.0, ywcMax = 225.0;

void init()
{
    glClearColor(1.0,1.0,1.0,1.0);
}

void plotPoint(Vec2 pt)
{
    glBegin(GL_POINTS);

    glVertex2f(pt.x,pt.y);

    glEnd();

}


void subdivision(const Vec2& p0, const Vec2& p1, const Vec2& p2,const Vec2& p3, Vector_Vec2* pv)
{
    const Vec2 p01 = (p0 + p1) * 0.5f, p12 = (p1 + p2) * 0.5f, p23 = (p2 + p3) * 0.5f;
    const Vec2 p012 = (p01 + p12) * 0.5f, p123 = (p12 + p23) * 0.5f;
    const Vec2 p0123 = (p012 + p123) * 0.5f;

    float dx = p3.x - p0.x;
    float dy = p3.y - p0.y;

    float d1 = fabs((p1.x - p3.x) * dy - (p1.y - p3.y) * dx);
    float d2 = fabs((p2.x - p3.x) * dy - (p2.y - p3.y) * dx);

    if( (d1 + d2) * (d1 + d2) < 0.25 * (dx * dx + dy * dy))
    {
        pv->push_back(p0123);
        return;
    }

    subdivision(p0, p01,p012,p0123,pv);
    subdivision(p0123,p123,p23,p3,pv);

}


void displayFunc()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glPointSize(4);

    glColor3f(1.0,0.0,0.0);

    Vec2 ctrlPts[4] = { {-40.0,-40.0}, {-10.0,200.0},
                              {10.0,-200.0}, {40.0,40.0}
                      };


    Vector_Vec2 v;

    v.push_back(ctrlPts[0]);

    subdivision(ctrlPts[0],ctrlPts[1],ctrlPts[2],ctrlPts[3],&v);

    v.push_back(ctrlPts[3]);

    for(int i = 0 ; i < v.size() ; i++)
    {
       plotPoint(v[i]);
    }

    glFlush();

}

void winReshapeFunc(GLint newWidth,GLint newHeight)
{
    glViewport(0,0,newHeight,newHeight);

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
    glutCreateWindow("bezier recursive");

    init();
    glutDisplayFunc(displayFunc);
    glutReshapeFunc(winReshapeFunc);
    glutMainLoop();



}










































