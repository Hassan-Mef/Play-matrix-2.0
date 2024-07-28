#ifndef _USERPROFILE_H
#define _USERPROFILE_H
#include <cstdio>
#include <iostream>
#include <array>
#include <memory>
#include <stdexcept>
using namespace std;
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "GameRecord.h"
#include "nlohmann/json.hpp"
using json = nlohmann::json;

class UserProfile {
private:
    string name;
    int score;
    int gamesPlayed;

public:
    UserProfile(const string& _name);

    void increaseScore();
    void incrementGamesPlayed();
    string getName() const;
    int getScore() const;
    void setScore(int score);
    int getGamesPlayed() const;

    UserProfile& operator+=(int increase) {
        score += increase;
        return *this;
    }

    bool verifyFile(string filename);

    void loadFromFile(const string& filename);
    void saveToFile( string& filename) const;

private:
    json toJson() const;
    void fromJson(const json& j);
};
#endif