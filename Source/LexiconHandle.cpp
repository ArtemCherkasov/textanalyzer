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
	std::string path;

	if ((this->dir = opendir(writable)) != NULL) {
		/* print all the files and directories within directory */
		while ((this->ent = readdir (dir)) != NULL) {
			if (!((strcmp(this->ent->d_name, ".") == 0) || (strcmp(this->ent->d_name, "..")) == 0)){
				this->list_of_file.push_back(path_of_file + "/" + this->ent->d_name);
				path = path_of_file + "/" + this->ent->d_name;
				std::ifstream file(path.c_str());
				std::string line;
				if (file.is_open()) {
						while (getline(file, line)) {
							//this->saved_words_list.push_back(line.substr(0, line.find('\t')));
							this->saved_words_list.push_back(this->getWordFromLine(line.substr(0, line.find('\t'))));
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

		closedir (dir);
	} else {

	}
	delete[] writable;
}

const std::string LexiconHandle::getWordFromLine(const std::string line) const{
	std::string result = "";
	int i = 0;
	while( ((line[i] >= 65) && (line[i] <= 90)) || ((line[i] >= 97) && (line[i] <= 122)) || (line[i] == 39) ){
		result.push_back(line[i]);
		++i;
	}
	return result;
}

const std::vector<std::string>& LexiconHandle::getSavedWordsList() const{
	return this->saved_words_list;
}
