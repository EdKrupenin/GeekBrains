#pragma once

/*4. ������� ����� Card, ����������� ����� � ���� ��������. � ����� ������ ������ ���� ��� ����: �����, �������� ����� � ��������� ����� (����� ����� ��� ��������).
������� ���� ����� � �������� ����� ����� ������������ (enum). ��������� ����� - ��� bool. ����� � ���� ������ ������ ���� ��� ������:
����� Flip(), ������� �������������� �����, �.�. ���� ��� ���� �������� �����, �� �� �� ������������ ����� �����, � ��������.
����� GetValue(), ������� ���������� �������� �����, ���� ����� �������, ��� ��� = 1.*/

/// <summary>
/// Enum - ����� �� ������ int � ������� ����
/// </summary>
enum class c_suit :int
{
	HEART,
	CLUB,
	DIAMOND,
	SPADE,
};

/// <summary>
/// Enum-����� �� ������ int � ���������� ����
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
/// ����� �����
/// </summary>
class Card {
	/// <summary>
	/// ����� �����
	/// </summary>
	c_suit suitCard;

	/// <summary>
	/// ������� �����
	/// </summary>
	c_value valueCard;

	/// <summary>
	/// ��������� ����� �� �����
	/// </summary>
	bool conditionCard;
public:
	Card(c_suit Suit, c_value Value) : suitCard(Suit), valueCard(Value), conditionCard(false) {

	}
	/// <summary>
	/// ����������� �����
	/// </summary>
	void flip();

	/// <summary>
	/// ������ ������� �����
	/// </summary>
	/// <returns>�������� �����</returns>
	c_value get_value() const;
};

