#include "Card.h"

void Card::flip() {
	is_Face_Up = !(is_Face_Up);
}

c_value Card::get_value() const {
	return valueCard;
}

std::ostream& operator<<(std::ostream& out, const Card& card)
{
	const std::string RANKS[] = { "0", "A", "2", "3", "4", "5", "6", "7", "8", "9","10", "J", "Q", "K" };
	const std::string SUITS[] = { "c", "d", "h", "s" };

	if (card.is_Face_Up) {
		out << RANKS[(int)card.valueCard] << SUITS[(int)card.suitCard]<<" ";
	}
	else
	{
		out << "XX";
	}
	return out;
}

