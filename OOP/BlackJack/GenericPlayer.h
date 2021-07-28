#pragma once
#include <string>
#include <iostream>
#include "Hand.h"

class GenericPlayer : public Hand
{
	/// <summary>
	/// Имя игрока
	/// </summary>
	std::string m_Name{};
public:
	GenericPlayer(std::string name) : Hand(), m_Name(name)
	{}

	/// <summary>
	/// Указывает, нужна ли игроку еще одна карта.Чистая виртуальная функция
	/// </summary>
	/// <returns>Да или нет</returns>
	virtual bool IsHitting() const = 0;

	/// <summary>
	/// Указывает, что у игрока перебор
	/// </summary>
	/// <returns></returns>
	bool IsBoosted() const;

	/// <summary>
	/// Выводит на экран имя игрока и объявляет, что у него перебор
	/// </summary>
	void Bust() const;
};

