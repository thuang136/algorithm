#include<iostream>
using namespace std;

class Context;

class BooleanExp
{
public:
    BooleanExp();

    virtual ~BooleanExp();

    virtual bool Evaluate(Context& context) = 0;

    virtual BooleanExp* Replace(const char* key, BooleanExp& exp) = 0;

    virtual BooleanExp* Copy() const = 0;


};

int main(int argc, char** argv)
{



}


