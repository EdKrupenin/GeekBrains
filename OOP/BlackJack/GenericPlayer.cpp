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
