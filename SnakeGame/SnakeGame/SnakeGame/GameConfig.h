#pragma once
#include <iostream>
#include <windows.h>
#include <fstream>
#include "Types.h"

struct GameConfig {
	int width;
	int height;
	int speed;
	bool IsHardcore;
	Difficulty diff;

	
};
GameConfig loadConfig(std::string filename);