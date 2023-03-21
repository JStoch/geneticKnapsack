#include "OutOfDomainException.h"
#include "ExceptionMessages.h"

OutOfDomainException::OutOfDomainException() 
{
	message = defaultOutOfDomainMessage;
}

OutOfDomainException::OutOfDomainException(const std::string& msg) {
	message = msg;
}

std::string OutOfDomainException:: what() {
	return message;
}