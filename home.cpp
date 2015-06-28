/*

The farmer wants to return home,

Farm No. 1 from Farm No. N. The farmer who is very tired is going to return home as fast as he can.

In the farms he cultivates, there is the total number of T of two-way roads.

Create a program that helps the tired farmer find the shortest distance from Farm No. N to Farm No. 1 Home.

Time limit: 1 second (java: 2 seconds)

Input format

Several test cases can be included in the inputs. T, the number of cases is given in the first row of the inputs. After that, the test cases as many as T (T ≤ 20) are given in a row.
The first row of each test is given by being separated as the spaces which are T, the number of two-way roads and N, the number of farm. (1 ≤ T ≤ 10,000, 1 ≤ N ≤ 1,000)
S, E, & D which are the information of roads are given from the second row to T number rows. It means that Farm No. S and Farm No. E has a connected road and its road length is D (1 ≤ D ≤ 100).

Output format

Output the shortest distance to move from Farm No. N to Farm No. 1 Home on the first row per each test case.

Example of Input

2
5 5
1 2 20
2 3 30
3 4 20
4 5 20
1 5 100
10 2
1 2 68
1 2 66
1 2 64
1 2 62
1 2 60
1 2 58
1 2 56
1 2 54
1 2 52
1 2 50

Example of output

90
50


*/




#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;

const int MAX = 1001;
const int MAX_DIST = 1000000;

int matrix[MAX][MAX];

int dist[MAX];

bool marker[MAX];

int dijstra(int N)
{

// 先初始化N 到其余节点的最小距离
   memset(dist,0, sizeof(dist));
   memset(marker, false,sizeof (marker));

// 每次选取一个最小距离，更新dist

   for( int i = 1; i < N; i++)
   {
       if(matrix[i][N] != 0)
       {
           dist[i] = matrix[i][N];
       }
       else
       {
           dist[i] = MAX_DIST;
       }
   }

   dist[N] = 0;
   marker[N] = true;

   while( true)
   {
       int min = MAX_DIST;
       int k;
       int i = 1;
       for(; i <= N; i++)
       {
           if(!marker[i] && dist[i] < min)
           {
               min = dist[i];
               k = i;
           }

       }

       if( min == MAX_DIST)
       {
           return dist[1];
       }

       marker[k] = true;

       for(int i = 1; i < N; i++)
       {
          if( !marker[i] && matrix[i][k] > 0 && dist[k] + matrix[i][k]  < dist[i])
          {
              dist[i] = dist[k] + matrix[i][k];
          }
       }






   }



}

int main(int argc, char** argv)
{
    const char* INPUTFILE("../res/test-case/sample_input_home.txt");
    freopen(INPUTFILE,"r",stdin);

    int t;

    cin >> t;

    for(int i = 0; i < t; i++)
    {
        int T, N;
        cin >> T >> N;

        memset(matrix,0, sizeof(matrix));

        for(int j = 0; j < T; j++)
        {
            int S, E;
            cin >> S >> E;
            int distance;
            cin >> distance;
            if( ( matrix[S][E] > 0 &&  distance < matrix[S][E] ) || matrix[S][E] == 0 )
            {
                matrix[S][E] = distance;
                matrix[E][S] = distance;
            }

        }

        int maxPath = dijstra(N);

        cout << maxPath << endl;
    }

}

