#pragma once
#include <string>

class IndexOutOfBoundsException {
public:
	IndexOutOfBoundsException();
	IndexOutOfBoundsException(const std::string& msg);
	std::string what();
private:
	std::string message;
};