#include <SFML/Graphics.hpp>
#include "Headers/TextField.h"

#define WIDTH 800
#define HEIGHT 600

int main()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML works!");
    sf::CircleShape shape(150.f);
    sf::Clock clock;
    shape.setFillColor(sf::Color::Green);
    TextField *text_field = new TextField(WIDTH, HEIGHT, &window);
    text_field->loadText();

    while (window.isOpen())
    {
        sf::Event event;
        sf::Time time = sf::seconds(1.1f);
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        // window.draw(shape);
        text_field->draw();
        window.display();
    }
    return 0;
}
