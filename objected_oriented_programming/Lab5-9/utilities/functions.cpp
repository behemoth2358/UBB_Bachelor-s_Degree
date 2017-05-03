#include "functions.h"

std::vector< std::string > split(const std::string& str, char delim) {
	std::vector< std::string > objects;
	std::stringstream aux(str);
	std::string it;

	while( std::getline(aux, it, delim) ) {
		if( !it.empty() ) {
			objects.push_back(it);
		}
	}

	return objects;
}
