#include "SnakeList.h"
#include "GameConfig.h"
#include "Draw.h"
#include "Types.h"


int main() {
    GameConfig cfg = loadConfig("config.txt");
    eDirection dir = eDirection::STOP;
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
                dir = eDirection::LEFT;
                break;
            case 'd':
                dir = eDirection::RIGHT;
                break;
            case 'w':
                dir = eDirection::UP;
                break;
            case 's':
                dir = eDirection::DOWN;
                break;
            case 'x':
                gameOver = true;
                break;
            }
        }


        if (dir != eDirection::STOP) {
            if (dir == eDirection::LEFT) {
                headX--;
            }
            else if (dir == eDirection::RIGHT) {
                headX++;
            }
            else if (dir == eDirection::UP) {
                headY--;
            }
            else if (dir == eDirection::DOWN) {
                headY++;
            }
            if (snake.isSnakeAt(headX, headY)) {
                gameOver = true;
            }
            snake.push_front(headX, headY);
          

            if (headX == fruitX && headY == fruitY) {
            /*    score += 10;
                fruitX = rand() % cfg.width;
                fruitY = rand() % cfg.height;*/
            

                switch (cfg.diff) {
                case Difficulty::EASY:
                    score += 10;
                    fruitX = rand() % cfg.width;
                    fruitY = rand() % cfg.height;
                    break;
                case Difficulty::MEDIUM:
                    score += 20;
                    cfg.speed -= 2;
                    fruitX = rand() % cfg.width;
                    fruitY = rand() % cfg.height;
                    break;

                case Difficulty::HARD:
                    system("cls");
                    score += 50;
                    cfg.speed -= 3;
                    if (cfg.width > 10)cfg.width -= 1;
                    if(cfg.height>5)cfg.height -= 1;
                    fruitX = 1 + (rand() % (cfg.width - 2));
                    fruitY = 1 + (rand() % (cfg.height - 2));
                    break;

                }
                MessageBeep(MB_ICONWARNING);
                /*if (cfg.IsHardcore == true) {
                    system("cls");
                    cfg.speed -= 2;
                    cfg.height -= 1;
                    cfg.width -= 1;
                    fruitX = 1 + (rand() % (cfg.width - 2));
                    fruitY = 1 + (rand() % (cfg.height - 2));

                }*/

            }
            else {
                snake.pop_back();
            }

        }
        Draw(cfg, snake, fruitX, fruitY, score);
        if (headX < 0 || headX >= cfg.width || headY < 0 || headY >= cfg.height) {

            gameOver = true;

        }
        Sleep(cfg.speed);
        

    }
   
    std::cout << "========================================" << std::endl;
    std::cout << "               GAME OVER!               " << std::endl;
    std::cout << "          Your Final Score: " << score * (110 - cfg.speed) << std::endl;
    std::cout << "========================================" << std::endl;
 
    return 0;
}
