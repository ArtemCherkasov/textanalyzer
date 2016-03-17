/*
 * ContextMenu.cpp
 *
 *  Created on: 17 марта 2016 г.
 *      Author: artemcherkasov
 */

#include "../Headers/ContextMenu.h"

ContextMenu::ContextMenu(int x, int y, int width, int height, sf::RenderWindow *window){
	this->width = width;
	this->height = height;
	this->x = x;
	this->y = y;
	this->window = window;
}
