/*


?You are given a string that consists of parentheses. That is, the string is composed of the following two characters: ‘(‘ and ‘)’. We say that such a string is well formed if it follows normal parenthesis rules.
For example, “(())” is well formed but “)(()” is not.

Let’s call the operation of exchanging two adjacent characters in a string a swap operation. In the previous example, if we swap the first and the second characters in “)(()” then we obtain a well-formed string.
Obviously, that is the minimum number of swaps needed to transform it into a well-formed string.
You can define an order among the well-formed strings of a same length, which is called the first-closing order. (Incidentally, that order is the exact reverse of the lexicographical order.)
For example, if you consider the case of length-six strings, the order would be: “()()()”, “()(())”, “(())()”, “(()())”, “((()))”.
 If you look closely, you will see that the strings in which the first opening parenthesis is closed the earliest come first, and if that is the same for two strings, the rule is recursively applied to the next opening parenthesis.

Given a string composed of parentheses, write a program to compute the minimum number of swap operations to transform it into a well-formed string and the first-closing order number for the resulting string.

Time Limit: 1 second for 20 cases. (java 2 second)
(If your program exceeds this time limit, the answers that have been already printed are ignored and the score becomes 0.
 So, it may be better to print a wrong answer when a specific test case might cause your program to exceed the time limit. One guide for the time limit excess would be the size of the input.)


[Input]
There can be more than one test case in the input file. The first line has C, the # of test cases. Then the totally C test cases are provided in the following lines (1 ≤ C ≤ 20).
Each test case is just one line that contains the input string. The maximum size of the string is 100,000.

[Output]
For the T-th test case, “Case #T” should be printed out in the first line. If the input for the case can be transformed to a well-formed string, print two integers.
The first one is the minimum number of swap operations to transform the input into a well-formed string.
If the given string would be already well-formed before solving with your program then print 0.
The second one is the order number of the resulting string.
This number can be really huge, so print the remainder when it is divided by 1,000,000,007.

?If the given string would not be well-formed using swap operations then only print -1.
?

[I/O Example]
Input
3                        ←  There are three test cases in total.
)(()                     ←  Case 1
))((()                   ←  Case 2
)()                      ←  Case 3

Output
Case #1
1 1
Case #2
3 1
Case #3
-1



*/

#include<iostream>
#include<cstdio>

using namespace std;

string void exchangeParentheses(string line)
{
    int size = line.size();
    char* result = new char[size];
    int top = 0;

    for(int i = 0 ; i < size; i++)
    {
       char cur = line[i];

       if(top == 0)
       {
           result[top++] = cur;
           continue;
       }

       if(cur == '(')
       {
           if(result[top-1] == '(')
           {
               result[top++] = cur;
           }
           else
           {
               //往前看，有没有未匹配的)
           }
       }
       else if( cur == ')')
       {
           if(result[top -1] == '(')
           {
              result[top++] = cur;
           }

           else
           {

           }

       }

    }
}


int main(int argc, char** argv)
{
    int C;
    cin >> C;

    for(int i = 0; i < C; i++)
    {
        string line;
        cin >> line;
    }

}

