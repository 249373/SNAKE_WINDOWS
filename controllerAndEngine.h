//
// Created by konrad on 09.05.19.
//

#ifndef UNTITLED2_CONTROLLERANDENGINE_H
#define UNTITLED2_CONTROLLERANDENGINE_H

#include "Snake.h"
#include <SFML/Graphics.hpp>


class controllerAndEngine {

    Snake &snake;
    sf::Clock MoveCLock;
    bool IsFirstApple=false;
    Direct Dir;
public:
    controllerAndEngine(Snake&);
    void runEngine(sf::Event &event);
};


#endif //UNTITLED2_CONTROLLERANDENGINE_H
