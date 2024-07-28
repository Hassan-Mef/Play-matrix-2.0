#include <cstdio>
#include <iostream>
#include <array>
#include <memory>
#include <stdexcept>
using namespace std;
#include <string>
#include <sstream>
#include "GameFlow.h"
#include "GameManager.h"
#include "Player.h"
#include "UserProfile.h"
#include "Display.h"

GameFlow::GameFlow(const string& playerName) : player(playerName), userProfile(playerName) {}

GameFlow *GameFlow::inst = nullptr;
void GameFlow::PlayerSetUp()
{
    string file_name = player.getName() + ".json";
    
    if(userProfile.verifyFile(file_name))
     userProfile.loadFromFile(file_name);
    else
     userProfile.saveToFile(file_name);
}

GameFlow *GameFlow::getInstance(string p_name)
{
    if (inst == nullptr)
    {
        inst = new GameFlow(p_name);
    }
    return inst;
}

void GameFlow::start() {
    game.startGame();
    PlayerSetUp();
    userProfile.incrementGamesPlayed();

    

    while (!game.isGameOver()) {
        game.display();
        char letter = Display::getUserInput();
        game.play(letter);
        userProfile.setScore(game.getScore());
    }

    Display::showResult(game.getMonth(), game.getTries());
    string filename = player.getName() + ".json" ;
    userProfile.saveToFile(filename);
}