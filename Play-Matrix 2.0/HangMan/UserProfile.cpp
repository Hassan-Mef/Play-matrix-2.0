#include <cstdio>
#include <iostream>
#include <array>
#include <memory>
#include <stdexcept>
using namespace std;
#include <string>
#include <sstream>
#include <sstream>
#include "GameRecord.h"
#include "nlohmann/json.hpp"
using json = nlohmann::json;
#include "UserProfile.h"
UserProfile::UserProfile(const string& _name) : name(_name), score(0), gamesPlayed(0) {}

void UserProfile::increaseScore() {
    score++;
}

void UserProfile::incrementGamesPlayed() {
    gamesPlayed++;
}

string UserProfile::getName() const {
    return name;
}

int UserProfile::getScore() const {
    return score;
}

void UserProfile::setScore(int score)
{
    this->score = score;
}

int UserProfile::getGamesPlayed() const {
    return gamesPlayed;
}

bool UserProfile::verifyFile(string filename)
{
    ifstream file(filename);
    if (file.is_open()) {
        file.close();
        return true;
    }
    else {
        return false;
    }
}

void UserProfile::loadFromFile(const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        json j;
        file >> j;
        fromJson(j);
        file.close();
    }
}

void UserProfile::saveToFile( string& filename) const {
    ofstream file(filename);
    if (file.is_open()) {
        json j = toJson();
        file << setw(4) << j << endl;
        file.close();
    }
    else {
        cerr << "Unable to save file: " << filename << endl;
    }
}

json UserProfile::toJson() const {
    json j;
    j["name"] = name;
    j["score"] = score;
    j["gamesPlayed"] = gamesPlayed;
    return j;
}

void UserProfile::fromJson(const json& j) {
    name = j.at("name").get<string>();
    score = j.at("score").get<int>();
    gamesPlayed = j.at("gamesPlayed").get<int>();
}