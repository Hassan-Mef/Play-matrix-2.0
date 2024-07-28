#include "Snake.h"
#include <raylib.h>
#include <iostream>

using namespace std;

#include "Snake.h"
#include <iostream>

using namespace std;

Snake::Snake() : dir(STOP), addSegment(false) {
    body.push_back(SnakeSegment(800 / 2, 600 / 2, STOP));
    bodyPositions.push_back(body.back().position);
}

void Snake::draw() {
    for (int i = 0; i < body.size(); ++i) {
        if (i == 0) {
            DrawRectangle(body[i].position.x, body[i].position.y, 20, 20, RED);
        }
        else {
            DrawRectangle(body[i].position.x, body[i].position.y, 20, 20, YELLOW);
        }
    }
}


void Snake::update() {
    if (dir != STOP) {
        // Move the body segments
        for (int i = body.size() - 1; i > 0; --i) {
            body[i].dir = body[i - 1].dir;
            body[i].position = body[i - 1].position; // Update each segment's position to the previous segment's position
        }

        // Update the head's position based on the direction
        switch (dir) {
        case LEFT:
            body[0].position.x -= 5;
            break;
        case RIGHT:
            body[0].position.x += 5;
            break;
        case UP:
            body[0].position.y -= 5;
            break;
        case DOWN:
            body[0].position.y += 5;
            break;
        default:
            break;
        }

        // Wrap around the screen if the snake hits the wall
        if (body[0].position.x < 0)
            body[0].position.x = GetScreenWidth() - 20;
        else if (body[0].position.x >= GetScreenWidth())
            body[0].position.x = 0;

        if (body[0].position.y < 0)
            body[0].position.y = GetScreenHeight() - 20;
        else if (body[0].position.y >= GetScreenHeight())
            body[0].position.y = 0;

        // If the snake eats a fruit, add a new segment
        if (addSegment) {
            // Get the position and direction of the last segment
            Coordinate tailPosition = body.back().position;
            Direction tailDirection = body.back().dir;

            // Calculate the position of the new segment based on the direction of the last segment
            switch (tailDirection) {
            case LEFT:
                tailPosition.x += 20;
                break;
            case RIGHT:
                tailPosition.x -= 20;
                break;
            case UP:
                tailPosition.y += 20;
                break;
            case DOWN:
                tailPosition.y -= 20;
                break;
            default:
                break;
            }

            // Add the new segment at the calculated position
            body.push_back(SnakeSegment(tailPosition.x, tailPosition.y, STOP));
            addSegment = false;
        }

        // Update the bodyPositions vector
        bodyPositions.clear();
        for (auto& segment : body) {
            bodyPositions.push_back(segment.position);
        }
    }
}



void Snake::setDirection(Direction newDir) {
    if (dir == STOP || ((dir == LEFT && newDir != RIGHT) || (dir == RIGHT && newDir != LEFT) ||
        (dir == UP && newDir != DOWN) || (dir == DOWN && newDir != UP))) {
        dir = newDir;
    }
}

void Snake::eatFruit() {
    //score++;
    addSegment = true;
}

Coordinate Snake::getHeadPosition() const {
    return body[0].position;
}

const  vector<Coordinate>& Snake::getSnakeBody() const {
    return bodyPositions;
}
