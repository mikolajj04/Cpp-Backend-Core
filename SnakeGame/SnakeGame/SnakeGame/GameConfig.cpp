#include "GameConfig.h"
#include <conio.h>
GameConfig loadConfig(std::string filename){
	std::ifstream file(filename);
	GameConfig config;
	std::string tempDiff;

	if (!file.is_open()) {
		std::cerr << "Error: cannot open the file: " << filename << "!" << std::endl;
		std::cerr << "Loading default settings..." << std::endl; 
		std::cerr << "Press any key to continue..." << std::endl;
		_getch();
		system("cls");
			return { 20,15,100,Difficulty::EASY };
	}

	file >> config.width >> config.height >> config.speed  >> tempDiff;
	if (config.width > 100 || config.height > 24) {
		std::cerr << "Error: maximum width is 100 and maximum height is 24 "<< std::endl;
		std::cerr << "Loading default settings..." << std::endl; 
		std::cerr << "Press any key to continue..." << std::endl;
		_getch();
		system("cls");
		
			return { 20,15,100,Difficulty::EASY };
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