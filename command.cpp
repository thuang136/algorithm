/*
how intelligent should a command be? A command can have a wide range of abilities.At one extreme it merely defines a binding between a receiver and the actions that carry out the request
at the other extreme it implements everything itself without delegating to a receiver at all. The last extreme is useful when you want to define command that are independent of existing
classes, when no suitable receiver exists, or when a command knows its receiver implicity. for example, a command that create another application window may be just are capable of creating
the window as any other object.


supporting undo and redo. Commands can support undo and redo capabilities, if they provide a way to reverse their execution, a ConcreateCommand class might need to store additional state to
do so.this state can include:

the Receiver object, which actually carries out operations in response to the request

the arguments to the operation performed on the receiver

any orignal values in the receiver that can change as a result of handling the request. the receiver must provide operations that let the command return the receiver to its prior state


using c++ template


*/

#include<iostream>
#include<vector>
using namespace std;

class Command
{
public:
    virtual ~Command()
    {
    }

    virtual void Execute() = 0;

protected:
    Command()
    {

    }
};


template<class Receiver>
class SimpleCommand : public Command
{
public:
    typedef void (Receiver::*Action)();

    SimpleCommand(Receiver* r, Action a) : _receiver(r),_action(a)
    {

    }

    virtual void Execute()
    {
        (_receiver->*_action)();
    }

private:

    Action _action;
    Receiver* _receiver;

};

class MyClass
{
public:
    void redo()
    {
        cout << "in myclass" << endl;
    }

};

class YourClass
{
public:
    void check()
    {
        cout << "check your class" << endl;
    }
};

int main(int argc, char** argv)
{

    MyClass* receiver = new MyClass;

    Command* aCommand = new SimpleCommand<MyClass>(receiver,&MyClass::redo);

    YourClass* youReceiver = new YourClass;

    Command* yCommand = new SimpleCommand<YourClass>(youReceiver,&YourClass::check);

    vector<Command*> commandQueue;
    commandQueue.push_back(aCommand);
    commandQueue.push_back(yCommand);

    for(int i = 0 ; i < commandQueue.size(); i++)
    {
        commandQueue[i]->Execute();
    }

}


