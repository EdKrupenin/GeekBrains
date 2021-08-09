#pragma once
#include <exception>
#include <sstream>
#include "Direction.h"


class IllegalCommand :
	public std::exception
{
	std::string d_message{};
public:
	IllegalCommand(direction dir);
	virtual  const char* what() const override;
};

