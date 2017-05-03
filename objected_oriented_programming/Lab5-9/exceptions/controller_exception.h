#ifndef CONTROLLER_EXCEPTION_H
#define CONTROLLER_EXCEPTION_H

#include <exception>
#include <string>

class ControllerException : public std::exception {

protected:

	std::string error;

public:

	ControllerException(){}
	ControllerException(const std::string& error);
	const char* what();

};

#endif