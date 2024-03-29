/*


There are several pockets containing marbles. 

Each pocket has different numbers of marbles. 

How many times you move to make every pocket with the equal number of marbles by the minimum movement? Create a program to solve this problem.

Time limit: 1 second (java: 2 seconds)

[Input]
Several test cases can be included in the inputs. T, the number of cases is given in the first row of the inputs. After that, the test cases as many as T (T �� 30) are given in a row. 
The number of pockets, N is given on the first row per each test case. (2 �� N �� 32000)
The number of marbles containing each pocket is given from the second row to the row of N numbers. The maximum number of marbles is 32,000 in each pocket. 

[Output]
Output the minimum number of moving marbles to make the number of marbles in several pockets equal on the first row of each test case. If you cannot equalize the number of marbles in all pockets, output -1. 

[I/O Example]
Input
2
5
1
1
1
1
6
2
1
3

Output
4
1 



*/


#include<iostream>
#include<cstdio>
using namespace std;

int main(int argc, char** argv)
{

    const char* INPUTFILE("../res/test-case/sample_input_marbles.txt");
    freopen(INPUTFILE,"r",stdin);

    int T;
    cin >> T;

    for(int t = 0 ; t < T ; t++)
    {
        int N;
    cin >> N;

        int* pArray = new int[N];
    int sum = 0;
    for(int i = 0 ; i < N; i++)
    {
            cin >> pArray[i];
        sum += pArray[i];
    }

    int average = sum / N;
        int diffSum = 0;
    for(int i = 0 ; i < N ; i++)
    {
            if(pArray[i] < average)
            {
                diffSum += (average - pArray[i]);
            }
        else
        {
                diffSum += (pArray[i] - average);
        }
    }

    delete [] pArray;

    cout << diffSum /2  << endl;

    }


}



