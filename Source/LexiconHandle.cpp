/*
 * LexiconHandle.cpp
 *
 *  Created on: 28 дек. 2015 г.
 *      Author: artemcherkasov
 */

#include "../Headers/LexiconHandle.h"

LexiconHandle::LexiconHandle(std::string path_of_file){
	char *writable = new char[path_of_file.size() + 1];
	std::copy(path_of_file.begin(), path_of_file.end(), writable);
	writable[path_of_file.size()] = '\0';

	if ((this->dir = opendir(writable)) != NULL) {
		/* print all the files and directories within directory */
		while ((this->ent = readdir (dir)) != NULL) {
			std::cout << this->ent->d_name <<std::endl;
		}
		closedir (dir);
	} else {

	}
	delete[] writable;
}
