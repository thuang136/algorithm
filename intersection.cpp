/*

Description
You are to write a program that has to decide whether a given line segment intersects a given rectangle.

An example:
line: start point: (4,9)
end point: (11,2)
rectangle: left-top: (1,5)
right-bottom: (7,1)

The line is said to intersect the rectangle if the line and the rectangle have at least one point in common. The rectangle consists of four straight lines and the area in between. Although all input values are integer numbers, valid intersection points do not have to lay on the integer grid.
Input
The input consists of n test cases. The first line of the input file contains the number n. Each following line contains one test case of the format:
xstart ystart xend yend xleft ytop xright ybottom

where (xstart, ystart) is the start and (xend, yend) the end point of the line and (xleft, ytop) the top left and (xright, ybottom) the bottom right corner of the rectangle.
The eight numbers are separated by a blank. The terms top left and bottom right do not imply any ordering of coordinates.

Output
For each test case in the input file, the output file should contain a line consisting either of the letter "T" if the line segment intersects the rectangle or the letter "F" if the line segment does not intersect the rectangle.
Sample Input
14 9 11 2 1 5 7 1
Sample Output
F


*/

#include<iostream>
#include<stdio.h>

using namespace std;

struct Point
{
  float x;
  float y;
};

const int leftFlag = 0x1;
const int rightFlag = 0x2;
const int bottomFlag = 0x4;
const int topFlag = 0x8;

inline bool inside(int code) { return !code; }

inline bool accept(int code1, int code2) { return !(code1 | code2); }

inline bool reject(int code1, int code2) { return  code1 & code2;}


unsigned int  encode(Point min,Point max, Point p)
{
    unsigned int code = 0x0;

    if( p.x < min.x)
    {
        code = code | leftFlag;
    }

    if( p.x > max.x)
    {
        code = code | rightFlag;
    }

    if( p.y < min.y)
    {
        code = code | bottomFlag;
    }

    if( p.y > max.y)
    {
        code = code | topFlag;
    }

    return code;

}

void swapPoint(Point* point1, Point* point2)
{
    Point temp;

    temp = *point1;
    *point1 = *point2;
    *point2 = temp;
}

void swapCode(unsigned int* code1, unsigned int* code2)
{
     unsigned int temp;
     temp = *code1;
     *code1 = *code2;
     *code2 = temp;
}





bool intersect(Point minXY, Point maxXY,Point start, Point end)
{
    // 什么时候结束循环，二个端点都在裁剪矩形内，或者二个端点都
    bool done = false;

    float m;

    while(!done)
    {
          unsigned int startCode = encode(minXY,maxXY,start);
          unsigned int endCode = encode(minXY,maxXY,end);

          if( accept( startCode,endCode) )
          {
              done = true;
              return true;
          }
          else
          {
              if(reject(startCode,endCode))
              {
                  done = true;
                  return false;
              }

              else
              {
                if( inside(startCode) )
                {
                     swapPoint(&start,&end);
                     swapCode(&startCode,&endCode);
                }

                if(start.x != end.x)
                {
                    m = (end.y - start.y) / (end.x - start.x);
                }

                if(startCode & leftFlag)
                {

                     start.y = start.y + m * (minXY.x - start.x);

                     start.x = minXY.x;
                }
                else
                {
                    if(startCode & rightFlag)
                    {

                        start.y = start.y + m * (maxXY.x - start.x);

                        start.x = maxXY.x;
                    }

                    else
                    {
                         if(startCode & bottomFlag)
                         {
                             if(start.x != end.x)
                             {
                                 start.x = start.x + (minXY.y - start.y)/ m;
                             }
                             start.y = minXY.y;
                         }

                         else
                         {
                             if(startCode & topFlag)
                             {
                                 if(start.x != end.x)
                                 {
                                     start.x = start.x + (maxXY.y - start.y)/m;
                                 }
                                 start.y = maxXY.y;
                             }
                         }


                    }


                }


              }


          }

    }

}




int main(int argc ,char** argv)
{
    int n;


    const char* INPUTFILE("../res/test-case/sample_input_intersection.txt");
    freopen(INPUTFILE,"r",stdin);


    cin >> n;

    for( int i = 0; i < n; i++)
    {
        Point minXY, maxXY, start,  end;

        cin >> start.x >> start.y;
        cin >> end.x >> end.y;

        cin >> minXY.x >> minXY.y;
        cin >> maxXY.x >> maxXY.y;

        float minX = std::min(minXY.x,maxXY.x);
        float maxX = std::max(minXY.x,maxXY.x);

        float minY = std::min(minXY.y, maxXY.y);
        float maxY = std::max(minXY.y, maxXY.y);

        minXY.x = minX;
        minXY.y = minY;

        maxXY.x = maxX;
        maxXY.y = maxY;

        bool intersection = intersect(minXY,maxXY,start,end);

        if(intersection)
        {
            cout << "T" << endl;
        }
        else
        {
            cout << "F" << endl;
        }
    }
}



