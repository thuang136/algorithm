/*

¡®Palindromic figures' mean numbers that read the same forward and reversed. For example, see the number 12321. It has the same forward and reversed.
¡®Palindromic squares' mean palindromic antilogarithms after squaring a certain number from 1 to 300. For example, if B=2, 1¡Á1=1=1(2) and 3¡Á3=9=1001(2), both are palindromic figures.
In an antilogarithm, let¡¯s express A, B and C when each digit figure is more than 10. In a given antilogarithm B, find out all cases of palindromic squares.

Time limit: 1 second (java: 2 seconds)

[Input]
Several test cases can be included in the inputs. T, the number of cases is given in the first row of the inputs. After that, the test cases as many as T (T ¡Ü 30) are given in a row.
Antilogarithm B is given on the first row per each test case. (2 ¡Ü B ¡Ü 30)

[Output]
Output the number of cases of palindromic squares with antilogarithm B on the first row of each test case.

[I/O Example]
Input
2
10
2

Output
12
2

Explanation of example
Check out the following 12 cases:
1¡Á1=1, 2¡Á2=4, 3¡Á3=9, 11¡Á11=121, 22¡Á22=484, 26¡Á26=676, 101¡Á101=10201, 111¡Á111=12321, 121¡Á121=14641, 202¡Á202=40804, 212¡Á212=44944, 264¡Á264=69696


*/


/*

Palindromic


*/

#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

const int MAX = 300;


bool isPalindromic(string square)
{
    int r = square.size() - 1;

    int l = 0;

    while( l < r)
    {
        if(square[l] != square[r])
        {
            return false;
        }
        else
        {
            l++;
            r--;
        }
    }

    return true;

}

string convert(int square,int antilogarithm)
{
    string result = "";

    while(square != 0)
    {
        int mode = square % antilogarithm;
        result += (mode + '0');
        square /= antilogarithm;
    }

    return result;
}

int main(int argc, char** argv)
{
    const char* INPUTFILE("../res/test-case/sample_input_Palindromic.txt");
    freopen(INPUTFILE,"r",stdin);

    int T;
    cin >> T;

    for(int t = 0 ; t < T ; t++)
    {
        int antilogarithm ;
        cin >> antilogarithm;

        int count = 0;
        for(int i = 1; i <= 300; i++)
        {
            string s = convert(i* i, antilogarithm);
            if(isPalindromic(s))
            {
                count++;
            }
        }

        cout << count << endl;
    }


}
