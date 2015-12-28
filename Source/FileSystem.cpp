/*
 * FyleSystem.cpp
 *
 *  Created on: 24 дек. 2015 г.
 *      Author: artemcherkasov
 */

#include "../Headers/FileSystem.h"

std::string FileSystem::getCurrentPath(){
	if (!GetCurrentDir(cCurrentPath, sizeof(cCurrentPath))){
		return "-1";
	}
	return cCurrentPath;
}
