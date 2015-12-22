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
		while (std::getline(file, line)) {
			this->addWord(line);
			//this->full_dictionary.push_back(*(new Word(line)));
			//this->toFillList(line);

		}

		//std::cout << "dictionary file: " << this->full_dictionary.size() << std::endl;

		file.close();
	} else {
		std::cout << "ERROR FILE OPEN" << std::endl;
	}
}

void FullDictionary::addWord(Word word){
	this->full_dictionary.push_back(word);
	std::cout << "dictionary++++file: " << this->full_dictionary.size() << std::endl;
}

void FullDictionary::toFillList(std::string line){
	std::string word;

	try {
		//this->full_dictionary.push_back(*(new Word("5")));

	} catch (std::exception e) {
		std::cout << e.what() << std::endl;
	}
	if (line[0] != '\t') {
		int i = 0;
		while (((line[i] >= 65) && (line[i] <= 90))
				|| ((line[i] >= 97) && (line[i] <= 122))) {
			word.push_back(line[i]);
			++i;
		}
		//std::cout << line << std::endl;
		//std::transform(word.begin(), word.end(), word.begin(), ::tolower);
		//Word *word_ = new Word();
		//word_->setWord(word);
		//std::cout << word_->getWord() << " ---- " << std::endl;
		//this->full_dictionary.push_back(*(new Word("5")));
	} else {
		int i = 1;
		while (((line[i] >= 65) && (line[i] <= 90))
				|| ((line[i] >= 97) && (line[i] <= 122))) {
			word.push_back(line[i]);
			++i;
		}
		//std::transform(word.begin(), word.end(), word.begin(), ::tolower);
		//int current_index = this->full_dictionary.size() - 1;
		//this->full_dictionary[current_index].addChildWord(word);
		//std::cout << "---" << this->full_dictionary[current_index].getWord() << std::endl;
	}
}
