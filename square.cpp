/*

There is a square-shaped map as in . 0 indicates that an area has no houses, and 1 indicates that an area has houses.

Mr. Lee wants to define a housing area which is a group of connected houses using this map and to mark numbers on housing areas.

Here, the ‘connected’ means that a certain house is attached to other house on the right/left or up/down. Two houses in diagonal are not connected.

is the numbered by housing areas. Create a program that outputs the number of housing areas by inputting a map.?


Example of Input

2
7
0 1 1 0 1 0 0
0 1 1 0 1 0 1
1 1 1 0 1 0 1
0 0 0 0 1 1 1
0 1 1 1 0 0 0
0 1 1 1 1 1 0
0 1 0 0 0 1 1
5
0 1 0 1 0
1 0 1 0 1
0 1 0 1 0
1 0 1 0 1
0 1 0 1 0

Example of Output

3
12


Several test cases can be included in the inputs. T, the number of cases is given in the first row of the inputs.
After that, the test cases as many as T (T ≤ 20) are given in a row.
N, the map size is given in the first row of each test case. This map is always a square (5 ≤ N ≤ 25).
The map information is given separately from the second row to the number of N.
In case houses do not exist in the corresponding area, 0 is given, and in case houses exist in the corresponding area, 1 is given.



*/

#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const int MAX = 27;

int houseMatrix[MAX][MAX];

// 从i,j开始递归标记
void markHouse(int i ,int j)
{
    if(houseMatrix[i][j] == 1)
    {
        houseMatrix[i][j] = 0;
        markHouse(i+1,j);
        markHouse(i-1,j);
        markHouse(i,j+1);
        markHouse(i,j-1);
    }
}

int main(int argc, char** argv)
{

    const char* INPUTFILE("../res/test-case/sample_input_square.txt");
    freopen(INPUTFILE,"r",stdin);

    int T;

    cin >> T;

    for(int t = 0 ; t < T ; t++)
    {
        int N;

        cin >> N;

        memset(&houseMatrix[0][0],0,sizeof(houseMatrix));

        for(int i = 1 ; i <= N ; i++)
        {
            for(int j = 1 ; j <= N ; j++)
            {
                cin >> houseMatrix[i][j];
            }
        }

        int count = 0;

        for(int i = 1; i <= N; i++)
        {
            for(int j = 1; j <= N ; j++)
            {
               if(houseMatrix[i][j] ==  1)
               {
                   markHouse(i,j);
                   count++;
               }
            }
        }

        cout << count << endl;

    }
}

