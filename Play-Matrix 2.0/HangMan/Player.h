#ifndef _PLAYER_H
#define _PLAYER_H
#include <cstdio>
#include <iostream>
#include <array>
#include <memory>
#include <stdexcept>
using namespace std;
#include <string>
#include <sstream>
#include "UserProfile.h"


class Player {
private:
    string name;
    int score;

public:
    Player(const string& _name);

    void increaseScore();
    string getName() const;
    int getScore() const;
};

#endif