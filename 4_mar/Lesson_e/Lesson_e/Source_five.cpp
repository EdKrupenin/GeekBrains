#include <iostream>

namespace Lesson_E {
	//5e--------------------------------------
	//����� ���� ������������ ������� �� �� �� ��� �� ���������)
	//�� ����� ���� ������� ������� �������� ����� ������� � ������ � �������� �� ��� ������, ��� �� �������� ������� �� �������
	//�� ����� �� ���� ����� ���������� ������ ����� �����, �� ��� ����� ������������ ������ �� ����������� ��������.
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