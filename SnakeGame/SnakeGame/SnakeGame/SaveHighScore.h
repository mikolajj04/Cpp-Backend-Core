/**
 * @file SaveHighScore.h
 * @brief File I/O operations for saving and displaying player scores.
 */
#pragma once
#include <fstream>
#include <string>
 /**
  * @brief Appends a new score to the highscore file.
  * @param playerName Name of the player.
  * @param score Final score achieved.
  */
void saveHighScore(std::string playerName, int score);

/**
 * @brief Displays the leaderboard from the highscore file to the console.
 */
void displayLeaderboard();