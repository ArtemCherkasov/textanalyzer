/*
 * ContextMenu.h
 *
 *  Created on: 17 марта 2016 г.
 *      Author: artemcherkasov
 */

#ifndef HEADERS_CONTEXTMENU_H_
#define HEADERS_CONTEXTMENU_H_

#include <iostream>
#include "SFML/Graphics.hpp"
#include "TextField.h"
#include <vector>
#include <exception>

class ContextMenu {
private:
	int width;
	int height;
	int x;
	int y;
	int x_right;
	int x_left;
	int y_above;
	int y_belove;
	sf::RenderWindow *window;
	sf::RectangleShape menu;
	bool visible = false;
	bool mouse_cliked = false;
	TextField *text_field;
public:
	ContextMenu(int width, int height, sf::RenderWindow *window, TextField *text_field);
	void draw();
	void setVisible(bool);
	void setCoordinates(int x, int y);
	void setMouseCliked(bool);
	bool isClicked(int x, int y);
	void drawSomethingLines();
};

#endif /* HEADERS_CONTEXTMENU_H_ */
