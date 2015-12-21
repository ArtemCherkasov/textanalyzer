#include <SFML/Graphics.hpp>
#include "Headers/TextField.h"

#define WIDTH 1024
#define HEIGHT 768

int main()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML works!");
    sf::View view(sf::FloatRect(0, 0, WIDTH, HEIGHT));
    sf::CircleShape shape(150.f);
    sf::Clock clock;
    shape.setFillColor(sf::Color::Green);
    TextField *text_field = new TextField(WIDTH, HEIGHT, &window);
    text_field->loadText();
    float time_count = 0;
    int m = 0;

    while (window.isOpen())
    {
        sf::Event event;
        sf::Time time = clock.restart();
        time_count += time.asSeconds();
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();
            //sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
            //window.setView(sf::View(visibleArea));
        }

		// window.draw(shape);
		if (time_count > 0.05){
			time_count = 0.0;
			window.clear(sf::Color::White);
			text_field->draw(m);
			view.move(0, 1);
			//view.rotate(2);
			window.setView(view);
			window.display();
			if (m < 500){
				++m;
			} else {
				m = 0;
			}
		}

    }
    return 0;
}
