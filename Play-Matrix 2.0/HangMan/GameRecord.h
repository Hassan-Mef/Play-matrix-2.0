#ifndef _GAMERECORD_H
#define _GAMERECORD_H
#include <cstdio>
#include <iostream>
#include <array>
#include <memory>
#include <stdexcept>
using namespace std;
#include <string>
#include <sstream>

class GameRecord {
private:
    int gamesPlayed;

public:
    GameRecord();

    void incrementGamesPlayed();
    int getGamesPlayed() const;
};

#endif