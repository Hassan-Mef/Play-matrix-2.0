#ifndef _SCOREBOARD_H
#define _SCOREBOARD_H



#include<iostream>
#include "nlohmann/json.hpp"

using json = nlohmann::json;

using namespace std;

class ScoreBoard
{
private:
	int score;
	int highScore;

public:
	ScoreBoard();
	void setScore(int sc);
	void setHighScore(int Hsc);
	int getScore();
	int getHighScore();
	void savetoFile();
	void loadFromFile();
};

#endif // !_SCOREBOARD_H