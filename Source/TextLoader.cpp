/*
 * TextLoader.cpp
 *
 *  Created on: 21 дек. 2015 г.
 *      Author: artemcherkasov
 */

#include "../Headers/TextLoader.h"

int TextLoader::getCountWords() const {
	return count_words;
}

std::vector<std::string> TextLoader::getWords(){
	return words;
}

const std::vector<WordBlock> &TextLoader::getWordBlockList() const{
	return word_block_list;
}

void TextLoader::setPosition(int index, int x, int y){
	this->word_block_list[index].setPosition(x ,y);
}

void TextLoader::setBlock(int index, bool block){
	this->word_block_list[index].setBlock(block);
}

std::string TextLoader::getWord(int i){
	return this->words[i];
}

TextLoader::TextLoader(std::string file_name, sf::Font *font){
	this->count_words = 0;
	this->file_name = file_name;
	std::ifstream file(this->file_name.c_str());
	std::string line;
	std::string output;
	if (file.is_open()) {
		while (getline(file, line)) {
			this->text.append(line);
		}
		file.close();
	} else {
		std::cout << "ERROR FILE OPEN" << std::endl;
	}
	int size_book = this->text.size();
	std::cout << "size file " << size_book << std::endl;
	bool new_word = false;

	std::string word_to_add;

	for (int i = 0; i < size_book; ++i){
		if (((this->text[i] >= 65) && (this->text[i] <= 90)) || ((this->text[i] >= 97) && (this->text[i] <= 122)) || (this->text[i] == 39)){
			new_word = true;
			word_to_add.push_back(this->text[i]);
			//word_to_add.append();
		} else {
			if (new_word){
				new_word = false;
				this->sf_text.setFont(*font);
				this->sf_text.setString(word_to_add);
				this->sf_text.setCharacterSize(CHARACTER_SIZE);
				this->words.push_back(word_to_add);
				++this->count_words;
				this->word_block_list.push_back(*(new WordBlock(word_to_add, font, 10, 10)));
				//std::cout << word_to_add << std::endl;
				word_to_add.erase();
			}
		}
	}
}
