//
// Created by konrad on 09.05.19.
//

#include "snakeView.h"

snakeView::snakeView(Board &board):board(board) {



    if (!Font.loadFromFile("Arial.ttf")) {
        abort();
    }
    RectangleShape.setSize(sf::Vector2f(RectSize,RectSize));
    ScoreText.setFont(Font);
    ScoreText.setCharacterSize(50);
    ScoreText.setFillColor(sf::Color(255,215,75,255));
    ScoreText.setPosition(290,50);
    ScoreText.setString("Score :");


    Score.setFont(Font);
    Score.setCharacterSize(50);
    Score.setFillColor(sf::Color(255,215,75,255));
    Score.setPosition(450,50);
    ChooseDir.setPosition(57,50);
    ChooseDir.setString("Choose direction to start the game");
    ChooseDir.setCharacterSize(40);
    ChooseDir.setFillColor(sf::Color(255,215,75,255));
    ChooseDir.setFont(Font);




}

void snakeView::draw(sf::RenderWindow &win) {
    if(board.getGameState()==START)
    {
        win.draw(ChooseDir);
    }
    if(board.getGameState()!=START)
    {
        Score.setString(board.getScore());
        win.draw(Score);
        win.draw(ScoreText);
    }
    for(int y=0 ; y<board.getHeight() ; y++ )
    {
        for(int x=0 ; x<board.getWidth() ; x++)
        {
            RectangleShape.setPosition(3+x*RectSize,3+y*RectSize);

            if((board.getFieldInfo(x,y))=='W')
            {
                RectangleShape.setFillColor(sf::Color::White);
                win.draw(RectangleShape);
            }
            if(board.getFieldInfo(x,y)=='S')
            {
                RectangleShape.setFillColor(sf::Color::Green);
                win.draw(RectangleShape);
            }
            if(board.getFieldInfo(x,y)=='A')
            {
                RectangleShape.setFillColor(sf::Color::Red);
                win.draw(RectangleShape);
            }

        }
    }

}

