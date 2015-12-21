/*
 * TextLoader.h
 *
 *  Created on: 21 дек. 2015 г.
 *      Author: artemcherkasov
 */

#ifndef HEADERS_TEXTLOADER_H_
#define HEADERS_TEXTLOADER_H_

#include <string>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>
#include <map>

class TextLoader{
private:
	std::string file_name;
	std::string text;
	std::vector<std::string> words;
	int count_words;
public:
	TextLoader(std::string file_name);
	int getCountWords() const;
	std::vector<std::string> getWords();
	std::string getWord(int i);
};



#endif /* HEADERS_TEXTLOADER_H_ */
