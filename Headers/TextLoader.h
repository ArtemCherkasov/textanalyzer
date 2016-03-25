/*
 * TextLoader.h
 *
 *  Created on: 21 дек. 2015 г.
 *      Author: artemcherkasov
 */

#ifndef HEADERS_TEXTLOADER_H_
#define HEADERS_TEXTLOADER_H_

#include "SFML/Graphics.hpp"
#include "WordBlockAlternative.h"
#include <string>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>
#include <map>

#define CHARACTER_SIZE 14

class TextLoader{
private:
	std::string file_name;
	std::string text;
	std::vector<std::string> words;
	sf::Text sf_text;
	std::vector<WordBlockAlternative> word_block_list;
	int count_words;
public:
	TextLoader(std::string file_name, sf::Font *font);
	int getCountWords() const;
	std::vector<std::string> getWords();
	std::string getWord(int i);
	const std::vector<WordBlockAlternative> &getWordBlockList() const;
	void setPosition(int index, int x, int y);
};



#endif /* HEADERS_TEXTLOADER_H_ */
