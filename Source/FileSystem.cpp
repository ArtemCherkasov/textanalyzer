/*
 * FyleSystem.cpp
 *
 *  Created on: 24 дек. 2015 г.
 *      Author: artemcherkasov
 */

#include "../Headers/FileSystem.h"

std::string FileSystem::getCurrentPath(){
	//GetCurrentDir(cCurrentPath, sizeof(cCurrentPath))
	if ( !get_current_dir_name() ){
		std::cout << "cCurrentPath ---- > " << std::endl;
		return "-1";
	}
	return get_current_dir_name();
}
