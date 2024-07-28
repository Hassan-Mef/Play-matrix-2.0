#ifndef _GAMEOBJECT_H
#define _GAMEOBJECT_H

struct Coordinate {
    int x;
    int y;
};

class GameObject
{
protected:
    Coordinate positions;

public:
    virtual void draw() = 0;
    virtual void update() = 0;
};

#endif 




