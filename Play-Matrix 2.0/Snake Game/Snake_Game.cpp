#include <iostream>
#include <string>
#include <raylib.h>
#include "Snake_Game.h"


using namespace std;

int Snake_Game()
{
    Color Dark_Green = Color{ 20, 160, 133, 255 };

    const int screenWidth = 800;
    const int screenHeight = 600;
    Game_manager game;

    Snake snake;


    InitWindow(screenWidth, screenHeight, "Snake ");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(Dark_Green);
        game.handleInput();
        game.draw();
        game.update();
		
        if (game.getGameOver())
        {
            string scoreStr = to_string(game.getCurrentScore());
			DrawText("Score :", 200, 280, 40, RED);
            DrawText(scoreStr.c_str(), 350, 280, 40, RED);
        }

        if (IsKeyPressed(KEY_ESCAPE)) {
            return 1;  // return 1 when the game window is closed
        }
        EndDrawing();
    }


    CloseWindow();


	return 0;
}

