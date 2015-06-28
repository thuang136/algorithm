#include<iostream>
using namespace std;

class wcPt2D {
    public:
        GLfloat x, y;
};

inline GLint round(const GLfloat a) { return GLint ( a + 0.5); }

const GLint winLeftBitCode = 0x1;
const GLint winRightBitCode = 0x2;
const GLint winBottomBitCode = 0x4;
const GLint winTopBitCode = 0x8;


inline GLint inside(GLint code) { return GLint(!code); }




/*

any line that has a region-code value of 1 in the same bit position for each endpoint is completely outside the clipping rectangle, we eliminate that line segment

any line that are completely inside the clip window and which are completely outside

we can perform the inside-outside test for segments using logical operators. when the or operation between two endpoint region code for a line segment is false (0000)

the line is inside of the clipping window

*/


inline GLint reject(GLint code1, GLint code2) { return GLint( code1 & code2); }


inline GLint accept(GLint code1, GLint code2) { return GLint(!(code1 | code2)); }






GLubyte encode(wcPt2D pt, wcPt2D winMin, wcPt2D winMax)
{
    GLubyte code = 0X00;

    if(pt.x < winMin.x)
    {
        code = code | winLeftBitCode;
    }
    if(pt.x > winMax.x)
    {
        code = code | winRightBitCode;
    }
    if(pt.y < winMin.y)
    {
        code = code | winBottomBitCode;
    }
    if(pt.y > winMax.y)
    {
        code = code | winTopBitCode;
    }

    return code;

}


void swapPts(wcPt2D *pt1, wcPt2D* pt2)
{
    wcPt2D tmp;

    tmp = *pt1; *pt1 = *pt2; *pt2 = tmp;

}

void swapCodes(GLubyte * c1, GLubyte *c2)
{
    GLubyte tmp;
    tmp = *c1;
    *c1 = *c2;
    *c2 = tmp;
}

void lineClip(wcPt2D winMin, wcPt2D winMax, wcPt2D p1, wcPt2D p2)
{
    GLubyte code1, code2;

    GLint done = false, plotLine = false;

    GLfloat m;

    while(!done)
    {

        code1 = encode(p1,winMin,winMax);
        code2 = encode(p2,winMin,winMax);

        if(accept(code1, code2))
        {
            done = true;
            plotLine = true;
        }
        else
        {
            if(reject(code1,code2))
            {
                done = false;
            }
            else
            {
            if(inside(code1))
            {
                swapPts(&p1,&p2);
                swapCodes(&code1,&code2);
            }

            if( p2.x != p1.x)
            {
                m = (p2.y - p1.y) / (p2.x - p1.x);
            }

            if( code1 & winLeftBitCode)
            {
                p1.y += m * (winMin.x - p1.x);
                p1.x = winMin.x;
            }
            else
            {
                if( code1 & winRightBitCode)
                {
                  p1.y += (winMax.x - p1.x) * m;
                  p1.x = winMax.x;
                }

                else
                {
                    if( code1 & winBottomBitCode)
                    {
                       if(p2.x != p1.x)
                       {
                           p1.x += (winMin.y - p1.y) / m;
                       }
                       p1.y = winMin.y;
                    }
                    else
                    {
                        if(code1 & winTopBitCode)
                        {
                            if(p2.x != p1.x)
                            {
                                p1.x += (winMax.y - p1.y)/m;
                            }
                            p1.y = winMax.y;
                        }
                    }

                }
            }

            }

        }


    }

    if(plotLine)
    {
        cout << p1.x << " " << p1.y << " " << p2.x  << " " << p2.y << endl;
    }

}



int main(int argc ,char** argv)
{

wcPt2D winMin;
winMin.x = 1;
winMin.y = 1;

wcPt2D winMax;
winMax.x = 7;
winMax.y = 5;

wcPt2D p1;
p1.x = 4;
p1.y = 9;

wcPt2D p2;
p2.x = 11;
p2.y = 2;


lineClip(winMin,winMax,p1,p2);


}














































