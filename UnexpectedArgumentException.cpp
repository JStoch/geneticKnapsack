#include "UnexpectedArgumentException.h"
#include "ExceptionMessages.h"

UnexpectedArgumentException::UnexpectedArgumentException() 
{
	message = defaultUnexpectedArgumentMessage;
}

UnexpectedArgumentException::UnexpectedArgumentException(const std::string& msg) 
{
	message = msg;
}

UnexpectedArgumentException::UnexpectedArgumentException(int argumentLine, int argumentWord)
{
	line = argumentLine;
	word = argumentWord;
	message = unexpectedArgumentWithPlaceMessage+"line: " + std::to_string(line) + ", word : " + std::to_string(word);
}

std::string UnexpectedArgumentException::what() {
	return message;
}

int UnexpectedArgumentException::getLineNumber() const {
	return line;
}

int UnexpectedArgumentException::getWordNumber() const {
	return word;
}