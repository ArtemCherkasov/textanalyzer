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

class FullDictionary{
private:
	std::vector<Word> full_dictionary;
	void toFillList(std::string line);
public:
	FullDictionary(std::string path_to_dictionary);
	void addWord(Word word);
};


#endif /* HEADERS_FULLDICTIONARY_H_ */
