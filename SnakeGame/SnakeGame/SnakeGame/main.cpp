#include "SnakeList.h"
#include "GameConfig.h"
#include "Draw.h"

int main() {
    GameConfig cfg = loadConfig("config.txt");
    enum eDirection {stop= 0, left, right, up, down};
    eDirection dir = stop;
    SnakeList snake;

    int score = 0;
    int headX = cfg.width / 2;
    int headY = cfg.height / 2;
    return 0;
}
