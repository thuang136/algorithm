/*

You are busy to promote a newly released film in a movie theater.
The title is ¡®Biochemical Laughing Bomb¡¯ which is about terror.
Guerrillas drop a biochemical laughing bomb in the middle of a city.
Once exposed, you have to laugh all your life. The bomb will contaminate four people around it during 1 second,

and another four around each of them during another one second.
However, you won¡¯t be contaminated if you are not in the adjacent four directions.
as the below shows the location of the bomb and affected people, and shows contamination process in seconds and you can figure out that the whole city is contaminated in 8 seconds.
In order to protect the city from the epidemic, create a program that figures out when the city will be contaminated by the bomb for the last.


2
7 8
0 0 1 1 0 0 0
1 1 1 1 0 1 0
0 0 1 1 1 1 1
0 1 1 1 1 1 1
0 1 0 0 1 1 0
0 1 1 1 1 0 0
0 0 1 0 1 1 1
0 0 0 0 1 0 0
2 5
10 10
1 1 1 1 0 1 1 0 0 0
0 1 1 1 1 1 0 1 1 0
0 0 1 1 0 1 0 1 1 1
0 1 1 1 1 1 0 0 1 1
0 1 0 1 0 1 1 1 1 0
0 0 0 0 0 1 1 0 0 0
1 0 1 0 1 0 1 1 0 0
0 0 1 1 1 1 1 1 1 1
1 0 1 0 0 1 0 1 1 0
1 1 1 0 0 0 0 1 1 1
2 2


Several test cases can be included in the inputs. T, the number of cases is given in the first row of the inputs. After that, the test cases as many as T (T ¡Ü 30) are given in a row.
The row and column of the city, N and M are given by being separated with a blank on the first row of each test case. (1 ¡Ü N, M ¡Ü 100)
The status within city is given by being separated with a blank from the second row to N number rows. 1 means people exist and 0 means people do not exist.
The coordinate of the row and column on which the bomb fall is given by being separated with a blank on the last row.



*/


#include<iostream>
#include<cstdio>
#include<cstring>


using namespace std;

const int MAXNUM = 102;
const int LIMIT = 10000;

int matrix[MAXNUM][MAXNUM];

int N,M;

void recurBomb(int x, int y, int level)
{
    if( level >= matrix[x][y] )
    {
        return;
    }

    matrix[x][y] = level;

    if(x < M && matrix[x+1][y] != 0)
    {
        recurBomb(x+1,y,level+1);
    }

    if(y < N && matrix[x][y+1] != 0)
    {
         recurBomb(x,y+1,level+1);
    }

    if(x > 1 && matrix[x-1][y] != 0)
    {
        recurBomb(x-1,y,level+1);
    }

    if(y > 1 && matrix[x][y-1] != 0)
    {
         recurBomb(x,y-1,level+1);
    }

}


int main(int argc, char** argv)
{
    const char* INPUTFILE("../res/test-case/sample_input_bomb.txt");
    freopen(INPUTFILE,"r",stdin);

    int T;
    cin >> T;

    for(int t = 0 ; t < T; t++)
    {

        cin >> N >> M;

        memset(&matrix[0][0],0,sizeof(matrix));

        for(int i = 1 ; i <= M; i++)
        {
            for(int j = 1; j <= N; j++)
            {
                cin >> matrix[i][j];
                if( matrix[i][j] )
                {
                    matrix[i][j] = LIMIT;
                }
            }
        }


        int explodX, explodY;

        cin >> explodY >> explodX;

        recurBomb(explodX,explodY,1);

        int answer = 0;

        for(int i = 1 ; i <= M; i++)
        {
            for(int j = 1; j <= N; j++)
            {
                if( matrix[i][j] > answer && matrix[i][j] != LIMIT)
                {
                    answer = matrix[i][j];
                }
            }
        }

        cout << answer << endl;

    }

}


