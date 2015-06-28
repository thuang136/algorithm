#include<iostream>
#include<memory>
#include<vector>

using namespace std;

class A
{
  public:
      A(int num)
      {
        _num = num;
        cout << "constructor" << endl;
      }

    virtual ~A()
    {
        cout << "destructor" << endl;
    }
  private:
      int _num;
};

int main(int argc, char** argv)
{
    A* p = new A(0);

    auto_ptr<A> pA(p);

    vector<A*> pVec;

    pVec.push_back(pA.release());

}

