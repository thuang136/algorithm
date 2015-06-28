/*



Between the columns using four parentheses ¡®(¡®, ¡®)¡¯, ¡®[¡®, ¡®]¡¯, a correct parentheses column is defined as below:

1. ¡®()¡¯ or ¡®[]¡¯ consisting of a couple of parenthesis only is correct.
2. If X is the correct parentheses column, both ¡®(X)¡¯ and ¡®[X]¡¯ are correct.
3. If both X & Y are correct parentheses columns, the combined ¡®XY¡¯ is correct.

For example, ¡®(()[[]])¡¯ or ¡®(())[][]¡¯ is the correct parentheses column but ¡®([)]¡¯ or ¡®(()()[]¡¯ is not.

For a certain correct parentheses X, we define the value (in parentheses) in the row as below and indicate as Value(X).

1. The value of ¡®()¡¯ parentheses column is 2.
2. The value of ¡®[]¡¯ parentheses column is 3.
3. The value of ¡®(X)¡¯ parentheses column is 2¡ÁValue(X).
4. The value of ¡®[X]¡¯ parentheses is 3¡ÁValue(X).
5. The value of ¡®XY¡¯ parentheses is Value(X)+Value(Y).

For example, to find the parentheses value of ¡®(()[[]])([])¡¯, the value of parentheses ¡®()[[]]¡¯ is 2+3¡Á3=11.
Therefore, the parentheses value of ¡®(()[[]])¡¯ is 2¡Á11=22.
In addition, as the parentheses value of ¡®([])¡¯ is 2¡Á3=6, the total parentheses column value is 22+6=28.
Calculate parentheses values in given parentheses columns.

Time limit: 1 second (java: 2 seconds)

[Input]
Several test cases can be included in the inputs. T, the number of cases is given in the first row of the inputs.
After that, the test cases as many as T (T ¡Ü 30) are given in a row.
Character columns indicating parentheses columns are given on the first row per each test case. The length is over 1 below 30.

[Output]
Output the parentheses values on the first row of each test case. At this time, if parentheses columns are not correct, output zero.

[I/O Example]
Input
2
(()[[]])([])
[][]((])

Output
28
0


*/


#include<iostream>
#include<cstdio>
#include<stack>
#include<string>
using namespace std;

int main(int argc, char** argv)
{

const char* INPUTFILE("../res/test-case/sample_input_parenthese.txt");
freopen(INPUTFILE,"r",stdin);


int T;

    cin >> T;

    for(int t = 0 ; t < T ; t++)
    {
        string parentheses;
        cin >> parentheses;

        int parentheses_size = parentheses.size();
        stack<char> charStack;
        stack<int>  intStack;

        int top = 0;

        int result = -1;

         for(int i = 0 ; i < parentheses_size; i++)
        {
            char c = parentheses[i];

            if(charStack.empty() || c == '(' || c == '[')
            {
                charStack.push(c);
            }
            else if( c == ')')
            {
                char topChar = charStack.top();
                if(topChar == '(')
                {
                   charStack.pop();
                   charStack.push('*');
                   intStack.push(2);
                }
                else if( topChar == '[')
                {
                   result = 0;
                   break;
                }
                else
                {
                    char topVal = charStack.top();
                    int sum = 0;
                    while(topVal == '*')
                    {
                        charStack.pop();
                        topVal = charStack.top();
                        int val = intStack.top();
                        sum += val;
                        intStack.pop();
                    }

                    if(topVal == '(')
                    {
                        sum *= 2;
                        charStack.pop();
            charStack.push('*');
                        intStack.push(sum);
                    }
                }

            }
            else
            {
                char topChar = charStack.top();
                if(topChar == '[')
                {
                   charStack.pop();
                   charStack.push('*');
                   intStack.push(3);
                }
                else if( topChar == '(')
                {
                   result = 0;
                   break;
                }
                else
                {
                    char topVal = charStack.top();
                    int sum = 0;
                    while(topVal == '*')
                    {
                        charStack.pop();
                        topVal = charStack.top();
                        int val = intStack.top();
                        sum += val;
                        intStack.pop();
                    }

                    if(topVal == '[')
                    {
                        sum *= 3;
                        charStack.pop();
            charStack.push('*');
                        intStack.push(sum);
                    }
                }

            }


        }


    while(!charStack.empty())
    {
        char c = charStack.top();
        charStack.pop();
        if( c != '*')
        {
        result = 0;
        break;
        }
    }
        
    if(result == -1)
    {
        result = 0;
        while(!intStack.empty())
        {
        result += intStack.top();
        intStack.pop();
        }
    }

        cout << result << endl;
    }


}

