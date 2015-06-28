#include<iostream>
#include<cstring>
using namespace std;

int main(int argc, char** argv)
{
    int * ch = new int[10];

    memset(ch, -1, sizeof(ch));

    for(int i = 0 ; i < 10; i++)
    {
        cout << ch[i] << endl;
    }
}
