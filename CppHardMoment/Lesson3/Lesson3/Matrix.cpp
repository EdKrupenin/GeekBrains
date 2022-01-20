#include "Matrix.h"

/// <summary>
/// Конструктор матрицы
/// </summary>
/// <param name="n">Размеры ширины</param>
/// <param name="m">Размер высоты</param>
Matrix::Matrix(size_t n, size_t m) : _n(n), _m(m)
{
	_matrix.resize(_n, std::vector<int>(_m));
}

/// <summary>
/// Доступ к элементу матрицы
/// </summary>
/// <param name="i">Координата I</param>
/// <param name="j">Координата J</param>
/// <returns></returns>
int& Matrix::get_element(size_t i, size_t j)
{
	if (i > _n && j > _m) {
		std::cout << "Bad range!!!";
	}
	return _matrix[i][j];
}

/// <summary>
/// Вывод матрицы в консоль...
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
/// Рекурсивный метод вычисления определителя...
/// </summary>
/// <param name="i_matrix">Ссылка на исходную матрицу</param>
/// <param name="n">Размер исходной матрицы</param>
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
		return i_matrix[0][0]; //Частный случай когда матрица 1 * 1
	case 2:
		return (i_matrix[0][0] * i_matrix[1][1] - i_matrix[0][1] * i_matrix[1][0]); // частный случай матрицы 2*2
	default:
		for (size_t k = 0; k < n; ++k) {
			std::vector<std::vector<int>> o_matrix((n - 1), std::vector<int>((n - 1)));
			for (size_t i = 1; i < n; i++) { //Убираем строку
				size_t t = 0;
				for (size_t j = 0; j < n; j++) {
					if (j == k)
						continue; //Убираем столбец и по этому используем счетчик t
					o_matrix[i - 1][t] = i_matrix[i][j];
					t++;
				}
			}
			answer += pow(-1, k+2) * i_matrix[0][k] * determinant(o_matrix, n - 1); //Рекурсивно вызываем функцию определителя...
		}
	}
	return answer; //Возвращаем найденый определитель
}

/// <summary>
/// Доступ к матрице по ссылке
/// </summary>
/// <returns>ссылка на вектор матрицы</returns>
std::vector<std::vector<int>>& Matrix::get_matrix()
{
	return this->_matrix;
}

/// <summary>
/// Доступ к размеру матрицы
/// </summary>
/// <returns>ссылка на размер матрицы</returns>
size_t& Matrix::get_size()
{
	return this->_n;
}

/// <summary>
/// Заполнить матрицу случайными значениями от 0 до 10
/// </summary>
void Matrix::fill_matrix()
{
	for (size_t i = 0; i< _n; ++i)
	{
		for (size_t j = 0; j < _n; ++j)
			this->_matrix[i][j] = rand() % 10;
	}
}
