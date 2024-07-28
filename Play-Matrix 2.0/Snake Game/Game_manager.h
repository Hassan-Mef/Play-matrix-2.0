#ifndef _GAME_S_MANAGER_H
#define _GAME_S_MANAGER_H

#include <iostream>
#include "Fruit.h"
#include "Snake.h"
#include "ScoreBoard.h"

class Game_manager
{
private:
    Snake snake;
    Fruit fruit;
    bool gameOver;
    int score;
	ScoreBoard* scoreBoard = new ScoreBoard();


public:
    Game_manager();
    void draw();
    void update();
    void handleInput();
	bool getGameOver();

	int getCurrentScore();




    

};

#endif

