#include "GenericPlayer.h"

bool GenericPlayer::IsBoosted() const
{
	if (h_get_total() > 21)
	{
		return true;
	}
	return false;
}

void GenericPlayer::Bust() const
{
	if (IsBoosted())
		std::cout << m_Name << " has Boosted!!!" << std::endl;
}

const std::string GenericPlayer::get_Name() const
{
	return m_Name;
}

std::ostream& operator<<(std::ostream& out, const GenericPlayer& player)
{
	out << player.get_Name() << ":\t";
	if (!player.m_Cards.empty()) {
		for (auto it = player.m_Cards.begin(); it != player.m_Cards.end(); ++it) {
			out << *(*it) << "\t";
		}

		if (player.h_get_total() != 0) {
			out << "(" << player.h_get_total() << ")" << std::endl;
		}
	}
	else
	{
		out << "Empty";
	}

	return out;
}
