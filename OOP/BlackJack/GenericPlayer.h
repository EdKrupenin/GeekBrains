#pragma once
#include "Stdafx.h"
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

	/// <summary>
	/// Функция получения имени игрока
	/// </summary>
	/// <returns>Ссылку на строку с именем</returns>
	const std::string get_Name() const;

	friend std::ostream& operator<< (std::ostream& out, const GenericPlayer& player);
};

