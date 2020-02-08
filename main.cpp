#include <SFML/Graphics.hpp>
#include "Board.h"
#include <unistd.h>
#include "Snake.h"
#include "snakeView.h"
#include "controllerAndEngine.h"
#include <cstdlib>
#include <iostream>
using namespace std;



int main() {

    srand(time(NULL));
    sf::ContextSettings settings;
    settings.antialiasingLevel=16;

    sf::RenderWindow win(sf::VideoMode(787, 527), "SNAKE",sf::Style::Default,settings);
    win.setFramerateLimit(60);

    Board board;
    Snake S(board);
    snakeView sv(board);
    controllerAndEngine sc(S);

    while (win.isOpen()) {
        sf::Event event;
        while (win.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                win.close();

        }
        sc.runEngine(event);

        win.clear(sf::Color(144,144,144,255));

        sv.draw(win);

        win.display();
    }

    return EXIT_SUCCESS;
}