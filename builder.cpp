/*

Builder pattern:

1. it let you vary a product's internal representation, the builder object provide the director with an abstract interface for constructing the product
the interface let the builder hide the representation and internal structure of product, it also hide how the product get assembled, because the product
is constructed through an abstract interface. all you have to do to change product's internal representation is define a new kind of builder

2. it isolates code for construction and representation . the Builder pattern improves modularity by encapsulating the way a complex object is constructed
and repsented, client needn't know anything about the classes the define product's internal structure, such classes not appear in builder's interface
Each concreteBuilder contains all the code to create and assemble a particular kind of product.

3.it give you finer control over the construction process. unlike creational pattern that construct product in one shot, the builder pattern constructs
the product step by step under the director's control, only when the product is finished does the director retrieve it from builder, hence the builder interface
reflects the process of constructing  the product more than other creational patterns, this give you finer control over the construction process and consequently
the internal structure of the resulting product


*/

#include<iostream>
#include<map>

using namespace std;

enum Direction { North, South, East, West};


class MapSite
{
public:
    virtual void Enter() = 0;
};

class Room : public MapSite
{
public:
    Room(int roomNo)
    {
        _roomNumber = roomNo;
        for(int i = 0 ; i < 4 ; i++)
        {
            _sides[i] = NULL;
        }
    }

    MapSite* GetSide(Direction dir) const
    {
        return _sides[dir];
    }


    void SetSide(Direction dir, MapSite* site)
    {
         _sides[dir] = site;
    }

    virtual void Enter()
    {
        cout << "enter room" << endl;
    }

public:

    MapSite* _sides[4];
    int _roomNumber;

};

class Wall : public MapSite
{
public:
    Wall()
    {

    }

    virtual void Enter()
    {
        cout << "this is wall , can't enter" << endl;
    }

};

class Door : public MapSite
{
public:
    Door(Room* roomA = 0 , Room* roomB = 0)
    {
        _room1 = roomA;
        _room2 = roomB;
    }

    virtual void Enter()
    {
        cout << "enter the door" << endl;
    }

    Room* otherSideFrom(Room* aRoom)
    {
        if(aRoom == _room1)
        {
            return _room2;
        }
        else
        {
            return _room1;
        }
    }

private:

    Room* _room1;
    Room* _room2;

    bool _isOpen;
};

class Maze
{
public:

    Maze()
    {

    }

    void AddRoom(Room* room)
    {
        roomMap[room->_roomNumber] = room;
    }


    Room* RoomNo(int roomNo)
    {
        return roomMap[roomNo];
    }

    int RoomSize()
    {
        return roomMap.size();
    }

private:

    map<int, Room*> roomMap;

};
class MazeBuilder
{
public:
    virtual void BuildMaze() {}

    virtual void BuildRoom(int room) {}

    virtual void BuildDoor(int roomFrom , int roomTo) {}

    virtual Maze* GetMaze() { return NULL;}

protected:

    MazeBuilder() {}
};

class StandardMazeBuilder : public MazeBuilder
{
public:

    StandardMazeBuilder()
    {
        _currentMaze = 0;
    }

    virtual void BuildMaze()
    {
        _currentMaze = new Maze;
    }

    virtual Maze* GetMaze()
    {
        return _currentMaze;
    }

    virtual void BuildRoom(int room)
    {
       if(_currentMaze != NULL && (_currentMaze->RoomNo(room) == NULL))
       {
           Room* roomA = new Room(room);
           _currentMaze->AddRoom(roomA);
           roomA->SetSide(North,new Wall);
           roomA->SetSide(South,new Wall);
           roomA->SetSide(East,new Wall);
           roomA->SetSide(West,new Wall);
       }
    }

    virtual void BuildDoor(int n1, int n2)
    {
        Room* r1 = _currentMaze->RoomNo(n1);
        Room* r2 = _currentMaze->RoomNo(n2);

        Door* d = new Door(r1,r2);

        r1->SetSide(South,d);
        r2->SetSide(North,d);

    }

private:

    Maze* _currentMaze;
};

class CountingMazeBuilder : public MazeBuilder
{

public:

    CountingMazeBuilder()
    {
        _doors = 0;
        _rooms = 0;
    }

    virtual void BuildMaze()
    {

    }

    virtual void BuildRoom(int n)
    {
        _rooms++;
    }

    virtual void BuildDoor(int n1, int n2)
    {
        _doors++;
    }

    void GetCounts(int& rooms, int& doors)
    {
        rooms = _rooms;
        doors = _doors;
    }

private:

    int _doors;
    int _rooms;


};

class MazeGame
{
public:
    Maze* CreateMaze(MazeBuilder& builder)
    {
        builder.BuildMaze();

        builder.BuildRoom(1);
        builder.BuildRoom(2);

        builder.BuildDoor(1,2);

        return builder.GetMaze();

    }

};

int main(int argc, char** argv)
{
    Maze* maze;

    MazeGame game;

    StandardMazeBuilder builder;
    CountingMazeBuilder countBuilder;

    game.CreateMaze(builder);

    maze = builder.GetMaze();

    game.CreateMaze(countBuilder);

    cout << "room size in maze : " << maze->RoomSize() << endl;

    int roomNum, doorNum;
    countBuilder.GetCounts(roomNum,doorNum);

    cout << "room Num : " << roomNum << " door Num: "  << doorNum << endl;
}

