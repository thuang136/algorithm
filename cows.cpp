/*






There are N numbers of cows grazing in the farm in a row.
They talk to each other and they need to raise their voices depending on the distance of the two cows.
Suddenly you are curious of the total sum of all the cows¡¯ lowing volume about how high they should raise the voice to talk.
For example, when 5 cows are in each location of 1, 5, 3, 2 and 4, No. 1 cow needs to raise its voice to talk to other cows and the sum is 4+2+1+3=10,

No. 2 cow¡¯s sum is 4+2+3+1=10,

No. 3 cow¡¯s sum is 2+2+1+1=6,

No. 4 cow¡¯s sum is 1+3+1+2=7 and

No. 5 cow¡¯s sum is 3+1+1+2=7.

Therefore the total sum is 10+10+6+7+7=40. Now make your own method to calculate the total sum of lows.

Time limit: 1 second (java: 2 seconds)

Input format

Several test cases can be included in the inputs. T, the number of cases is given in the first row of the inputs.
After that, the test cases as many as T (T ¡Ü 30) are given in a row.
N, the number of cows is given in the first row of each test case. (1 ¡Ü N ¡Ü 500000)
Each cow location is given from the second row to the number of N. The locations of cows are always given as integers,
and several cows may exist on the same location.

Output format

Output the volume sum of lows of cows to rise in order to talk each other in the first row of each test case. This sum is not over 10^15.

Example of Input

2
5
1
5
3
2
4
5
1
1
1
1
1

Example of Output

40
0






*/

/*


#include<iostream>
#include<math.h>
#include<cstdio>
using namespace std;

int main(int argc,char** argv)
{

    const char* INPUTFILE("../res/test-case/sample_input_cows.txt");
    freopen(INPUTFILE,"r",stdin);

    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        int N;
        cin >> N;

        int* arr = new int[N];
        for(int j = 0; j < N; j++)
        {
            cin >> arr[j];
        }
        int total = 0;
        for(int m = 0; m < N; m++)
        {
            for(int n = 0; n < N; n++)
            {
                if( m != n)
                {
                    total += fabs(arr[m]-arr[n]);
                }
            }
        }

        cout << total << endl;
    }



}

*/


#include<iostream>
#include<cstdio>
using namespace std;

int N;

int diffSum(int* arr, int p, int r)
{

    int i = p - 1;
    int j = p;

    int pivot = arr[r];

    for(; j <= r - 1; j++)
    {
        if(arr[j] <= pivot)
        {
            ++i;
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }

    int temp = arr[r];
    arr[r] = arr[i+1];
    arr[i+1] = temp;

    return i + 1;
}


int  quickSort(int* arr, int p, int r)
{
    if( p < r)
    {
        int q = diffSum(arr,p,r);

        quickSort(arr,p,q-1);
        quickSort(arr,q+1,r);

    }

}

int main(int argc,char** argv)
{

    const char* INPUTFILE("../res/test-case/sample_input_cows.txt");
    freopen(INPUTFILE,"r",stdin);

    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        cin >> N;

        int* arr = new int[N];
        for(int j = 0; j < N; j++)
        {
            cin >> arr[j];
        }

        quickSort(arr,0,N-1);

        for(int j = 0; j < N; j++)
        {
            cout << " " << arr[j];
        }
        cout << endl;
    }



}





