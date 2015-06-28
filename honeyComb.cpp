/*


hows a honeycomb with length 3 on a side. When it calls a figure-written circle a node,

a method to move from the current node to the next is to move down left or down right diagonally. ?




Find the highest sum of nodes starting from the top node to the bottom node.

There is a chance to change a figure only once in the same row while you go down.

Using this chance, find out the maximum sum of routes from the top node to the bottom node.

Time limit: 1 second (java: 2 seconds)

[Input]
Several test cases can be included in the inputs. T, the number of cases is given in the first row of the inputs.

After that, the test cases as many as T (T ≤ 30) are given in a row.

A side length of a honeycomb, N is given on the first row per each test case. These figures are over 0 below 99.

[Output]
After changing two figures of the same row on the first row only once per each test case, output the maximum sum of the routes from the top node to the bottom node.

[I/O Example]
Input
2
3
1 2 3
3 2 2 1
4 2 8 0 3
5 3 1 2
3 1 4
2
53 14
27 2 31
85 30

Output
22
169

Explanation of example
The answer of is 3+2+8+5+4=22 painted as gray color. At this time, the figure, 5 is changed with the third node from left on the same row, 1.


*/


/*

首先它肯定是个正六边形，边长由第一个参数构成

*/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int MAX = 100;

int matrix[400][400];
int memo[400][400];

struct Coord
{
    int x;
    int y;
};

Coord path[400];

int max_num[400];

/*
   从数组顶部某个位置从上往下，经过的数的和最大，只能改变其中一行的数

   先求从上到下的，可以换掉某个位置的一个数。

   原最大，替换之后说不定比原来小了

   不管怎么样，先来算算正常情况下，最大和
*/


/*
   计算从某个点往下
*/
int sum(int row, int col,int lastRow)
{
    if(row >= lastRow)
    {
        return 0;
    }

    if(col < 0 || col >= (2 * lastRow - 1))
    {
        return 0;
    }

    if(memo[row][col] != 0)
    {
        return memo[row][col];
    }

    else
    {
        int option1 = sum(row+1, col-1,lastRow);
        int option2 = sum(row+1, col+1,lastRow);
        if(option1 > option2)
        {
            cout << row + 1 << " " << col - 1 << endl;
            memo[row][col] = option1 + matrix[row][col];
            //path[row+1].x = row + 1;
            //path[row+1].y = col - 1;
            return memo[row][col];
        }
        else
        {
            cout << row + 1 << " " << col + 1 << endl;
            memo[row][col] = option2 + matrix[row][col];
            //path[row+1].x = row + 1;
            //path[row+1].y = col + 1;
            return memo[row][col];
        }
    }
}

int main(int argc, char** argv)
{
    const char* INPUTFILE("../res/test-case/sample_input_honeyComb.txt");
    freopen(INPUTFILE,"r",stdin);

    int T;
    cin >> T;

    for(int t = 0 ; t < T ; t++)
    {
        memset(matrix,0, sizeof(matrix));
        memset(max_num, 0, sizeof(max_num));


        int length;
        cin >> length;

        int maxRowLength = 4 * length - 3;
        int maxRows = 2 * length - 1;

        /*
           第一行从length -1 的位置开始放，每个数间隔一个位置放
        */

        int rowLength = length - 1;

        for(int i = 0 ; i < maxRows; i++)
        {
            int cmp = 0;

            int start = 0;

            if( i < length)
            {
                start = length - 1 - i;
                rowLength++;
            }
            else
            {
                start = i - length + 1;
                rowLength--;
            }

            for(int j = 0 ; j < rowLength; j++)
            {
                cin >> matrix[i][start];

                if(matrix[i][start] > cmp)
                {
                    cmp = matrix[i][start];
                }

                start += 2;
            }

            max_num[i] = cmp;

        }



        for(int m = 0 ; m < maxRowLength; m++)
        {
            for(int n = 0 ; n < maxRowLength; n++)
            {
                cout << matrix[m][n] << " ";
            }
            cout << endl;
        }

        cout << endl;

        int maxSum = 0;
        for(int i = 0 ; i < length; i++)
        {
            memset(memo,0,sizeof(memo));
            memset(path,0,sizeof(path));
            int result = sum(0,2 * i+length-1,maxRows);
            if( result > maxSum)
            {
                maxSum = result;
            }
        }

        /*

        int larger = 0;
        for(int i = 1; i < maxRows; i++)
        {
            //cout << path[i].x << " " << path[i].y << endl;
            cout <<  matrix[path[i].x][path[i].y] << " " << max_num[i] << endl;
            if(max_num[i] - matrix[path[i].x][path[i].y] > larger)
            {
                larger = max_num[i] - matrix[path[i].x][path[i].y];
            }

        }

        maxSum += larger;

        */


        cout << maxSum << endl;

    }
}
