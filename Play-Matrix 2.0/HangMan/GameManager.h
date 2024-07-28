#ifndef _GAMEMANAGER_H
#define _GAMEMANAGER_H
#include <cstdio>
#include <iostream>
#include <array>
#include <memory>
#include <stdexcept>
using namespace std;
#include <string>
#include <sstream>

#include "HangmanDrawing.h"

class GameManager {
private:
    string month;
    string hiddenMonth;
    int tries;
    int score;
    int level;
    HangmanDrawing* drawing;

    int checkGuess(char guess);

public:

    GameManager();
    void startGame();
    void play(char guess);
    bool isGameOver();
    string getMonth() const;
    int getTries() const;
    int getScore() const;
    int getLevel() const;  
    void display();
    ~GameManager();
};
#endif