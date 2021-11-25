#include "Matrix.h"
#include "Iterator.h"

/// <summary>
/// Добавляет в конец листа стреднее арифметическое его элементов
/// </summary>
/// <param name="iList">Ссылка на лист</param>
void listAverage(std::list<int>& iList)
{
	int average {};
	for (auto element : iList) {
		average += element;
	}
	average /= iList.size();
	iList.push_back(average);
}


int main()
{
	std::list<int> iList = { 1,2,3,4,5 };
	listAverage(iList);
	std::cout << iList.back()<<std::endl;
	
	int n{3}, m{3};
	auto matrix = Matrix(n, m);
	std::cout << "Matrix 1\n";
	matrix.fill_matrix();
	matrix.print_matrix();
	std::cout <<"Determinant = " << matrix.determinant(matrix.get_matrix(), matrix.get_size())<<std::endl;

	std::vector<int> vec1 = { 14,14,15 };
	auto my = Iterator(vec1);
	for (auto my1 : my)
	{
		std::cout << my1 <<" ";
	}
}
