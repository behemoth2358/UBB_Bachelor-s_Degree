#include "repository_exception.h"

RepositoryException::RepositoryException(const std::string& error) {
	this->error = error;
}

const char*	RepositoryException::what() {
	return this->error.c_str();
}