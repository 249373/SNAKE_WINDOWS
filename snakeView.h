//
// Created by konrad on 09.05.19.
//

#ifndef UNTITLED2_SNAKEVIEW_H
#define UNTITLED2_SNAKEVIEW_H


#include <SFML/Graphics.hpp>
#include "Board.h"

class snakeView {

    Board &board;
    sf::Text ScoreText;
    sf::Text Score;
    sf::RectangleShape RectangleShape;
    int RectSize=13;
    sf::Font Font;
    sf::Text ChooseDir;




public:
    snakeView(Board &board);
    void draw(sf::RenderWindow & win);
};


#endif //UNTITLED2_SNAKEVIEW_H
