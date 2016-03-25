/*
 * WordBlockAlternative.h
 *
 *  Created on: 25 марта 2016 г.
 *      Author: artemcherkasov
 */

#ifndef HEADERS_WORDBLOCKALTERNATIVE_H_
#define HEADERS_WORDBLOCKALTERNATIVE_H_

#include "SFML/Graphics.hpp"
#include <stdio.h>

#define CHARACTER_SIZE 14

class WordBlockAlternative{
private:
	int x;
	int y;
	int rectangle_x;
	int rectangle_y;
	int rectangle_width;
	int rectangle_height;
	int height;
	int width;
	int margin_bottom;
	int margin_left;
	std::string word_string;
	sf::Text word;
	sf::RectangleShape rectangle;
	bool block;
public:
	WordBlockAlternative(std::string word, sf::Font *font, int margin_bottom, int margin_left);
	int getHeight() const;
	int getMarginBottom() const;
	int getMarginLeft() const;
	int getWidth() const;
	const sf::Text& getWord() const;
	const sf::RectangleShape& getRectangle() const;
	void setPosition(int x, int y);
	int getRectangleHeight() const;
	int getRectangleWidth() const;
	int getRectangleX() const;
	int getRectangleY() const;
	const std::string& getWordString() const;
	bool isBlock() const;
	void setBlock(bool block);
};

#endif /* HEADERS_WORDBLOCKALTERNATIVE_H_ */
