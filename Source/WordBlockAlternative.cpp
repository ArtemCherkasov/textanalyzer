/*
 * WordBlockAlternative.cpp
 *
 *  Created on: 25 марта 2016 г.
 *      Author: artemcherkasov
 */

#include "../Headers/WordBlockAlternative.h"

WordBlockAlternative::WordBlockAlternative(std::string word, sf::Font *font, int margin_bottom, int margin_left){
	this->word_string = word;
	this->word.setFont(*font);
	this->word.setString(word);
	this->word.setCharacterSize(CHARACTER_SIZE);
	this->word.setColor(sf::Color::Black);
	this->word.setStyle(sf::Text::Regular);
	this->width = this->word.getLocalBounds().width;
	this->height = this->word.getLocalBounds().height;
	this->margin_bottom = margin_bottom;
	this->margin_left = margin_left;
}

void WordBlockAlternative::setPosition(int x, int y){
	this->x = x;
	this->y = y;
	this->word.setPosition(x, y);
	this->rectangle.setFillColor(sf::Color::Red);
	this->rectangle_x = x - 2;
	this->rectangle_y = y;
	this->rectangle_width = this->width + 4;
	this->rectangle_height = this->height + 8;
	this->rectangle.setPosition(x - 2, y);
	this->rectangle.setSize(sf::Vector2f(this->rectangle_width, this->rectangle_height));
}

int WordBlockAlternative::getHeight() const {
	return height;
}

int WordBlockAlternative::getMarginBottom() const {
	return margin_bottom;
}

int WordBlockAlternative::getMarginLeft() const {
	return margin_left;
}

int WordBlockAlternative::getWidth() const {
	return width;
}

const sf::Text& WordBlockAlternative::getWord() const {
	return word;
}

const sf::RectangleShape& WordBlockAlternative::getRectangle() const {
	return rectangle;
}

int WordBlockAlternative::getRectangleHeight() const {
	return rectangle_height;
}

int WordBlockAlternative::getRectangleWidth() const {
	return rectangle_width;
}

int WordBlockAlternative::getRectangleX() const {
	return rectangle_x;
}

int WordBlockAlternative::getRectangleY() const {
	return rectangle_y;
}

bool WordBlockAlternative::isBlock() const {
	return block;
}

void WordBlockAlternative::setBlock(bool block) {
	this->block = block;
}

const std::string& WordBlockAlternative::getWordString() const {
	return word_string;
}
