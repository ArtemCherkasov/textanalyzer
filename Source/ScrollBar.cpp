/*
 * ScrollBar.cpp
 *
 *  Created on: 21 дек. 2015 г.
 *      Author: artemcherkasov
 */

#include "../Headers/ScrollBar.h"

ScrollBar::ScrollBar(int width_client, int higth_client_window, sf::RenderWindow *window){
	this->width_client = width_client;
	this->hight = higth_client_window - 100;
	this->window = window;
	this->line.setSize(sf::Vector2f(1, this->hight));
	this->line.setPosition(sf::Vector2f(this->width_client - 50, 50));
	this->line.setFillColor(sf::Color::Black);
	this->circle.setRadius(CIRCLE_RADIUS);
	this->x = this->width_client - 50 - CIRCLE_RADIUS;
	this->y = 50 - CIRCLE_RADIUS;
	this->circle.setPosition(sf::Vector2f( this->x, this->y));
	this->circle.setFillColor(sf::Color::White);
	this->circle.setOutlineThickness(1);
	this->circle.setOutlineColor(sf::Color::Black);
}

void ScrollBar::draw(){
	this->window->draw(line);
	this->window->draw(circle);
}

bool ScrollBar::isPressed(sf::Vector2i position){
	return (((this->x) < position.x) && ((this->x + 2*CIRCLE_RADIUS) > position.x) && ((this->y) < position.y) && ((this->y + 2*CIRCLE_RADIUS) > position.y));
}

void ScrollBar::setPosition(int y){
	this->y = y - CIRCLE_RADIUS;
	this->circle.setPosition(sf::Vector2f(this->x, y));
}
