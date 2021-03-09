#include "Source_four.h"

namespace Lesson_E {
	bool Equals(int* arr, size_t length) {
		int sum1 = 0, sum2 = 0;
		for (size_t i = 0; i < length; i++)
		{
			sum1 += arr[i];
			for (size_t j = (i+1); j < length; j++)
			{
				sum2 += arr[j];
			}
			if (sum1 == sum2) return true;
			sum2 = 0;
		}
		return false;
	}
}