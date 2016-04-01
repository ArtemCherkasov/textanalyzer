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
#include "../Headers/TextLoader.h"
#include "../Headers/FullDictionary.h"
#include "../Headers/FileSystem.h"
#include "../Headers/LexiconHandle.h"
#include <vector>
#include <string>
#include <algorithm>

#define PATH_TO_FONT "/Store/couriernew.ttf"
#define PATH_TO_TEXT "/Store/harry.txt"
#define PATH_TO_DICTIONARY "/Store/fulldictionary.txt"
#define PATH_TO_TRANSLATE_DICTIONARY "/Store/translatedictionary.txt"

class TextField{

private:
	int width;
	int height;
	int move_position;
	sf::Font font;
	int text_line_index;
	sf::RenderWindow *window;
	TextLoader *text_loader;
	sf::Text info_text;
	FullDictionary *full_dictionary;
	FileSystem *file_system;
	LexiconHandle *lexiconHandle;
	std::vector< std::pair< std::string, bool > > *ordered_words_list;
	int width_text_column;
	int height_text_column;
	bool load;
	int id_text_line;
	float percent;
public:
	TextField(int width, int height, sf::RenderWindow *window, FileSystem &file_system);
	void loadText();
	int getHeight() const;
	void setHeight(int height);
	int getWidth() const;
	void setWidth(int width);
	void draw(int position_y);
	int getMovePosition() const;
	bool isLoad();
	int getTextLineId() const;
	void setTextColumnParameter();
	std::vector<int> getRangeForDrawField(int percent);
	const TextLoader *getTextLoader() const;
	float getPercent() const;
	sf::Font getFont();
	FullDictionary *getFullDictionary();

};

#endif /* HEADERS_TEXTFIELD_H_ */
