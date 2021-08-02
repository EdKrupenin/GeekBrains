#include "Card.h"

void Card::flip() {
	conditionCard = !(conditionCard);
}
c_value Card::get_value() const {
	return valueCard;
}