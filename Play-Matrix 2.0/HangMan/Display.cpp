#include <cstdio>
#include <iostream>
#include <array>
#include <memory>
#include <stdexcept>
using namespace std;
#include <string>
#include <sstream>
#include "Display.h"

char Display::getUserInput() {
    char letter;
   cout << "\t\t\t\tGuess a letter: ";
   cin >> letter;
    return letter;
}

void Display::showResult(const string& month, int tries) {
  cout << "\t\t\t\tThe Word is: " << month << endl;
    if (tries == 0) {
       cout << "\t\t\t\tYou're Hanged!" << endl;
    }
    else {
        cout << "\t\t\t\tYou're Free!" << endl;
    }
}