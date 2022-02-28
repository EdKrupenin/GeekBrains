#pragma once
#include "Direction.h"
#include "IllegalCommand.h"
#include "OffTheField.h"

class Robot
{
	int d_x{};
	int d_y{};
	direction d_direction{};
protected:
	static const auto  xMAX = 10;
	static const auto  yMAX = 10;
	static const auto  xMIN = 0;
	static const auto  yMIN = 0;
public:
	Robot();
	Robot(int x, int y);
	bool move(direction dir);
	void setDirection();
	const direction& getDirection();
	void clearScreen();
	void plotTheField();
	void plotMenu();
	void play();
};

