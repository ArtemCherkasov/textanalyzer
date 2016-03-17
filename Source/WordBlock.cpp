/*
 * WordBlock.cpp
 *
 *  Created on: 19 дек. 2015 г.
 *      Author: artemcherkasov
 */

#include "../Headers/WordBlock.h"

void WordBlock::setWord(const std::string& word) {
	this->word = word;
}

void WordBlock::addWord(std::string word, sf::Font *font){
	this->word = word;
	this->size = this->word.size();
	this->font = font;
}

WordBlock::WordBlock(std::string word, sf::Font *font, bool block){
	//this->word = word;
	this->word.append(word);
	this->font = font;
	this->text_sfml.setFont(*this->font);
	this->text_sfml.setString(this->word);
	this->text_sfml.setCharacterSize(CHARACTER_SIZE);
	this->text_sfml.setColor(sf::Color::Black);
	this->text_sfml.setStyle(sf::Text::Regular);
	this->rectangle.setFillColor(sf::Color::Red);
	this->size = this->word.size();
	this->width = this->text_sfml.getLocalBounds().width + 6;
	this->height = 16;
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
	this->x = x - 2;
	this->y = y + 2;
	this->rectangle.setSize(sf::Vector2f(this->width, this->height));
}

bool WordBlock::getBlock(){
	return this->block;
}

int WordBlock::getWidth(){
	return this->width;
}

int WordBlock::getHeigth(){
	return this->height;
}

int WordBlock::getX(){
	return this->x;
}

int WordBlock::getY(){
	return this->y;
}

void WordBlock::draw(){

}

std::string WordBlock::getWord(){
	return this->word;
}

WordBlock::WordBlock(){

}
