

class CallbackBase
{
public:
    CallbackBase();

    ~CallbackBase();


protected:

    typedef void(*Function)(void);

    typedef void(CallbackBase::*MemberFunction)(void);

    typedef void(*Dispatcher)(CallbackBase& base);


    CallbackBase(Function function);

    CallbackBase(void* object, MemberFunction function, Dispatcher dispatcher);


};

/*
    abstract interface used by a signal to inform a slot it is disconnecting.

    this will happen if the object owning the signal is destroyed

*/
class SignalObserver
{
public:

     SignalObserver();

      virtual ~SignalObserver();

     /*
        this method is called when the signal is disconnecting

        slotObserver : the signal that has disconnected
        callback : the callback attached to the signal disconnected

     */
     virtual void SignalDisconnected(SlotObserver* slotObserver,CallbackBase* callback) = 0;

};


class SignalConnection
{
public:

    SignalConnection(CallbackBase* callback);


    SignalConnection(SignalObserver* signalObserver,CallbackBase* callback);


    ~SignalConnection();

    /*
         disconnect the signal from the slot
    */
    void Disconnect(SlotObserver* slotObserver);

    CallbackBase* GetCallback();

private:

    SignalConnection(const SignalConnection& );

    SignalConnection& operator= (const SignalConnection& );

private:

    SignalObserver* mSignalObserver;  // a pointer to the signal observer(not owned)
    CallbackBase* mCallback;          // the callback, has ownership

};

SignalConnection::SignalConnection(CallbackBase* callback)
    : mSignalObserver(NULL),
      mCallback(callback)
{


}

SignalConnection::SignalConnection(SignalObserver* signalObserver,CallbackBase* callback)
     : mSignalObserver(signalObserver),
       mCallback(callback)
{

}

SignalConnection::~SignalConnection()
{
    delete mCallback;
}


class SlotObserver
{
public:

    SlotObserver();

    virtual ~SlotObserver();


    virtual void SlotDisconnected();

};

int main(int argc ,char** argv)
{


}






























