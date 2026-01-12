#include "Draw.h"

void Draw(const GameConfig& cfg, SnakeList& snake, int fruitX, int fruitY, int score) {

    COORD cursorPosition;
    cursorPosition.X = 0;
    cursorPosition.Y = 0;
   
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
    //upper wall
    for (int i = 0; i < (cfg.width/2)-8; i++) { std::cout << " "; }
    std::cout << "---SNAKE GAME---\n";
    for (int i = 0; i < cfg.width + 2; i++) { std::cout << "#"; }
    std::cout << "\n";


    //left wall->checking if snake is on j,i position-> right wall
    for (int i = 0; i < cfg.height; i++) {
        for (int j = 0; j < cfg.width; j++) {
            if (j == 0) std::cout << "#";
            if (snake.isSnakeAt(j, i)) {
                std::cout << "O";
            }
            else if (j == fruitX && i == fruitY)
            {
                std::cout << "Q";
            }
            else {
                std::cout << " ";
            }
            if (j == cfg.width - 1) std::cout << "#";
        }
        std::cout << "\n";
    }
    //bottom wall
    for (int i = 0; i < cfg.width + 2; i++) {
        std::cout << "#";
    }
    std::cout << "\n";
    for (int i = 0; i < cfg.width + 2; i++) {
        std::cout << "-";
    }
    std::cout << "\n";
    //Final score= Points * speed!
    std::cout << "Points: " << score << "| map config: " << cfg.width << "x" << cfg.height << "| speed :" << 110-cfg.speed <<"\n";



}
