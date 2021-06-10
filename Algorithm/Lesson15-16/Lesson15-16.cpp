#include <iostream>
#include "Resource/Lesson9-10.h"
#include <string>
typedef int K;
typedef int htIndex;
const int countWord = 26; //Константа - кол-во букв англ. алфавита

int htSize; // глобальный размер хэш таблицы
#pragma region Хэш Функции



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
		for (int i = 0; i <= length; i++)
			hashCount += (int)data[length - i] * (int)pow(countWord, i);
		break;
	case 1:
		for (int i = 0; i <= length; i++)
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
boolean insertNode(NodeOneLink** table, K data) {
	NodeOneLink* p;  //Указатель на новый узел в который будет записан переданный ключ
	NodeOneLink* p0; //Указатель на старую голову списка к которой будет добавлен новый узел

	htIndex bucket = hash(data); //Индекс хэш-таблицы
	p = new NodeOneLink;
	if (p == NULL) {
		std::cout << "Out of memory\n";
		return false;
	}
	//if (table[bucket] == NULL) table[bucket]->next == NULL;
	//Указатель на текущую голову списка
	p0 = table[bucket];
	table[bucket] = p; //Запишем новую голову
	p->next = p0;      //Припишем хвост новой голову
	p->data = data;	   // Запишем данные в новую голову
	return true;
}

/// <summary>
/// Поиск данных в хэш таблице
/// </summary>
/// <param name="table">Ссылка на таблицу</param>
/// <param name="data">Ключ</param>
/// <returns>Узел или NULL</returns>
NodeOneLink* findKnot(NodeOneLink** table, K data) {
	NodeOneLink* p = table[hash(data)];
	//В цикле while будем до тех пор пока не найдем дату или не пройдем весь список
	while (p && p->data != data)
		p = p->next;
	//если нашли дату то вернем узел, иначе вернем null
	return p;
}

/// <summary>
/// Функция удаления ключа
/// </summary>
/// <param name="table">Ссылка на хэш-таблицу со списками</param>
/// <param name="data">Ключ который надо удалить</param>
void deleteKnot(NodeOneLink** table, K data) {
	NodeOneLink* parent; //Предок
	NodeOneLink* current; //Значение которое анализируем
	parent = NULL; //Обнуляем предка
	htIndex bucket = hash(data); //Вычисляем в каком именно списке предположительно
	// будет наш ключ, с помощью хэш функции
	current = table[bucket]; //достаем этот список из массива
	//Проходим по списку пока он не кончиться или же пока не найдем ключ
	while (current && current->data != data) {
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
void printTable(NodeOneLink** table, int size) {
	NodeOneLink* current;
	//Перебираем весь массив со списками
	for (int i = 0; i < size; i++)
	{
		current = table[i]; //берем подряд каждый список
		while (current) //Пока не дойдем до конца списка
		{
			std::cout << current->data << " ";
			current = current->next;
			//current->date ? current : NULL;
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
	for (int i = 0; i < countCoin; i++)
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

typedef struct {
	int data;
	int key;
} KeyNode;

KeyNode** openHashTable;
int hashTableSize;

KeyNode* nullItem;

int hashFuncOpen(int key) {
	return key % hashTableSize;
}

KeyNode* createNode(int data) {
	return new KeyNode{ data,data };
}

void initTable(int length, int index) {
	for (int i = index; i < length; i++) {
		openHashTable[i] = NULL;
	}
}

boolean isFull() {
	for (int i = 0; i < hashTableSize; i++) {
		if (openHashTable[i] == NULL || openHashTable[i] == nullItem)
			return false;
	}
	return true;
}

boolean insertNode(int data);

void increaseCapacity() {
	hashTableSize *= 2;
	KeyNode** oldHashTable = openHashTable;
	openHashTable = new KeyNode * [hashTableSize];
	int i;
	for (i = 0; i < hashTableSize / 2; i++)
	{
		insertNode(oldHashTable[i]->data);
	}
	initTable(hashTableSize, i);
	delete oldHashTable;
}

/// <summary>
/// Линейное пробирование
/// </summary>
/// <param name="val">Индекс из хэш функции</param>
/// <returns>смещение</returns>
int linearProbe(int val) {
	++val;
	val %= hashTableSize; //Гарантированно останемся в пределах границ таблицы
	return val;
}

/// <summary>
///  Квадратичное пробирование
/// </summary>
/// <param name="val"></param>
/// <param name="step"></param>
/// <returns></returns>
int quadProbe(int val, int step) {
	val += step * step;
	val %= hashTableSize;
	return val;
}

/// <summary>
/// Вторичная хэш функция
/// </summary>
/// <param name="key"></param>
/// <returns></returns>
int hashFuncDoub(int key) {
	return 19 - key % 19;
}

boolean insertNode(int data) {
	KeyNode* node = createNode(data);
	if (!node) return false;
	int hashVal = hashFuncOpen(node->key);
	//Применим псевдодинамический массив, как только таблица будет заполняться то мы увеличим ее размер в 2 раза
	if (isFull())
		increaseCapacity();
	//int step = 0; //Счетчик шагов!!!
	int step = hashFuncDoub(node->key); //Шаг для определения места вставки
	while (openHashTable[hashVal] && openHashTable[hashVal] != nullItem) { //Проверяем каждый раз что заполнена ли таблици, и чем она заполнена
		//если пустое место или 0 то стопимся и прекращаем линейно пробировать
		//hashVal = linearProbe(hashVal);
		//hashVal = quadProbe(hashVal, ++step);
		hashVal += step;
		hashVal %= hashTableSize; // что бы не было переполнения
	}
	openHashTable[hashVal] = node;
	return true;
}

KeyNode* findNode(int data) {
	int key = data;
	int hashVal = hashFuncOpen(key);
	//int step = 0;
	int step = hashFuncDoub(key);
	while (openHashTable[hashVal] && openHashTable[hashVal] != nullItem) {
		//Проверяем каждый раз что заполнена ли таблиц, и чем она заполнена
		//если пустое место или 0 то стопимся и прекращаем линейно пробировать
		if (openHashTable[hashVal]->key = key) {
			return openHashTable[hashVal];
		}
		//hashVal = linearProbe(hashVal);
		//hashVal = quadProbe(hashVal, ++step);
		hashVal += step;
		hashVal %= hashTableSize;
	}
	return NULL;
}

KeyNode* deleteNode(int data) {
	int key = data;
	int hashVal = hashFuncOpen(key);
	//int step = 0;
	int step = hashFuncDoub(key);
	while (openHashTable[hashVal] && openHashTable[hashVal] != nullItem) {
		//Проверяем каждый раз что заполнена ли таблици, и чем она заполнена
		//если пустое место или 0 то стопимся и прекращаем линейно пробировать
		if (openHashTable[hashVal]->key = key) {
			return openHashTable[hashVal];
			KeyNode* tmp = openHashTable[hashVal];
			openHashTable[hashVal] = nullItem;
			return tmp;
		}
		//hashVal = linearProbe(hashVal);
		//hashVal = quadProbe(hashVal, ++step);
		hashVal += step;
		hashVal %= hashTableSize;
	}
	return NULL;
}

void printNode(KeyNode* n) {
	if (!n) {
		std::cout << "[*,*] ";
		return;
	}
	std::cout << "[k= " << n->key << ", d= " << n->data << " ] ";
}

void prTable() {
	for (int i = 0; i < hashTableSize; i++)
	{
		printNode(openHashTable[i]);
	}
	std::cout << std::endl;
}

#pragma endregion

#pragma region Шифрование

/// <summary>
/// Шифр перестановкой
/// </summary>
/// <param name="stirng">строка для шифрования</param>
/// <param name="key">количество столбцов</param>
/// <returns></returns>
char* simpleEncryption(char* string, int length, int key) {
	char* encrypt = new char[length];
	int row = (length % key) + (length / key); //Рассчитываем длину строки
	int col = key; //Кол-во столбцов
	for (int j = 0; j < row; j++)
		for (int i = 0; i < col; i++)
			encrypt[j * col + i] = string[i * row + j];

	return encrypt;
}

/// <summary>
/// Расшифровка перестановкой
/// </summary>
/// <param name="string">Зашифрованное сообщение</param>
/// <param name="length">Длина зашифрованного сообщения</param>
/// <param name="key">Кол-во столбцов</param>
/// <returns>Расшифрованное сообщение</returns>
char* simpleDecryption(char* string, int length, int key) {
	char* decrypt = new char[length];
	int row = (length % key) + (length / key); //Рассчитываем длину строки
	int col = key; //Кол-во столбцов
	for (int j = 0; j < row; j++)
		for (int i = 0; i < col; i++)
			decrypt[i * row + j] = string[j * col + i];

	return decrypt;
}


/// <summary>
/// Шифрование цезаря
/// </summary>
/// <param name="string">Сообщение</param>
/// <param name="length">Длина сообщения</param>
/// <param name="key">смещение</param>
/// <returns>Зашифрованное сообщение</returns>
char* cesarEncryption(char* string, int length, int key) {
	char* encrypt = new char[length];
	int LowercaseletterStart = 65;
	int LowercaseletterEnd = 90;
	int cursiveletterStart = 97;
	int cursiveletterEnd = 122;
	for (int i = 0; i < length; i++)
	{
		if ((string[i] >= LowercaseletterStart && string[i] <= LowercaseletterEnd) ||
			(string[i] >= LowercaseletterStart && string[i] <= LowercaseletterEnd))
		{
			int letter = (int)string[i] + key;
			if (letter > LowercaseletterEnd && letter < cursiveletterStart)
				encrypt[i] = char(letter - (LowercaseletterEnd + 1) + LowercaseletterStart);
			else
				if (letter > cursiveletterEnd)
					encrypt[i] = char(letter - (cursiveletterEnd + 1) + cursiveletterStart);
				else
					encrypt[i] = char(letter);
		}
		else
		{
			encrypt[i] = string[i]; //Если пришел пробел или прочие служебные символы.
		}
	}
	return encrypt;
}

/// <summary>
/// Дешифровка цезаря
/// </summary>
/// <param name="string">Зашифрованная строка</param>
/// <param name="length">Длина строки</param>
/// <param name="key">Смешение</param>
/// <returns>Расшифрованное сообщение</returns>
char* cesarDecryption(char* string, int length, int key) {
	char* decrypt = new char[length];
	int LowercaseletterStart = 65;
	int LowercaseletterEnd = 90;
	int cursiveletterStart = 97;
	int cursiveletterEnd = 122;
	for (int i = 0; i < length; i++)
	{
		if ((string[i] >= LowercaseletterStart && string[i] <= LowercaseletterEnd) ||
			(string[i] >= LowercaseletterStart && string[i] <= LowercaseletterEnd))
		{
			int letter = (int)string[i] - key;
			if (letter < LowercaseletterStart)
				decrypt[i] = char(LowercaseletterEnd - (LowercaseletterStart - letter - 1));
			else if (letter > LowercaseletterEnd && letter < cursiveletterStart)
				decrypt[i] = char(cursiveletterEnd - (cursiveletterStart - letter - 1));
			else
				decrypt[i] = char(letter);
		}
		else
		{
			decrypt[i] = string[i]; //Если пришел пробел или прочие служебные символы.
		}
	}
	return decrypt;
}

#pragma endregion


int main()
{
	htSize = 8;
	const int SZ = 20; //Размер массива
	int* arr = new int[SZ];
	fillIntRandom(arr, SZ, 100);
	NodeOneLink** hashTable = new NodeOneLink * [htSize];

	for (size_t i = 0; i < SZ; i++)
	{
		insertNode(hashTable, arr[i]);
	}
	printNode(findKnot(hashTable, 41));
	//printTable(hashTable, htSize);

	std::string words = "abc";
	std::cout << "hash String = " << hashString(words, 1) << std::endl;
	const int MAX = 98; //Максимальное значение
	int denomination[] = { 50, 10, 5, 2, 1 }; //номинал монет
	std::cout << "minimal Coin = " << minimalCoin(denomination, 5, MAX) << std::endl;

	hashTableSize = 25;
	openHashTable = new KeyNode * [hashTableSize];
	initTable(hashTableSize, 0);
	nullItem = createNode(-1);

	insertNode(10);
	insertNode(10);
	insertNode(20);
	insertNode(40);
	insertNode(50);
	insertNode(90);
	insertNode(88);
	insertNode(61);
	insertNode(11);
	insertNode(18);
	insertNode(10);
	insertNode(11);
	insertNode(10);
	prTable();

	char mess[] = { "Thisisasecretmessage" };
	char mess2[] = { "ABC,XYZ abc xyz" };

	simpleDecryption(simpleEncryption(mess, 20, 4), 20, 4);
	cesarDecryption(cesarEncryption(mess2, 20, 4), 20, 4);
	return 0;

}
