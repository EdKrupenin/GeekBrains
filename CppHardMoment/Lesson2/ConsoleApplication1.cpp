// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <algorithm>
#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <vector>
#include "Timer.h"


/// <summary>
/// Шаблоннаяя функция которая меняет местами содержание ссылок. Ссылки при этом остаюсться на своих местах.
/// </summary>
/// <typeparam name="Type">Шаблонный параметр</typeparam>
/// <param name="lhs">Левое значение</param>
/// <param name="rhs">Правое значение</param>
template<class Type>
void Swap(Type& lhs, Type& rhs)
{
	std::cout << &lhs << " - " << lhs << "\t" << &rhs << " - " << rhs << std::endl;
	Type buffer = std::move(lhs);
	lhs = std::move(rhs);
	rhs = std::move(buffer);
	std::cout << &lhs << " - " << lhs << "\t" << &rhs << " - " << rhs << std::endl;
}

/// <summary>
/// Шаблонная функция SortPointers - сортирует указатели по значениям, на которые они указывают
/// </summary>
/// <typeparam name="Type">Тип указателей</typeparam>
/// <param name="Pointers">вектор указателей</param>
template<class Type>
void SortPointers(std::vector<Type*> Pointers)
{
	std::sort(Pointers.begin(), Pointers.end(), [](Type* lhs, Type* rhs)->bool
		{
			return *lhs < *rhs;
		});
}

int CountForFor(std::string& inputString, std::string& vowels)
{
	int counter{};
	std::string_view iString = inputString;
	Timer timer("For-for");
	for (auto _vowels : vowels)
	{
		for (auto _word : iString)
		{
			if (_vowels == _word)
				counter++;
		}
	}
	timer.print();
	return  counter;
}

int CountForFind(std::string& inputString, std::string& vowels)
{
	int counter{};
	std::string_view iString = inputString;
	Timer timer("For-find");
	size_t pos{};
	for (auto i_string : iString)
	{
		pos = vowels.find(i_string);
		if (pos != std::string::npos)
			counter++;
	}
	timer.print();
	return  counter;
}

int CountCount_ifFor(std::string& inputString, std::string& vowels)
{
	int counter{};
	std::string_view iString = inputString;
	const Timer timer("Count_if-for");
	for (const char i_vowel : vowels)
	{
		counter += std::count_if(iString.begin(), iString.end(), [i_vowel](auto i_string)->bool {return i_vowel == i_string; });
	}
	timer.print();
	return  counter;
}


int CountCount_ifFind(std::string& inputString, std::string& vowels){
	int counter{};
	std::string_view iString = inputString;
	const Timer timer("Count_if - Find");
	counter = std::count_if(iString.begin(), iString.end(), [vowels](auto i_String) {return vowels.find(i_String) != std::string::npos ? true : false; });
	timer.print();
	return  counter;
}

int CountRegex(std::string& inputString)
{
	int counter{};
	std::regex regular("([aeiouyAEIOUY])");
	std::smatch result;                      //Результат поиска с помощью регулярного выражения
	const Timer timer("Count_if - Find");
	//std::regex_search(inputString, result, regular, std::regex_constants::format_no_copy);
	//counter = result.size();
	timer.print();
	return  counter;
}

int main()
{
	std::string first = "alfa";
	std::string second = "betta";
	Swap<std::string>(first, second);


	std::ifstream file("War and peace.txt");
	file.seekg(0, std::ios::end);
	const size_t size = file.tellg();
	file.seekg(0);
	std::string s(size, ' ');
	file.read(&s[0], size);
	std::string vowels = { "aeiouyAEIOUY"};
	
	int count1 = CountForFor(s, vowels);
	int count2 = CountForFind(s, vowels);
	int count3 = CountCount_ifFor(s, vowels);
	int count4 = CountCount_ifFor(s, vowels);
	//int count5 = CountRegex(s);
	std::cout << count1 << " " << count2<< " "<< count3<< " "<<count4 << std::endl;	
}