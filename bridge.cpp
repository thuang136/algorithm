#include<iostream>
using namespace std;

/*

RefObject处理引用计数

IntrusivePtr<T> 处理T相关拷贝构造或者析构时处理T的引用计数

IntrusivePtr<T> 作为handle的handle的真实的对象，防止对应重复



*/

class RefObject
{
public:

    void Reference();

    void Unreference();

    int ReferenceCount();

protected:

    RefObject();

    virtual ~RefObject();

    RefObject(const RefObject& rhs);

    RefObject& operator=( const RefObject& rhs);

private:

    int mCount;
};

RefObject::RefObject() : mCount(0)
{

}

RefObject::RefObject(const RefObject& refObj) : mCount(0)
{


}

RefObject::~RefObject()
{
    cout << "destructor" << endl;
}

RefObject& RefObject::operator=(const RefObject& refObject)
{
    return *this;
}

void RefObject::Reference()
{
    ++mCount;
}

void RefObject::Unreference()
{
    if(--mCount == 0)
    {
        delete this;
    }
}

int RefObject::ReferenceCount()
{
    return mCount;
}


template<typename T>
class IntrusivePtr
{
public:

    IntrusivePtr() : mPtr(0){}


    IntrusivePtr(T* p) : mPtr(p)
    {
        cout << "IntrusivePtr constructor" << endl;
        if(mPtr)
        {
            mPtr->Reference();
        }
    }


    IntrusivePtr(IntrusivePtr const& rhs) : mPtr(rhs.mPtr)
    {
        cout << "IntrusivePtr copy constructor" << endl;
        if(mPtr)
        {
            cout << "reference count in copy constructor" << mPtr->ReferenceCount() << endl;
            mPtr->Reference();

        }
    }

    ~IntrusivePtr()
    {
        if(mPtr)
        {
            cout << "reference count in destructor" << mPtr->ReferenceCount() << endl;
            mPtr->Unreference();

        }
    }

    T* Get()
    {
        return mPtr;
    }

    T* operator->()
    {
        return mPtr;
    }

    T& operator*()
    {
        return *mPtr;
    }



private:


T* mPtr;


};


class Handle
{
public:
    Handle(RefObject* obj);

    Handle(const Handle& handle);

    ~Handle()
    {
        cout << "handle destructor" << endl;
    }

private:
    IntrusivePtr<RefObject> mObjectHandle;
};

Handle::Handle(RefObject* handle) : mObjectHandle(handle)
{
    cout <<"handle constructor" << endl;
}



Handle::Handle(const Handle& handle)
  : mObjectHandle(handle.mObjectHandle)
{
    cout <<"handle copy constructor" << endl;
}



class MyObject : public RefObject
{

};

int main(int argc, char** argv)
{
    MyObject obj;

    Handle handle1(&obj);

    Handle handle2 = handle1;

    cout << "ref object reference count: " << obj.ReferenceCount() << endl;
}





