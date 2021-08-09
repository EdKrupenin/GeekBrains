#pragma once
#include <exception>
#include <string>
#include <strstream>

class Ex : public std::exception
{
public:
	int x{};
public:
	Ex(int input);
	virtual char const* what() const override;
	std::string CreateMessage() const;
};
