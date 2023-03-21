#pragma once
#include <exception>
#include <string>

class GenotypeSizesDontMatchException : public std::exception {
public:
	GenotypeSizesDontMatchException();
	GenotypeSizesDontMatchException(const std::string& msg);
	std::string what();
private:
	std::string message;
 };