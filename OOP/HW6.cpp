#include <iostream>
#include "Date.h"

/// <summary>
/// Можно написать собственный класс но в STL уже все есть
/// </summary>
/// <typeparam name="T"></typeparam>
template<class T>
class Auto_ptr {
	T* m_ptr;
public:
	/// Конструктор
	/// \param ptr то из чего надо сдлеать умный указатель
	Auto_ptr(T* ptr = nullptr) : m_ptr(ptr)
	{}

	~Auto_ptr() {
		delete m_ptr;
	}

	/// Перегрузка оператора разыменования, чтобы иметь возможность использовать Auto_ptr1 как m_ptr
	/// \return то на что указывает указатель
	T& operator* () { return *m_ptr; }

	/// Перегрузка оператора оператора ->, чтобы иметь возможность использовать Auto_ptr1 как m_ptr
	/// \return возврщаем сам указатель
	T* operator->() { return m_ptr; }
};

void comparisonDate(const std::unique_ptr<Date>& date1, const std::unique_ptr<Date>& date2) {
	std::cout << (*date1 < *date2);
	
}

void exchangeDate(std::unique_ptr<Date>& date1, std::unique_ptr<Date>& date2) {
	auto date = std::move(date1);
	date1 = std::move(date2);
	date2 = std::move(date);
}

int main() {
	//Auto_ptr<Date> today = new Date();
	std::unique_ptr<Date> today(new Date());
	today->set_day(5);
	today->set_month(8);
	today->set_year(2021);
	std::cout << "today - " << *today;
	auto date = std::unique_ptr<Date>();
	date = std::move(today);
	std::cout << "date - " << *date;
	if (today == nullptr)
		std::cout << "today is null Ptr \n";
	//-------------------------------------------------//
	std::unique_ptr<Date> date1(new Date(17,11,2021));
	std::unique_ptr<Date> date2(new Date(7,10,2021));
	comparisonDate(date1, date2);
	std::cout << "Date1 - " << *date1 << "Date 2 - " << *date2 << std::endl;
	std::swap(date1, date2);
	std::cout << "Date1 - " << *date1 << "Date 2 - "<< *date2 << std::endl;
	return 0;
}