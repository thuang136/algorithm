
/*

Consider a TreeDisplay widget that can display tree structures graphically. if this were a special-purpose widget for use in just one application, then we might require
the objects that it displays to have a specific interface; that is , all must descend from a Tree abstract class.But if we want to make TreeDisplay more reuseable, then requirement
would be unreasonable. Applications will define their own classes for tree structures, they shouldn't be forced to use our Tree abstract class. Different tree structures will have
different interfaces.In a directory hierarchy, for example,children might be accessed with a GetSubdirectories operation, whereas in an inheritance hierarchy,the corresponding operation
might be called GetSubclasses. a reusable TreeDispaly must be able to display both kinds of hierarchies even if they use different interfaces



two way adaptor

use abstract operation

use delegate object  to implement pluggable adapters




*/

#include<iostream>
using namespace std;

struct Point
{
    float x;
    float y;
};

class Shape
{
public:
    Shape()
    {

    }

    virtual void BoundingBox(Point& bottomLeft,Point& topRight) = 0;

};

class TextView
{
public:

    TextView()
    {

    }

    void GetOrigin(float& x, float& y) const
    {
       x = 1.0f;
       y = 2.0f;
    }

    void GetExtent(float& width, float& height) const
    {
       width = 10.0f;
       height = 20.0f;
    }

};


/*
class TextShape : public Shape, private TextView
{
public:
    TextShape()
    {

    }

    virtual void BoundingBox(Point& bottomLeft, Point& topRight)
    {
       float bottom, left, width,height;

       GetOrigin(bottom,left);

       GetExtent(width,height);

       bottomLeft.x = left;
       bottomLeft.y = bottom;

       topRight.x = left + width;
       topRight.y = bottom + height;

    }


};*/

class TextShape : public Shape
{
public:
    TextShape(TextView* textView)
    {
        _text = textView;
    }

    virtual void BoundingBox(Point& bottomLeft, Point& topRight)
    {
        float bottom, left, width,height;

        _text->GetOrigin(bottom,left);

        _text->GetExtent(width,height);

        bottomLeft.x = left;
        bottomLeft.y = bottom;

        topRight.x = left + width;
        topRight.y = bottom + height;

    }

private:
    TextView* _text;

};


int main(int argc ,char** argv)
{

    TextView textView;

    Shape* textShape = new TextShape(&textView);

    /*
    Shape* textShape = new TextShape();
    */

    Point bottomLeft, topRight;

    textShape->BoundingBox(bottomLeft,topRight);

    cout << "bottomleft " << bottomLeft.x << " " << bottomLeft.y << endl;
    cout << "topRight " << topRight.x << " " << topRight.y << endl;



}


