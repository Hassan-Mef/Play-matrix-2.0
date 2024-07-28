#ifndef _HANGMANDRAWING_H
#define _HANGMANDRAWING_H
#include <cstdio>
#include <iostream>
#include <array>
#include <memory>
#include <stdexcept>
using namespace std;
#include <string>
#include <sstream>

class HangmanDrawing {
public:
    virtual void draw(int incorrectGuesses) = 0;
    virtual ~HangmanDrawing() {}
};

#endif

