#include <SFML/Graphics.hpp>
#include "Headers/TextField.h"
#include "Headers/ScrollBar.h"

#define WIDTH 1024
#define HEIGHT 768

int main()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Text analyzer");
    sf::View view(sf::FloatRect(0, 0, WIDTH, HEIGHT));
    sf::CircleShape shape(150.f);
    sf::Clock clock;
    shape.setFillColor(sf::Color::Green);
    TextField *text_field = new TextField(WIDTH - 100, HEIGHT, &window);
    ScrollBar *scroll_bar = new ScrollBar(WIDTH, HEIGHT, &window);

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

            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
				sf::Vector2i position = sf::Mouse::getPosition(window);
				if (scroll_bar->isPressed(position) && !scroll_bar->isClicked()){
					scroll_bar->setClicked(true);
					scroll_bar->setDelta(position.x, position.y);
				}

				if (scroll_bar->isClicked()){
					scroll_bar->setPosition(position.y);
				}

            } else {
            	scroll_bar->setClicked(false);
            }
            if(sf::Mouse::isButtonPressed(sf::Mouse::Right)){

            }
        }

		// window.draw(shape);
		if (time_count > 0.05){
			time_count = 0.0;
			window.clear(sf::Color::White);
			text_field->draw(scroll_bar->getPositionProcent());
			scroll_bar->draw();
			//view.move(0, scroll_bar->getPositionProcent());
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
