#pragma once
#include "Stdafx.h"
#include "Player.h"
#include "House.h"
#include "Deck.h"

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
	Game(const std::vector<std::string>& names);
	/// <summary>
	/// �������� ��� ���� Blackjack
	/// </summary>
	void Play();
};

