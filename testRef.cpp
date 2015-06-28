#include "testRef.h"

Ref :: Ref()
  :_referenceCount(1)
{

}

Ref :: ~Ref()
{

}

void Ref::retain()
{
    ++_referenceCount;
}

void Ref::release()
{
    -- _referenceCount;
    if( _referenceCount == 0)
    {
        delete this;
    }
}

Ref* Ref::autorelease()
{
    PoolManager::getInstance()->getCurrentPool()->addObject(this);
    return this;
}

unsigned int Ref::getReferenceCount() const
{
    return _referenceCount;
}


AutoreleasePool::AutoreleasePool()
    :_isClearing(false)
{

  _managedObjectArray.reserve(150);

  PoolManager::getInstance()->push(this);

}

AutoreleasePool:: AutoreleasePool(const string& name)
    :_isClearing(false),
    _name(name)
{
    _managedObjectArray.reserve(150);

    PoolManager::getInstance()->push(this);

}

void AutoreleasePool::clear()
{
    for(int i = 0 ; i < _managedObjectArray.size(); i++)
    {
       _managedObjectArray[i]->release();
    }

    _managedObjectArray.clear();
}

int AutoreleasePool::size()
{
    return _managedObjectArray.size();
}

AutoreleasePool::~AutoreleasePool()
{
    PoolManager::getInstance()->pop();
}

void AutoreleasePool::addObject(Ref * object)
{
    _managedObjectArray.push_back(object);
}

bool AutoreleasePool::contains(Ref* object) const
{
    for(int i = 0 ; i < _managedObjectArray.size(); i++)
    {
        if(_managedObjectArray[i] == object)
        {
            return true;
        }
    }

    return false;
}

PoolManager* PoolManager::s_singleInstance = NULL;

PoolManager* PoolManager::getInstance()
{
    if(s_singleInstance == NULL)
    {
        s_singleInstance = new PoolManager();
        new AutoreleasePool("cocos2d autorelease pool");
    }

    return s_singleInstance;
}

void PoolManager::destroyInstance()
{
    delete s_singleInstance;
    s_singleInstance = NULL;
}

PoolManager::PoolManager()
{
    _releasePoolStack.reserve(10);
}

PoolManager::~PoolManager()
{
    while( !_releasePoolStack.empty())
    {
        AutoreleasePool* pool = _releasePoolStack.back();
        delete pool;
        _releasePoolStack.pop_back();
    }
}

AutoreleasePool* PoolManager::getCurrentPool() const
{
    return _releasePoolStack.back();
}

bool PoolManager::isObjectInPools(Ref * obj) const
{
    for(int i = 0 ; i < _releasePoolStack.size(); i++)
    {
        AutoreleasePool* pool = _releasePoolStack[i];
        if(pool->contains(obj))
        {
            return true;
        }
    }

    return false;
}

void PoolManager::push(AutoreleasePool* pool)
{
    _releasePoolStack.push_back(pool);
}

void PoolManager::pop()
{
    _releasePoolStack.pop_back();
}

class TestObject : public Ref
{
    public:

        TestObject() : _name("") {}

        TestObject(string name) : _name(name)
        {
            cout << "TestObject:" << name << "is created" << endl;
        }

        ~TestObject()
        {
            if(_name.size() > 0)
            {
                cout << "TestObject: " << _name << "is destroyed" << endl;
            }
        }

    private:
        string _name;

};


int main(int argc, char** argv)
{
    TestObject *obj = new TestObject("testObject");
    obj->autorelease();

    cout << "reference count1:" << obj->getReferenceCount() << endl;

    obj->retain();
    obj->autorelease();

    cout << "reference count2:" << obj->getReferenceCount() << endl;


    if(PoolManager::getInstance()->getCurrentPool()->contains(obj))
    {
       cout << "contain the object" << endl;
    }

    cout << "AutoReleasePool size :" << PoolManager::getInstance()->getCurrentPool()->size() << endl;

    {
        AutoreleasePool pool1;

        // can invoke autorelease more than once
        obj->retain();
        obj->autorelease();
        cout << "reference count3:" << obj->getReferenceCount() << endl;
        obj->retain();
        obj->autorelease();
        cout << "reference count4:" << obj->getReferenceCount() << endl;

        // retain, release can work together with autorelease pool
        obj->retain();
        cout << "reference count5:" << obj->getReferenceCount() << endl;
        obj->release();
        cout << "reference count6:" << obj->getReferenceCount() << endl;
    }


}

