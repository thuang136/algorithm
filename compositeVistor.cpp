
/*

consequence:

define class hierarchies consisting of primitive objects and composite objects

make the client simple

make it easy to add new kinds of components


implementation:

Explicit parent reference,Maintaining references from child components to their parent can simplify the traversal and managment of a composite structure.
The parent reference simplifies moving up the structure and deleting a component.Parent references also help support the chain of responsibility pattern

sharing components

maximizing the component interface

declaring the child management operation

child ordering






*/

#include<iostream>
#include<string>
#include<vector>

using namespace std;

template<class Item>
class Iterator
{
public:

    virtual void First() = 0;

    virtual void Next() = 0;

    virtual bool IsDone() = 0;

    virtual Item  CurrentItem() const = 0;

protected:

    Iterator() {}

};

template<class T>
class NullIterator : public Iterator<T>
{
public:


    virtual void First()
    {

    }

    virtual void Next()
    {

    }

    virtual bool IsDone()
    {
        return true;
    }

    virtual T CurrentItem() const
    {
        return NULL;
    }
};

template<class T>
class VecIterator : public Iterator<T>
{
public:

    VecIterator(const vector<T>* aVec) : _vec(aVec)
    {
        _current = 0;
    }
    virtual void First()
    {
        _current = 0;
    }

    virtual void Next()
    {
        _current++;
    }

    virtual bool IsDone()
    {
        return _current >= _vec->size();
    }

    virtual T CurrentItem() const
    {
        return _vec->at(_current);
    }

private:

    const vector<T>* _vec;
    long _current;

};

class Component
{
public:
    Component(const char* name)
    {
        _name = name;
    }
    virtual ~Component()
    {

    }

    virtual const string GetName()
    {
        return _name;
    }

    virtual void Add(Component* component)
    {

    }

    virtual void Remove(Component* component)
    {

    }

    virtual Iterator<Component*>* CreateIterator()
    {
        return new NullIterator<Component*>();
    }

protected:

    string _name;

};


class Composite : public Component
{
public:
    Composite(const char* name) : Component(name)
    {

    }

    virtual ~Composite()
    {
      // Îö¹¹
    }

    void Add(Component* component)
    {
        components.push_back(component);
    }

    void Remove(Component* component)
    {
        vector<Component*>::iterator it = components.begin();

        while(it != components.end())
        {
            if(*it == component)
            {
                it = components.erase(it);
                break;
            }
            else
            {
                ++it;
            }
        }
    }

    Iterator<Component*>* CreateIterator()
    {
        return  new VecIterator<Component*>(&components);
    }


    virtual const string GetName()
    {
        string _nameList = _name;

        Iterator<Component*>* it = CreateIterator();

        for(it->First(); !it->IsDone(); it->Next())
        {
            _nameList += it->CurrentItem()->GetName();
        }

        return _nameList;
    }

private:

    vector<Component*> components;
};

int main(int argc, char** argv)
{
  Composite a("A");

  Composite b("B");

  Component c("C");
  Component d("D");

  b.Add(&c);
  b.Add(&d);

  a.Add(&b);

  Component e("E");
  a.Add(&e);

  cout << a.GetName() << endl;

}

