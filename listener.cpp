#include<iostream>
#include<vector>
using namespace std;

class Delegate;

class Observer
{
public:
    static Observer* getInstance();

    void addDelegates(Delegate* delegate)
    {
        cout << "addDelegates" << endl;
        m_Delegates.push_back(delegate);
    }

    void trigger();

public:

vector<Delegate*>  m_Delegates;

private:
    Observer()
    {

    }

    static Observer* m_observer;
};



Observer* Observer::m_observer = NULL;

Observer* Observer::getInstance()
{
    if(m_observer == NULL)
    {
        m_observer = new Observer();
    }

    return m_observer;
}

class Delegate
{
  public:

    Delegate()
    {
        cout << "constructor in Delegate" << endl;
        Observer::getInstance()->addDelegates(this);
    }

    virtual void action()
    {
        cout << " action in Delegate" << endl;
    }


};


void Observer::trigger()
{
    cout << "trigger" << endl;
    cout << "m_Delegates.size() " << m_Delegates.size() << endl;
    for(int i = 0 ; i < m_Delegates.size(); i++)
    {
        (m_Delegates[i])->action();
    }
}

class DelegateDerive : public Delegate
{
public:
    DelegateDerive()
    {
        cout << "constructor in delegate derive" << endl;
    }

    virtual void action()
    {
        cout << " action in DelegateDerive" << endl;
    }
};


class DelegateDerive2 : public Delegate
{
public:
    DelegateDerive2()
    {
        cout << "constructor in delegate derive2" << endl;
    }

    virtual void action()
    {
        cout << " action in DelegateDerive2" << endl;
    }
};

int main(int argc, char** argv)
{
    DelegateDerive* pDelegateDervie = new DelegateDerive();

    DelegateDerive2* pDelegateDervie2 = new DelegateDerive2();

    Observer::getInstance()->trigger();

    return 0;
}