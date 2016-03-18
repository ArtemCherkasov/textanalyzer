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
	int x;
	int y;
	int width;
	int height;
	int size;

	sf::Text text_sfml;
	sf::RectangleShape rectangle;
	sf::Font *font;
	bool block;
public:
	std::string word;
	WordBlock();
	WordBlock(std::string word, sf::Font *font, bool block);
	void addWord(std::string word, sf::Font *font);
	std::string getWord();
	void setWord(const std::string& word);
	void draw();
	const sf::Text getTextSfml();
	const sf::RectangleShape getRectangle();
	void setPosition(float x, float y);
	bool getBlock();
	int getX();
	int getY();
	int getWidth();
	int getHeigth();
};

#endif /* HEADERS_WORDBLOCK_H_ */
