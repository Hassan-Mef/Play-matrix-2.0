#ifndef _ASCIIHANGMANDRAWING_H
#define _ASCIIHANGMANDRAWING_H
#include <cstdio>
#include <iostream>
#include <array>
#include <memory>
#include <stdexcept>
using namespace std;
#include <string>
#include <sstream>

#include "HangmanDrawing.h"

class AsciiHangmanDrawing : public HangmanDrawing {
public:
    void draw(int incorrectGuesses) override;
};

#endif