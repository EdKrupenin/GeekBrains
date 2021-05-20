// LessonG.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "LessonG.h"
const int ROW = 3;
const int COL = 3;

void print2dArray(int** array, int row, int col) {
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			std::cout << array[i][j] << " ";
		}
		std::cout << std::endl;
	}
}


/// <summary>
/// Функция выделяет память под двумерный массив 
/// </summary>
/// <param name="row">размер строк</param>
/// <param name="col">размер столбцов</param>
/// <returns>возвращаем ссылку на фрагмент выдленной памяти</returns>
int** init2dIntArray(size_t row, size_t col) {
	int** arr = new int* [row]; //выделяем память на row ссылок
	arr[0] = new int[row * col];   //выделяем в первой ячейке память под весь массив
	for (size_t i = 1; i != row; i++) {
		arr[i] = arr[i - 1] + col; // переписываем ссылки на участки памяти
	}
	// Приемущество данного подхода оператор new вызывается всего лишь два раза, независимо от размерности массива
	return arr;
}

/// <summary>
///  Функция для очистки памяти
/// </summary>
/// <param name="arr">массив который надо удалить</param>
/// <param name="row">размер строк</param>
/// <param name="col">размер столбцов</param>
void free_memory2dIntArray(int** arr, size_t row, size_t col) {
	delete[] arr[0];
	delete[] arr;
}

/// <summary>
/// Функция - заполенеие массива конкретными значениями
/// </summary>
/// <param name="matrix"> ссылка на массив</param>
/// <param name="cols">количество коловнок</param>
/// <param name="row">количество строк</param>
/// <param name="leghtAgrs">длина аргументов массива</param>
/// <param name="">Аргументы массива</param>
void setLineValues(int** matrix, int cols, int row, int leghtAgrs, ...) {
	int j = 0;
	int k = 0;
	va_list args;
	__crt_va_start(args, leghtAgrs);
	for (size_t i = 0; i < leghtAgrs; i++)
	{
		matrix[j][k] = __crt_va_arg(args, int);
		if (k == (cols-1)) {
			k = 0;
			j++;
		}
		else k++;
	}
	__crt_va_end(args);
}

/// <summary>
/// Функция замены агрументов местами
/// </summary>
/// <param name="a">аргумент 1</param>
/// <param name="b">аргумент 2</param>
void swap(int* a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/// <summary>
/// Пузырьковая сортировка
/// </summary>
/// <param name="arr">сслыка на массив</param>
/// <param name="row">количество строк</param>
/// <param name="col">количество колонок</param>
void bubbleSort(int** arr, int row, int col) {
	for (size_t k = 0; k < row; ++k)
	{
		for (size_t l = 0; l < col; ++l)
		{
			for (size_t i = 0; i < row; ++i)
			{
				for (size_t j = 0; j < col; ++j)
				{
					if (i + 1 == row && j + 1 == col) continue;
					else {
						if ((j+1)==col && (arr[i][j] > arr[i+1][0]))
						{
							swap(&arr[i][j], &arr[i+1][0]);
						}
						else {
							if (arr[i][j] > arr[i][j + 1]) swap(&arr[i][j], &arr[i][j + 1]);
						}							
					}
				}
			}
		}
	}
}

/// <summary>
/// Мат часть от алгоритма Трабба-Прадо-Кнута
/// </summary>
/// <param name="a">ссылка на элемент массива</param>
/// <returns></returns>
double Math(int* a) {
	return sqrt(5 * pow(*a, 3) + fabs(*a));
}

/// <summary>
/// Алгоритм Трабба-Прадо-Кнута
/// </summary>
/// <param name="N">Коллчисетсво элементов</param>
void trabbaPrado(int N) {
	 
	std::cout << "Ввведите "<<N<<" чисел"<< std::endl;
	int* arrayP = new int[N];
	double Result = 0;
	for (size_t i = 0; i < N; i++)
	{
		std::cin >> arrayP[i];
	}
	for (size_t i = 0, j = N-1; i < N/2; i++, j--)
	{
		swap(&arrayP[i], &arrayP[j]);
	}
	for (size_t i = 0; i < N; i++)
	{
		if(Math(&arrayP[i])>400) std::cout <<i+1<<"-й элемент массива П, больше 400";
	}
	delete[] arrayP;
}

int main()
{
	int** bubbleArr = init2dIntArray(ROW, COL);
	setLineValues(bubbleArr, COL, ROW,COL*ROW, 1, 9, 2, 5, 7, 6, 4, 3, 8);
	print2dArray(bubbleArr, ROW, COL);
	std::cout << std::endl;
	bubbleSort(bubbleArr, ROW, COL);
	print2dArray(bubbleArr, ROW, COL);
	std::cout << std::endl;
	trabbaPrado(5);
	free_memory2dIntArray(bubbleArr, ROW, COL);
}
