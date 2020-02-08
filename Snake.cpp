//
// Created by konrad on 08.05.19.
//

#include "Snake.h"


Snake::Snake(Board &b): board(b)  {
    HeadX=board.getWidth()/2;
    HeadY=(board.getHeight()/2);
    board.setSnake(HeadX,HeadY);
    }

void Snake::moveSnake() {
    HistoryX.push(HeadX);
    HistoryY.push(HeadY);

    if (Dir == LEFT) {
        HeadX = HeadX - 1;
    }
    if (Dir == RIGHT) {
        HeadX = HeadX + 1;
    }
    if (Dir == UP) {
        HeadY = HeadY - 1;
    }
    if (Dir == DOWN) {
        HeadY = HeadY + 1;
    }
    board.setSnake(HeadX, HeadY);
    board.unsetSnake(HistoryX.front(), HistoryY.front());
    HistoryX.pop();
    HistoryY.pop();
}

void Snake::growSnake()
{
    HistoryX.push(HeadX);
    HistoryY.push(HeadY);

    if(Dir==LEFT)
    {
        HeadX=HeadX-1;
    }
    if(Dir==RIGHT)
    {
        HeadX=HeadX+1;
    }
    if(Dir==UP)
    {
        HeadY=HeadY-1;
    }
    if(Dir==DOWN)
    {
        HeadY=HeadY+1;
    }
    board.setSnake(HeadX,HeadY);

}

void Snake::setDir(Direct d) {
    if(Dir==UP and d==DOWN)return;
    if(Dir==DOWN and d==UP)return;
    if(Dir==RIGHT and d==LEFT)return;
    if(Dir==LEFT and d==RIGHT)return;
    Dir=d;

}

void Snake::collision() {
    if(board.collisionApple()==1)growSnake();
    if(board.collisionWall()==1)board.setGameState(FINISHED);

}
