#include "House.h"


House::House(const std::string name) : GenericPlayer(name)
{
}

House::~House()
{
}

bool House::IsHitting() const
{
    return (h_get_total() <= 16);
}

void House::FlipFirstCard()
{
    if (!(m_Cards.empty())) {
        m_Cards[0]->flip();
    }else
    {
        std::cout << "No cards to flip";
    }
}
