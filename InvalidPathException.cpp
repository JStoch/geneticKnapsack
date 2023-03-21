#include "InvalidPathException.h"
#include "ExceptionMessages.h"

InvalidPathException::InvalidPathException() {
	message = defaultInvalidPathMessage;
}

InvalidPathException::InvalidPathException(const std::string& msg) {
	message = msg;
}

std::string InvalidPathException::what() {
	return message;
}