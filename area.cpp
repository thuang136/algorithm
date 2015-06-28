/*


Area
Time Limit: 1000MS  Memory Limit: 10000K
Total Submissions: 15617  Accepted: 4347

Description

You are going to compute the area of a special kind of polygon.

One vertex of the polygon is the origin of the orthogonal coordinate system.

From this vertex, you may go step by step to the following vertexes of the polygon until back to the initial vertex.

For each step you may go North, West, South or East with step length of 1 unit, or go Northwest, Northeast, Southwest or Southeast with step length of square root of 2.

For example, this is a legal polygon to be computed and its area is 2.5:


Input

The first line of input is an integer t (1 <= t <= 20), the number of the test polygons.

Each of the following lines contains a string composed of digits 1-9 describing how the polygon is formed by walking from the origin.

Here 8, 2, 6 and 4 represent North, South, East and West,

while 9, 7, 3 and 1 denote Northeast, Northwest, Southeast and Southwest respectively.

Number 5 only appears at the end of the sequence indicating the stop of walking.

You may assume that the input polygon is valid which means that the endpoint is always the start point

and the sides of the polygon are not cross to each other.Each line may contain up to 1000000 digits.

Output

For each polygon, print its area on a single line.
Sample Input

4
5
825
6725
6244865
Sample Output

0
0
0.5
2


*/

#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

struct Move
{
    long long x;
    long long y;

    Move& operator + (Move& k)
    {
        this->x += k.x;
        this->y += k.y;
        return *this;
    }
};

Move move[9] = {{-1,-1},{0,-1},{1,-1},{-1,0},{0,0},{1,0},{-1,1},{0,1},{1,1}};

long long Det(Move p, Move q)
{
    return p.x * q.y - q.x * p.y;
}

int main(int argc, char** argv)
{
    const char* INPUTFILE("../res/test-case/sample_input_area.txt");
    freopen(INPUTFILE,"r",stdin);

    int t;
    cin >> t;

    Move cur = {0,0};


    for(int T = 0 ; T < t ; T++)
    {
        string walkSeq;

        cin >> walkSeq;

        int size = walkSeq.size();

        Move p1,p2;

        long long area = 0;

        for(int i = 0 ; i < size - 1; i++)
        {
           cur = cur + move[walkSeq[i]- '1'];

           if( i > 1)
           {
               p1 = p2;

               p2 = cur;
           }
           else
           {
               if( i == 0)
               {
                   p1 = cur;
               }
               else
               {
                   p2 = cur;
               }
           }
           if( i > 0)
           {
               area += Det(p1,p2);
           }
        }

        if(area < 0)
        {
            area = -area;
        }

        if( area % 2 == 0)
        {
            cout << area/2 << endl;
        }
        else
        {
            printf("%lld.5\n",area/2);
        }


    }
}


