#ifndef _DISPLAY_H
#define _DISPLAY_H
#include <cstdio>
#include <iostream>
#include <array>
#include <memory>
#include <stdexcept>
using namespace std;
#include <string>
#include <sstream>

class Display {
public:
    static char getUserInput();
    static void showResult(const string& month, int tries);
};

#endif