#pragma once
#include "Stdafx.h"
#include "GenericPlayer.h"
#include "Hand.h"

class Player : public GenericPlayer
{
public:
	Player(const std::string name = "");

	virtual ~Player();

	/// <summary>
	/// ”казывает, нужна ли игроку еще одна карта
	/// </summary>
	/// <returns>ƒа или нет</returns>
	virtual bool IsHitting() const;
	/// <summary>
	/// ќбъ€вл€ет, что игрок выиграл
	/// </summary>
	void Win() const;
	/// <summary>
	/// ќбъ€вл€ет, что игрок проиграл
	/// </summary>
	void Lose() const;
	/// <summary>
	/// ќбъ€вл€ет, что игрок сыграл вничью
	/// </summary>
	void Push() const;
};

