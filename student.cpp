#include "people.h"

#define _CHART_EXPORT_ __attribute__((visibility("default")))
#define _CHART_LOCAL_  __attribute__((visibility("hidden")))


class Student : public BasePeople
{

public:

    Student(const string& name, const int age) : BasePeople(name,age)
    {
        cout << "student's constructor invoked" << endl;
    }

    virtual ~Student()
    {
        cout  << "student's deconstructor invoked" << endl;
    }


    virtual void speak()
    {
        int i = 0;
        while( i < 10)
        {
            cout << " i am a student my name is " << this->name_ << ",age is " << this->age_ << endl;
            //sleep(1);
            ++i;
        }

    }

};





BasePeople* create_BasePeople(const string& name, const int age)
{
    return new Student(name,age);
}

void delete_BasePeople(BasePeople * pp)
{
    if(pp)
    {
        delete pp;
    }
}





























