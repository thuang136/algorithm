#include<iostream>
#include<map>
using namespace std;


/*

1. Ensuring a unique instance

2. Subclassing the Singleton class, the main issue is not so much defining the subclass but installing its unique instance so that client will be able to use it
in essence, the variable that refers to the singleton instance must get initialized with an instance of the subclass.

   a more flexible approach uses a registry of singletons. instead of having Instance define the set of possible Singleton classes. the Singleton class can register
   their singleton instance by name in a well-known registry

   the registry map between string names and singletons, when Instance needs a singleton, it consults the registry, asking for the singleton by name
   the registry looks up the corresponding singleton and return it

   this approach free instance from knowing all possible Singleton classes or instances, all it requires is a common interface for all singleton classes or instance
   All it requ

*/

class Singleton
{
public:

    static Singleton* Instance();

    static void Register(const char* name,Singleton* singleton);



    virtual void print()
    {
        cout << "i am singleton" << endl;
    }


protected:

    Singleton()
    {

    }

    static Singleton* Lookup(const char* name);

private:

    static Singleton* _instance;

    static map<const char*,Singleton*> _registry;

};

Singleton* Singleton::_instance = NULL;

map<const char*,Singleton*> Singleton::_registry;


Singleton* Singleton::Instance()
{
    if(_instance == NULL)
    {
        _instance = Lookup("MySingleton");
        if(_instance == NULL)
        {
            _instance = new Singleton();
        }
    }

    return _instance;
}

void Singleton::Register(const char* name,Singleton* singleton)
{
     _registry[name] = singleton;

}

Singleton* Singleton::Lookup(const char* name)
{
    return _registry[name];
}

class MySingleton : public Singleton
{
public:

    MySingleton()
    {
        Singleton::Register("MySingleton",this);
    }

    void print()
    {
        cout << "i am MySingleton" << endl;
    }

};

static MySingleton theSingleton;


int main(int argc, char** argv)
{
    Singleton::Instance()->print();
}


