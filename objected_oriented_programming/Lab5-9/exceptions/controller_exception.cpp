#include "controller_exception.h"

ControllerException::ControllerException(const std::string& error) {
	this->error = error;
}

const char*	ControllerException::what() {
	return this->error.c_str();
}