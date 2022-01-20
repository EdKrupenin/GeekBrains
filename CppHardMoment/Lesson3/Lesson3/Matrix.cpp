#include "Matrix.h"

/// <summary>
/// ����������� �������
/// </summary>
/// <param name="n">������� ������</param>
/// <param name="m">������ ������</param>
Matrix::Matrix(size_t n, size_t m) : _n(n), _m(m)
{
	_matrix.resize(_n, std::vector<int>(_m));
}

/// <summary>
/// ������ � �������� �������
/// </summary>
/// <param name="i">���������� I</param>
/// <param name="j">���������� J</param>
/// <returns></returns>
int& Matrix::get_element(size_t i, size_t j)
{
	if (i > _n && j > _m) {
		std::cout << "Bad range!!!";
	}
	return _matrix[i][j];
}

/// <summary>
/// ����� ������� � �������...
/// </summary>
void Matrix::print_matrix()
{
	for (auto row : this->_matrix)
	{
		std::cout << '[';
		for (auto element : row)
			std::cout<< element << " ";
		std::cout << ']' << std::endl;
	}
}

/// <summary>
/// ����������� ����� ���������� ������������...
/// </summary>
/// <param name="i_matrix">������ �� �������� �������</param>
/// <param name="n">������ �������� �������</param>
/// <returns></returns>
int Matrix::determinant(std::vector<std::vector<int>>& i_matrix, size_t n) const
{
	int answer{};
	if (this->_n != this->_m)
	{
		std::cout << "Bad Matrix!";
		return -1;
	}
	switch (n)
	{
	case 1:
		return i_matrix[0][0]; //������� ������ ����� ������� 1 * 1
	case 2:
		return (i_matrix[0][0] * i_matrix[1][1] - i_matrix[0][1] * i_matrix[1][0]); // ������� ������ ������� 2*2
	default:
		for (size_t k = 0; k < n; ++k) {
			std::vector<std::vector<int>> o_matrix((n - 1), std::vector<int>((n - 1)));
			for (size_t i = 1; i < n; i++) { //������� ������
				size_t t = 0;
				for (size_t j = 0; j < n; j++) {
					if (j == k)
						continue; //������� ������� � �� ����� ���������� ������� t
					o_matrix[i - 1][t] = i_matrix[i][j];
					t++;
				}
			}
			answer += pow(-1, k+2) * i_matrix[0][k] * determinant(o_matrix, n - 1); //���������� �������� ������� ������������...
		}
	}
	return answer; //���������� �������� ������������
}

/// <summary>
/// ������ � ������� �� ������
/// </summary>
/// <returns>������ �� ������ �������</returns>
std::vector<std::vector<int>>& Matrix::get_matrix()
{
	return this->_matrix;
}

/// <summary>
/// ������ � ������� �������
/// </summary>
/// <returns>������ �� ������ �������</returns>
size_t& Matrix::get_size()
{
	return this->_n;
}

/// <summary>
/// ��������� ������� ���������� ���������� �� 0 �� 10
/// </summary>
void Matrix::fill_matrix()
{
	for (size_t i = 0; i< _n; ++i)
	{
		for (size_t j = 0; j < _n; ++j)
			this->_matrix[i][j] = rand() % 10;
	}
}
