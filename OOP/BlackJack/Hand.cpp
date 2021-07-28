#include "Hand.h"

void Hand::add_Card(Card* new_Card)
{
	m_Cards.push_back(new_Card);
}

void Hand::h_Clear()
{
	m_Cards.clear();
}

int Hand::h_get_total() const
{
	int total = 0;
	bool flag_ace = false;
	for (std::vector<Card*>::iterator card = m_Cards.begin(); card != m_Cards.end();++card) {
		Card* current_card = *card;
		if (current_card->get_value() == c_value::ace) flag_ace = true;
		total += static_cast<int>(current_card->get_value());
	}
	if ((total+10) < 21 && flag_ace) total += 10;
	return total;
}
