//
// Created by konrad on 09.05.19.
//

#include "controllerAndEngine.h"

controllerAndEngine::controllerAndEngine(Snake &s):snake(s) {

}

void controllerAndEngine::runEngine(sf::Event &event) {
    if (snake.getGameState() == START) {
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Right) {
                Dir=RIGHT;
                snake.setGameState(RUNNING);
            }
            if (event.key.code == sf::Keyboard::Left) {
                Dir=LEFT;
                snake.setGameState(RUNNING);
            }
            if (event.key.code == sf::Keyboard::Down) {
                Dir=DOWN;
                snake.setGameState(RUNNING);
            }
            if (event.key.code == sf::Keyboard::Up) {
                Dir=UP;
                snake.setGameState(RUNNING);
            }
        }
    }
    if (snake.getGameState() == RUNNING)
    {   if(IsFirstApple==false)
        {
            snake.setApple();
            IsFirstApple=true;
        }
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Right) {
                Dir=RIGHT;
            }
            if (event.key.code == sf::Keyboard::Left) {
                Dir=LEFT;
            }
            if (event.key.code == sf::Keyboard::Down) {
                Dir=DOWN;
            }
            if (event.key.code == sf::Keyboard::Up) {
                Dir=UP;
            }
        }

         if (MoveCLock.getElapsedTime() > sf::milliseconds(50)) {
             snake.setDir(Dir);
             snake.moveSnake();
             snake.collision();
             MoveCLock.restart();
        }
    }

}
