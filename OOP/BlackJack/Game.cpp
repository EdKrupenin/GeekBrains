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
    // ������� ������� �� ��� ��������� �����
    std::vector<Player>::iterator pPlayer;
    for (int i = 0; i < 2; ++i)
    {
        for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
        {
            m_Deck.Deal(*pPlayer);
        }
        m_Deck.Deal(m_House);
    }

    // ������ ������ ����� ������
    m_House.FlipFirstCard();

    // ��������� ���� ���� �������
    for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
    {
       std::cout << *pPlayer << std::endl;
    }
    std::cout << m_House << std::endl;

    // ������� ������� �������������� �����
    for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
    {
        m_Deck.AddltionalCards(*pPlayer);
    }

    // ���������� ������ ����� ������
    m_House.FlipFirstCard();
    std::cout << std::endl << m_House;

    // ������� ������ �������������� �����
    m_Deck.AddltionalCards(m_House);

    if (m_House.IsBoosted())
    {
        // ���, ��� ������� � ����, ���������
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
        // ���������� ����� ����� ���� ���������� ������� � ������ ����� ������
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

    // ������� ���� ���� �������
    for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
    {
        pPlayer->h_Clear();
    }
    m_House.h_Clear();
    //������������� ����� ������
    m_Deck.Populate();
    //������ �����
    m_Deck.Shuffle();
}
