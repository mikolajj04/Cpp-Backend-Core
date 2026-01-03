#include "GameConfig.h"
GameConfig loadConfig(std::string filename){
	std::ifstream file(filename);
	GameConfig config;

	if (!file.is_open()) {
		std::cout << "Error: cannot open the file: " << filename << "!" << std::endl;
		std::cout << "Loading default settings..." << std::endl; \
			return { 20,20,100 };
	}

	file >> config.width >> config.height >> config.speed;
	file.close();
	std::cout << "Loaded settings: " << config.width << "x" << config.height << "| Speed: " << config.speed << std::endl;
	return config;


}