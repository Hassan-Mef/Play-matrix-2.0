#include <iostream>
#include <string>
#include"HangMan.h"

using namespace std;

int HangMan() {
    string playerName;
    bool validNameEntered = false;

    while (!validNameEntered) {
        cout << "Enter your name: ";
        cin >> playerName;
        

        try {
            // Check if playerName contains only digits
            for (char c : playerName) {
                if (isdigit(c)) {
                    throw invalid_argument("Player name must not contain digits.");
                }
            }

            validNameEntered = true;
        }
        catch (const invalid_argument& e) {
            cerr << "Invalid input: " << e.what() << endl;
        }
       
    }

    // If a valid name is entered, start the game
    GameFlow* game = GameFlow::getInstance(playerName);
    game->start();

    return 0;
}