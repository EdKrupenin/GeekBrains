#pragma once
#include <exception>
#include <string>
#include <ostream>
#include <sstream>

class Exception : public std::exception
{
protected:
	std::string d_message{};
public:
	virtual const char* what() const = 0;
};

