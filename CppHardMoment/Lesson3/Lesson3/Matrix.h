#pragma once
#include "Header.h"

class Matrix
{
	size_t _n{};
	size_t _m{};
	std::vector<std::vector<int>> _matrix; // ќбъ€вление вектора дл€ матрицы
public:
	Matrix(size_t n, size_t m);
	std::vector<std::vector<int>>& get_matrix();
	size_t& get_size();
	int& get_element(size_t i, size_t j);
	int determinant(std::vector<std::vector<int>>& matrix, size_t n) const;
	void print_matrix();
	void fill_matrix();
};

