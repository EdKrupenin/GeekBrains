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
	/// ���������, ����� �� ������ ��� ���� �����
	/// </summary>
	/// <returns>�� ��� ���</returns>
	virtual bool IsHitting() const;
	/// <summary>
	/// ���������, ��� ����� �������
	/// </summary>
	void Win() const;
	/// <summary>
	/// ���������, ��� ����� ��������
	/// </summary>
	void Lose() const;
	/// <summary>
	/// ���������, ��� ����� ������ ������
	/// </summary>
	void Push() const;
};

