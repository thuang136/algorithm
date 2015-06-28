/*


In a city, a bus stops every kilometer. Also the bus fare is different from 1km to 10km, so you can use each section well to decrease the total fare to get to the destination.
For example, let��s suppose a bus fare list as below:



According to the list, the minimum fare would be 147 for 15km: 1 ticket for 3km + 2 tickets for 6km. Or 3 tickets for 5km will have the same result. Other ways cost more. When the bus fare and distance are given, calculate the minimum fare that you can move the given distance.

Time limit: 1 second (java: 2 seconds)

[Input]
Several test cases can be included in the inputs.

T, the number of cases is given in the first row of the inputs.
After that, the test cases as many as T (T �� 30) are given in a row.
The info of the bus fare, 10 integers are given on the first row per each test case. This is the bus fare from 1km to 10km respectively,

and the maximum bus fare is 500.

In addition, i km fare is not always bigger than (i-1)km.

The distance to move, N is given on the second row. (1 �� N �� 10000)

[Output]
Output the minimum fare to give the given distance on the first row per each test case.

[I/O Example]
Input
12 21 31 40 49 58 69 79 90 101
15
12 20 30 40 25 60 70 80 90 11
21

Output
147
34


*/


/*

Ҫ��15���ﻨ����С���ã� ��1���ﻨ�ķ��ã� ʣ��14������������С����

����fare(i)��ʾ��i�������С���ã���i������Էֽ����fare(j) + fare(i-j) ,

���Կ��Դӵ������㣬 ������1�������С���ã�

������2�������С���ã� �����1 ��  10 �������С���ã�������������

*/

#include<iostream>
#include<cstdio>
using namespace std;

const int MAX = 10001;
const int MAX_FEE = 500;

int main(int argc, char** argv)
{

    const char* INPUTFILE("../res/test-case/sample_input_busStop.txt");
    freopen(INPUTFILE,"r",stdin);

    int T;
    cin >> T;

    for(int i = 0 ; i < T; i++)
    {
        //�Ƚ���֪����С��������,֮�󲻶ϸ������ֵ
        int bus_fare[MAX];
        bus_fare[0] = 0;
        int j = 1 ;
        for(; j <= 10 ; j++)
        {
            cin >> bus_fare[j];
        }

        int distance;
        cin >> distance;

        for(; j <= distance; j++)
        {
            bus_fare[j] = MAX_FEE * distance;
        }

        for(int m = 1 ; m <= distance; m++)
        {
            for(int n = 1; n < m; n++)
            {
                if(bus_fare[n] + bus_fare[m-n] < bus_fare[m])
                {
                    bus_fare[m] =  bus_fare[n] + bus_fare[m-n];
                }
            }
        }

        cout << bus_fare[distance] << endl;


    }

}

