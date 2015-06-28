/*


Our company planned to send the staff’s parents a sight-seeing trip for a week.
The list of attractions includes many famous places from Seoul (Starting point) to the southernmost tip of the country in order from north to south.

Routes for the tour bus are also included on the list.
Because of the short itinerary for a week, it is not possible to go around all attractions but you want to make them visit as many places as they can.

Naturally, they will not need to go the same place twice except the starting point to which they will return eventually.

They need to keep visiting tourist sites by coming down from south and coming up north to reduce the travel expenses and to visit as many sites as possible.


Mr. Lee plans to set up a tour route with the list to visit tourist attractions as many as possible.

Create a program that allows the largest number of the sights.

Time limit: 1 second (java: 2 seconds)

Input format

Several test cases can be included in the inputs. T, the number of cases is given in the first row of the inputs.
After that, the test cases as many as T (T ≤ 30) are given in a row.
The number of sightseeing cities, N and the number of bus routes, M are given by being separated with a blank on the first row per each test case. (1 ≤ N ≤ 100, 1 ≤ M ≤ 700)
Names of cities are given from north to south direction from the second row to N number rows.

Names of cities which are the information of bus routes are given by being separated with a blank from the next row to M number rows. i.e. the tour bus can move between two cities.

Output format

Output the maximum number of cities where they come down from Seoul (Starting point) to the southernmost tip of the country and come back to Seoul.

Example of Input

2
8 9
Seoul    0
Incheon  1
Daejeon  2
Daegu    3
Gwangju  4
Jeonju   5
Ulsan    6
Busan    7
Seoul Daejeon 0 2
Seoul Daegu   0 3
Daegu Gwangju 3 4
Gwangju Jeonju 4 5
Jeonju Busan 5 7
Ulsan Busan 6 7
Daejeon Ulsan 2 6
Daejeon Incheon 2 1
Daejeon Daegu 2 3
8 13
A city
B city
C city
D city
E city
F city
G city
H city
A city B city
A city C city
C city B city
D city C city
D city B city
D city E city
D city F city
E city F city
E city G city
D city H city
H city F city
H city G city
A city G city

Example of Output

7
8

*/

#include<iostream>
#include<string>
#include<cstdio>
#include<map>
#include<cstring>

using namespace std;



const int MAX_NUM = 101;

int conMatrix[MAX_NUM][MAX_NUM];
bool visited[MAX_NUM];
int cityPath[MAX_NUM];

int N, M;

int maxValue = 0;


/* 从 s 出发进行深度优先遍历，看看能否找到一条回来原点的路径

怎么区分从起点出发和回到起点，回路不能有重复，所以还是需要加访问标记

*/

void dfs(int s,int* path,int size)
{
    path[size] = s;

    for(int k = 0 ; k < N ; k++)
    {
        if( conMatrix[s][k] == 1 && visited[k] == false)
        {
            if( k == path[0])
            {
               for(int i = 0; i <= size; i++)
               {
                   cout << path[i] << " ";
               }
               cout << endl;

               if( size + 1 > maxValue)
               {
                   maxValue = size + 1;
               }
            }

            else
            {
                visited[k] = true;

                dfs(k,path,size+1);

                visited[k] = false;

            }
        }
    }
}



int main(int argc , char** argv)
{

    const char* INPUTFILE("../res/test-case/sample_input_city.txt");
    freopen(INPUTFILE,"r",stdin);

    int T;

    cin >> T;

    for(int i = 0; i < T; i++)
    {


        cin >> N >> M;

        map<string,int> placeIndexMap;

        memset(&conMatrix[0][0],0,sizeof(conMatrix));

        memset(&visited[0],false,sizeof(visited));

        for(int j = 0; j < N; j++)
        {
            string place;
            cin >> place;
            placeIndexMap[place] = j;
        }

        for(int j = 0; j < M; j++)
        {
            string place1, place2;
            cin >> place1 >> place2;
            int m = placeIndexMap[place1];
            int n = placeIndexMap[place2];
            conMatrix[m][n] = 1;
            conMatrix[n][m] = 1;
        }

        maxValue = 0;

        dfs(0,cityPath,0);

        cout << maxValue << endl;


    }


}

