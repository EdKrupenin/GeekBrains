#pragma once
#include "Stdafx.h"
#include "Hand.h"
#include "GenericPlayer.h"

class Deck : public Hand
{
public:
	Deck();

	virtual ~Deck();
	/// <summary>
	/// ������� ����������� ������ �� 52 ����
	/// </summary>
	void Populate();
	/// <summary>
	/// ������ �����
	/// </summary>
	void Shuffle();
	/// <summary>
	/// ������� � ���� ���� �����
	/// </summary>
	void Deal(Hand& aHand);
	/// <summary>
	/// ������� ������ �������������� ����� �� ��� ���, ���� �� ����� � ����� �� ��������
	/// </summary>
	void AddltionalCards(GenericPlayer& aGenericPlayer);

};

