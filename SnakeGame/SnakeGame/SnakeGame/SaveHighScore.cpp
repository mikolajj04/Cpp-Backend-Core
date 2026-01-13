#pragma once
#include "SaveHighScore.h"
#include <iostream>
void saveHighScore(std::string playerName, int score) {
	std::ofstream outFile("highscores.txt", std::ios::app);
	if (outFile.is_open()) {
		outFile <<playerName << " | Score: " << score << std::endl;
		outFile.close();
	}
	else {
		std::cerr << "Error: Could not open highscores.txt for writing!";
	}
}


void displayLeaderboard(){
	std::ifstream inFile("highscores.txt");
	std::string line;
	system("cls");
	std::cout << "=== RECENT SCORES ===\n" << std::endl;
	if (inFile.is_open()) {
		while (getline(inFile, line)) {
			std::cout << line << std::endl;
		}

	}else {
		std::cout << "No scores yet. Be the first!" << std::endl;
	}
	std::cout << "\n=====================" << std::endl;

}