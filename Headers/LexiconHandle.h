/*
 * LexiconHandle.h
 *
 *  Created on: 28 дек. 2015 г.
 *      Author: artemcherkasov
 */

#ifndef HEADERS_LEXICONHANDLE_H_
#define HEADERS_LEXICONHANDLE_H_

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <vector>
#include <dirent.h>
#include <algorithm>

class LexiconHandle {
private:
	std::vector<std::string> list_of_file;
	std::vector<std::string> saved_words_list;
	DIR *dir;
	struct dirent *ent;
public:
	LexiconHandle(std::string path_of_file);
};

#endif /* HEADERS_LEXICONHANDLE_H_ */
