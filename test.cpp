
#include <SFML/Graphics.hpp>

int main( int argc, char** argv )
{
    sf::RenderWindow appWindow( sf::VideoMode( 1000, 10, 32 ), "App" );
    sf::Event appEvent;

    while ( appWindow.isOpen() )
    {
        while ( appWindow.pollEvent( appEvent ) )
        {
            if ( appEvent.type == sf::Event::Closed )
                appWindow.close();
        }
        sf::CircleShape shape(50);
        shape.setFillColor(sf::Color(150, 50, 250));

// set a 10-pixel wide orange outline
        shape.setOutlineThickness(10);
        shape.setOutlineColor(sf::Color(250, 150, 100));

        appWindow.clear();
        appWindow.display();
    }

    return 0;
}