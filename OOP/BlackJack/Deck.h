#pragma once
#include "Stdafx.h"
#include "Hand.h"
#include "GenericPlayer.h"

class Deck
{
public:
	/// <summary>
	/// —оздает стандартную колоду из 52 карт
	/// </summary>
	void Populate();
	/// <summary>
	/// “асует карты
	/// </summary>
	void Shuffle();
	/// <summary>
	/// –аздает в руку одну карту
	/// </summary>
	void Deal(Hand& aHand);
	/// <summary>
	/// –аздает игроку дополнительные карты до тех пор, пока он может и хочет их получать
	/// </summary>
	void AddltionalCards(GenericPlayer& aGenerlcPlayer);

};

