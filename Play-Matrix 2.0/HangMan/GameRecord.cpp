#include <cstdio>
#include <iostream>
#include <array>
#include <memory>
#include <stdexcept>
using namespace std;
#include <string>
#include <sstream>
#include "GameRecord.h"

GameRecord::GameRecord() : gamesPlayed(0) {}

void GameRecord::incrementGamesPlayed() {
    gamesPlayed++;
}

int GameRecord::getGamesPlayed() const {
    return gamesPlayed;
}