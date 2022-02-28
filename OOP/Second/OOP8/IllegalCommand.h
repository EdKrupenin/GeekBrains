#pragma once
#include "Direction.h"
#include "Exception.h"


class IllegalCommand : public Exception

{
public:
	IllegalCommand(direction dir);
	const char* what() const override;
};

