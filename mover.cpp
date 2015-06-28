/*


Mover
Time Limit: 1000MS  Memory Limit: 65536K
Total Submissions: 465  Accepted: 73  Special Judge

Description

Given a board of N ¡Á N cells, each cell may contain at most one piece.

For the purpose of this problem, two pieces A and B are directly connected if their cells share a common edge.

Two pieces A and B are connected indirectly if there exists another piece C such that A and C are connected (indirectly or directly)

and B and C are connected (indirectly or directly). Write a program to use no more than 50000 instructions to make all pieces connected (indirectly or directly) with each other.

Each instruction can move one piece to an empty cell, which shares a common edge.

Input

The first line of input contains two integers N, M, denoting the size of board and the number of pieces on the board. 1 ¡Ü N ¡Ü 100, 1 ¡Ü M ¡Ü N ¡Á N
Following m lines, each contains two numbers X,Y, denoting the position of one piece. All (X,Y) will be distinct. 0 < X,Y ¡Ü N

Output

The first line of output contains one integer C denoting the number of instructions.
Following C lines, each contains four numbers X1, Y1, X2, Y2 for one instruction, which will move the piece in (X1,Y1) to (X2,Y2). If there are many such instructions, you can output any one of them.

Sample Input

4 4
1 1
2 2
3 3
4 4

Sample Output

4
1 1 2 1
4 4 3 4
3 4 2 4
2 4 2 3



*/

#include<iostream>
#include<cstdio>
using namespace std;

int main(int argc, char** argv)
{




}
