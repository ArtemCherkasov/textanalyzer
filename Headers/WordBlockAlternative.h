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
	int height;
	int width;
	int margin_bottom;
	int margin_left;
	sf::Text word;
	sf::RectangleShape rectangle;
public:
	WordBlockAlternative(std::string word, sf::Font *font, int margin_bottom, int margin_left);
	int getHeight() const;
	int getMarginBottom() const;
	int getMarginLeft() const;
	int getWidth() const;
	const sf::Text& getWord() const;
	const sf::RectangleShape& getRectangle() const;
	void setPosition(int x, int y);
};

#endif /* HEADERS_WORDBLOCKALTERNATIVE_H_ */
