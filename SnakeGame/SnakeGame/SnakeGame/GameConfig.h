#pragma once
#include <iostream>
#include <windows.h>
#include <fstream>

struct GameConfig {
	int width;
	int height;
	int speed;
	
};
GameConfig loadConfig(std::string filename);