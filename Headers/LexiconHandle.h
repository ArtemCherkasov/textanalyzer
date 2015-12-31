/*
 * LexiconHandle.h
 *
 *  Created on: 28 дек. 2015 г.
 *      Author: artemcherkasov
 */

#ifndef HEADERS_LEXICONHANDLE_H_
#define HEADERS_LEXICONHANDLE_H_

#include <iostream>
#include <string>
#include <vector>
#include <dirent.h>

class LexiconHandle {
private:
	std::vector<std::string> list_of_file;
	DIR *dir;
	struct dirent *ent;
public:
	LexiconHandle(std::string path_of_file);
};

#endif /* HEADERS_LEXICONHANDLE_H_ */
