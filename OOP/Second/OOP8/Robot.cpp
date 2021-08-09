#include "Robot.h"



Robot::Robot()
{
}

Robot::Robot(int x, int y) : d_x(x), d_y(y)
{
}



bool Robot::move(direction dir)
{
	switch (dir)
	{
	case (up):
		if (d_y < 9) {
			d_y++;
			return true;
		}
		break;
	case (down):
		if (d_y > 0) {
			d_y--;
			return true;
		}
		break;
	case (right):
		if (d_x > 0) {
			d_x--;
			return true;
		}
		break;
	case (left):
		if (d_x < 9) {
			d_x++;
			return true;
		}
		break;
	default:
		throw IllegalCommand(dir);
	}
	throw OffTheField(dir, d_x, d_y);
	return false;
}
