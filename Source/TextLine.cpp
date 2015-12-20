/*
 * TextLine.cpp
 *
 *  Created on: 19 дек. 2015 г.
 *      Author: Cherkasov A.V.
 */

#include "../Headers/TextLine.h"

TextLine::TextLine(int id, int width, int height, int margin_bottom, int space){
	this->id = id;
	this->width_parent = width;
	this->width = 0;
	this->height = height;
	this->margin_bottom = margin_bottom;
	this->space = space;
	this->position_y = id*15 + 10;

}

void TextLine::addWordBlock(WordBlock word_block){
	word_block.setPosition(this->width, this->position_y);
	this->word_block_list.push_back(word_block);
	this->width += word_block.getWidth() + this->space;
	std::cout << this->width << std::endl;
}

int TextLine::getHeight() const {
	return height;
}

void TextLine::setHeight(int height) {
	this->height = height;
}

int TextLine::getId() const {
	return id;
}

void TextLine::setId(int id) {
	this->id = id;
}

int TextLine::getMarginBottom() const {
	return margin_bottom;
}

void TextLine::setMarginBottom(int marginBottom) {
	margin_bottom = marginBottom;
}

int TextLine::getWidth() const {
	return width;
}

void TextLine::setWidth(int realWidth) {
	width = realWidth;
}

int TextLine::getSpace() const {
	return space;
}

void TextLine::setSpace(int space) {
	this->space = space;
}
