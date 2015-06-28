#include<iostream>
using namespace std;


/*

the abstract factory:

1. it isolates concrete classes, The abstract factory pattern helps you control the classes of objects that an application creates.Because
a factory encapsulates the responsiblity and the process of creating product objects,it isolates clients from implementation classes, client manipulate
instance through their abstract interface. Product classes names are isolated in the implementation of the concreate factory; they do not appear in client code


2. it makes exchanging product families easy. the classes of a concreate factory appears only once in an application, that is , where it's instantiated
this makes it easy to change the concrete factory an application uses, it can use different product configuration simply by changing the concrete factory.
because an abstract factory creates a complete family of products, the whole product family changes at once. in our user interface example, we can switch
from Motif widgets to PM widgets simply by switching the corresponding factory objects and recreating the interface

3. it promotes consistency among products. when product objects in a family are designed to work together, it's important that an application use objects from
only one family at a time. abstractFamily makes this easy to enforce

4. supporting new kinds of products is difficult. extending abstract factories to produce new kinds of product isn't easy. That' s because the abstractFactory interface
fixes the set of products that can be created. supporting new kind of products requires extending the factory interface, which involves changing the abstractFactory class
and all of its subclass.

*/


class Window
{
public:
    virtual void print() = 0;

};

class PMWindow : public Window
{

public:

    virtual void print()
    {
        cout << "PM window" << endl;
    }
};

class MotifWindow : public Window
{

public:

    virtual void print()
    {
        cout << "Motif Window" << endl;
    }
};


class ScrollBar
{
public:
    virtual void print() = 0;
};

class PMScrollBar : public ScrollBar
{
public:
    virtual void print()
    {
        cout << "PM ScrollBar" << endl;
    }
};

class MotifScrollBar : public ScrollBar
{
public:
    virtual void print()
    {
        cout << "Motif ScrollBar" << endl;
    }
};



class WidgetFactory
{
public:
   virtual  Window* createWindow() = 0;

   virtual  ScrollBar* createScrollBar() = 0;

};

class PMWidgetFactory : public WidgetFactory
{
public:
   virtual Window* createWindow()
   {
       return new PMWindow();
   }

   virtual ScrollBar* createScrollBar()
   {
       return new PMScrollBar();
   }
};


class MotifWidgetFactory : public WidgetFactory
{
public:
    virtual Window* createWindow()
    {
        return new MotifWindow();
    }

    virtual ScrollBar* createScrollBar()
    {
        return new MotifScrollBar();
    }
};



int main()
{
    WidgetFactory* widgetFactory = new PMWidgetFactory();

    Window* window = widgetFactory->createWindow();
    ScrollBar* scrollBar = widgetFactory->createScrollBar();

    window->print();
    scrollBar->print();

    return 0;

}