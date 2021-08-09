#pragma once
#include "Direction.h"
#include "IllegalCommand.h"
#include "OffTheField.h"

class Robot
{
	int d_x{};
	int d_y{};
public:
	Robot();
	Robot(int x, int y);
	bool move(direction dir);
};

