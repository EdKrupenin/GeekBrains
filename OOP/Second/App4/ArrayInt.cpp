#include "ArrayInt.h"

void ArrayInt::erase()
{
	delete[] m_data;
	m_data = nullptr;
	m_length = 0;
}

int& ArrayInt::operator[](int index)
{
	assert(index >= 0 && index < m_length);
	return m_data[index];
}

int ArrayInt::get_length() const
{
	return m_length;
}

void ArrayInt::resize(int newLength)
{
	if (newLength == m_length)
		return;
	if (newLength <= 0) {
		erase();
		return;
	}

	int* data = new int[newLength];
	if (m_length > 0)
	{
		int elementsToCopy = (newLength > m_length) ? m_length : newLength;
		for (int index = 0; index < elementsToCopy; index++) {
			data[index] = m_data[index];
		}
	}

	delete[] m_data;
	m_data = data;
	m_length = newLength;
}

void ArrayInt::insert_before(int value, int index)
{
	assert(index >= 0 && index < m_length);

	int* data = new int[m_length + 1];

	for (int before = 0; before < index; ++before)
		data[before] = m_data[before];

	data[index] = value;

	for (int after = index; after < m_length; ++after)
		data[after + 1] = m_data[after];

	delete[] m_data;
	m_data = data;
	++m_length;
}

void ArrayInt::push_back(int value)
{
	insert_before(value, m_length);
}

int ArrayInt::pop_back()
{
	int answer = 0;
	if (m_data == nullptr) return NULL;
	else {
		answer = m_data[m_length - 1];
		resize(m_length - 1);
		return answer;
	}
}

int ArrayInt::pop_front()
{
	int answer = 0;
	if (m_data == nullptr) return NULL;
	answer = m_data[0];
	int* data = new int[m_length - 1];
	for (int index = 0; index < m_length - 1; index++)
		data[index] = m_data[index + 1];
	delete[] m_data;
	m_data = data;
	--m_length;
	return answer;
}

void ArrayInt::sort() const
{
	std::sort(m_data, m_data + m_length);
}

void ArrayInt::print() const
{
	for (int i = 0; i < m_length; i++)
		std::cout << m_data[i] << ' ';
	std::cout << std::endl;
}