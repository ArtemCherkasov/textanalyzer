/*
 * ContextMenu.cpp
 *
 *  Created on: 17 марта 2016 г.
 *      Author: artemcherkasov
 */

#include "../Headers/ContextMenu.h"

ContextMenu::ContextMenu(int width, int height, sf::RenderWindow *window){
	this->width = width;
	this->height = height;
	this->window = window;
	this->x = 0;
	this->y = 0;
}

void ContextMenu::draw(){
	if (visible){
		this->menu.setPosition(sf::Vector2f(this->x, this->y));
		this->menu.setSize(sf::Vector2f(this->width, this->height));
		this->menu.setFillColor(sf::Color::Cyan);
		this->window->draw(this->menu);
	}
}

void ContextMenu::setCoordinates(int x, int y){
	if (!this->mouse_cliked){
		this->x = x;
		this->y = y;
		this->mouse_cliked = true;
	}

}

void ContextMenu::setVisible(bool visible){
	this->visible = visible;
}

void ContextMenu::setMouseCliked(bool mouse_cliked){
	this->mouse_cliked = mouse_cliked;
}

bool ContextMenu::isClicked(int x, int y){
	return (x >= this->x && x <= this->x+this->width && y >= this->y && y <= this->y + this->height);
}
