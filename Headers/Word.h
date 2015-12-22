/*
 * Word.h
 *
 *  Created on: 22 дек. 2015 г.
 *      Author: artemcherkasov
 */

#ifndef HEADERS_WORD_H_
#define HEADERS_WORD_H_

#include <string>
#include <vector>

class Word{
private:
	std::string word;
	std::vector<std::string> child_words_list;
public:
	std::vector<std::string> getChildWordsList();
	void addChildWord(std::string childWord);
	std::string getWord();
	void setWord(std::string word);
};

#endif /* HEADERS_WORD_H_ */
