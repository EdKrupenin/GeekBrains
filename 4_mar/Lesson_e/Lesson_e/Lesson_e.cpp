#include <iostream>
#include "Source_two.h"

//1e
namespace Lesson_E {
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

int main()
{
	//_______________________________

	void(*Funk)(int*, size_t);
	Funk = Lesson_E::swapZeroOne;

	void(*printArray)(int*, size_t);
	printArray = Lesson_E::printMass;

	//-------------------------------

	int* (*massiveMemo)(int);
	massiveMemo = Lesson_E::massive;

	void(*initlize)(int*, size_t);
	initlize = Lesson_E::initMass;

	void(*freeMemory)(int*);
	freeMemory = Lesson_E::freeMassive;

	//--------------------------------

	bool(*balance)(int*, size_t);
	balance = Lesson_E::Equals;

	//--------------------------------

	bool(*shifting)(int*, size_t, int);
	shifting = Lesson_E::shift;

	//---------------------------------

	int* (*oneMoreTime)(int, ...);
	oneMoreTime = Lesson_E::swapZeroOneLongArg;

	void(*exFive)(int*, size_t);
	exFive = Lesson_E::swapZeroOneAnyLenght;

	//____________________________________


	//1е задание
	int mass[] = { 1, 1, 0, 0, 1, 0, 1, 1, 0, 0 };
	(*Funk)(mass, 10);
	(*printArray)(mass, (sizeof(mass) / sizeof(int)));

	//2е задание
	int* mass2 = (*massiveMemo)(8);
	(*initlize)(mass2, 8);
	(*printArray)(mass2, 8);
	(*freeMemory)(mass2);

	//3е задание
	int massive[] = { 10,1,2,3,4 };
	std::cout << ((*balance)(massive, 5)) ? "Есть равновесие" : "Нет равновесия";
	std::cout << std::endl;

	//4е задание
	int massiveFout[] = { 1,2,3,4,5 };
	bool ans = (*shifting)(massiveFout, 5, -3);
	(*printArray)(massiveFout, 5);

	//5е задание
	int mass3[] = { 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 0, 1 };
	(*exFive)(mass3, sizeof(mass3));
	int* Mass5 = oneMoreTime(6,1,1,1,1,0,0);
	(*printArray)(Mass5, 6);
	(*printArray)(mass3, (sizeof(mass3) / sizeof(int)));
	(*freeMemory)(Mass5);
}
