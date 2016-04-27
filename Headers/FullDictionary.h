/*
 * FullDictionary.h
 *
 *  Created on: 22 дек. 2015 г.
 *      Author: artemcherkasov
 */

#ifndef HEADERS_FULLDICTIONARY_H_
#define HEADERS_FULLDICTIONARY_H_

#include <string>
#include <vector>
#include "../Headers/Word.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <exception>
#include <iterator>
#include <map>

class FullDictionary{
private:
	struct translation_pair {
		std::string transcription;
		std::string translation;
	};
	std::vector<Word> full_dictionary;
	std::map<std::string, std::vector<std::string> > full_dictionary_map;
	bool swap_trigger;
	std::string main_word;
	std::vector<std::string> child_words_list;
	std::map<std::string, std::string> words_list_pair;
	std::map<std::string, std::string> translation_pair_list;
public:
	FullDictionary(std::string path_to_dictionary, std::string path_to_translate_dictionary);
	void addWord(Word word);
	std::string getOriginalWord(std::string word);
	std::string getTranslate(std::string word);
	std::string getTranslate();
	const std::map<std::string, std::string> getTranslationPairList() const;
	void toFillList(std::string line);
	void toSeparateStrings(std::string line);
};


#endif /* HEADERS_FULLDICTIONARY_H_ */
