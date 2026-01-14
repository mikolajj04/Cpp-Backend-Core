/**
 * @file Types.h
 * @brief Common enumerations used across the project.
 */
#pragma once
 /** @enum eDirection @brief Possible movement directions for the snake. */
enum class eDirection { 
	STOP = 0,
	LEFT,
	RIGHT,
	UP,
	DOWN 
};
/** @enum Difficulty @brief Difficulty levels that scale gameplay mechanics. */
enum class Difficulty {
	EASY,
	MEDIUM,
	HARD
};
