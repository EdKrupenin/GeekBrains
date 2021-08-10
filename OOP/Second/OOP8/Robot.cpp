#include "Robot.h"

#include <iostream>


Robot::Robot()
{
}

Robot::Robot(int x, int y) : d_x(x), d_y(y)
{
	if ((x > 10) || (y > 10))
		throw OffTheField(x, y);
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
		if (d_x < 9) {
			d_x++;
			return true;
		}
		break;
	case (left):
		if (d_x > 0) {
			d_x--;
			return true;
		}
		break;
	default:
		throw IllegalCommand(dir);
	}
	throw OffTheField(dir, d_x, d_y);
	return false;
}

void Robot::setDirection()
{
	int input;
	std::cin >> input;
	d_direction = static_cast<direction>(input);
}

const direction& Robot::getDirection()
{
	return d_direction;
}



void Robot::clearScreen()
{
	std::cout << "\x1B[2J\x1B[H";
}

void Robot::plotTheField()
{
	std::cout << "    ";
	for (auto i = 0; i < xMAX; i++)
		std::cout << i << " ";
	std::cout << std::endl;
	for (auto i = 0; i < xMAX; i++)
	{
		std::cout << i << "  |";
		for (auto j = 0; j < yMAX; j++)
		{
			if ((d_x == j) && (d_y == i)) std::cout << "*|";
			else std::cout << " |";
		}
		std::cout << std::endl << "    ";
		for (auto j = 0; j < yMAX; j++)
		{
			std::cout << "--";
		}
		std::cout << std::endl;
	}
}

void Robot::plotMenu()
{
	std::cout << direction::up << "Вверх \n";
	std::cout << direction::up << "Вправо \n";
	std::cout << direction::up << "Влево \n";
	std::cout << direction::up << "Вниз \n";
	std::cout << direction::up << "Выход \n";
}

void Robot::play()
{
	clearScreen();
	plotTheField();
	setDirection();
	move(d_direction);
}
