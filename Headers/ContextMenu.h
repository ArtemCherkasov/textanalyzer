/*
 * ContextMenu.h
 *
 *  Created on: 17 марта 2016 г.
 *      Author: artemcherkasov
 */

#ifndef HEADERS_CONTEXTMENU_H_
#define HEADERS_CONTEXTMENU_H_

#include "SFML/Graphics.hpp"

class ContextMenu {
private:
	int width;
	int height;
	int x;
	int y;
	sf::RenderWindow *window;
public:
	ContextMenu(int x, int y, int width, int height, sf::RenderWindow *window);
	int getX();
	void setX(int x);
	int getY();
	void setY(int y);
};

#endif /* HEADERS_CONTEXTMENU_H_ */
