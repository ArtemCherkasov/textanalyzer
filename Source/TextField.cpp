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
	this->load = false;
	this->width = width;
	this->height = height;
	this->window = window;
	this->text_line_index = 0;
	this->text_line_list.push_back(*(new TextLine(this->text_line_index,this->width, this->height, 10, 10)));
	if(!font.loadFromFile(PATH_TO_FONT)){
		//printf("load font from file is error");
	}
}

void TextField::draw(int position_y){
	sf::CircleShape shape(150.f);
	shape.setFillColor(sf::Color::Green);
	//this->window->draw(shape);

	//***********
	//int id = (position_y - 10)/18;
	int id = position_y*this->text_line_list.size()/100;
	this->move_position = id*18;
	int size = this->text_line_list.size();
	for(int i = id; i < (id + 50); ++i){
		int size_line = this->text_line_list[i].word_block_list.size();
		for (int j = 0; j < size_line; ++j){
			//std::cout << this->text_line_list[i].word_block_list[j].getWord() << std::endl;
			//this->window->draw(this->text_line_list[i].word_block_list[j].getRectangle());
			int y = this->text_line_list[i].word_block_list[j].getTextSfml().getPosition().y;
			this->text_line_list[i].word_block_list[j].setPosition(this->text_line_list[i].word_block_list[j].getTextSfml().getPosition().x, this->text_line_list[i].word_block_list[j].getTextSfml().getPosition().y - id*18 - 10);
			if(this->text_line_list[i].word_block_list[j].getBlock()){
				this->window->draw(this->text_line_list[i].word_block_list[j].getRectangle());
			}
			this->window->draw(this->text_line_list[i].word_block_list[j].getTextSfml());
			this->text_line_list[i].word_block_list[j].setPosition(this->text_line_list[i].word_block_list[j].getTextSfml().getPosition().x, y);
		}
	}
}

void TextField::loadText(){
	std::map<std::string, int> words_map;
	this->text_loader = new TextLoader(PATH_TO_TEXT);
	bool block;

	for(int i = 0; i < this->text_loader->getCountWords(); ++i){
		std::string w = this->text_loader->getWord(i);
		std::transform(w.begin(), w.end(), w.begin(), ::tolower);
		if (!words_map.count(w)){
			words_map.insert(std::pair<std::string, int>(w, 1));
			block = true;
		} else {
			words_map.find(w) = ++words_map.find(w);
			block = false;
		}
		this->toTextLine(this->text_loader->getWord(i), block);
	}
	this->load = true;

}

void TextField::toTextLine(std::string word, bool block){

	//this->text_line_list.push_back(text_line);
	WordBlock *word_block = new WordBlock(word, &this->font, block);
	if (((*word_block).getWidth() + this->text_line_list[this->text_line_index].getWidth()) > this->width){
		++this->text_line_index;
		this->text_line_list.push_back(*(new TextLine(this->text_line_index,this->width, this->height, 10, 10)));
	}
	this->text_line_list[this->text_line_index].addWordBlock(*word_block);
}

bool TextField::isLoad(){
	return this->load;
}
