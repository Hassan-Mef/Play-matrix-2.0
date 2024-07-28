#ifndef _GAMEFLOW_H
#define _GAMEFLOW_H
#include <cstdio>
#include <iostream>
#include <array>
#include <memory>
#include <stdexcept>
using namespace std;
#include <string>
#include <sstream>

#include "GameManager.h"
#include "Player.h"
#include "UserProfile.h"

class GameFlow {
private:
    static GameFlow* inst ;
    GameManager game;
    Player player;
    UserProfile userProfile;

    GameFlow(const string& playerName);
    

public:
    
    void PlayerSetUp();
    
    static GameFlow* getInstance(string p_name);


    void start();
};

#endif