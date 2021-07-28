#pragma once
class House
{
public:
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

