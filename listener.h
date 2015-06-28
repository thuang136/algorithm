#ifndef _EVENT_LISTENER_H
#define _EVENT_LISTENER_H


enum EventType
{
    Key,
        Mouse
};

class EventNotifier;

class EventListener
{
    public:
            virtual void OnEvent(const EventType type, EventNotifier* notifer) = 0;
};

#endif



