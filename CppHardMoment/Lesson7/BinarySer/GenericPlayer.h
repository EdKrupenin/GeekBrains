#pragma once
#include "Stdafx.h"
#include "Hand.h"


class GenericPlayer : public Hand
{
	/// <summary>
	/// ��� ������
	/// </summary>
	std::string m_Name{};
public:
	GenericPlayer(std::string name);
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

	/// <summary>
	/// ������� ��������� ����� ������
	/// </summary>
	/// <returns>������ �� ������ � ������</returns>
	const std::string get_Name() const;

	friend std::ostream& operator<< (std::ostream& out, const GenericPlayer& player);
};

