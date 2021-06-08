#include <iostream>
#include "Resource/Lesson9-10.h"
#include <string>
typedef int K;
typedef int htIndex;
const int countWord = 26; //Константа - кол-во букв англ. алфавита

int htSize; // глобальный размер хэш таблицы

/// <summary>
/// Расчет индекса в хэш таблице (массива)
/// </summary>
/// <param name="data">Ключ</param>
/// <returns>Искомый индекс</returns>
htIndex hash(T data) {
	return data % htSize;
}

/// <summary>
///  Простейшая хеш-функция.
/// </summary>
/// <param name="data">Строка</param>
/// <param name="Type">Просто сложение или с участием степеней</param>
/// <returns>сумма кодов символов</returns>
htIndex hashString(std::string data, int Type) {
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
/// Добавление элементов в хэш-таблицу
/// </summary>
/// <param name="table">Ссылка на массив со списками</param>
/// <param name="data">ключ</param>
/// <returns>Результат операции</returns>
boolean insertNode(Knot** table, K data) {
	Knot* p;  //Указатель на новый узел в который будет записан переданный ключ
	Knot* p0; //Указатель на старую голову списка к которой будет добавлен новый узел

	htIndex bucket = hash(data); //Индекс хэш-таблицы
	p = new Knot;
	if (p == NULL) {
		std::cout << "Out of memory\n";
		return false;
	}
	if (table[bucket] == NULL) table[bucket]->next == NULL;
	//Указатель на текущую голову списка
	p0 = table[bucket];
	table[bucket] = p; //Запишем новую голову
	p->next = p0;      //Припишем хвост новой голову
	p->date = data;	   // Запишем данные в новую голову
	p->name = char(data);
	return true;
}

/// <summary>
/// Поиск данных в хэш таблице
/// </summary>
/// <param name="table">Ссылка на таблицу</param>
/// <param name="data">Ключ</param>
/// <returns>Узел или NULL</returns>
Knot* findKnot(Knot** table, K data) {
	Knot* p = table[hash(data)];
	//В цикле while будем до тех пор пока не найдем дату или не пройдем весь список
	while (p && p->date != data)
		p = p->next;
	//если нашли дату то вернем узел, иначе вернем null
	return p;
}

/// <summary>
/// Функция удаления ключа
/// </summary>
/// <param name="table">Ссылка на хэш-таблицу со списками</param>
/// <param name="data">Ключ который надо удалить</param>
void deleteKnot(Knot** table, K data) {
	Knot* parent; //Предок
	Knot* current; //Значение которое анализируем
	parent = NULL; //Обнуляем предка
	htIndex bucket = hash(data); //Вычисляем в каком именно списке предположительно
	// будет наш ключ, с помощью хэш функции
	current = table[bucket]; //достаем этот список из массива
	//Проходим по списку пока он не кончиться или же пока не найдем ключ
	while (current && current->date != data) {
		parent = current;
		current = current->next;
	}
	//Если список прошли до конца но ключа не нашли...
	if (!current) {
		std::cout << "Value not found\n";
		return;
	}
	if (parent) //если ключ не в голове списка,
		//то выкидываем current узел из списка убирая ссылку
		parent->next = current->next;
	else { //Если ключ в голове списка переназначаем голову
		table[bucket] = current->next;
	}
	//Удаляем узел
	delete current;
}

/// <summary>
/// Печать таблицы хэш функции
/// </summary>
/// <param name="table">Ссылка на массив</param>
/// <param name="size">Размер таблицы</param>
void printTable(Knot** table, int size) {
	Knot* current = NULL;
	//Перебираем весь массив со списками
	for (int i = 0; i < size; i++)
	{
		current = table[i]; //берем подряд каждый список
		while (current != NULL) //Пока не дойдем до конца списка
		{
			std::cout << current->date << " ";
			current = current->next;
			current->date ? current : NULL;
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
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
		while ((countSum + denomination[i]) <= sum)
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
	htSize = 8;
	const int SZ = 20; //Размер массива
	int* arr = new int[SZ];
	fillIntRandom(arr, SZ, 100);
	Knot** hashTable = new Knot * [htSize];
	
	for (size_t i = 0; i < SZ; i++)
	{
		insertNode(hashTable, arr[i]);
	}
	printKnot(findKnot(hashTable, 41));
	printTable(hashTable, htSize);

	std::string words = "abc";
	std::cout << "hash String = " << hashString(words, 1) << std::endl;
	const int MAX = 98; //Максимальное значение
	int denomination[] = { 50, 10, 5, 2, 1 }; //номинал монет
	std::cout << "minimal Coin = " << minimalCoin(denomination, 5, MAX) << std::endl;
}
