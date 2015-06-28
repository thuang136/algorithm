/*



There is a regular triangle with written numbers.

Let’s make a maximum sum in the triangle.

At this moment, to calculate the sum, add numbers going down from the current position to the left or right in diagonal lines,

and the starting position is always the top apex of the triangle.

7
3 8
8 1 0
2 7 4 4
4 5 2 6 5

In the example above, you can see how to make the maximum sum is going down from 7 to 3, 8, 7, 5.

Time limit: 1 second (jave: 2 seconds)

Input format

Several test cases can be included in the inputs. T, the number of cases is given in the first row of the inputs. After that, the test cases as many as T (T ≤ 30) are given in a row.
The number of N is given on the first row of each test case. (1 ≤ N ≤ 1000)
The corresponding numbers are given by being separated with a blank on each row from the second row to T number rows. Each number is an integer above 0 below 100.

Output format

Output the maximum sum on the first row of each test case.

Example of Input

2
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5
10
1
2 3
4 5 6
7 8 9 10
11 12 13 14 15
21 20 19 18 17 16
22 23 24 25 26 27 28
36 35 34 33 32 31 30 29
37 38 39 40 41 42 43 44 45
55 54 53 52 51 50 49 48 47 46

Example of Output

30
202


*/

#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const int MAX = 1000;

int matrix[MAX][2 * MAX + 1];
int result[MAX][2 * MAX + 1];

// 计算从某一点开始沿着对角线方向的最大值

int Cal(int i , int j, int col)
{
     if(i >= col)
     {
       return 0;
     }
     if( j < 0 || j >= (2*col-1))
     {
       return 0;
     }

     if( result[i][j] != -1)
     {
         return result[i][j];
     }

     int valueLeft = Cal(i+1,j-1,col);
     int valueRight = Cal(i+1,j+1,col);

     if(valueLeft < valueRight)
     {
         result[i][j] = matrix[i][j] + valueRight;
     }
     else
     {
         result[i][j] = matrix[i][j] + valueLeft;
     }

     return result[i][j];

}






int main(int argc, char** argv)
{

    const char* INPUTFILE("../res/test-case/sample_input_tri.txt");
    freopen(INPUTFILE,"r",stdin);

    int T;

    cin >> T;

    for(int t = 0 ; t < T ; t++)
    {
        int N;
        cin >> N;

        memset(matrix,-1,sizeof(matrix));
        memset(result,-1,sizeof(result));

        for(int i = 1 ; i <= N; i++)
        {
            int start = N-i;

            // 第i行从start开始放置
            for(int j = 0; j < i ; j++)
            {
                cin >> matrix[i-1][start];

                start += 2;
            }

        }

        // 先测试一下

        /*
        for(int i = 0 ; i < N ; i++)
        {
            for(int j = 0 ; j < (2 * N -1); j++)
            {
                if(matrix[i][j] != -1)
                {
                    cout << matrix[i][j] ;
                }
                else
                {
                    cout << ' ';
                }

            }

            cout << endl;

        }*/

        cout << Cal(0,N-1,N) << endl;


    }


}

