#pragma once
#include <exception>
#include <string>

class OutOfDomainException : public std::exception {
public:
	OutOfDomainException();
	OutOfDomainException(const std::string& msg);
	std::string what();
private:
	std::string message;
};