#include "Game.h"
#include <algorithm>


Game::Game(const std::vector<std::string>& names)
{
    std::vector<std::string>::const_iterator pName;
	for (pName = names.begin(); pName != names.end(); ++pName)
    {
		m_Players.push_back(Player(*pName));
	}

	srand(static_cast<unsigned int>(time(0)));
	m_Deck.Populate();
	m_Deck.Shuffle();
}

void Game::Play()
{
    // раздает каждому по две стартовые карты
    std::vector<Player>::iterator pPlayer;
    for (int i = 0; i < 2; ++i)
    {
        for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
        {
            m_Deck.Deal(*pPlayer);
        }
        m_Deck.Deal(m_House);
    }

    // прячет первую карту дилера
    m_House.FlipFirstCard();

    // открывает руки всех игроков
    for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
    {
       std::cout << *pPlayer << std::endl;
    }
    std::cout << m_House << std::endl;

    // раздает игрокам дополнительные карты
    for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
    {
        m_Deck.AddltionalCards(*pPlayer);
    }

    // показывает первую карту дилера
    m_House.FlipFirstCard();
    std::cout << std::endl << m_House;

    // раздает дилеру дополнительные карты
    m_Deck.AddltionalCards(m_House);

    if (m_House.IsBoosted())
    {
        // все, кто остался в игре, побеждают
        for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
        {
            if (!(pPlayer->IsBoosted()))
            {
                pPlayer->Win();
            }
        }
    }
    else
    {
        // сравнивает суммы очков всех оставшихся игроков с суммой очков дилера
        for (pPlayer = m_Players.begin(); pPlayer != m_Players.end();
            ++pPlayer)
        {
            if (!(pPlayer->IsBoosted()))
            {
                if (pPlayer->h_get_total() > m_House.h_get_total())
                {
                    pPlayer->Win();
                }
                else if (pPlayer->h_get_total() < m_House.h_get_total())
                {
                    pPlayer->Lose();
                }
                else
                {
                    pPlayer->Push();
                }
            }
        }

    }

    // очищает руки всех игроков
    for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
    {
        pPlayer->h_Clear();
    }
    m_House.h_Clear();
    //Распаковываем новую колоду
    m_Deck.Populate();
    //Тасуем карты
    m_Deck.Shuffle();
}
