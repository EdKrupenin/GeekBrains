#include <iostream>
#include <string>
typedef int htIndex;
const int countWord = 26; //Константа - кол-во букв англ. алфавита


/// <summary>
///  Простейшая хеш-функция.
/// </summary>
/// <param name="data">Строка</param>
/// <param name="Type">Просто сложение или с участием степеней</param>
/// <returns>сумма кодов символов</returns>
htIndex hashString(std::string data, int Type) {
	/*Не знаю можно было тут использовать строку или нет, но по сути ее можно заменить на массив char* и его size
	Со строкой получилось универсальнее*/
	int length = data.length() - 1;
	int hashCount = 0;
	switch (Type)
	{
	case 0:
		for (size_t i = 0; i <= length; i++)
			hashCount += (int)data[length - i] * pow(countWord, i);
		break;
	case 1:
		for (size_t i = 0; i <= length; i++)
			hashCount += (int)data[i];
		break;
	default:
		break;
	}
	return hashCount;
}

/// <summary>
/// Жадный алгоритм подсчета минимального количества монет
/// </summary>
/// <param name="denomination">Массив с номиналами монет</param>
/// <param name="countCoin">Размер массива</param>
/// <param name="sum">Сумма которую надо набрать</param>
/// <returns>Количество монет</returns>
int minimalCoin(int* denomination, int countCoin, int sum) {
	int count = 0; //Счетчик монет
	int countSum = 0; //Сумма из монет
	//Проходим по всему массиву
	for (size_t i = 0; i < countCoin; i++)
	{
		// Пока можем добавляем номинал, как только ушли за пределы суммы
		// переходим к следующему номиналу
		while ((countSum+denomination[i]) <= sum)
		{
			countSum += denomination[i];
			count++;
		} 
		//Если набрали то что надо выходим
		if (countSum == sum) return count;
	}
	return -1; //Из полученных монет нельзя набрать нужную сумму...
}

int main()
{
	std::string words = "abc";
	std::cout << "hash String = " << hashString(words,1) << std::endl;
	const int MAX = 98; //Максимальное значение
	int denomination[] = { 50, 10, 5, 2, 1 }; //номинал монет
	std::cout << "minimal Coin = " << minimalCoin(denomination, 5, MAX) << std::endl;
}
