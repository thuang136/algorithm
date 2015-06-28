#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

/*
    ±£Ö¤ a > b
*/

void vectorStd(int& x, int& y)
{
    int a = x;
    int b = y;

    while( b != 0)
    {
      int temp = a;
      a = b;
      b= temp % b;
    }

    x = x / a;
    y = y / a;
}


int hash(int x, int y, int N)
{
    return x * (N+1) + y;
}

int main(int argc ,char** argv)
{

    const char* INPUTFILE("../res/test-case/grid_sample_input.txt");
    freopen(INPUTFILE,"r",stdin);

    int T;
    cin >> T;

    for(int t = 0 ; t < T ; t++)
    {
        int N;
        cin >> N;

        set<int> hashSet;

        for(int i = 1 ; i <= N ; i++)
        {
            for(int j = 1; j <= i; j++)
            {
                int x = i, y = j;
                vectorStd(x,y);
                hashSet.insert(hash(x,y,N));
            }
        }

        int size = hashSet.size() * 2  - 1 + 2;

        cout << size << endl;

    }

}


