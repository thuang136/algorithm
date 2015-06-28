
#include<string>
#include<iostream>

using namespace std;



static const string _CREATE_OBJECT_ = "create_BasePeople";
static const string _DELETE_OBJECT_ = "delete_BasePeople";

class BasePeople
{
    public:

            BasePeople(const string& name, const int age) : name_(name),age_(age)
            {
          cout << "BasePeopleis constructor invoked" << endl;
            }

            virtual ~BasePeople()
            {
          cout << "BasePeople's deconstructor invoked" << endl;
            }


      virtual void speak() = 0;

            void test()
            {
          cout << "this is the test method!" << endl;
            }


    protected:
            int age_;
            string name_;
};



extern "C" BasePeople* create_BasePeople(const string& name, const int age);

extern "C" void delete_BasePeople(BasePeople *pp);





























