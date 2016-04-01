/*
 * FullDictionary.cpp
 *
 *  Created on: 22 дек. 2015 г.
 *      Author: artemcherkasov
 */

#include "../Headers/FullDictionary.h"

FullDictionary::FullDictionary(std::string path_to_dictionary, std::string path_to_translate_dictionary){
	std::ifstream file(path_to_dictionary.c_str());
	std::string line;
	std::string output;
	std::cout << "LOAD DICTIONARY..." << std::endl;
	if (file.is_open()) {
		while (std::getline(file, line, '\n')) {
			this->toFillList(line);
			//std::cout << line << "." << std::endl;
		}
		std::cout << "SIZE() " << this->words_list_pair.size() << std::endl;
		file.close();
	} else {
		std::cout << "ERROR FILE OPEN" << std::endl;
	}
	std::cout << "LOAD TRANSLATE DICTIONARY..." << std::endl;
	file.open(path_to_translate_dictionary.c_str());

	if (file.is_open()) {
		while (std::getline(file, line, '\n')) {
			//std::cout << line << std::endl;
			this->toSeparateStrings(line);
		}
		std::cout << "SIZE TRANSLATION PAIR() " << this->translation_pair_list.size() << std::endl;
		int contain_index = 25;
		std::cout << "TRANSLATION PAIR() contain for index " << contain_index << " " << this->getTranslate("apple") << std::endl;
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
	if (line[0] != '\t') { // проверка на коренное слово
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

void FullDictionary::toSeparateStrings(std::string line){
	int separate_index_main = line.find('\t');
	std::string main_word = line.substr(0, separate_index_main);
	int separate_index_transcription = line.find('\t', separate_index_main + 1);
	std::string transcription = line.substr(separate_index_main + 1, separate_index_transcription - separate_index_main - 1);
	int separate_index_translation = line.find('\t', separate_index_transcription + 1);
	std::string translation = line.substr(separate_index_transcription + 1, separate_index_translation - separate_index_transcription - 1);
	std::transform(main_word.begin(), main_word.end(), main_word.begin(), ::toupper);
	translation_pair translation_pair_value = {transcription, translation};
	this->translation_pair_list.insert(std::pair<std::string, std::string>(main_word, translation));
}

std::string FullDictionary::getOriginalWord(std::string word){

	std::string return_word = word;
	std::transform(return_word.begin(), return_word.end(), return_word.begin(), ::toupper);

	if(this->words_list_pair.count(return_word)){
		return this->words_list_pair[return_word];
	}
	return return_word;
}

std::string FullDictionary::getTranslate(std::string word){

	std::string return_word = word;
	std::transform(return_word.begin(), return_word.end(), return_word.begin(), ::toupper);
	std::cout << "calculate: " << return_word << " size: " << std::endl;
	std::cout << this->translation_pair_list["APPLE"] << std::endl;

	if(this->translation_pair_list.count(return_word)){
		return this->translation_pair_list[return_word];
		//return "TRANSLATION";
	}
	return "NO TRANSLATION";
}

std::string FullDictionary::getTranslate(){

	std::string return_word = "table";
	std::transform(return_word.begin(), return_word.end(), return_word.begin(), ::toupper);
	std::cout << "calculate: " << return_word << " size: " << std::endl;
	std::cout << this->translation_pair_list[return_word] << std::endl;

	if(this->translation_pair_list.count(return_word)){
		return this->translation_pair_list[return_word];
		//return "TRANSLATION";
	}
	return "NO TRANSLATION";
}
