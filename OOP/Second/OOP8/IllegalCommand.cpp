#include "IllegalCommand.h"

IllegalCommand::IllegalCommand(direction dir)
{
	std::stringstream message{};
	message << "Robot don't know that command (";
	message << dir << ")!!!Please enter the command fom 0 to 3.";
	d_message = message.str();
}

const char* IllegalCommand::what() const
{
	return d_message.c_str();
}
