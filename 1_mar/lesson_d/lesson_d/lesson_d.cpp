#include <iostream>

int main()
{
	//1
	int a, b;
	std::cout << "Ввведите число 1" << std::endl;
	std::cin >> a;
	std::cout << "Ввведите число 2" << std::endl;
	std::cin >> b;
	if (((a + b) >= 10) && ((a + b) <= 20)) std::cout << "True" << std::endl;
	else std::cout << "False" << std::endl;

	//2
	int d;
	std::cout << "Ввведите число" << std::endl;
	std::cin >> d;
	int i = 2;
	// начинаем с 2 намерено и ищем только 1 делитель тогда число будет простым
	while ((d % i != 0) && (i < d)) {
		i++;
	}
	std::cout << ((i == d) ? "Yes" : "No") << std::endl;

	//3
	int e, f;
	e = 5;
	f = 5;
	if (((e + f) == 10) || ((e == 10 && f == 10)))std::cout << "True" << std::endl;
	else std::cout << "False" << std::endl;

	//4
	int year;
	std::cin >> year;
	if (year % 4 == 0) {
		if (year % 100 == 0) {
			if (year % 400 == 0) {
				std::cout << "Високосный" << std::endl;
			}
			else{
				std::cout << "Simple" << std::endl;
			}
		}
		else{
			std::cout << "Високосный" << std::endl;
		}
	}
	else{
		std::cout << "Simple" << std::endl;
	}

}