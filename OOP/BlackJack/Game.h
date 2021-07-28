#pragma once
#include "Deck.h"
#include "House.h"
#include "Player.h"
#include <vector>
class Game
{
	/// <summary>
	/// ������ ����
	/// </summary>
	Deck m_Deck{};
	/// <summary>
	/// ���� ������
	/// </summary>
	House m_House{};
	/// <summary>
	/// ������ ������� - �����.������, ���������� ������� ���� Player
	/// </summary>
	std::vector<Player> m_Players{};
public:
	/// <summary>
	/// �������� ��� ���� Blackjack
	/// </summary>
	void Play();
};
