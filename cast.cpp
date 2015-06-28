#include<iostream>
using namespace std;

struct A
{

    A(int v)
    {
        mValue = v;
    }

    operator float ()
    {
        return mValue;
    }

    float mValue;

};

int main(int argc, char** argv)
{

    A a(10);

    float value = a;

    cout << value << endl;

}
