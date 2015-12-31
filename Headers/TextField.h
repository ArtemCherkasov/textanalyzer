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
#include "../Headers/FullDictionary.h"
#include "../Headers/FileSystem.h"
#include "../Headers/LexiconHandle.h"
#include <vector>
#include <string>
#include <algorithm>

#define PATH_TO_FONT "/Store/couriernew.ttf"
#define PATH_TO_TEXT "/Store/harry.txt"
#define PATH_TO_DICTIONARY "/Store/fulldictionary.txt"

class TextField{

private:
	int width;
	int height;
	int move_position;
	sf::Font font;
	std::vector<TextLine> text_line_list;
	int text_line_index;
	sf::RenderWindow *window;
	void toTextLine(std::string word, bool block);
	TextLoader *text_loader;
	sf::Text info_text;
	FullDictionary *full_dictionary;
	FileSystem *file_system;
	LexiconHandle *lexiconHandle;
	bool load;
public:
	TextField(int width, int height, sf::RenderWindow *window);
	void loadText();
	int getHeight() const;
	void setHeight(int height);
	int getWidth() const;
	void setWidth(int width);
	void draw(int position_y);
	int getMovePosition();
	bool isLoad();
};

#endif /* HEADERS_TEXTFIELD_H_ */
