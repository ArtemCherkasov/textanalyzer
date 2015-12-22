/*
 * WordBlock.h
 *
 *  Created on: 19 дек. 2015 г.
 *      Author: artemcherkasov
 */

#ifndef HEADERS_WORDBLOCK_H_
#define HEADERS_WORDBLOCK_H_

#include <string>
#include "SFML/Graphics.hpp"

#define CHARACTER_SIZE 14

class WordBlock {
private:
	int width;
	int size;
	std::string word;
	sf::Text text_sfml;
	sf::RectangleShape rectangle;
	sf::Font *font;
	bool block;
public:
	WordBlock();
	WordBlock(std::string word, sf::Font *font, bool block);
	void addWord(std::string word, sf::Font *font);
	const std::string& getWord() const;
	void setWord(const std::string& word);
	void draw();
	int getWidth();
	const sf::Text getTextSfml();
	const sf::RectangleShape getRectangle();
	void setPosition(float x, float y);
	bool getBlock();
};

#endif /* HEADERS_WORDBLOCK_H_ */
