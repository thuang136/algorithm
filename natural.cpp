/*



List natural numbers from 1 in binary numbers, then it will go as follows:

?

                1, 10, 11, 100, 101, ¡­



Create a string after deleting commas and spaces in-between and it will go ¡°11011100101¡­¡±.



Write a program that prints the corresponding number in decimal numbers when five numbers are read continuously from the n-th character in the string above.

For example, if five numbers are read from the 1st character, it is 11011, which is 27 in decimal numbers, and when read from the 7th character, it is 00101, which is 5 in decimal numbers.



[input]

10 test cases are given. Throughout 10 lines, each test case is given in one line. Each test case consists of one positive integer, n. (1 ¡Ü n ¡Ü 1000)



[output]

Print answers to 10 test cases in 10 lines. Each line starts with "#x", leaves one space and writes the answer. (x: index of case)



[input/output example]

Input



1

7

...





Output



#1 27

#2 5

...




*/


#include<iostream>
#include<cstdio>
#include<string>
#include<queue>

using namespace std;

int N;
int Answer;

int main(int argc, char** argv)
{
    int test_case;
    /*
       freopen function below opens input.txt file in read only mode, and afterward,
       the program will read from input.txt file instead of standard(keyboard) input.
       To test your program, you may save input data in input.txt file,
       and use freopen function to read from the file when using cin function.
       You may remove the comment symbols(//) in the below statement and use it.
       Use #include<cstdio> or #include<stdio.h> to use the function in your program.
       But before submission, you must remove the freopen function or rewrite comment symbols(//).
    */
    // freopen("input.txt", "r", stdin);

    const char* INPUTFILE("../res/test-case/sample_input_digit.txt");
    freopen(INPUTFILE,"r",stdin);

    for(test_case = 1; test_case <= 10; ++test_case)
    {
        /*
            Read each test case from standard input.
        */
        cin >> N ;

        string series = "1";
        string target = "";
        queue<string> strqueue;

        strqueue.push(series);

        Answer = 0;

        while(!strqueue.empty())
        {
            string curDigit = strqueue.front();
            strqueue.pop();
            target += curDigit;

            if(target.size() >= (N+5-1))
            {
                string result = target.substr(N-1,5);
                int idx = result.size() - 1;
                int power = 1;
                while(idx >= 0)
                {
                     int digit = result[idx] - '0';
                     digit *= power;
                     Answer += digit;
                     power *= 2;
                     idx--;
                }

                break;

            }

            strqueue.push(curDigit + '0');
            strqueue.push(curDigit + '1');

        }


        /////////////////////////////////////////////////////////////////////////////////////////////
        /*
            Implement your algorithm here.
        */
        /////////////////////////////////////////////////////////////////////////////////////////////
        // Answer = 0;


        // Print the answer to standard output(screen).
        cout << "#" << test_case << " " << Answer << endl;
    }

    return 0;//Your program should return 0 on normal termination.
}

