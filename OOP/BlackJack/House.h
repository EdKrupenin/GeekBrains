#pragma once
class House
{
public:
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

