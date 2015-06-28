/*

There are an individual match and group match in Taekwondo.
An individual match is between two players and
a group match is repetition of matches between two different individual players of each group.
You plan to make a group match which is comprised of several individual matches by selecting each player from each group.
Every player of the group can play one match only. Therefore, the number of matches is the same as the smaller number of the players of the two groups.
Like other sports, Taekwondo has a rule to make a weight difference minimal between two players of a match to be fair.
In a given two players¡¯ groups, create a program to make a group match with the total sum of absolute weight differences to a minimum
between each two players who participate in each individual game.

Time limit: 1 second (java: 2 seconds)

Input format

Several test cases can be included in the inputs. T, the number of cases is given in the first row of the inputs.
After that, the test cases as many as T (T ¡Ü 30) are given in a row.
The number of players in the first group, N and the number of players in the second group, M are given as being separated with a blank. (1 ¡Ü N, M ¡Ü 500)
The players¡¯ weights of the second group are given respectively from the next row to M number rows.
Each player weight is a real number over 40.0 below 130.0, and a weight to be inputted has an accuracy of one place of decimal.

Output format

Output the total sum of absolute values of two players¡¯ weights participating in an individual game included in a group match to one decimal place on the first row of each test case.

Example of Input

2
2 4
55.0
50.0
60.0
48.0
53.5
43.0
1 5
106.8
55.7
46.4
78.8
103.1
56.0

Example of Output

3.5
3.7



*/


#include<iostream>
#include<cstdio>
#include<algorithm>
#include<math.h>

using namespace std;

const int MAX = 501;
double matrix[MAX][MAX];

double maxDiff(int N, double* base, int M, double* cmp)
{

   double minDiff = 140.0;
   for(int i = 0; i < M; i++)
   {
       float diff = fabs(base[0] - cmp[i]);
       if( diff < minDiff)
       {
           minDiff = diff;
       }
       matrix[1][i+1] = minDiff;
   }

   minDiff = 0.0;
   for(int j = 0; j < N; j++)
   {
       float diff = fabs(base[j] - cmp[j]);
       minDiff += diff;
       matrix[j+1][j+1] = minDiff;
   }

   for(int j = 2; j <= N ; j++)
   {
        for(int k = j + 1; k <= M; k++)
        {
            double option1 = matrix[j-1][k-1] + fabs(base[j-1] - cmp[k-1]);

            double option2 = matrix[j][k-1];

            matrix[j][k] = std::min(option1, option2);
        }
   }

   return matrix[N][M];

}

int main(int argc , char** argv)
{

    const char* INPUTFILE("../res/test-case/sample_input_Taekwondo.txt");
    freopen(INPUTFILE,"r",stdin);

    int T;
    cin >> T;

    for(int t = 0; t < T; t++)
    {
        int N, M;
        cin >> N >> M;

        double* weightA = new double[N];
        for(int i = 0; i < N ; i++)
        {
            cin >> weightA[i];
        }
        sort(weightA, weightA + N);

        double* weightB = new double[M];
        for(int i = 0; i < M; i++)
        {
            cin >> weightB[i];
        }
        sort(weightB, weightB + M);

        double result = 0.0;
        if( N < M )
        {
           result = maxDiff(N,weightA, M, weightB);
        }
        else
        {
           result = maxDiff(M,weightB, N, weightA);
        }

        cout << result << endl;



    }


}
