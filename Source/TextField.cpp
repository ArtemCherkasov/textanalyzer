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

TextField::TextField(int width, int height, sf::RenderWindow *window, FileSystem &file_system){
	this->load = false;
	this->width = width;
	this->height = height;
	this->window = window;
	this->text_line_index = 0;
	//std::cout << file_system->getCurrentPath() << std::endl;
	lexiconHandle = new LexiconHandle(file_system.getCurrentPath() + "/Store/Lexicon");
	if(!font.loadFromFile(file_system.getCurrentPath() + PATH_TO_FONT)){
		//printf("load font from file is error");
	}
	ordered_words_list = new std::vector< std::pair< std::string, bool > >;
}

void TextField::draw(int position_y){
	this->percent = position_y;
	std::vector<int> range = this->getRangeForDrawField(position_y);
	for(int i = range[0]; i < range[1]; ++i){
		if (this->text_loader->getWordBlockList()[i].isBlock()){
			this->window->draw(this->text_loader->getWordBlockList()[i].getRectangle());
		}
		this->window->draw(this->text_loader->getWordBlockList()[i].getWord());
	}
}

void TextField::loadText(){
	std::map<std::string, int> words_map;
	std::cout << "TextField::loadText() " << std::endl;
	this->full_dictionary = new FullDictionary(file_system->getCurrentPath() + PATH_TO_DICTIONARY, file_system->getCurrentPath() + PATH_TO_TRANSLATE_DICTIONARY);
	this->text_loader = new TextLoader(file_system->getCurrentPath() + PATH_TO_TEXT, &this->font);
	bool block;
	//HAYES
	std::cout << "TESt::00 " << file_system->getCurrentPath() << std::endl;
	//загружаем в words_map слова которые были ранее сохранены в разных файлах

	//std::cout << "keeping -> " << full_dictionary->getOriginalWord("keeping") << std::endl;
	int size_saved_words = this->lexiconHandle->getSavedWordsList().size();

	for (int i = 0; i < size_saved_words; ++i){
		std::string w = full_dictionary->getOriginalWord(lexiconHandle->getSavedWordsList()[i]);
		if (!words_map.count(w)){
			words_map.insert(std::pair<std::string, int>(w, 1));
		} else {
			words_map.find(w) = ++words_map.find(w);
		}
	}
	//маркировка повторяющихся слов
	for(int i = 0; i < this->text_loader->getCountWords(); ++i){
		std::string w = full_dictionary->getOriginalWord(this->text_loader->getWord(i));
		if (!words_map.count(w)){
			words_map.insert(std::pair<std::string, int>(w, 1));
			block = true;
		} else {
			words_map.find(w) = ++words_map.find(w);
			block = false;
		}
		//this->toTextLine(this->text_loader->getWord(i), block);
		this->text_loader->setBlock(i, block);
	}
	this->setTextColumnParameter();
	//std::cout << "333 " << full_dictionary->getTranslate("girl") << std::endl;
	//std::cout << "size word list: " << words_map.size() << std::endl;
	this->load = true;
}

void TextField::setTextColumnParameter(){
	this->width_text_column = this->width - 50;
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

float TextField::getPercent() const {
	return percent;
}

const TextLoader* TextField::getTextLoader() const {
	return text_loader;
}

std::vector<int> TextField::getRangeForDrawField(int percent){
	std::vector<int> result;
	int string_width = 0;
	int clear_row = 0;
	int current_height_text_column = 0;
	int needed_height_text_column = percent * (this->height_text_column / 100);
	int i = 0;
	int max_size = this->text_loader->getWordBlockList().size();
	while(current_height_text_column < needed_height_text_column){
		if (string_width + this->text_loader->getWordBlockList()[i].getWidth() + this->text_loader->getWordBlockList()[i].getMarginLeft() > this->width_text_column){
			string_width = this->text_loader->getWordBlockList()[i].getWidth() + this->text_loader->getWordBlockList()[i].getMarginLeft();
			current_height_text_column += this->text_loader->getWordBlockList()[i].getHeight() + this->text_loader->getWordBlockList()[i].getMarginBottom();
		} else {
			string_width += this->text_loader->getWordBlockList()[i].getWidth() + this->text_loader->getWordBlockList()[i].getMarginLeft();
		}
		++i;
	}
	result.push_back(i);
	string_width = 0;
	while(current_height_text_column < needed_height_text_column + this->height && i < max_size){
		this->text_loader->setPosition(i, string_width + 50, clear_row);
		if (string_width + this->text_loader->getWordBlockList()[i].getWidth() + this->text_loader->getWordBlockList()[i].getMarginLeft()> this->width_text_column){
			string_width = 0;
			current_height_text_column += this->text_loader->getWordBlockList()[i].getHeight() + this->text_loader->getWordBlockList()[i].getMarginBottom();
			clear_row += this->text_loader->getWordBlockList()[i].getHeight() + this->text_loader->getWordBlockList()[i].getMarginBottom();
		} else {
			string_width += this->text_loader->getWordBlockList()[i].getWidth() + this->text_loader->getWordBlockList()[i].getMarginLeft();
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

sf::Font TextField::getFont(){
	return font;
}

FullDictionary* TextField::getFullDictionary(){
	return full_dictionary;
}
