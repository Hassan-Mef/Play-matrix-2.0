#include <cstdio>
#include <iostream>
#include <array>
#include <memory>
#include <stdexcept>
using namespace std;
#include <string>
#include <sstream>
#include "Player.h"

Player::Player(const string& _name) : name(_name), score(0) {}

void Player::increaseScore() {
    score++;
}

string Player::getName() const {
    return name;
}

int Player::getScore() const {
    return score;
}