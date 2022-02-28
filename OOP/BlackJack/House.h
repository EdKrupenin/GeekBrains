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
	/// ���������, ����� �� ������ ��� ���� �����
	/// </summary>
	/// <returns>�� ��� ���</returns>
	virtual bool IsHitting() const;

	/// <summary>
	/// �������������� ������ �����
	/// </summary>
	void FlipFirstCard();
};

