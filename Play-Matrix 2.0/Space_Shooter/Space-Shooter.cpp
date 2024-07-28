#include <iostream>  
#include <fstream>   
#include <string>    
#include <ctime>     // For time-related functions
#include <raylib.h>  // For game development functions
#include "Space_Shooter.h"  

using namespace std;

int Space_Shooter()
{
	srand(time(0));  // Initialize random number generator
	static int checking = 0;  // Static variable to check game over state

	Console console;  // Console object for input/output operations

	// Define colors
	Color Grey = Color{ 99, 102, 112, 255 };
	Color Yellow = Color{ 243 , 216 , 63 , 255 };

	int offset = 50;  // Offset for window size
	const int screenWidth = 500;  // Screen width
	const int screenHeight = 600;  // Screen height

	InitAudioDevice();  // Initialize audio device

	// Initialize game window with specified width, height and title
	InitWindow(screenWidth + offset, screenHeight + offset, "Space Shooter");

	// Load font
	Font font = LoadFontEx("Fonts/monogram.ttf", 64 , 0 , 0);


	Game_Manage game(screenWidth);  // Game manager object

	string gameScore = "0";  // Initialize game score
	game.printConsoleName(console);  // Print console name
	console.clearConsole();  // Clear console

	// Prompt user for name
	cout << "Enter your name : " << endl;
	string name;
	cin >> name;

	game.UserSetup(name);  // Setup user with entered name

	// Load game music and sounds
	Music music = LoadMusicStream("Sounds/game_bg.mp3");
	Sound hit = LoadSound("Sounds/hit2.mp3");
	Sound lose = LoadSound("Sounds/xpSound.mp3");
	PlayMusicStream(music);  // Play game music

	float timePlayed = 0.0f;  // Initialize time played
	int high = game.getHighestScore();  // Get highest score
	string H_score = to_string(high);  // Convert highest score to string

	SetTargetFPS(60);  // Set target frames per second

	static int menu = 0;  // Static variable for menu state

	// Game loop
	while (!WindowShouldClose())
	{
		UpdateMusicStream(music);  // Update music stream

		timePlayed = GetMusicTimePlayed(music) / GetMusicTimeLength(music);  // Calculate time played

		if (timePlayed > 1.0f) timePlayed = 1.0f;  // Limit time played to 1.0f

		BeginDrawing();  // Begin drawing
		ClearBackground(Grey);  // Clear background with grey color

		// Menu state
		if (menu == 0)
		{
			// Draw menu texts
			DrawTextEx(font, "SPACE SHOOTER ", { 95 , 100 }, 50, 2, Yellow);
			DrawTextEx(font, "HIGH SCORE : ", { 150 , 190 }, 25, 2, Yellow);
			DrawTextEx(font, H_score.c_str(), { 315 , 190 }, 25, 2, Yellow);
			DrawTextEx(font, "Press Enter to Start ", { 105 , 260 }, 21, 2, Yellow);

			// Check if Enter key is pressed
			if(IsKeyPressed(KEY_ENTER))
				menu = 1;  // Change menu state to 1

			EndDrawing();  // End drawing
			continue;  // Continue to next iteration of game loop
		}

		// Draw game elements
		DrawRectangleRoundedLines({ 10 ,10 ,520 , 630 }, 0.18f,20 , 2, Yellow);
		DrawLineEx({ 15 , 600 }, { 521 ,600 }, 3 , Yellow);
		game.handleInput();  // Handle game input
		DrawTextEx(font, "Score", {400 , 604}, 20, 2, Yellow);
		gameScore = to_string(game.getScore());  // Update game score
		DrawTextEx(font, gameScore.c_str(), { 460 , 604 }, 20, 2, Yellow);

		game.draw();  // Draw game
		game.update();  // Update game

		game.updatePlayerScore(game.getScore(), name);  // Update player score

		// Check if game is over
		if (game.getGameOver())
		{
			// Draw game over text
			DrawTextEx(font, "Game Over", { 250-50 , 300-50 }, 40, 2, Yellow);

			// Play lose sound once
			if (checking == 0)
			{
				PlaySound(lose);
				checking = 1;
			}
		}

		gameScore = game.getScore();  // Update game score

		EndDrawing();  // End drawing
	}

	// Set highest score
	game.setHighestScore(game.getScore());

	// Unload music stream and close audio device
	UnloadMusicStream(music);
	CloseAudioDevice();

	CloseWindow();  // Close game window

	return 0;
}
