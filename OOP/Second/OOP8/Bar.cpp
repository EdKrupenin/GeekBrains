#include "Bar.h"

void Bar::set(int a)
{
	if (y + a > 100)
		throw Ex(a * y);
	else
		y = a;
}
