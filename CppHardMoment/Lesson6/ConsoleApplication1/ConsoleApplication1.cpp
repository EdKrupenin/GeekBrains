#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <future>
#include <set>
using namespace std::chrono_literals;

std::mutex lock_cout;
std::mutex lock_numeric;
std::mutex lock_set;
std::atomic_bool stop_thread_1 = true;
std::mutex boolean;

/// <summary>
/// Шаблонная потокобезопасная оболочка для объекта cout
/// </summary>
/// <typeparam name="Type">Тип выводимых данных</typeparam>
/// <param name="Data">Данные</param>
template<class Type>
void pcout(Type Data)
{
	std::lock_guard<std::mutex> lock{ lock_cout };
	std::cout << Data << std::endl;
}

//------------------------------------------//

/// <summary>
/// Печатает в консоли Progress Bar
/// </summary>
/// <param name="persent">Процент выполнения</param>
void printProgress(int percent) {
	std::cout << "\r[";
	for (int i = 0; i < 100; ++i) {
		if (i < percent) std::cout << "=";
		else if (i == percent) std::cout << ">";
		else std::cout << " ";
	}
	std::cout << "] " << percent << " %";
}

/// <summary>
/// Функция проверяет число на простоту!
/// </summary>
/// <param name="n">Число приходит на вход</param>
/// <returns>Результат проверки</returns>
bool prime(int n) {
	bool prime = true;
	for (int counter = 2; counter <= n / 2; counter++) {
		if (n % counter == 0) {
			prime = false;
			break;
		}
	}
	return prime;
}

/// <summary>
/// Функция ищет n-е простое число
/// </summary>
/// <param name="serial">Порядоковый номер числа</param>
/// <param name="numeric"> Пара выходных парметров</param>
/// <returns></returns>
void countNumeric(int serial,std::pair<int,int>& numeric)
{
	int i{};
	for (i = 2; numeric.first < serial; ++i) {
		if (prime(i)) {
			lock_numeric.lock();
			numeric.first++;
			lock_numeric.unlock();
		}
	}
	numeric.second = (i-1);
}

int simpleNumeric(int serialNumber)
{
	const float progressBar =  static_cast<float>(serialNumber) / 100; //Для организации прогресс бара = 1 проценту
	std::pair<int, int> numeric{}; //Выходные параметры
	std::thread calculate(countNumeric,serialNumber,std::ref(numeric));
	calculate.detach(); //Подключаем поток и идем дальше
	while (numeric.first < serialNumber)
	{
		std::this_thread::sleep_for(200ms);// что бы не рисовать слишком часто, 5 раз в секунду
		//Защищаем выходные параметры при перерисовке
		lock_numeric.lock();
		printProgress(static_cast<int>(numeric.first / progressBar));
		lock_numeric.unlock();
	}
	std::cout << std::endl;
	return numeric.second;
}

//--------------------------------------------------------------------------------------------------------------------//

/*
 * Промоделировать следующую ситуацию. Есть два человека (2 потока): хозяин и вор.
 * Хозяин приносит домой вещи (функция добавляющая случайное число в вектор с периодичностью 1 раз в секунду).
 * При этом у каждой вещи есть своя ценность. Вор забирает вещи (функция,которая находит наибольшее число и
 * удаляет из вектора с периодичностью 1 раз в 0.5 секунд), каждый раз забирает вещь с наибольшей ценностью.
 */

void Owner(std::multiset<int>& things)
{
	while (stop_thread_1)
	{
		std::this_thread::sleep_for(1s);
		std::lock_guard<std::mutex> lock(lock_set);
		things.insert(rand() % 101);
	}
}

void Theif(std::multiset<int>& things)
{
	while (stop_thread_1)
	{
		std::this_thread::sleep_for(500ms);
		std::lock_guard<std::mutex> lock(lock_set);
		if (!things.empty())
			things.erase(--things.end());
		else {
			boolean.lock();
			stop_thread_1 = false;
			boolean.unlock();
		}
	}	
}

void NeighboursfromHell()
{
	auto start = std::chrono::steady_clock::now();
	std::multiset<int> things{};
	for (size_t i = 0; i < 50; ++i)
		things.insert(rand() % 100);
	std::thread owner(Owner, ref(things));
	std::thread theif(Theif, ref(things));
	owner.detach();
	theif.detach();
	while (!things.empty())
	{
		std::this_thread::sleep_for(200ms);
		std::cout << "\rThings :";
		lock_set.lock();
		for (auto thing : things)
		{
			std::cout << thing << " ";
		}
		std::cout << "\r";
		lock_set.unlock();				
	}
	std::cout.flush();
	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> diff = end - start;
	std::cout <<"Work time is "<< diff.count() << "s";
}

int main()
{
	system("color 0e");
	std::cout<<"Simple number is "<<simpleNumeric(13);
	std::cout<<std::endl;
	NeighboursfromHell();
	
}