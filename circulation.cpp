/*


The R&D center in our company formulated a Samsung sequence from a spectrum according to electron orbital changes.

In order to create the sequence, the initial number, N & the square number, P are required.

When N & P are fixed, the first element of the sequence is N,

and the second element is the sum of raising each cipher of the first element to P. And also for the third element, you can do the sum of raising each cipher of the second element to P.

For example, let¡¯s think about the case, N=57 & P=2. The first element of the sequence is 57, and the second element is 5¡Á5+7¡Á7=74. Like this, the third element is 7¡Á7+4¡Á4=65,

& the forth element is 6¡Á6+5¡Á5=61. After that, you can find the following sequence: 57, 74, 65, 61, 37, 58, 89, 145, 42, 20, 4, 16, 37, 58, 89 etc.

However, our R&D center found that the elements of Samsung sequence are circulated and wanted to find out the length of the sequence of the front section which is not circulated.

Let¡¯s satisfy their curiosity of the R&D center.

Time limit: 1 second (java: 2 seconds)

Input format

Several test cases can be included in the inputs. T, the number of cases is given in the first row of the inputs. After that, the test cases as many as T (T ¡Ü 30) are given in a row.
N, the initial number and P, the square number of the sequence in the first row of each test case are given as being separated. (2 ¡Ü N ¡Ü 9999, 2 ¡Ü P ¡Ü 5)

Output format

Output the length of the sequence of the front section which is not circulated from the Samsung sequence given in the first row of each test case.

Example of Input

2
57 2
638 2

Example of Output

4
5

*/

#include<map>
#include<iostream>
#include<cstdio>
using namespace std;

int nextInt(int num,int p)
{
   int nextValue = 0;

   while(num != 0)
   {
       int digit;
       digit = num % 10;

       int powNum = digit;
       for(int i = 1; i < p; i++)
       {
           powNum *= digit;
       }

       nextValue += powNum;

       num = num /10;

   }

   return nextValue;

}

int main(int argc, char** argv)
{
    const char* INPUTFILE("../res/test-case/sample_input_circulation.txt");
    freopen(INPUTFILE,"r",stdin);

    int T;

    cin >> T;

    for(int i = 0 ; i < T; i++)
    {
        int N, P;

        cin >> N >> P;

        map<int,int> indexMap;

        int index = 0;

        indexMap[N] = index++;


        while(true)
        {
            N = nextInt(N,P);

            if(indexMap.find(N) == indexMap.end())
            {
                indexMap[N] = index++;
            }
            else
            {
                index = indexMap[N];
                break;
            }

        }

        cout << index << endl;

    }


}

