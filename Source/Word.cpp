/*
 * Word.cpp
 *
 *  Created on: 22 дек. 2015 г.
 *      Author: artemcherkasov
 */

#include "../Headers/Word.h"

Word::Word(std::string word){
	this->word = word;
}

std::vector<std::string> Word::getChildWordsList(){
	return child_words_list;
}

void Word::addChildWord(std::string childWord){
	//this->child_words_list = childWordsList;
	this->child_words_list.push_back(childWord);
}

std::string Word::getWord(){
	return this->word;
}

void Word::setWord(std::string word) {
	this->word = word;
}
