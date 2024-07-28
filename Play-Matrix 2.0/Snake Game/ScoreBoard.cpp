#include "ScoreBoard.h"
#include <fstream>

ScoreBoard::ScoreBoard() {
    score = 0;
    highScore = 0;
    loadFromFile();
}

void ScoreBoard::setScore(int sc) {
    score = sc;
    if (score > highScore) {
        highScore = score;
        savetoFile();
    }
}

void ScoreBoard::setHighScore(int Hsc) {
    highScore = Hsc;
}

int ScoreBoard::getScore() {
    return score;
}

int ScoreBoard::getHighScore() {
    return highScore;
}

void ScoreBoard::savetoFile() {
    json j;
    j["highScore"] = highScore;
     ofstream file("highScore.json");
    file << setw(4) <<j;
    file.close();
}

void ScoreBoard::loadFromFile() {
     ifstream file("highScore.json");
    if (file.is_open()) {
        json j;
        file >> j;
        highScore = j["highScore"];
        file.close();
    }
}
