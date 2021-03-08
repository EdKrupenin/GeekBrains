#include <iostream>
#include "Source_two.h"

//1e
namespace Lesson_E{
	void swapZeroOne(int* arr, size_t length) {
		for (size_t i = 0; i < length; i++)
		{
			arr[i] = (!arr[i]);
		}
	}

	void printMass(int* arr, size_t lenght) {
		for (size_t i = 0; i < lenght; i++)
		{
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
	}
}
//---------------------------------------


//3e--------------------------------------
//----------------------------------------

//4e--------------------------------------
//----------------------------------------

int main()
/*
* Написать функцию, в которую передается не пустой одномерный целочисленный массив, функция должна вернуть
истину если в массиве есть место, в котором сумма левой и правой части массива равны.
Примеры: checkBalance([1, 1, 1, || 2, 1]) → true, checkBalance ([2, 1, 1, 2, 1]) → false,
checkBalance ([10, || 1, 2, 3, 4]) → true. Абстрактная граница показана символами ||, эти символы в массив не входят.

* Написать функцию, которой на вход подаётся одномерный массив и число n (может быть положительным, или отрицательным),
при этом функция должна циклически сместить все элементы массива на n позиций.

** Написать функцию из первого задания так, чтобы она работала с аргументом переменной длины.

** Написать все функции в отдельных файлах в одном пространстве имён,
вызвать их на исполнение в основном файле программы используя указатели на функции.*/
{
	std::cout << "Hello World!\n";
	//1е задание
	int mass[] = { 1, 1, 0, 0, 1, 0, 1, 1, 0, 0 };
	Lesson_E::swapZeroOne(mass, 10);
	Lesson_E::printMass(mass, (sizeof(mass) / sizeof(int)));
	std::cout << sizeof(mass) << std::endl;

	//2е задание
	int* mass2 = Lesson_E::massive(8);
	Lesson_E::initMass(mass2, 8);
	Lesson_E::printMass(mass2, 8);
	Lesson_E::freeMassive(mass2);

	//4е задание
	int mass3[] = { 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 0, 1 };
	Lesson_E::swapZeroOneAnyLenght(mass3, sizeof(mass3));
	Lesson_E::printMass(mass3, (sizeof(mass3)/sizeof(int)));
}
