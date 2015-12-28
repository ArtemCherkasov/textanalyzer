/*
 * FileSystem.h
 *
 *  Created on: 24 дек. 2015 г.
 *      Author: artemcherkasov
 */

#ifndef HEADERS_FILESYSTEM_H_
#define HEADERS_FILESYSTEM_H_

#ifdef WINDOWS
	#include <direct.h>
	#define GetCurrentDir _getcwd
#else
	#include <unistd.h>
	#define GetCurrentDir getcwd
#endif
#define FILENAME_MAX 5000
#include <string>

class FileSystem {
private:
	std::string path;
	char cCurrentPath[FILENAME_MAX];
public:
	std::string getCurrentPath();
};

#endif /* HEADERS_FILESYSTEM_H_ */
