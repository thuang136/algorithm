/*

Long time ago, there lived Hansel and Gretel.

And a strange witch took Hansel to the deep forest to get rid of him.
Smart Hansel abandoned scraps of bread that he¡¯d got little by little on the way to the forest.
But the problem is that the scraps of bread scattered here and there by the similar scraps by other mountaineers is making hard for Gretel to follow.

At this time, a fairy of the forest appears to tell her how to find the way.

¡®Move to where you can find as many scraps of bread as you can.¡¯
Following to her advice, Gretel plans to use the route where she can find as many scraps of bread as she can from the departure to the destination.

There is one condition that she is allowed to move up or left only along the mountain to the destination.







Create a program that she can find the way as the fairy advised.

Time limit: 1 second (java: 2 seconds)

Input format

Several test cases can be included in the inputs. T, the number of cases is given in the first row of the inputs. After that, the test cases as many as T (T ¡Ü 30) are given in a row.
N, the size of the forest is given in the first row of each test case. The forest is always the square shape of N¡ÁN size.
The information of the forest is given by being separated as spaces over the lines of the number of N from the second row.
In case a scrap of bread is in the corresponding cell, it is 1, and in case a scrap of bread is not in the corresponding cell, it is 0.

Output format

Output the number of bread when they take bread as much as they can from the departure on the first row of each test case to the destination.

Example of Input

2
5
0 1 0 0 1
0 0 1 0 0
1 0 1 1 0
1 1 0 1 0
1 0 0 0 1
10
1 0 0 1 0 1 0 0 1 0
1 1 1 0 1 1 1 1 0 0
0 0 0 1 1 0 1 0 0 0
0 1 1 1 0 0 0 0 1 0
1 0 1 1 0 0 1 0 1 0
0 0 1 1 1 0 1 0 1 0
1 1 0 0 0 0 1 0 1 0
0 1 0 1 1 1 0 0 0 0
1 0 1 1 0 1 0 0 1 0
0 0 0 1 1 0 1 0 1 0

Example of Output

6
14


*/

#include<iostream>
#include<cstdio>
using namespace std;



int main(int argc, char** argv)
{

    const char* INPUTFILE("../res/test-case/sample_input_hansel.txt");
    freopen(INPUTFILE,"r",stdin);

    int T;

    cin >> T;


    for( int i = 0 ; i < T; i++)
    {
         int n;

         cin >> n;

         int** matrix = new int*[n+1];
         int** maxCount = new int*[n+1];
         for(int j = 0; j < n+1; j++)
         {
             matrix[j] = new int[n+1];
             maxCount[j] = new int[n+1];
         }

         int row, col;
         for(row = 1; row <= n; row++)
         {
             for( col = 1; col <= n; col++)
             {
                  cin >> matrix[row][col];
             }
         }

         for( row = 0; row < n+1 ; row++)
         {
             maxCount[row][0] = 0;
             maxCount[0][row] = 0;
         }

         for(row = 1; row <= n; row++)
         {
             for( col = 1; col <= n; col++)
             {
                 int most = std::max(maxCount[row-1][col-1],maxCount[row-1][col]);

                 most = std::max(most,maxCount[row][col-1]);

                 maxCount[row][col] = matrix[row][col] + most;
             }
         }

         cout << maxCount[n][n] << endl;

    }

}

