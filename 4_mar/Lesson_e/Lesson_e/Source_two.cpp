#include <iostream>
#include "Source_three.h"
namespace Lesson_E {
	//2e-------------------------------------
	int* massive(int size_a) {
		int* arr;
		arr = new int[size_a];
		return arr;
	}
	void freeMassive(int* arr) {
		delete[] arr;
	}
	void initMass(int* arr, size_t length) {
		int j = 1;
		for (size_t i = 0; i < length; i++)
		{
			arr[i] = j;
			j += 3;
		}
	}
	//----------------------------------------

}