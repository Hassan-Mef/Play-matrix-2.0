#include <cstdio>
#include <iostream>
#include <array>
#include <memory>
#include <stdexcept>
using namespace std;
#include <string>
#include <ctime>
#include <sstream>
#include "Wordbank.h"

const vector<string> WordBank::months = { "january", "february", "march", "april", "may", "june",
                                                    "july", "august", "september", "october", "november", "december" };

const vector<string> WordBank::animals = { "dog", "cat", "rhino", "hippo", "giraffe", "elephant", "cow", "tiger","donkey","monkey"};

const map<string, vector<string>> WordBank::wordCategories = {
    {"month", months},
    {"animal", animals}
};

string WordBank::getRandomWord() {
    srand(time(nullptr));
    int categoryIndex = rand() % wordCategories.size(); // Randomly select a category index
    auto it = wordCategories.begin();
    advance(it, categoryIndex);
    const vector<string>& category = it->second; // Get the vector of words for the selected category
    int randomIndex = rand() % category.size(); // Randomly select a word index
    return category[randomIndex]; // Return the randomly selected word
}