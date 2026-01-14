/**
 * @file GameConfig.h
 * @brief Configuration structures and functions for game settings.
 */
#pragma once
#include <iostream>
#include <windows.h>
#include <fstream>
#include "Types.h"

 /**
 * @struct GameConfig
 * @brief Stores game parameters such as board dimensions and speed.
 */
struct GameConfig {
    int width;  ///< Width of the game board.
    int height; ///< Height of the game board.
    int speed;  ///< Delay between frames in milliseconds.
    Difficulty diff; ///< Game difficulty level.
};

/**
 * @brief Loads game configuration from a file.
 * @param filename Name of the file containing config data.
 * @return GameConfig object with loaded or default values.
 */
GameConfig loadConfig(std::string filename);