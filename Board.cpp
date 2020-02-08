//
// Created by konrad on 08.05.19.
//

#include "Board.h"

Board::Board(): Width(60), Height(40)
{
    for(int x=0 ; x<Width ; x++)
    {
        if(x==0 or x==Width-1)
        {
            for(int y=0; y<Height ; y++)
            {
                Tab[x][y].isWall=1;

            }
        }

        if(x>0 and x<Width-1)
        {
            Tab[x][0].isWall=1;
            Tab[x][Height-1].isWall=1;
        }
    }
}

void Board::debug() const {

        for(int y=0; y<Height; y++)
        {
            for(int x=0; x<Width; x++)
            {

                if(Tab[x][y].hasSnake==1)std::cout<<"S";
                else std::cout<<".";

                if(Tab[x][y].hasApple==1)std::cout<<"A";
                else std::cout<<".";

                if(Tab[x][y].isWall==1)std::cout<<"W";
                else std::cout<<".";

                std::cout<<"]";
            }
            std::cout<<std::endl;
        }
}


void Board::setSnake(int x, int y)
{   if(Tab[x][y].hasSnake==1)gameState=FINISHED;
    Tab[x][y].hasSnake=1;
}


GameState Board::getGameState() {
    return gameState;
}

void Board::unsetSnake(int x, int y) {
    Tab[x][y].hasSnake=0;
}

void Board::setGameState(GameState gm) {
    gameState=gm;
    return;

}

char Board::getFieldInfo(int x, int y) const{

    if(x>Width or y>Height)return'#';
    if(Tab[x][y].isWall==1)return'W';
    if(Tab[x][y].hasSnake==1)return'S';
    if(Tab[x][y].hasApple==1)return'A';
    return'E';
}

void Board::setApple() {
    int x= rand()%Width;
    int y =rand()%Height;
    if(Tab[x][y].hasSnake==0 and Tab[x][y].isWall==0)
        Tab[x][y].hasApple=1;
    else setApple();
}

bool Board::collisionApple() {
    for(int y=0; y<Height; y++)
    {
        for(int x=0; x<Width; x++)
        {
            if(Tab[x][y].hasApple==1 and Tab[x][y].hasSnake==1)
            {
                Tab[x][y].hasApple=0;
                setApple();
                Score++;
                return true;
            }
        }
    }
    return false;
}

std::string Board::getScore() {
    std::stringstream ss;
    ss<<Score;
    std::string str= ss.str();
    return str;
}

bool Board::collisionWall() {
    for(int y=0; y<Height; y++) {
        for (int x = 0; x < Width; x++)
        {
            if(Tab[x][y].isWall==1 and Tab[x][y].hasSnake==1) return true;
        }
    }
    return false;
}




