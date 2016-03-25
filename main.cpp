#include <SFML/Graphics.hpp>
#include "Headers/TextField.h"
#include "Headers/ScrollBar.h"
#include "Headers/ContextMenu.h"
#include <iostream>
#include <pthread.h>

#define WIDTH 1024
#define HEIGHT 768

struct thread_data{
	int  thread_id;
	char *message;
};

int main()
{
	std::cout << "second thread" << std::endl;
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Text analyzer");
	TextField *text_field = new TextField(WIDTH - 100, HEIGHT, &window);
	sf::View view(sf::FloatRect(0, 0, WIDTH, HEIGHT));
	sf::CircleShape shape(150.f);
	sf::Clock clock;
	shape.setFillColor(sf::Color::Green);
	//text_field = new TextField(WIDTH - 100, HEIGHT, &window);
	ScrollBar *scroll_bar = new ScrollBar(WIDTH, HEIGHT, &window);
	std::cout << "adress window object " << &window << " size of " << sizeof(window)<< std::endl;
	std::cout << "adress textfield object " << text_field << " size of " << sizeof(text_field)<< std::endl;
	ContextMenu *context_menu = new ContextMenu(150, 220, &window, text_field);
	std::cout << "text line size: " << text_field->text_line_list.size() << std::endl;
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
			sf::Vector2i position = sf::Mouse::getPosition(window);
			if (event.type == sf::Event::Closed) window.close();

			if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
				if (scroll_bar->isPressed(position) && !scroll_bar->isClicked()){
					scroll_bar->setClicked(true);
					scroll_bar->setDelta(position.x, position.y);
				}

				if (scroll_bar->isClicked()){
					scroll_bar->setPosition(position.y);
				}

				if (!context_menu->isClicked(position.x, position.y)){
					context_menu->setVisible(false);
					context_menu->setMouseCliked(false);
				}

			} else {
				scroll_bar->setClicked(false);
			}

			if (sf::Event::MouseButtonReleased){
				if(event.mouseButton.button == sf::Mouse::Right){
					if (!context_menu->isClicked(position.x, position.y)){
						context_menu->setVisible(true);
						context_menu->setMouseCliked(false);
					}
				}
			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Right)){
				if (!context_menu->isClicked(position.x, position.y)){
					context_menu->setCoordinates(position.x, position.y);
				}
			}

		}

		window.clear(sf::Color::White);
		if (text_field->text_line_list.size() > 1) {
			text_field->draw(scroll_bar->getPositionProcent());
		}

		/*
		if (words_map.size() > 0) {
			FileSystem *file_system = new FileSystem();
			sf::Text text;
			sf::Font font;
			font.loadFromFile(file_system->getCurrentPath() + PATH_TO_FONT);
			text.setString("Loaded");
			text.setFont(font);
			text.setPosition(20, 20);
			text.setColor(sf::Color::Black);
			window.draw(text);
		}
		*/
		scroll_bar->draw();
		context_menu->draw();
		context_menu->drawSomethingLines();

		window.setView(view);
		window.display();

	}
	return 0;
}
