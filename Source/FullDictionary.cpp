/*
 * FullDictionary.cpp
 *
 *  Created on: 22 дек. 2015 г.
 *      Author: artemcherkasov
 */

#include "../Headers/FullDictionary.h"

FullDictionary::FullDictionary(std::string path_to_dictionary){
	std::ifstream file(path_to_dictionary.c_str());
	std::string line;
	std::string output;
	if (file.is_open()) {
		while (std::getline(file, line, '\r')) {
			this->toFillList(line);
			//std::cout << line << "." << std::endl;
		}
		std::cout << "SIZE() " << this->words_list_pair.size() << std::endl;
		file.close();
	} else {
		std::cout << "ERROR FILE OPEN" << std::endl;
	}
}

void FullDictionary::addWord(Word word){
	this->full_dictionary.push_back(word);
}

void FullDictionary::toFillList(std::string line){

	std::string word;
	if (line[0] != '\t') {

		if (!this->main_word.empty()){
			int size_child_list = this->child_words_list.size();
			for(int i = 0; i < size_child_list; ++i){
				this->words_list_pair.insert( std::pair<std::string, std::string>(this->child_words_list[i], this->main_word) );
			}

			this->main_word.clear();
			this->child_words_list.clear();
		}

		this->swap_trigger = true;
		int i = 0;
		while (((line[i] >= 65) && (line[i] <= 90))
				|| ((line[i] >= 97) && (line[i] <= 122))) {
			word.push_back(line[i]);
			++i;
		}
		this->main_word = word;

	} else {
		int i = 1;
		while (((line[i] >= 65) && (line[i] <= 90))
				|| ((line[i] >= 97) && (line[i] <= 122))) {
			word.push_back(line[i]);
			++i;
		}
		this->child_words_list.push_back(word);
	}
}

std::string FullDictionary::getOriginalWord(std::string word){

	std::string return_word = word;
	std::transform(return_word.begin(), return_word.end(), return_word.begin(), ::toupper);

	if(this->words_list_pair.count(return_word)){
		return this->words_list_pair[return_word];
	}
	return return_word;
}
