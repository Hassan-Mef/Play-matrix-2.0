// Include necessary libraries and namespaces
#include <iostream>
#include <string>
#include <map>
#include "nlohmann/json.hpp"
#include <fstream>
using json = nlohmann::json;
using namespace std;

// Define a generic player class with two template parameters U and S
template <class U, class S>
class G_Player
{
private:
	map<U, S> player;  // Map to store player names and their scores
	U currentUsername;  // Variable to store the current username

public:
	G_Player() = default;  // Default constructor
	G_Player(U name, S score);  // Constructor that takes a name and a score

	U getName();  // Method to get the current username
	S getScore(U name);  // Method to get the score of a player
	void setName(U name);  // Method to set the current username
	void setScore(S score);  // Method to set the score of the current user

	void update(U key, S value);  // Method to update the score of a player

	json serialize();  // Method to serialize the player map to a JSON object
	void deserialize(json j);  // Method to deserialize a JSON object to the player map
	void saveToFile(U name);  // Method to save the player map to a file
	void loadFromFile(U name);  // Method to load the player map from a file

	G_Player operator+(int score);  // Overload the + operator to add a score to a player

	// Overload the << operator to print the player map
	friend ostream& operator<<(ostream& os, const G_Player<U, S>& plyr);
};

// Implement the methods of the G_Player class
template<class U, class S>
G_Player<U, S>::G_Player(U name, S score)
{
	player[name] = score;  // Initialize the player map with the given name and score
	currentUsername = name;  // Set the current username
}

template<class U, class S>
U G_Player<U, S>::getName()
{
	return currentUsername;  // Return the current username
}

template<class U, class S>
S G_Player<U, S>::getScore(U name)
{
	// Check if the player exists in the map
	if (player.find(name) != player.end()) {
		// Return the player's score
		return player[name];
	}
	else {
		// Return a default score of 0 if the player does not exist
		return 0;
	}
}

template<class U, class S>
void G_Player<U, S>::setName(U name)
{
	currentUsername = name;  // Set the current username
}

template<class U, class S>
void G_Player<U, S>::setScore(S score)
{
	player[getName()] = score;  // Set the score of the current user
}

template<class U, class S>
void G_Player<U, S>::update(U key, S value)
{
	player[key] = value;  // Update the score of a player
}

template<class U, class S>
json G_Player<U, S>::serialize()
{
	json j;
	for (auto& it : player) {
		j[it.first] = it.second;  // Add each player and their score to the JSON object
	}
	return j;  // Return the JSON object
}

template<class U, class S>
void G_Player<U, S>::deserialize(json j) {
	for (auto& it : j.items()) {
		player[it.key()] = it.value();  // Add each player and their score to the player map
		currentUsername = it.key();  // Set the current username
	}
}

template<class U, class S>
void G_Player<U, S>::saveToFile(U name) {
	// Check if the name is not empty
	if (name.empty()) {
		std::cerr << "Player name cannot be empty" << '\n';
		return;
	}
	// Load existing JSON from file
	json j;
	string filename = name + ".json";
	ifstream file(filename);
	if (file.is_open()) {
		file >> j;
		file.close();
	}

	// Update the value
	j[name] = getScore(name);

	// Save updated JSON to file
	ofstream outfile(filename);
	try {
		outfile << setw(4) << j;
		outfile.close();
	}
	catch (const std::exception& e) {
		std::cerr << "A problem occurred when saving to file: " << e.what() << '\n';
	}
}

template<class U, class S>
void G_Player<U, S>::loadFromFile(U name) {
	string filename = name + ".json";
	ifstream file(filename);
	if (file.is_open()) {
		json j;
		file >> j;
		deserialize(j);  // Deserialize the JSON object to the player map
		file.close();
	}
	else {
		// Handle error
		cout << "Unable to open file " << filename << endl;
	}
}

template<class U, class S>
ostream& operator<<(ostream& os, const G_Player<U, S>& plyr)
{
	for (const auto& p : plyr.player)
	{
		os << "Name: " << p.first << ", Score: " << p.second << "\n";  // Print each player and their score
	}
	return os;
}
