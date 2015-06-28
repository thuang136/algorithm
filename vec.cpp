#include <iostream>
#include <vector>
using namespace std;

int main(int argc ,char** argv)
{
    vector<int>* pVec = new vector<int>(3,10);

    vector<int> vec = *pVec;

    vec.insert(vec.begin(),0);

    for(int i = 0 ; i < 4; i++)
    {
        if( i == 0)
        {
           continue;
        }
        cout << "vec" << i << " " << vec[i] << endl;
    }

    return 0;
}
