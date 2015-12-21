/*
 * TextField.h
 *
 *  Created on: 19 дек. 2015 г.
 *      Author: artemcherkasov
 */

#ifndef HEADERS_TEXTFIELD_H_
#define HEADERS_TEXTFIELD_H_

#include <iostream>
#include "SFML/Graphics.hpp"
#include "../Headers/TextLine.h"
#include "../Headers/TextLoader.h"
#include "../Headers/WordBlock.h"
#include <vector>
#include <string>

class TextField{

private:
	int width;
	int height;
	sf::Font font;
	std::vector<TextLine> text_line_list;
	int text_line_index;
	sf::RenderWindow *window;
	void toTextLine(std::string word);
	TextLoader *text_loader;
public:
	TextField(int width, int height, sf::RenderWindow *window);
	void loadText();
	int getHeight() const;
	void setHeight(int height);
	int getWidth() const;
	void setWidth(int width);
	void draw(int position_y);
};

#endif /* HEADERS_TEXTFIELD_H_ */
