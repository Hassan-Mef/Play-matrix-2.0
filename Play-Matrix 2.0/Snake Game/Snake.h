#ifndef _SNAKE_H
#define _SNAKE_H
#include "GameObject.h"
#include <iostream>
#include <vector>

using namespace std;

enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };

class SnakeSegment {
public:
	Coordinate position;
	Direction dir;

	SnakeSegment(int x, int y, Direction d) : position({ x, y }), dir(d) {}
};

class Snake : public GameObject
{
private:
	
	 vector<SnakeSegment> body;
	 vector<Coordinate> bodyPositions;
	Direction dir;
	bool addSegment;
	
public:
	Snake();
	void draw() override;
	void update() override;
	
	void setDirection(Direction newDir);
	void eatFruit();
	
	Coordinate getHeadPosition() const;
	const  vector<Coordinate>& getSnakeBody() const;
	

	

};

#endif
