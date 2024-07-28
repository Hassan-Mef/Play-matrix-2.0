#ifndef _WORDBANK_H
#define _WORDBANK_H
#include <cstdio>
#include <iostream>
#include <array>
#include <memory>
#include <stdexcept>
using namespace std;
#include <string>
#include <sstream>
#include <string>
#include <vector>
#include <map>

class WordBank {
private:
    static const vector<string> months;
    static const vector<string> animals;
    static const map<string, vector<string>> wordCategories;

public:
    string getRandomWord();

private:
    const vector<string>& getCategory(const string& category) const;
};
#endif
