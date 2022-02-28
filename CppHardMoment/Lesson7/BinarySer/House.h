#pragma once
#include "Stdafx.h"
#include "Hand.h"
#include "GenericPlayer.h"

class House : public GenericPlayer
{
public:
	House(const std::string name = "House");

	virtual ~House();

	/// <summary>
	/// Указывает, нужна ли игроку еще одна карта
	/// </summary>
	/// <returns>Да или нет</returns>
	virtual bool IsHitting() const;

	/// <summary>
	/// Переворачивает первую карту
	/// </summary>
	void FlipFirstCard();
};

