//
// Created by konrad on 08.05.19.
//

#ifndef UNTITLED2_SNAKE_H
#define     UNTITLED2_SNAKE_H

#include <queue>
#include <unistd.h>
#include "Board.h"

enum Direct {UP,DOWN,LEFT,RIGHT};

class Snake {
    int HeadX;
    int HeadY;
    Direct Dir;
    std::queue <int> HistoryX;
    std::queue <int> HistoryY;
    Board &board;

public:
    Snake(Board&);
    void moveSnake();
    void growSnake();
    void setDir(Direct);
    void collision();
    GameState getGameState(){return board.getGameState();}
    void setGameState(GameState gm) {board.setGameState(gm);}
    void setApple(){ board.setApple();}

};


#endif //UNTITLED2_SNAKE_H
