#ifndef _FRUIT_H
#define _FRUIT_H


#include <iostream>
#include <string>
#include "GameObject.h"

using namespace std;


class Fruit : public GameObject
{
private:
    Coordinate position;

public:
    Fruit();
    Fruit(int x, int y);
    void draw() override;
    Coordinate getPosition() const;
    void update() override;
};

#endif

