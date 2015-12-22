/*
 * ScrollBar.cpp
 *
 *  Created on: 21 дек. 2015 г.
 *      Author: artemcherkasov
 */

#include "../Headers/ScrollBar.h"

ScrollBar::ScrollBar(int width_client, int higth_client_window, sf::RenderWindow *window){
	this->position_procent = 0;
	this->clicked = false;
	this->width_client = width_client;
	this->hight = higth_client_window - 100;
	this->window = window;
	this->line.setSize(sf::Vector2f(1, this->hight));
	this->line.setPosition(sf::Vector2f(this->width_client - 50, 50));
	this->setPosition_0(50);
	this->setPosition_100(higth_client_window - 50);
	this->line.setFillColor(sf::Color::Black);
	this->circle.setRadius(CIRCLE_RADIUS);
	this->x_center = this->width_client - 50;
	this->y_center = 50;
	this->x_shape = this->x_center - CIRCLE_RADIUS;
	this->y_shape = this->y_center - CIRCLE_RADIUS;
	this->circle.setPosition(sf::Vector2f( this->x_shape, this->y_shape));
	this->circle.setFillColor(sf::Color::White);
	this->circle.setOutlineThickness(1);
	this->circle.setOutlineColor(sf::Color::Black);
}

void ScrollBar::draw(){
	this->window->draw(line);
	this->window->draw(circle);
}

bool ScrollBar::isPressed(sf::Vector2i position){
	return (((this->x_center - CIRCLE_RADIUS) < position.x) && ((this->x_center + CIRCLE_RADIUS) > position.x) && ((this->y_center - CIRCLE_RADIUS) < position.y) && ((this->y_center + CIRCLE_RADIUS) > position.y));
}

void ScrollBar::setPosition(int y){
	//this->y = y - CIRCLE_RADIUS;

	if ((y + this->y_delta) < this->position_0){
		this->y_shape = this->position_0;
	} else if ((y + this->y_delta) > this->position_100){
		this->y_shape = this->position_100;
	} else {
		this->y_shape = y + this->y_delta;
	}
	this->y_center = this->y_shape + CIRCLE_RADIUS;
	this->position_procent = 100.0 - (100.0 * ( (this->position_100 - this->y_shape)/ (this->position_100 - this->position_0)));
	this->circle.setPosition(sf::Vector2f(this->x_shape, this->y_shape));
}

bool ScrollBar::isClicked(){
	return this->clicked;
}

void ScrollBar::setClicked(bool click){
	this->clicked = click;
}

void ScrollBar::setDelta(int x_delta, int y_delta){
	this->x_delta = this->x_shape - x_delta;
	this->y_delta = this->y_shape - y_delta;
}

void ScrollBar::setPosition_0(float position){
	this->position_0 = position - CIRCLE_RADIUS;
}

void ScrollBar::setPosition_100(float position){
	this->position_100 = position - CIRCLE_RADIUS;
}

float ScrollBar::getPosition_0(){
	return this->position_0;
}

float ScrollBar::getPosition_100(){
	return this->position_100;
}

int ScrollBar::getPositionProcent(){
	return this->position_procent;
}
