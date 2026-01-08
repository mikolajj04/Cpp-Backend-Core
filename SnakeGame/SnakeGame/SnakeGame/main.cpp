#include "SnakeList.h"
#include "GameConfig.h"
#include "Draw.h"

int main() {
    GameConfig cfg = loadConfig("config.txt");
    enum eDirection {STOP= 0, LEFT, RIGHT, UP, DOWN};
    eDirection dir = STOP;
    SnakeList snake;

    int score = 0;
    int headX = cfg.width / 2;
    int headY = cfg.height / 2;
    int fruitX = rand() % cfg.width;
    int fruitY = rand() % cfg.height;
    bool gameOver = false;
    snake.push_front(headX,headY);

    while (!gameOver) {
        if (_kbhit()) {
            switch (_getch())
            {
            case 'a':
                dir = LEFT;
                break;
            case 'd':
                dir = RIGHT;
                break;
            case 'w':
                dir = UP;
                break;
            case 's':
                dir = DOWN;
                break;
            case 'x':
                gameOver = true;
                break;
            }
        }
    }

    return 0;
}
