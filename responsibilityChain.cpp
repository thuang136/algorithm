
/*

Reduced coupling. The pattern frees an object from knowing which other object handles a request. An object only has to known that a request will be handled "appropriately" both the
receiver and the sender have no explicit knowledge of each other,and an object in the chain doesn't have to know about the chain's structure
As a result, Chain of Responsibility can simplify object interconnection. Instead of objects maintaining reference to all candidate receivers

added flexibility in assigning repsonsibilies to objects

receipt isn't guaranteed





*/


#include<iostream>
using namespace std;

typedef int Topic;

const Topic NO_HELP_TOPIC = -1;

class HelpHandler
{
public:
    HelpHandler(HelpHandler* successor = 0, Topic topic = NO_HELP_TOPIC) : _successor(successor),_topic(topic)
    {

    }

    virtual bool HasHelp()
    {
        return _topic != NO_HELP_TOPIC;
    }

    virtual void SetHandler(HelpHandler* handler, Topic topic)
    {
        _successor = handler;
        _topic = topic;
    }


    virtual void HandleHelp()
    {
       if(_successor != 0)
       {
           _successor->HandleHelp();
       }
    }


private:
    HelpHandler* _successor;
    Topic _topic;

};


class Widget : public HelpHandler
{

protected:

    Widget(Widget* w, Topic t = NO_HELP_TOPIC) : HelpHandler(w, t)
    {
        _parent = w;
    }

private:
    Widget* _parent;
};


class Button : public Widget
{
public:
    Button(Widget* d, Topic t = NO_HELP_TOPIC) : Widget(d,t)
    {

    }

    virtual void HandleHelp()
    {
        if(HasHelp())
        {
            cout << "button help" << endl;
        }
        else
        {
           HelpHandler::HandleHelp();
        }
    }

};


class Dialog : public Widget
{
public:
    Dialog(HelpHandler* d, Topic t = NO_HELP_TOPIC) : Widget(0)
    {
        SetHandler(d,t);
    }

    virtual void HandleHelp()
    {
        if(HasHelp())
        {
            cout << "Dialog help" << endl;
        }
        else
        {
           HelpHandler::HandleHelp();
        }
    }

};


class Application : public HelpHandler
{
public:
    Application(Topic t ) : HelpHandler(0,t)
    {

    }

    virtual void HandleHelp()
    {

    }

};


int main(int argc, char** argv)
{

  const Topic PRINT_TOPIC = 1;
  const Topic PAPER_ORIENTATION_TOPIC = 2;
  const Topic APPLICATION_TOPIC = 3;

  Application* application = new Application(APPLICATION_TOPIC);
  Dialog* dialog = new Dialog(application,PRINT_TOPIC);
  Button* button = new Button(dialog,NO_HELP_TOPIC);

  button->HandleHelp();





}






































































