#include "Fruit.h"
#include<raylib.h>


Fruit::Fruit()
{
}

Fruit::Fruit(int x, int y) : position({ x, y }) {}

void Fruit::draw() {
    // Draw fruit
    DrawCircle(position.x, position.y, 10, RED);
}

Coordinate Fruit::getPosition() const {
    return position;
}

void Fruit::update() {
    // Respawn fruit at random position
    position.x = GetRandomValue(10, GetScreenWidth() - 10);
    position.y = GetRandomValue(10, GetScreenHeight() - 10);

    cout << " Debugging value " << endl;
	cout << position.x << endl;
	cout << position.y << endl;
}

