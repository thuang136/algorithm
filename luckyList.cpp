/*


Mr. Kim is testing a mobile game that he developed.

In this game, you choose N numbers of figures from 1 to M and if your list matches to the given list, you¡¯ll get a big reward.

The ¡®lucky list¡¯ that he designed follows rules as below:

¡®The following figure is always more than twice bigger than the previous one.¡¯
For example, if N=4, M=10, the ¡®lucky list' is as below:

1, 2, 4, 8
1, 2, 4, 9
1, 2, 4, 10
1, 2, 5, 10

Mr. Kim is analyzing a winning probability of this ¡®lucky list.¡¯ Help him find out the number of the ¡®lucky list¡¯.

Time limit: 1 second (java: 2 seconds)

[Input]
Several test cases can be included in the inputs. T, the number of cases is given in the first row of the inputs.
After that, the test cases as many as T (T ¡Ü 300) are given in a row.
N & M are given by separated with a blank on the first row per each test case. (1 ¡Ü N ¡Ü 10, 1 ¡Ü M ¡Ü 2000, N ¡Ü M)

[Output]
Output the number of the ¡®lucky list¡¯ on the first row of each test case.

[I/O Example]
Input
3
4 10
2 20
2 200

Output
4
100
10000



Sample File :
sample_input.txt



*/

#include<iostream>
#include<cstdio>
using namespace std;


int main(int argc, char** argv)
{
    const char* INPUTFILE("../res/test-case/sample_input_luckyList.txt");
    freopen(INPUTFILE,"r",stdin);


}
