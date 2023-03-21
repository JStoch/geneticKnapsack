#pragma once
#include <exception>
#include <string>

class UnexpectedArgumentException : public std::exception {
public:
	UnexpectedArgumentException();
	UnexpectedArgumentException(const std::string& msg);
	UnexpectedArgumentException(int argumentLine, int argumentWord);
	std::string what();
	int getLineNumber() const;
	int getWordNumber() const;
private:
	std::string message;
	int line;
	int word;
};