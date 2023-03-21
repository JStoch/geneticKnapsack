#include "GenotypeSizesDontMatchException.h"
#include "ExceptionMessages.h"

GenotypeSizesDontMatchException::GenotypeSizesDontMatchException()
{
	message = defaultGenotypeSizesDontMatchMessage;
}

GenotypeSizesDontMatchException::GenotypeSizesDontMatchException(const std::string& msg)
{
	message = msg;
}

std::string GenotypeSizesDontMatchException::what() {
	return message;
}