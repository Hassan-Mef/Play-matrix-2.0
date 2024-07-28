#include "Game_Manage.h"  
#include <algorithm>  
#include <raylib.h>  // Include the raylib library for game development functions
#include <ctime>  // Include the ctime library for time-related functions

// Destructor for the Game_Manage class
Game_Manage::~Game_Manage()
{
    // No specific cleanup is done here
}

// Method to draw the game elements
void Game_Manage::draw()
{
    ship->draw();  // Draw the ship

    // Draw all the bullets
    for (int i = 0; i < bullets.size(); i++)
    {
        bullets[i].draw();
    }

    // Draw all the enemies
    for (int i = 0; i < enemies.size(); i++)
    {
        enemies[i].draw();
    }
}

// Method to update the game state
void Game_Manage::update()
{
    // Only update the game state if the game is not over
    if (!gameOver) {
        // Move all the bullets up
        for (int i = 0; i < bullets.size(); i++)
        {
            bullets[i].moveUp();

            // If a bullet is out of the window, delete it
            if (bullets[i].getY() <= 0)
            {
                bullets.erase(bullets.begin() + i);
                i--;
                cout << "deleted Bullets" << endl; // for testing purposes
            }
        }

        level = level_Manager();  // Update the game level

        // With a 1% chance, generate a new enemy
        if (rand() % 200 < 1) {
            int enemyX = rand() % (GetScreenWidth() - 40) + 1;
            enemies.push_back(Enemies(enemyX, 1));
        }

        // Move all the enemies down
        for (int i = 0; i < enemies.size(); i++)
        {
            enemies[i].moveDown();

            // If an enemy collides with the ship, delete the enemy and set the game over
            if (enemies[i].getX() < ship->getX() + ship->getWidth() &&
                enemies[i].getX() + enemies[i].getWidth() > ship->getX() &&
                enemies[i].getY() < ship->getY() + ship->getHeight() &&
                enemies[i].getY() + enemies[i].getHeight() > ship->getY())
            {
                enemies.erase(enemies.begin() + i);
                i--;
                gameOver = true;
                cout << "Enemies hit " << endl;
            }

            // If an enemy has reached the bottom of the window, delete it
            if (i < enemies.size() && enemies[i].getY() >= GetScreenHeight() - 60) {
                enemies.erase(enemies.begin() + i);
                i--; // decrement i after erasing
                score -= 10;
                cout << "deleted enemy" << endl;
            }
        }

        // Check for collisions between bullets and enemies
        for (int i = 0; i < enemies.size(); i++)
        {
            for (int j = 0; j < bullets.size(); j++)
            {
                // Find the closest x and y coordinates on the enemy rectangle to the bullet
                float closestX = max(enemies[i].getX(), min(bullets[j].getX(), enemies[i].getX() + enemies[i].getWidth()));
                float closestY = max(enemies[i].getY(), min(bullets[j].getY(), enemies[i].getY() + enemies[i].getHeight()));

                // Calculate the distance between the bullet's center and this closest point
                float distanceX = bullets[j].getX() - closestX;
                float distanceY = bullets[j].getY() - closestY;

                // If the distance is less than the bullet's radius, a collision occurred
                if ((distanceX * distanceX) + (distanceY * distanceY) <= (bullets[j].getRadius() * bullets[j].getRadius()))
                {
                    // Collision detected, remove the bullet and the enemy
                    bullets.erase(bullets.begin() + j);
                    enemies.erase(enemies.begin() + i);
                    j--;
                    i--;
                    score += 10;
                    break;
                }
            }
        }
    }
}

// Method to handle user input
void Game_Manage::handleInput()
{
    // Only handle input if the game is not over
    if (!gameOver)
    {
        // Move the ship left if the A key is pressed
        if (IsKeyDown(KEY_A))
            ship->moveLeft();

        // Move the ship right if the D key is pressed
        if (IsKeyDown(KEY_D))
            ship->moveRight(ScreenWidth);

        // Fire a bullet if the space key is pressed
        if (IsKeyDown(KEY_SPACE))
        {
            if (GetTime() - LastFiretime >= 0.50)
                bullets.push_back(Bullets((ship->getX() + ship->getWidth() / 2), ship->getY() + 3));
            LastFiretime = GetTime();
            PlaySound(laser);
        }
    }
}

// Method to get the game over state
bool Game_Manage::getGameOver()
{
    return gameOver;
}

// Method to setup the user
void Game_Manage::UserSetup(string name)
{
    // Construct the filename from the player's name
    string filename = name + ".json";

    // Check if the player's file exists
    ifstream file(filename);
    if (file.good())
    {
        // The file exists, so load the player's data
        player.loadFromFile(name);
    }
    else
    {
        // The file doesn't exist, so create a new player
        player = G_Player<string, int>(name, 0);
        player.saveToFile(name);
    }
}

// Method to get the current score
int Game_Manage::getScore()
{
    return score;
}

// Method to update the player's score
void Game_Manage::updatePlayerScore(int score, string name) {
    if (name.empty()) {
        std::cerr << "Player name cannot be empty" << '\n';
        return;
    }

    static int check = 0;
    if (check == 0)
    {
        // Load existing scores
        player.loadFromFile(name);
        check = +1;
    }

    // Update score if necessary
    if (score > player.getScore(name)) {
        player.setScore(getScore());

        // Save updated scores
        player.saveToFile(name);
    }
}

// Method to manage the game level
float Game_Manage::level_Manager()
{
    if (score > 100)
    {
        return 0.5;
    }
    else if (score < 200)
    {
        return 1.0;
    }

    return 0.0;
}

// Method to set the highest score
void Game_Manage::setHighestScore(int score)
{
    if (score > getHighestScore())
    {
        ofstream H_score("HighestScore.txt");
        if (H_score.is_open())
        {
            H_score << score;
            cout << "High Score Updated" << endl;
        }
    }
}

// Method to get the highest score
int Game_Manage::getHighestScore()
{
    ifstream H_score("HighestScore.txt");
    int highScore = 0;  // Initialize highScore to 0

    if (H_score.is_open())
    {
        H_score >> highScore;
        cout << "High Score testing " << highScore << endl;
    }
    else
    {
        cout << "Unable to open file" << endl;
    }

    return highScore;
}
