/*

specify the kinds of objects to create using a prototypical instance, and creating new objects by copying this prototype

applicability:

use the prototype pattern when a system should be independent of how its products are created, composed and represented

1.when the classes to instantiate are specified at run-time, for example, by dynamic loading

2.to avoid building a class hierarchy of factories that parallels the class hierarchy of products

3.when instances of a class can have  one of only  a few different combinations of state. it may be
more convenient to install a corresponding number of prototypes and clone them rather than instantiating the class manually, each time with appropriate state



prototype has many of the same consequences that the abstract factory and builder have, it hides the concrete product classes from the client, thereby reducing
the number of names clients know about.


1. adding and removing products at run-time.prototypes let you incorporate a new concrete product class into a system simply by regestering a prototype instance with the client
that's a bit more flexible than other creational patterns, because a client can install and remove prototype at run-time

2. specifying new objects by varying values. highly dynamic systems let you define new behavior through object composition-by specifying values for an object variables

3. specifying new object by varying structure



implement:

1.using a prototype manager, when the number of prototypes in a system isn't fixed(that is , they can be created and destroyed dynamically) keep a registry of a available prototypes
client won't manage prototypes themselves but will store and retrieve them from the registry. a client will ask the registry for a prototype before cloning it, we call this registry a prototype
manager

a prototype manager is an associative store that return the prototype matching a given key. it has operations for registering a prototype under a key and for unregistering it. client can
change or even browse through the registry at run-time



2. implement the clone operation

3. initializing clones





*/


#include<iostream>
#include<vector>
using namespace std;

class Clonable
{
public:
    virtual Clonable* clone() = 0;

    virtual ~Clonable() {}

};


class Float : public Clonable
{
public:
    Float(float v) : _value(v)
    {

    }

    float getValue()
    {
        return _value;
    }

    Float* clone()
    {
        Float* pRet = new Float(_value);
        return pRet;
    }

    ~Float()
    {

    }

private:
    float _value;
};


class Double : public Clonable
{
public:
    Double(float v) : _value(v)
    {

    }

    double getValue()
    {
        return _value;
    }

    Double* clone()
    {
        Double* pRet = new Double(_value);
        return pRet;
    }

    ~Double()
    {

    }

private:
    double _value;
};

class Array : public Clonable
{
public:

virtual Array* clone()
{
    Array* ret = new Array();

    vector<Clonable*>::iterator it = data.begin();

    for(; it != data.end(); ++it)
    {
        Clonable* cloneObj = (*it)->clone();
        ret->addObject(cloneObj);
    }

    return ret;
}

void addObject(Clonable* object)
{
    data.push_back(object);
}

~Array()
{
    vector<Clonable*>::iterator it = data.begin();

    for(; it != data.end(); ++it)
    {
        Clonable* cloneObj = (*it)->clone();
        delete cloneObj;
    }

}

private:

vector<Clonable*> data;
};

int main(int argc, char** argv)
{

    Float f1(1.0f);
    Float f2(2.0f);

    Double d1(3.0);
    Double d2(4.0);

    Array array1;
    array1.addObject(&f1);
    array1.addObject(&f2);
    array1.addObject(&d1);
    array1.addObject(&d2);

    Array* array2 = array1.clone();

    if(array2 != &array1)
    {
        cout << "copy successfully" << endl;
    }
    else
    {
        cout << "not success" << endl;
    }


}

