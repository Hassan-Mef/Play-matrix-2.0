#include "Game_manager.h"
#include "raylib.h"

Game_manager::Game_manager()
{
	gameOver = false;
	score = 0;
   // scoreBoard->savetoFile();
	
}

void Game_manager::draw()
{
	snake.draw();
	fruit.draw();
}


void Game_manager::update()
{
    if (!gameOver)
    {
        snake.update();

        // Handle collisions with fruit
        if (CheckCollisionCircles(
            { (float)fruit.getPosition().x, (float)fruit.getPosition().y }, 10.0f,
            { snake.getHeadPosition().x + 10.0f, snake.getHeadPosition().y + 10.0f }, 10.0f)) {
            snake.eatFruit();
            score += 10;
            fruit.update(); // Update fruit position after collision
        }

        // fruit.update(); // Update fruit position outside collision check

        

      // Handle collisions with itself
        for (int i = 4; i < snake.getSnakeBody().size(); i++) {
            if (snake.getHeadPosition().x == snake.getSnakeBody()[i].x &&
                snake.getHeadPosition().y == snake.getSnakeBody()[i].y) {
                gameOver = true;
                break;
            }
        }

        scoreBoard->setScore(score);

    }
}


void Game_manager::handleInput()
{
    if (!gameOver)
    {
        if (IsKeyDown(KEY_UP)) {
            snake.setDirection(UP);
            cout << "UP key pressed" << endl;
        }
        else if (IsKeyDown(KEY_DOWN)) {
            snake.setDirection(DOWN);
            cout << "DOWN key pressed" << endl;
        }
        else if (IsKeyDown(KEY_LEFT)) {
            snake.setDirection(LEFT);
            cout << "LEFT key pressed" << endl;
        }
        else if (IsKeyDown(KEY_RIGHT)) {
            snake.setDirection(RIGHT);
            cout << "RIGHT key pressed" << endl;
        }
    }
}


bool Game_manager::getGameOver()
{
	return gameOver;
}

int Game_manager::getCurrentScore()
{
    return score;
}


