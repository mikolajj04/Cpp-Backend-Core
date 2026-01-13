#pragma once
#include "SaveHighScore.h"
#include <iostream>
void saveHighScore(std::string playerName, int score) {
	std::ofstream outFile("highscores.txt", std::ios::app);
	if (outFile.is_open()) {
		outFile << "Name: " << playerName << " | Score: " << score << std::endl;
		outFile.close();
	}
	else {
		std::cerr << "Error: Could not open highscores.txt for writing!";
	}
}