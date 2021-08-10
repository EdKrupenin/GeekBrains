#include "OffTheField.h"


OffTheField::OffTheField(direction dir, int x, int y)
{
	std::stringstream message{};
	message << "Robot can't go there!!! It is located in coordinates" << x << ';' << y << std::endl;
	message << "If it will going to the " << dir << ", then it will leave the field";
	d_message = message.str();
}

OffTheField::OffTheField(int x, int y)
{
	std::stringstream message{};
	message << "Robot can't go there!!! It is located in coordinates" << x << ';' << y << std::endl;
	d_message = message.str();
}

char const* OffTheField::what() const
{
	return d_message.c_str();
}
