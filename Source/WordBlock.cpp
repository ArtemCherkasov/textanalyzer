/*
 * WordBlock.cpp
 *
 *  Created on: 19 дек. 2015 г.
 *      Author: artemcherkasov
 */

#include "../Headers/WordBlock.h"

const std::string& WordBlock::getWord() const {
	return word;
}

void WordBlock::setWord(const std::string& word) {
	this->word = word;
}

void WordBlock::addWord(std::string word, sf::Font *font){
	this->word = word;
	this->size = this->word.size();
	this->font = font;
}

WordBlock::WordBlock(std::string word, sf::Font *font, bool block){
	this->word = word;
	this->font = font;
	this->text_sfml.setFont(*this->font);
	this->text_sfml.setString(this->word);
	this->text_sfml.setCharacterSize(CHARACTER_SIZE);
	this->text_sfml.setColor(sf::Color::Black);
	this->text_sfml.setStyle(sf::Text::Regular);
	this->rectangle.setFillColor(sf::Color::Red);
	this->size = this->word.size();
	this->width = this->text_sfml.getLocalBounds().width;
	this->block = block;
}

const sf::RectangleShape WordBlock::getRectangle(){
	return rectangle;
}

const sf::Text WordBlock::getTextSfml() {
	return text_sfml;
}

void WordBlock::setPosition(float x, float y){
	this->text_sfml.setPosition(x ,y);
	this->rectangle.setPosition(x - 2, y + 2);
	this->rectangle.setSize(sf::Vector2f(this->width+6, 16));
}

bool WordBlock::getBlock(){
	return this->block;
}

int WordBlock::getWidth(){
	return this->width;
}

void WordBlock::draw(){

}

WordBlock::WordBlock(){

}
