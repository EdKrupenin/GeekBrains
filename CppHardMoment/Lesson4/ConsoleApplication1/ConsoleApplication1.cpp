#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <cstdlib>
#include <ctime>
#include <math.h>
#include <numeric>


/// <summary>
/// Универсальная фунцкия для вставки значения в отсортированную последотальность
/// </summary>
/// <typeparam name="Container">Тип контейнера</typeparam>
/// <typeparam name="T">Тип перменной содержащихся в контейнере</typeparam>
/// <param name="input">Ссылка на контейнер</param>
/// <param name="number">Обьект для вставки</param>
template<class  Container, class T>
void insert_sorted(Container& input, T number){
	bool reverse_flags{};
	if (input.front() > input.back()) {
		reverse_flags = true;
		std::reverse(input.begin(), input.end());
	}	
	input.emplace(std::lower_bound(input.begin(), input.end(), number), number);
	if (reverse_flags) {
		std::reverse(input.begin(), input.end());
	}
}

/// <summary>
/// Функция для печати контейнера в консоль
/// </summary>
/// <typeparam name="Container">Тип контейнера</typeparam>
/// <param name="input">Ссылка на контейнер</param>
template<class  Container>
void printContainer(Container& input) {
	std::cout << std::endl;
	for (auto element : input)
		std::cout << element << " ";
	std::cout << std::endl;
}

/// <summary>
/// Вспомогательная операция для вычисления СКО
/// </summary>
/// <param name="a">Аналоговый сигнал</param>
/// <param name="b">Цифровой сигнал</param>
/// <returns>Квадратичная разница</returns>
auto calculate(double a, int b) -> double
{
	return pow((a - b),2);
}

/// <summary>
/// Расчет СКО между двумя векторами
/// </summary>
/// <param name="analog_signal">Ссылка на вектор с аналоговым сигналом</param>
/// <param name="digital_signal">Ссылка на вектор с цифровым сигналом</param>
/// <param name="max_value_signal">Максимальное значение сигнала</param>
/// <returns>СКО</returns>
auto standard_deviation(std::vector<double>& analog_signal, std::vector<int>& digital_signal, double max_value_signal) -> double
{
	srand(static_cast <unsigned> (time(nullptr)));  // NOLINT(cert-msc51-cpp)
	double X = max_value_signal;
	std::generate(analog_signal.begin(), analog_signal.end(), [X]()
		{
			return static_cast <double> (rand()) / (RAND_MAX / X);
		}
	);
	
	printContainer(analog_signal);
	std::copy(analog_signal.begin(), analog_signal.end(), digital_signal.begin());

	/* Если округлять по правилам математики...
	 std::for_each(analog_signal.begin(), analog_signal.end(), [&digital_signal](double element)
		{
			digital_signal.push_back(static_cast<int>(round(element)));
		}
	);*/

	printContainer(digital_signal);
	return  std::inner_product(analog_signal.begin(), analog_signal.end(), digital_signal.begin(), 0.0, std::plus<>(), calculate);
}

int main()
{
	std::vector<int> vi{ 1,2,3,4,6 };
	insert_sorted(vi, 5);
	printContainer(vi);

	std::vector<int> iv{ 6,4,3,2,1 };
	insert_sorted(iv, 5);
	printContainer(iv);
	//----------------------------//
	std::list<int> il{ 6,4,3,2,1 };
	insert_sorted(il, 5);
	printContainer(il);

	std::list<int> li{ 1,2,3,4,6 };
	insert_sorted(li, 5);
	printContainer(li);
	//----------------------------//

	std::vector<double> analog_signal;
	std::vector<int> digital_signal;
	analog_signal.resize(100,0);
	digital_signal.resize(100, 0);
	const auto answer = standard_deviation(analog_signal, digital_signal, 150);
	std::cout <<"Standard deviation = " << answer << std::endl;
}
