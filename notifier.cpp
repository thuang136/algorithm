#ifndef EVENT_NOTIFIER_H
#define EVENT_NOTIFIER_H

#include "listener.h"
#include <iostream>
#include <list>
using namespace std;

class EventNotifier
{

public:

    EventNotifier() {};

    virtual ~EventNotifier() {};


public:
    typedef std::pair<EventListener*,EventType> Pair_EventListener;

    typedef std::list<Pair_EventListener> Map_EventListener;

    Map_EventListener m_mapListeners;


public:

    virtual void AddListener(EventListener* listener, const EventType type)
    {
        Pair_EventListener pair(listener,type);
        m_mapListeners.push_back(pair);
    }

    virtual void RemoveListener(EventListener* listener)
    {
        Map_EventListener::iterator it = m_mapListeners.begin();
        for(; it != m_mapListeners.end() ; ++it)
        {
            if(it->first == listener)
            {
                m_mapListeners.erase(it);
                break;
            }
        }
    }

    virtual void notify(EventType type)
    {
        if(!m_mapListeners.empty())
        {
            Map_EventListener::iterator it = m_mapListeners.begin();
            for(; it != m_mapListeners.end(); ++it)
            {
                if(it->second == type)
                {
                    it->first->OnEvent(it->second,this);
                }
            }
        }
    }

};

class MyNotifier : public EventNotifier
{
public:
    void notifyKey()
    {
        notify(Key);
    }

};

class MyListener : public EventListener
{
public:

    MyListener()
    {
        m_notifier = new MyNotifier;
        m_notifier->AddListener(this,Key);
        m_notifier->AddListener(this,Mouse);
    }

    void OnEvent(const EventType type, EventNotifier* notifer)
    {
          if(type == Key)
          {
              cout << "key event" << endl;
          }
          else if( type == Mouse)
          {
              cout << "Mouse event" << endl;
          }
    }

    void doSomething()
    {
        m_notifier->notifyKey();
    }

private:
    MyNotifier* m_notifier;
};


int main(int argc ,char** argv)
{
    MyListener listener;
    listener.doSomething();
}




#endif

