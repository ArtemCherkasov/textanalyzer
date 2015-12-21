/*
 * ScrollBar.h
 *
 *  Created on: 21 дек. 2015 г.
 *      Author: artemcherkasov
 */

#ifndef HEADERS_SCROLLBAR_H_
#define HEADERS_SCROLLBAR_H_

#include "SFML/Graphics.hpp"

#define CIRCLE_RADIUS 8

class ScrollBar{
private:
	int width_client;
	int hight;
	int x;
	int y;
	sf::RectangleShape line;
	sf::CircleShape circle;
	sf::RenderWindow *window;
public:
	ScrollBar(int width_client, int higth_client_window, sf::RenderWindow *window);
	void draw();
	bool isPressed(sf::Vector2i position);
	void setPosition(int y);
};



#endif /* HEADERS_SCROLLBAR_H_ */
