/*


more flexibility than static inheritance, with decorators, responsibilities can be added and removed at run-time simply by attaching and detaching them

1.decorator offers a pay as you go approach to adding responsibilities. Instead of trying to support all foreseeable features in a complex,customizable class,you can define a

2.simple class and add functionality incrementally with decorator objects

3. a decorator and its component aren't identical

4. lots of little objects


implementation:

interface conformance

omitting the abstract decorator class.there is no need to define an abstract decorator class when you only need to add one responsibility

keeping component classes lightweight. to ensure a conforming interface, components and decorators must decend from a common component class
it is important to keep this common class lightweight. it should focus on defining an interface, not on storing data.
the definition of the data representation should be deferred to subclasses
otherwise the complexity of the component class might make the decorator too heavyweight to use in quantity

changing the skin of an object versus changing its guts




*/


#include<iostream>
#include<string>
#include<sstream>
using namespace std;

const int MAXNUM = 10;

class Stream
{

public:

    virtual void PutInt(int num) = 0;

    virtual void PutString(const char* str) = 0;

    virtual void  HandleBufferFull() = 0;

};

class MemoryStream : public Stream
{
public:

    virtual void PutInt(int num)
    {
        ostringstream oss;
        oss << num;
        mBuf.append(oss.str());

    }

    virtual void PutString(const char* str)
    {
        mBuf.append(str);
    }

    virtual void HandleBufferFull()
    {
        mResultBuf += mBuf.substr(0,MAXNUM);
        mBuf.erase(0,MAXNUM);

        cout << mResultBuf << endl;
        cout << mBuf << endl;
    }

protected:

    void BufferFull()
    {
        if(mBuf.length() > MAXNUM)
        {
            this->HandleBufferFull();
        }
    }


private:

    string mBuf;
    string mResultBuf;

};

class StreamDecorator : public Stream
{
public:

    StreamDecorator(Stream* stream)
    {
        mStream = stream;
    }

    virtual void PutInt(int num)
    {
        mStream->PutInt(num);
    }

    virtual void PutString(const char* str)
    {
        mStream->PutString(str);
    }

    virtual void HandleBufferFull()
    {
        cout << "decorator start" << endl;

        mStream->HandleBufferFull();

        cout << "decorator end" << endl;
    }

private:

    Stream* mStream;

};


int main(int argc, char** argv)
{
    MemoryStream mStream;
    StreamDecorator streamDeco(&mStream);
    streamDeco.PutInt(22);
    streamDeco.PutString("dfadsffdsfs");
    streamDeco.HandleBufferFull();
}

















































