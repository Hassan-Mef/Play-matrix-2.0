#include <cstdio>
#include <iostream>
#include <array>
#include <memory>
#include <stdexcept>
using namespace std;
#include <string>
#include <sstream>

#include "AsciiHangmanDrawing.h"

void AsciiHangmanDrawing::draw(int incorrectGuesses) {
    cout << "\t\t\t\t+---+" << endl;
    cout << "\t\t\t\t|   |" << endl;

    // Drawing different parts of the hangman based on the number of incorrect guesses
    switch (incorrectGuesses) {
    case 0:
        cout << "\t\t\t\t|    " << endl;
        cout << "\t\t\t\t|    " << endl;
        cout << "\t\t\t\t|    " << endl;
        cout << "\t\t\t\t|    " << endl;
        break;
    case 1:
        cout << "\t\t\t\t|   O" << endl;
        cout << "\t\t\t\t|    " << endl;
        cout << "\t\t\t\t|    " << endl;
        cout << "\t\t\t\t|    " << endl;
        break;
    case 2:
        cout << "\t\t\t\t|   O" << endl;
        cout << "\t\t\t\t|   |" << endl;
        cout << "\t\t\t\t|    " << endl;
        cout << "\t\t\t\t|    " << endl;
        break;
    case 3:
        cout << "\t\t\t\t|   O" << endl;
        cout << "\t\t\t\t|  /|" << endl;
        cout << "\t\t\t\t|    " << endl;
        cout << "\t\t\t\t|    " << endl;
        break;
    case 4:
        cout << "\t\t\t\t|   O" << endl;
        cout << "\t\t\t\t|  /|\\" << endl;
        cout << "\t\t\t\t|    " << endl;
        cout << "\t\t\t\t|    " << endl;
        break;
    case 5:
        cout << "\t\t\t\t|   O" << endl;
        cout << "\t\t\t\t|  /|\\" << endl;
        cout << "\t\t\t\t|  / " << endl;
        cout << "\t\t\t\t|    " << endl;
        break;
    case 6:
        
        cout << "\t\t\t\t|   O" << endl;
        cout << "\t\t\t\t|  /|\\ " << endl;
        cout << "\t\t\t\t|  / \\" << endl;
        cout << "\t\t\t\t|    " << endl;
    }


    cout << "\t\t\t\t|    " << endl;
    cout << "\t\t\t\t+---+" << endl;
}
