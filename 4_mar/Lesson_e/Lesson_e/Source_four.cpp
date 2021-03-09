#include "Source_five.h"
#include <math.h>
#include <iostream>

namespace Lesson_E {
	bool shift(int* arr, size_t length, int sht) {
		int* arrCopy = new int[length];
		for (size_t i = 0; i < length; i++) arrCopy[i] = arr[i];
		int j = 0;

		if (sht > 0) {
			/*
			12345
			23451
			34512
			45123
			51234
			12345
			*/
			while (sht> length) sht -= length;
			if (sht == length) return false;
			for (size_t i = 0; i < length; i++)
			{
				if ((i + sht) < length) arr[i] = arrCopy[(i + sht)];
				else arr[i] = arrCopy[j++];
			}
			return true;
		}
		else if (sht < 0) {
			/*
			  12345
			  51234
			  45123
			  34512
			  23451
			  12345
			 */
			sht = abs(sht);
			while (sht > length) sht -= length;
			if (sht == length) return false;
			for (int i = 0; i < length; i++)
			{
				if ((sht - i) > 0)	arr[i] = arrCopy[(length -sht + i)];
				else arr[i] = arrCopy[j++];
			}
			return true;
		}
		else
		{
			if (sht == 0) return false;
		}
	}


}