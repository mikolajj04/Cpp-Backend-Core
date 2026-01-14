/**
 * @file Draw.h
 * @brief Functions responsible for rendering the game state to the console.
 */
#pragma once
#include "GameConfig.h"
#include "SnakeList.h"

/**
 * @brief Renders the game board, snake, and fruit.
 * @param cfg Current game configuration.
 * @param snake Reference to the SnakeList object.
 * @param fruitX X-coordinate of the fruit.
 * @param fruitY Y-coordinate of the fruit.
 * @param score Current player score.
 */
	void Draw(const GameConfig& cfg, SnakeList& snake, int fruitX, int fruitY, int score);
void Draw(const GameConfig& cfg, SnakeList& snake, int fruitX, int fruitY, int score);