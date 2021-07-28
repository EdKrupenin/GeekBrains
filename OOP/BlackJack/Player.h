#pragma once
class Player
{
public:
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

