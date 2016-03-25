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
	file_system = new FileSystem();
	//std::cout << file_system->getCurrentPath() << std::endl;
	lexiconHandle = new LexiconHandle(file_system->getCurrentPath() + "/Store/Lexicon");
	if(!font.loadFromFile(file_system->getCurrentPath() + PATH_TO_FONT)){
		//printf("load font from file is error");
	}
	ordered_words_list = new std::vector< std::pair< std::string, bool > >;
}

void TextField::draw(int position_y){
	/*
	sf::CircleShape shape(150.f);
	shape.setFillColor(sf::Color::Green);
	this->id_text_line = position_y*this->text_line_list.size()/100;
	this->move_position = this->id_text_line*18;
	for(int i = this->id_text_line; i < (this->id_text_line + 50); ++i){
		int size_line = this->text_line_list[i].word_block_list.size();
		for (int j = 0; j < size_line; ++j){
			int y = this->text_line_list[i].word_block_list[j].getTextSfml().getPosition().y;
			this->text_line_list[i].word_block_list[j].setPosition(this->text_line_list[i].word_block_list[j].getTextSfml().getPosition().x, this->text_line_list[i].word_block_list[j].getTextSfml().getPosition().y - this->id_text_line*18 - 10);
			if(this->text_line_list[i].word_block_list[j].getBlock()){
				this->window->draw(this->text_line_list[i].word_block_list[j].getRectangle());
			}
			this->window->draw(this->text_line_list[i].word_block_list[j].getTextSfml());
			this->text_line_list[i].word_block_list[j].setPosition(this->text_line_list[i].word_block_list[j].getTextSfml().getPosition().x, y);
		}
	}
	*/
	std::vector<int> range = this->getRangeForDrawField(position_y);
	for(int i = range[0]; i < range[1]; ++i){
		this->window->draw(this->text_loader->getWordBlockList()[i].getRectangle());
		this->window->draw(this->text_loader->getWordBlockList()[i].getWord());
	}
}

void TextField::loadText(){
	std::map<std::string, int> words_map;
	this->full_dictionary = new FullDictionary(file_system->getCurrentPath() + PATH_TO_DICTIONARY);
	this->text_loader = new TextLoader(file_system->getCurrentPath() + PATH_TO_TEXT, &this->font);
	bool block;
	//HAYES
	//std::cout << full_dictionary->getOriginalWord("HAYES") << std::endl;
	for(int i = 0; i < this->text_loader->getCountWords(); ++i){
		std::string w = full_dictionary->getOriginalWord(this->text_loader->getWord(i));
		//std::string w = this->text_loader->getWord(i);

		if (!words_map.count(w)){
			words_map.insert(std::pair<std::string, int>(w, 1));
			block = true;
		} else {
			words_map.find(w) = ++words_map.find(w);
			block = false;
		}
		this->toTextLine(this->text_loader->getWord(i), block);

	}
	this->setTextColumnParameter();
	std::cout << "index by percent: first " << this->getRangeForDrawField(50)[0] << " second "<< this->getRangeForDrawField(50)[1] << std::endl;
	std::cout << "size word list: " << words_map.size() << std::endl;
	this->load = true;
}

void TextField::toTextLine(std::string word, bool block){

	WordBlock *word_block = new WordBlock(word, &this->font, block);
	if (((*word_block).getWidth() + this->text_line_list[this->text_line_index].getWidth()) > this->width){
		++this->text_line_index;
		this->text_line_list.push_back(*(new TextLine(this->text_line_index,this->width, this->height, 10, 10)));
	}
	this->text_line_list[this->text_line_index].addWordBlock(*word_block);
	delete(word_block);
}

void TextField::setTextColumnParameter(){
	this->width_text_column = this->width;
	this->height_text_column = 0;
	int string_width = 0;
	int size_word_list = this->text_loader->getWordBlockList().size();
	for (int i = 0; i < size_word_list; ++i){
		string_width += this->text_loader->getWordBlockList()[i].getWidth() + this->text_loader->getWordBlockList()[i].getMarginLeft();
		if (string_width > this->width_text_column){
			string_width = this->text_loader->getWordBlockList()[i].getWidth() + this->text_loader->getWordBlockList()[i].getMarginLeft();
			this->height_text_column += this->text_loader->getWordBlockList()[i].getHeight() + this->text_loader->getWordBlockList()[i].getMarginBottom();
		}
	}
}

std::vector<int> TextField::getRangeForDrawField(int percent){
	std::vector<int> result;
	int string_width = 0;
	int current_height_text_column = 0;
	int needed_height_text_column = percent * (this->height_text_column / 100);
	int i = 0;
	while(current_height_text_column < needed_height_text_column){

		string_width += this->text_loader->getWordBlockList()[i].getWidth() + this->text_loader->getWordBlockList()[i].getMarginLeft();
		if (string_width > this->width_text_column){
			string_width = this->text_loader->getWordBlockList()[i].getWidth() + this->text_loader->getWordBlockList()[i].getMarginLeft();
			current_height_text_column += this->text_loader->getWordBlockList()[i].getHeight() + this->text_loader->getWordBlockList()[i].getMarginBottom();
		}
		++i;
	}
	result.push_back(i);
	string_width = 0;
	while(current_height_text_column < needed_height_text_column + this->height){
		this->text_loader->setPosition(i, string_width, current_height_text_column - needed_height_text_column);
		string_width += this->text_loader->getWordBlockList()[i].getWidth() + this->text_loader->getWordBlockList()[i].getMarginLeft();
		if (string_width > this->width_text_column){
			string_width = 0; //this->text_loader->getWordBlockList()[i].getWidth() + this->text_loader->getWordBlockList()[i].getMarginLeft();
			current_height_text_column += this->text_loader->getWordBlockList()[i].getHeight() + this->text_loader->getWordBlockList()[i].getMarginBottom();
		}
		++i;
	}
	result.push_back(i);
	return result;
}

bool TextField::isLoad(){
	return this->load;
}

int TextField::getTextLineId() const{
	return this->id_text_line;
}

std::vector<TextLine> TextField::getTextLineList() const{
	return this->text_line_list;
}
