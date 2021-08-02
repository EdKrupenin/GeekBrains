#pragma once
#include "Stdafx.h"
#include "Player.h"
#include "House.h"
#include "Deck.h"

class Game
{
	/// <summary>
	/// Колода карт
	/// </summary>
	Deck m_Deck{};
	/// <summary>
	/// Рука дилера
	/// </summary>
	House m_House{};
	/// <summary>
	/// Группа игроков - людей.Вектор, содержащий объекты типа Player
	/// </summary>
	std::vector<Player> m_Players{};
public:
	/// <summary>
	/// Проводит кон игры Blackjack
	/// </summary>
	void Play();
};

