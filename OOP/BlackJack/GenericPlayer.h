#pragma once
#include <string>
#include <iostream>
#include "Hand.h"

class GenericPlayer : public Hand
{
	/// <summary>
	/// ��� ������
	/// </summary>
	std::string m_Name{};
public:
	GenericPlayer(std::string name) : Hand(), m_Name(name)
	{}

	/// <summary>
	/// ���������, ����� �� ������ ��� ���� �����.������ ����������� �������
	/// </summary>
	/// <returns>�� ��� ���</returns>
	virtual bool IsHitting() const = 0;

	/// <summary>
	/// ���������, ��� � ������ �������
	/// </summary>
	/// <returns></returns>
	bool IsBoosted() const;

	/// <summary>
	/// ������� �� ����� ��� ������ � ���������, ��� � ���� �������
	/// </summary>
	void Bust() const;
};

