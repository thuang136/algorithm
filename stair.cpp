/*



A game about climbing stairs going up from the lowest starting point to the highest arriving point.

As in , each stair has a score. When you step on a stair, you will get the score written on the stair.

For example, as in , reaching the arriving point by going up from the starting point to the first, second, fourth and sixth stairs, the total score is 10+20+25+20=75.



The rules of going up the stairs are as below:

1. You may go up one or two stairs at a time. That means once you step on a stair, then you can step up to the next or two higher stairs.
2. You may not step on every three consecutive stairs. However, the starting point is not included in the number of stairs.
3. You must step on the final arriving stair.

Therefore, when you step on the first stair, you can step on the second or third stair. However, after you step on the first stair, you may neither step on the fourth stair
nor the first, second and third stair consecutively.

Create a program to find the maximum total score available in this game in the given scores written on the stairs.

Time limit: 1 second (java: 2 seconds>

Input format

Several test cases can be included in the inputs. T, the number of cases is given in the first row of the inputs. After that, the test cases as many as T (T ≤ 20) are given in a row.
The number of stairs, N is given on the first row per each test case. (1 ≤ N ≤300)
The scores written on each stair, S are given in order from the bottom stair one by one from the second row to N number rows. (1 ≤ S ≤ 10,000)

Output format

Output the maximum value of total score that you can gain from the game of climbing stairs on the first row per each test case.

Example of Input

2
6
10
20
15
25
10
20
7
13
1
15
27
29
21
20

Example of Output

75


*/


 #if 0
#include<cstdio>
#include<iostream>
using namespace std;

// 如果前面二个台阶的索引是preIndex, index,则爬完整个楼梯的分数
int maxScore(int* scores,int preIndex,int index)
{
    if(index < 1)
    {
        return 0;
    }
    int diff = preIndex - index;

    int total = scores[index];

    if( diff == 1)
    {
       //如果已经连续爬了二次单步楼梯，下次只能爬双步楼梯
       return total + maxScore(scores,index,index-2);

    }

    else if( diff == 2)
    {
       return total + std::max(maxScore(scores,index, index - 1),maxScore(scores,index, index-2));
    }

}

int main(int argc, char** argv)
{

    const char* INPUTFILE("../res/test-case/sample_input_stair.txt");
    freopen(INPUTFILE,"r",stdin);

    int T;

    cin >> T;

    for(int i = 0 ; i < T; i++)
    {
        int n;

        cin >> n;

        int* scores = new int[n+1];

        for(int j = 1; j <= n; j++)
        {
            cin >> scores[j];
        }

        cout << scores[n] + std::max(maxScore(scores,n,n-1),maxScore(scores,n,n-2)) << endl;

        delete [] scores;
    }


}

 #endif



#if 1

#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;

// 到达第i个台阶是怎么到达的,matrix[i][1] 上一个台阶到达i, matrix[i][2] 上二个台阶到达i

int matrix[301][3];

int main(int argc, char** argv)
{

    const char* INPUTFILE("../res/test-case/sample_input_stair.txt");
    freopen(INPUTFILE,"r",stdin);

    int T;

    cin >> T;

    for(int i = 0 ; i < T; i++)
    {
        int n;

        cin >> n;

        int* scores = new int[n+1];

        memset(&matrix[0][0],0,sizeof(matrix));

        for(int j = 1; j <= n; j++)
        {
            cin >> scores[j];
        }

        matrix[1][1] = scores[1];
        matrix[1][2] = 0;
        matrix[2][2] = scores[2];
        matrix[2][1] = scores[1] + scores[2];

        for(int k = 3; k <= n; k++)
        {
            matrix[k][2] = std::max( matrix[k-2][2], matrix[k-2][1] ) + scores[k];
            matrix[k][1] = matrix[k-1][2] + scores[k];
        }

        cout << std::max(matrix[n][1],matrix[n][2]) << endl;

        delete [] scores;
    }


}

#endif

#if 0

#include <cstdio>
#include <iostream>

using namespace std;

#define MAX(x,y) ((x>y) ? (x) : (y))

int NumStep = 0;
unsigned int Step[301];
unsigned int SumStep[2][301];
unsigned int Answer = 0;

void Calculate(int index)
{
    SumStep[0][index] = MAX(SumStep[0][index-2], SumStep[1][index-2]) + Step[index];
    SumStep[1][index] = SumStep[0][index-1] + Step[index];
}

int main(int argc, char** argv)
{
    int tc, T;

    // The freopen function below opens input.txt file in read only mode, and afterward,
    // the program will read from input.txt file instead of standard(keyboard) input.
    // To test your program, you may save input data in input.txt file,
    // and use freopen function to read from the file when using cin function.
    // You may remove the comment symbols(//) in the below statement and use it.
    // Use #include<cstdio> or #include<stdio.h> to use the function in your program.
    // But before submission, you must remove the freopen function or rewrite comment symbols(//).

    const char* INPUTFILE("../res/test-case/sample_input_stair.txt");
    freopen(INPUTFILE,"r",stdin);

    cin >> T;
    for(tc = 0; tc < T; tc++)
    {
        /**********************************
        *  Implement your algorithm here. *
        ***********************************/
        cin >> NumStep;

        for(int i = 1; i<=NumStep; i++)
        {
            cin >> Step[i];
        }

        Answer = 0;
        SumStep[0][1] = 0;
        SumStep[1][1] = Step[1];

        SumStep[0][2] = Step[2];
        SumStep[1][2] = Step[1] + Step[2];

        for(int i = 3; i<= NumStep; i++)
        {
            Calculate(i);
        }
        Answer = MAX(SumStep[0][NumStep], SumStep[1][NumStep]);
        cout << Answer << endl;
        // Print the answer to standard output(screen).

    }

    return 0;//Your program should return 0 on normal termination.
}

#endif


