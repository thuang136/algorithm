#include<iostream>
#include<string>
#include<vector>

using namespace std;


class Ref
{
public:

    /*
        retains the ownership
        this increase the Ref's reference count
    */

    void retain();

    /*
        releases the ownership immediately
        this decrements the Ref's reference count.

        if the reference count reaches 0 after the descrement, this Ref is destructed
    */
    void release();

    /*
        releases the ownership sometime soon automatically
        this descrements the Ref's reference count at the end of current autorelease pool block.

        if the reference count reaches 0 after the descrement, this Ref is destructed
    */

    Ref* autorelease();


    unsigned int getReferenceCount() const;

protected:

    /*
         Constructor
         The Ref's reference count is 1 after construction
    */

    Ref();

public:

    virtual ~Ref();

protected:

     unsigned int _referenceCount;

     friend class AutoreleasePool;
};


class AutoreleasePool
{
public:

        /*
            don't create an auto release pool in heap, create it in stack
        */

    AutoreleasePool();


        AutoreleasePool(const string& name);


        ~AutoreleasePool();


        /*
            add a given object to this pool.

            the same object may be added serveral times to the same pool; when

            the pool is destructed, the object's Ref::release() method will be called for each time it was added

        */
    void addObject(Ref *object);

    /*
        clear the autorelease pool.

        Ref::release() will be called for each time the managed object is added to the pool.
    */
    void clear();

        int size();

        /*
            checks whether the pool contains the specified object
        */
        bool contains(Ref* object) const;

private:

    vector<Ref*> _managedObjectArray;

        /*
        The flag for checking whether the pool is doing 'clear' operation.
        */
        bool _isClearing;
        string _name;

};


class PoolManager
{
public:

    static PoolManager* getInstance();

    static void destroyInstance();

    AutoreleasePool* getCurrentPool() const;

    bool isObjectInPools(Ref* obj) const;

  friend class AutoreleasePool;  //AutoreleasePool 能访问所有PoolManager的所有方法

private:

    PoolManager();
    ~PoolManager();

    void push(AutoreleasePool * pool);
    void pop();

    static PoolManager* s_singleInstance;

    vector<AutoreleasePool*> _releasePoolStack;

};


