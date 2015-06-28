

// In Practice, You should use the statndard input/output
// in order to receive a score properly.
// Do not use file input and output. Please be very careful.

#include <cstdio>
#include <set>
#include <iostream>

using namespace std;

/*
一个集合中任取二个数，计算差值， 然后从这个集合中删除一个较大值
如果这个集合只剩下二个值，那么直接可以求得
*/


int cal(int* contests, int N)
{
    /*
        两两比较
    */

    int min = 0;
    int i = 0;
    for(; i < N-1;i++)
    {
        int j = i+1;
        for(; j < N; j++)
        {
            int diff = contests[i] - contests[j];
            int k;
            if( diff > 0)
            {
                k = i;
            }
            else
            {
                k = j;
                diff = -diff;
            }

            // 删除较大的那个数，构成一个contests开始的 N-1 大的集合
            int* arr = new int[N-1];
            int  m = 0;
            int  n = 0;
            for(; m < N; m++)
            {
                if(contests[m] != k)
                {
                    arr[n++] = contests[m];
                }
            }

            int left = cal(arr,N-1);

            if( diff + left < min)
            {
                min = diff + left;
            }

            delete[] arr;

        }
    }

    return min;

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

    //freopen("sample_input_contest.txt", "r", stdin);

    const char* INPUTFILE("../res/test-case/sample_input_prim.txt");
    freopen(INPUTFILE,"r",stdin);


    cin >> T;
    for(tc = 0; tc < T; tc++)
    {
        /**********************************
        *  Implement your algorithm here. *
        ***********************************/

        // Print the answer to standard output(screen).

        int N;
        cin >> N;

        int* array = new int[N];
        int i = 0;
        for(; i < N; i++)
        {
            cin >> array[i];
        }

        cout << cal(array,N);

    }

    return 0;//Your program should return 0 on normal termination.
}



