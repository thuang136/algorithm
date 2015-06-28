/*


Multiply natural numbers in order starting from 1 as below.



         1, 1*2, 1*2*3, 1*2*3*4, ....



That is, it goes 1!, 2!, 3!, 4!, .... When we list this way, the first number that exceeds 100 is 5!, which is 120.



Given an integer N, write a program that finds the first number that exceeds N when expanding as above.



[input]

A positive number N is given. (1¡ÜN¡Ü100,000,000)



[output]

Print the first number that exceeds N.



[input/output example]

Input



587



Output



720






*/


#include<stdio.h>
#include<iostream>

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

    const char* INPUTFILE("../res/test-case/sample_input_exceed.txt");
    freopen(INPUTFILE,"r",stdin);


    /*
       Read each test case from standard input.
     */
    cin >> N;

    int curNum = 1;
    Answer = 1;
    while( Answer <= N)
    {
        Answer *= curNum;
        curNum += 1;
    }



    /////////////////////////////////////////////////////////////////////////////////////////////
    /*
       Implement your algorithm here.
     */
    /////////////////////////////////////////////////////////////////////////////////////////////
    //Answer = 0;


    // Print the answer to standard output(screen).
    cout << Answer << endl;

    return 0;//Your program should return 0 on normal termination.
}

