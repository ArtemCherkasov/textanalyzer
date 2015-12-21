/*
 * TextField.cpp
 *
 *  Created on: 19 дек. 2015 г.
 *      Author: artemcherkasov
 */
#include "../Headers/TextField.h"

int TextField::getHeight() const {
	return height;
}

void TextField::setHeight(int height) {
	this->height = height;
}

int TextField::getWidth() const {
	return width;
}

void TextField::setWidth(int width) {
	this->width = width;
}

TextField::TextField(int width, int height, sf::RenderWindow *window){
	this->width = width;
	this->height = height;
	this->window = window;
	this->text_line_index = 0;
	this->text_line_list.push_back(*(new TextLine(this->text_line_index,this->width, this->height, 10, 10)));
	if(!font.loadFromFile("/home/artemcherkasov/couriernew.ttf")){
		//printf("load font from file is error");
	}
}

void TextField::draw(int position_y){
	sf::CircleShape shape(150.f);
	shape.setFillColor(sf::Color::Green);
	//this->window->draw(shape);

	//***********
	int id = (position_y - 10)/18;
	int size = this->text_line_list.size();
	for(int i = id; i < (id + 100); ++i){
		int size_line = this->text_line_list[i].word_block_list.size();
		for (int j = 0; j < size_line; ++j){
			//std::cout << this->text_line_list[i].word_block_list[j].getWord() << std::endl;
			//this->window->draw(this->text_line_list[i].word_block_list[j].getRectangle());
			this->window->draw(this->text_line_list[i].word_block_list[j].getTextSfml());
		}
	}
}

void TextField::loadText(){

	this->text_loader = new TextLoader("/home/artemcherkasov/harry_full.txt");

	for(int i = 0; i < this->text_loader->getCountWords(); ++i){
		this->toTextLine(this->text_loader->getWord(i));
	}
}

void TextField::toTextLine(std::string word){

	//this->text_line_list.push_back(text_line);
	WordBlock *word_block = new WordBlock(word, &this->font);
	if (((*word_block).getWidth() + this->text_line_list[this->text_line_index].getWidth()) > this->width){
		++this->text_line_index;
		this->text_line_list.push_back(*(new TextLine(this->text_line_index,this->width, this->height, 10, 10)));
	}
	this->text_line_list[this->text_line_index].addWordBlock(*word_block);
}