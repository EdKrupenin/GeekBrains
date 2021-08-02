#pragma once
#include "Stdafx.h"
/*4. Создать класс Card, описывающий карту в игре БлэкДжек. У этого класса должно быть три поля: масть, значение карты и положение карты (вверх лицом или рубашкой).
Сделать поля масть и значение карты типом перечисления (enum). Положение карты - тип bool. Также в этом классе должно быть два метода:
метод Flip(), который переворачивает карту, т.е. если она была рубашкой вверх, то он ее поворачивает лицом вверх, и наоборот.
метод GetValue(), который возвращает значение карты, пока можно считать, что туз = 1.*/

/// <summary>
/// Enum - класс на основе int с мастями карт
/// </summary>
enum class c_suit :int
{
	HEART,
	CLUB,
	DIAMOND,
	SPADE,
};

/// <summary>
/// Enum-класс на основе int с номиналами карт
/// </summary>
enum class c_value : int
{
	ace = 1,
	two = 2,
	three = 3,
	four = 4,
	five = 5,
	six = 6,
	seven = 7,
	eight = 8,
	nine = 9,
	ten = 10,
	jack = 10,
	queen = 10,
	king = 10
};

/// <summary>
/// Класс карты
/// </summary>
class Card {
public:
	/// <summary>
	/// Масть карты
	/// </summary>
	c_suit suitCard;

	/// <summary>
	/// Номинал карты
	/// </summary>
	c_value valueCard;

	/// <summary>
	/// Положение карты на столе
	/// </summary>
	bool is_Face_Up;

	Card(c_suit Suit, c_value Value) : suitCard(Suit), valueCard(Value), is_Face_Up(false) {

	}
	/// <summary>
	/// Перевернуть карту
	/// </summary>
	void flip();

	/// <summary>
	/// Узнать номинал карты
	/// </summary>
	/// <returns>Значение карты</returns>
	c_value get_value() const;

	friend std::ostream& operator<< (std::ostream& out, const Card& card);
};
