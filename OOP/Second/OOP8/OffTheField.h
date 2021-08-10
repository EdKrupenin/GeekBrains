#pragma once
#include "Direction.h"
#include "Exception.h"

class OffTheField : public Exception
{
public:
	OffTheField(direction dir, int x, int y);
	OffTheField(int x, int y);
	char const* what() const override;
};

