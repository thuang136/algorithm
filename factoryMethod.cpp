/*

factory method eliminate the need to bind application-specific classes into your code, The code only deal with the product interface;
therefore it can work with any user-defined ConcreteProduct classes

A potential disadvantage of factory method is that client might have to subclass the creator class just to create a particular ConcreteProduct object.
Subclassing is fine when the client has to subclass the creator class anyway,but otherwise the client now must deal with another point of evolution


here are two additional consequences of the factory method pattern

1.Provide hooks for subclasses. creating object inside a class with a factory method is always more flexibe than creating an object directly. Factory method give subclasses a hook
for providing an extended version of an object

in the document example, the document class could define a factory method called createFileDialog that create a default file dialog object for opening an existing document.
A document subclass can define an application-specific file dialog by overriding this factory method.in this case the factory method is not abstract
but provides a reasonable default implementation

2.Connect parallel class hierarchies.in the example we've considered so far,
the factory method is only called by creator, client can find factory method userful, especially in the case of
parallel class hierarchies

Parallel class hierarchies result when a class delegates some of its responsibilityto a separator class.
consider graphical figures that can be manipulated interactively; that is , they can
be stretched, moved , or rotated using the mouse, implementing such interaction isn't always easy.
it often require storing and updating information that records the state of manipulation at
a given time.
this state is needed only during manipulation;
therefore it needn't be kept in the figure object.
Moreever, different figures behave differently when the user manipulates them











*/

#include<iostream>
using namespace std;

class Product
{
public:
  virtual void print()
  {
      cout << "product" << endl;
  }
};

class Creator
{
public:
    virtual Product* CreateProduct() = 0;
};

template< class TheProduct>
class StandardCreator : public Creator
{
public:
    virtual Product* CreateProduct();

};

template< class TheProduct>
Product*  StandardCreator<TheProduct>::CreateProduct()
{
    return new TheProduct;
}

class MyProduct : public Product
{
public:
  virtual void print()
  {
      cout << "my product" << endl;
  }
};

int main(int argc, char** argv)
{
    StandardCreator<MyProduct> myCreator;
    Product* prod = myCreator.CreateProduct();
    prod->print();
}