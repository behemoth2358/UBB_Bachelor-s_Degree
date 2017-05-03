#ifndef REPOSITORY_EXCEPTION_H
#define REPOSITORY_EXCEPTION_H

#include <exception>
#include <string>

class RepositoryException : public std::exception {

protected:

	std::string error;

public:

	RepositoryException(){}
	RepositoryException(const std::string& error);
	const char* what();

};

#endif