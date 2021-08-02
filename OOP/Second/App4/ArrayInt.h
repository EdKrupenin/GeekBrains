#pragma once
#pragma once
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

class ArrayInt
{
private:
	int m_length;
	int* m_data;
public:
	ArrayInt() : m_length(0), m_data(nullptr)
	{}
	ArrayInt(int length) : m_length(length)
	{
		assert(length >= 0); //Если длина будет меньше 0 будет исключение
		if (length > 0)
			m_data = new int[length];
		else
			m_data = nullptr;
	}
	~ArrayInt()
	{
		delete[] m_data;
	}

	/// <summary>
	/// Clear Array
	/// </summary>
	void erase();
	int& operator[] (int index);
	int get_length() const;
	void resize(int newLength);
	void insert_before(int value, int index);
	void push_back(int value);
	int pop_back();
	int pop_front();
	void sort() const;
	void print() const;
};
