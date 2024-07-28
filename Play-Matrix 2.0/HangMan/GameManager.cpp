#include <cstdio>
#include <iostream>
#include <array>
#include <memory>
#include <stdexcept>
using namespace std;
#include <string>
#include <sstream>
#include "GameManager.h"
#include "AsciiHangmanDrawing.h"
#include "WordBank.h"

GameManager::GameManager() : drawing(new AsciiHangmanDrawing()), tries(7), score(0), level(1) {}

void GameManager::startGame() {
    WordBank wordBank;
    month = wordBank.getRandomWord();
    hiddenMonth = string(month.length(), '-');
}

int GameManager::checkGuess(char guess) {
    int matches = 0;
    int len = month.length();

    for (int i = 0; i < len; i++) {
        if (guess == hiddenMonth[i]) {
            return 0;
        }
        if (guess == month[i]) {
            hiddenMonth[i] = guess;
            matches++;
        }
    }

    return matches;
}

void GameManager::play(char guess) {
    if (checkGuess(guess) == 0) {
        tries--;
        if (tries == 0) {
            cout << "Game over! You're hanged!" << endl;
            return;
        }
    } else {
        score += 10;
        cout << "Correct guess! Score: " << score << endl;
        if (hiddenMonth == month) {
            level++;
            cout << "Congratulations! You've completed level " << level << endl;
            startGame();
        }
    }
}

bool GameManager::isGameOver() {
    return hiddenMonth == month || tries == 0;
}

string GameManager::getMonth() const {
    return month;
}

int GameManager::getTries() const {
    return tries;
}

int GameManager::getScore() const {
    return score;
}

int GameManager::getLevel() const {
    return level;
}


    void GameManager::display() {
        system("cls");
        drawing->draw(7 - tries);

        // Check if the game is over
        if (isGameOver()) {
            cout << "Game over! You're hanged!" << endl;
        }
        else {
            cout << "\t\t\t\tLife: " << tries << endl;
            cout << hiddenMonth << endl;
        }
    }

GameManager::~GameManager() {
    delete drawing;
}