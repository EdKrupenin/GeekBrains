#pragma once
#include <exception>
#include <sstream>
#include "Direction.h"

class OffTheField :
    public std::exception
{
	std::string d_message{};
public:
	OffTheField(direction dir, int x, int y);
	virtual char const* what() const override;
};

