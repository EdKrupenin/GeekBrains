// OOP8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdexcept>
#include "Bar.h"
#include "Ex.h"
#include  "Robot.h"

template<typename T>
T divide(const T& rValue, const T& lValue)
{
	if (rValue == 0)
		throw std::overflow_error("Divide by zero exception");
	return  (rValue / lValue);
}

int main()
{
	int a{};
	try
	{
		a = divide<int>(0, 6);
	}
	catch (std::overflow_error& e)
	{
		std::cout << e.what() << " -> ";
	}
	std::cout << a << std::endl;
	/*----------------------------------------------*/
	Bar bar = Bar();
	try
	{
		int input{};
		std::cin >> input;
		bar.set(input);
	}
	catch (Ex & ex)
	{
		std::cout << ex.what();
	}
	/*----------------------------------------------*/
	
	Robot r = Robot();
	try
	{
		r.move(static_cast<direction>(1));
	}
	catch (OffTheField& er2)
	{
		std::cout << er2.what() << std::endl;
	}
	try
	{
		r.move(static_cast<direction>(5));
	}
	catch (IllegalCommand& er1)
	{
		std::cout<<er1.what()<<std::endl;
	}

}

