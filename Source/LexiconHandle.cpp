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
			if (!((strcmp(this->ent->d_name, ".") == 0) || (strcmp(this->ent->d_name, "..")) == 0)){
				this->list_of_file.push_back(path_of_file + "/" + this->ent->d_name);
				std::ifstream file(path_of_file + "/" + this->ent->d_name);
				std::string line;
				if (file.is_open()) {
						while (getline(file, line)) {
							this->saved_words_list.push_back(line.substr(0, line.find('\t')));
						}
						file.close();
					} else {
						std::cout << "ERROR FILE OPEN" << std::endl;
				}
			}
		}
		for(std::vector<std::string>::iterator object = this->list_of_file.begin(); object != this->list_of_file.end(); ++object){
			std::cout << *object << std::endl;
		}

		int words_list_size = this->saved_words_list.size();
		std::cout << "saved word list:" << std::endl;
		for(int i = 0; i < words_list_size; ++i){
			std::cout << this->saved_words_list[i] << std::endl;
		}

		closedir (dir);
	} else {

	}
	delete[] writable;
}
