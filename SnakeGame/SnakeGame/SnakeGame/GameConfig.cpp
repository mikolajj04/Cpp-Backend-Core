#include "GameConfig.h"
GameConfig loadConfig(std::string filename){
	std::ifstream file(filename);
	GameConfig config;
	std::string tempDiff;

	if (!file.is_open()) {
		std::cout << "Error: cannot open the file: " << filename << "!" << std::endl;
		std::cout << "Loading default settings..." << std::endl; 
			return { 20,15,100,false };
	}

	file >> config.width >> config.height >> config.speed >> config.IsHardcore >> tempDiff;
	if (config.width > 100 || config.height > 24) {
		std::cout << "							Error: maximum width is 100 and maximum height is 24 "<< std::endl;
		std::cout << "							Loading default settings..." << std::endl; 
		
			return { 20,15,100,false };
	}
	if (tempDiff == "HARD") {
		config.diff = Difficulty::HARD;
	}
	else if (tempDiff == "MEDIUM") {
		config.diff = Difficulty::MEDIUM;
	}
	else {
		config.diff = Difficulty::EASY;
	}
	file.close();
	return config;


}