#include "Source_five.h"
#include <math.h>
#include <iostream>

namespace Lesson_E {
	bool shift(int* arr, size_t length, int sht) {
		int* arrCopy = new int[length];
		for (size_t i = 0; i < length; i++) arrCopy[i] = arr[i];
		int j = 0;
		if (sht == 0) {
				delete[] arrCopy;
				return false;
		}
		int flag = (sht>0)?1:0;
		sht = abs(sht);
		while (sht > length) sht -= length;
		if (sht == length) return false;
		for (int i = 0; i < length; i++)
		{
			if (flag==1){
				if ((i + sht) < length) arr[i] = arrCopy[(i + sht)];
				else arr[i] = arrCopy[j++];
			}
			else {
				if ((sht - i) > 0)	arr[i] = arrCopy[(length -sht + i)];
				else arr[i] = arrCopy[j++];
			}	
		}
		delete[] arrCopy;
		return true;	
	}
}
