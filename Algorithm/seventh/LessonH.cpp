// LessonG.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>


int* initIntArrayRandom(size_t len) {
	int* arr = new int[len]; //выделяем память
	for (size_t i = 0; i < len; ++i)
		arr[i] = rand() % 100;
	return arr;
}

/// <summary>
/// Функция - заполенеие массива конкретными значениями
/// </summary>
/// <param name="matrix"> ссылка на массив</param>
/// <param name="len">длина аргументов массива</param>
/// <param name="">Аргументы массива</param>
int* initIntArrayValues(int len, ...) {
	int* arr = new int[len]; //выделяем память
	va_list args;
	__crt_va_start(args, len);
	for (size_t i = 0; i < len; i++)
		arr[i] = __crt_va_arg(args, int);
	__crt_va_end(args);
	return arr;
}

void printArray(int* array, int len) {
	for (size_t j = 0; j < len; j++)
		std::cout << array[j] << " ";
	std::cout << std::endl;
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

void fillZero2dIntArray(int** array, int row, int col) {
	for (size_t i = 0; i < row; i++)
		for (size_t j = 0; j < col; j++)
			array[i][j] = 0;
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
/// Функция замены агрументов местами
/// </summary>
/// <param name="a">аргумент 1</param>
/// <param name="b">аргумент 2</param>
void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int mid(int* arr, int first, int midle, int last) {
	if ((arr[first] >= arr[midle] && arr[first] <= arr[last])
		|| (arr[first] <= arr[midle] && arr[first] >= arr[last]))
		return first;
	if ((arr[midle] >= arr[first] && arr[midle] <= arr[last])
		|| (arr[midle] <= arr[first] && arr[midle] >= arr[last]))
		return midle;
	if ((arr[last] >= arr[midle] && arr[first] >= arr[last])
		|| (arr[last] <= arr[midle] && arr[first] <= arr[last]))
		return last;
}

/// <summary>
/// Улучшенная быстрая сортировка
/// </summary>
/// <param name="arr">массив который подаеться на вход</param>
/// <param name="first">индекс первого элемента</param>
/// <param name="last">индекс последнего элемента</param>
void cleverFastSort(int* arr, int first, int last) {
	int range = 10;
	if (first + last >= range) {
		int indexMid = mid(arr, first, ((first + last) / 2), last);
		swap(&arr[indexMid], &arr[((first + last) / 2)]);
		int i = first;
		int j = last;
		int refernce = arr[(first + last) / 2];
		do {
			while (arr[i] < refernce)i++;
			while (arr[j] > refernce)j--;
			if (i <= j) {
				swap(&arr[i], &arr[j]);
				i++;
				j--;
			}
		} while (i <= j);
		if (i < last) cleverFastSort(arr, i, last);
		if (j > first) cleverFastSort(arr, first, j);
	}
	else {
		for (size_t i = 1; i < range; i++)
		{
			int tmp = arr[i];
			int pos = i - 1;
			while (pos >= 0 && arr[pos] > tmp) {
				arr[pos + 1] = arr[pos];
				pos--;
			}
			arr[pos + 1] == tmp;
		}
	}
}

/// <summary>
/// Функция для вычисления разрядности числа
/// </summary>
/// <param name="arr">ссылка на массив</param>
/// <param name="length">длина массива</param>
/// <returns></returns>
int maxRazr(int* arr, int length) {
	int max = 0;
	int i = 1;
	for (size_t i = 0; i < length; i++)
		if (arr[i] > max) max = arr[i];
	while ((max / i) > 0) i *= 10;
	return i;
}

void bucketSort(int* arr, const int length) {
	const int max = length; //максимальное кол-во элементов каждой корзине.
	const int block = 10; //константа для обосночения корзины
	int raz = maxRazr(arr,length); //вычисляем разряд для ограничения в обходе корзин
	int** buckets = init2dIntArray(block, (max + 1)); //содержит в себе все корзины и их содержимое 
	//+1 это нужно для хранения не только значений, но и счетчика заполенения
	fillZero2dIntArray(buckets, block, (max + 1)); // заполняем нулями получившийся массив
	//Записываем в корзины эл. последовательно сортируя в каждом из разрядов
	for (size_t digit = 1; digit < raz; digit *= 10) {
		for (size_t i = 0; i < max; ++i) {
			int d = (arr[i] / digit) % block;
			if (arr[i] % 2 == 0)
				buckets[d][buckets[d][max]++] = arr[i];
		}
		int index = 0; //вспомогательная индексирующая переменная
		for (size_t i = 0; i < block; i++)
		{
			for (size_t j = 0; j < buckets[i][max]; j++)
			{
				while (arr[index] % 2 != 0) { index++; }
				arr[index++] = buckets[i][j];
			}
			buckets[i][max] = 0;
		}
	}
	free_memory2dIntArray(buckets, block, (max + 1));
}

int main()
{
	int* cleverArr = initIntArrayRandom(100);
	int* busckArr = initIntArrayValues(12,0,2,8,3,4,6,5,9,8,2,7,30);
	cleverFastSort(cleverArr, 0, 99);
	printArray(cleverArr, 100);
	bucketSort(busckArr, 12);
	printArray(busckArr, 12);
	delete[] cleverArr;
	delete[] busckArr;
}
