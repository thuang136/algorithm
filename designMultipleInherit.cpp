#include<iostream>
using namespace std;

class A
{
public:

  void operateA()
  {
      cout << "operate A" << endl;
  }
};

class B
{
public:

  void operateB()
  {
      cout << "operate B" << endl;
  }

};


class C : public A , private B
{
public:

   void operateC()
   {
       operateB();
       cout << "operate C" << endl;
   }

};

int main(int argc, char** argv)
{
    C c;
    c.operateC();
}
