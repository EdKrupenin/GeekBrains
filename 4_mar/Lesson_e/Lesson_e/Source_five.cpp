#include <iostream>

namespace Lesson_E {
	//5e--------------------------------------
	//Можно было использовать вектора но мы их еще не проходили)
	//по этому было принято решение передать рамер массива в байтах и поделить на тип данных, это же задается железно из условия
	//по факту на вход может подаваться массив любой длины, но это можно использовать только со статическим массивом.
	void swapZeroOneAnyLenght(int* arr, size_t lenght) {
		lenght /= sizeof(int);
		for (size_t i = 0; i < lenght; i++)
		{
			arr[i] = (!arr[i]);
		}
	}

	int* swapZeroOneLongArg(int countpara, ...) {
		int* Array = new int[countpara];
		int j = 0;
		va_list lst;
		__crt_va_start(lst, countpara);
		for (size_t i = 0; i < countpara; i++) {
			Array[j] = __crt_va_arg(lst, int);
			j++;
		}
		__crt_va_end(lst);
		for (size_t i = 0; i < countpara; i++)
		{
			Array[i] = (!Array[i]);
		}
		return Array;
	}
	//----------------------------------------
}