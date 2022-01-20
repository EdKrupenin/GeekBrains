#include "Deck.h"

Deck::Deck()
{
	m_Cards.reserve(52);
	Populate();
}

Deck::~Deck()
{
}

void Deck::Populate()
{
	h_Clear();

	for (int s = static_cast<int>(c_suit::CLUB); s <= static_cast<int>(c_suit::CLUB); ++s)
	{
		for (int v = static_cast<int>(c_value::ace); v <= static_cast<int>(c_value::king); ++v) {
			add_Card(new Card(static_cast<c_suit>(s), static_cast<c_value>(v)));
		}
	}
}

void Deck::Shuffle()
{
	random_shuffle(m_Cards.begin(), m_Cards.end());
}

void Deck::Deal(Hand& aHand)
{
	if (!m_Cards.empty()) {
		aHand.add_Card(m_Cards.back());
		m_Cards.pop_back();
	}
	else
	{
		std::cout << "Out of cards.Unable to deal.\n";
	}
}

void Deck::AddltionalCards(GenericPlayer& aGenericPlayer)
{
	std::cout << std::endl;

	while (!(aGenericPlayer.IsBoosted()) && aGenericPlayer.IsHitting())
	{
		Deal(aGenericPlayer);
		std::cout << aGenericPlayer << std::endl;

		if (aGenericPlayer.IsBoosted())
		{
			aGenericPlayer.Bust();
		}
	}

}
