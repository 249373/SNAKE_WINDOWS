//
// Created by konrad on 08.05.19.
//

#ifndef UNTITLED2_BOARD_H
#define UNTITLED2_BOARD_H

#include <iostream>
#include <sstream>
#include <string>

enum GameState {START,RUNNING, FINISHED};


struct Field
{
    bool hasApple=0;
    bool hasSnake=0;
    bool isWall=0;
};

class Board {
    int Width;
    int Height;
    Field Tab[60][40];
    GameState gameState=START;
    int Score=0;
public:
    Board();
    bool collisionWall();
    bool collisionApple();
    void debug()const;
    void setSnake(int x, int y);
    void unsetSnake(int x, int y);
    void setApple();


    std::string getScore();
    GameState getGameState();
    void setGameState(GameState gm);
    int getWidth(){return Width;};
    int getHeight(){return Height;};
    char getFieldInfo(int x,int y)const;
};


#endif //UNTITLED2_BOARD_H
