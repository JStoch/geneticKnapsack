#include "IndexOutOfBoundsException.h"
#include "ExceptionMessages.h";

IndexOutOfBoundsException::IndexOutOfBoundsException() {
	message = defaultIndexOutOfBoundsMessage;
}

IndexOutOfBoundsException::IndexOutOfBoundsException(const std::string& msg) {
	message = msg;
}

std::string IndexOutOfBoundsException::what() {
	return message;
}