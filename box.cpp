/*




There are two boxes, A and B with shelves, a and b. Following the ,

there are marbles with numbers written from 1 to N to every shelf of the two boxes.


Box A
1
2
1
4
Box B
1
3
2
2


You must always take out each marble from the left of the box in turn and each time you have one marble, you will get a score as below:
1. Take out a marble from Box A only. Your score is 0.
2. Take out a marble from Box B only. Your score is 0.
3. Take out each marble from Box A and B at the same time. At this moment, if the marble number is i from Box A and the marble number is j from Box B, you have a score as much by the row I & column j in the scoreboard below. The score can be negative numbers.


2
2
-3
3
1
3
2
4
-1
1
4
5
6
2
-4
-1


When the scoreboard is given as in the , in the case of the if you take the first marble each out of Box A and B at the same time, the number is (1, 1) so you score 2 by the row 1 & column 1.
If the marbles numbers are (1, 3), you score -3 by the row 1 & column 3.
When a scoreboard is given by inputs and marble numbers are given in two boxes, A and B, make the accumulated scores of given scores maximal.

Time limit : 2 seconds (java : 4 seconds)

Input format

Several test cases can be included in the inputs. T, the number of cases is given in the first row of the inputs.
After that, the test cases as many as T (T ¡Ü 20) are given in a row.
The maximum number of marbles, N, the number of marbles in the box A that is a,
and the number of marbles in the box B that is b are given in order with a space separately on the first row of each test case.
(1 ¡Ü N, a, b ¡Ü 1,000) Score tables are given from the second row to N number rows. Each score is given by being separated with a blank. The range of each number is over -1,000 below 1,000.
On the next row, marble numbers in the box A are given in order from the left.
On the final row, marble numbers in the box B are given in order from the left.

Output format

Output the maximum value of accumulated scores given on the first row of each test case.

Example of Input

2
4 4 4
2 2 -3 3
1 3 2 4
-1 1 4 5
6 2 -4 -1
1 2 1 4
1 3 2 2
5 5 5
5 9 9 -1 -9
-2 -10 -2 4 -3
5 0 2 0 -8
-6 -7 5 6 6
-4 8 8 -9 -10
1 1 2 1 3
3 3 1 3 5

Example of Output

8
27





*/


#include<iostream>
#include<cstdio>
using namespace std;

int** matrix = NULL;
int** scores = NULL;
int* arrayA = NULL;
int* arrayB = NULL;


int getScore(int a, int b)
{

    int max = 0;
    for(int k = b-1 ; k >= 0 ; k--)
    {
        int score = matrix[arrayA[a-1]-1][arrayB[k]-1];
        if(score > max)
        {
            max = score;
        }
        scores[a-1][k] = max;
    }


    max = 0;
    for(int k = a-1 ; k >= 0 ; k--)
    {
        int score = matrix[arrayA[k]-1][arrayB[b-1]-1];
        if(score > max)
        {
            max = score;
        }
        scores[k][b-1] = max;
    }

    for(int m = a-2 ; m >= 0 ; m--)
    {
        for(int n = b-2; n >= 0 ; n--)
        {
            int maxValue = std::max(scores[m+1][n],scores[m][n+1]);

            maxValue = std::max(scores[m+1][n+1]+matrix[arrayA[m]-1][arrayB[n]-1],maxValue);

            scores[m][n] = maxValue;

        }

    }

    return scores[0][0];

}

int main(int argc, char** argv)
{

    const char* INPUTFILE("../res/test-case/sample_input_box.txt");
    freopen(INPUTFILE,"r",stdin);


    int T;
    cin >> T;

    for(int t = 0; t < T; t++)
    {
        int N, a, b;
        cin >> N >> a >> b;

        matrix = new int*[N];
        scores = new int*[N];
        for(int i = 0; i < N; i++)
        {
            matrix[i]  = new int[N];
            scores[i] = new int[N];
            for(int j = 0; j < N; j++)
            {
                cin >> matrix[i][j];
            }
        }

        arrayA = new int[a];
        for(int i = 0; i < a; i++)
        {
            cin >> arrayA[i];
        }

        arrayB = new int[b];
        for(int i = 0; i < b; i++)
        {
           cin >> arrayB[i];
        }

        int result = getScore(a,b);

        cout << result << endl;

        for(int i = 0; i < N ; i++)
        {
            delete []  matrix[i];
            delete [] scores[i];
        }

        delete[] matrix;
        delete[] scores;

        delete[] arrayA;
        delete[] arrayB;

    }

}



