#pragma once
#include <exception>
#include <string>

class InvalidPathException : public std::exception {
public:
	InvalidPathException();
	InvalidPathException(const std::string& msg);
	std::string what();
private:
	std::string message;
};