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


        if (dir != STOP) {
            if (dir == LEFT) {
                headX--;
            }
            else if (dir == RIGHT) {
                headX++;
            }
            else if (dir == UP) {
                headY--;
            }
            else if (dir == DOWN) {
                headY++;
            }
            snake.push_front(headX, headY);

            if (headX == fruitX && headY == fruitY) {
                score += 10;
                fruitX = rand() % cfg.width;
                fruitY = rand() % cfg.height;
            }
            else {
                snake.pop_back();
            }

        }
        Draw(cfg, snake, fruitX, fruitY, score);
        if (headX < 0 || headX >= cfg.width || headY < 0 || headY >= cfg.height) {

            gameOver = true;

        }
        

    }
   
    std::cout << "GAME OVER! Your Score: " << score << std::endl;
    return 0;
}
