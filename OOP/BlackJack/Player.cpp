#include "Player.h"

bool Player::IsHitting() const
{
	std::cout << get_Name() << ", do you want a hit? (Y/N): ";
	char response;
	std::cin >> response;
	while (std::cin.fail() || (std::cin.peek() != '\n') || (response != 'Y' && response != 'N')) {
		std::cout << "IDIOT !! Enter again !\n";
		std::cin.clear();
		std::cin.ignore();
		std::cin.sync();
		std::cout << "Enter Y or N : ";
		std::cin >> response;
	}
	std::cout << std::endl;
	return (response == 'Y');
}

void Player::Win() const
{
	std::cout << "Player " << get_Name() << " is Win";
}

void Player::Lose() const
{
	std::cout << "Player " << get_Name() << " is Lose";
}

void Player::Push() const
{
	std::cout << "Player " << get_Name() << " is Push";
}
