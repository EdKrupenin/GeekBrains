﻿#include <iostream>
#define T char
#define true 1 == 1
#define false 1 != 1
typedef int boolean;

/*
#pragma region Stack
#define T int
#define SIZE 10
#define true 1 == 1
#define false 1 != 1
typedef int boolean;

int cursor = -1;
T Stack[SIZE];

boolean push(T data) {
	if (cursor < SIZE) {
		Stack[++cursor] = data;
		return true;
	}
	else {
		std::cout << "Stack overflow" << std::endl;
		return false;
	}
}

T pop() {
	if (cursor != -1) {
		return Stack[cursor--];
	}
	else {
		std::cout << "Stack is empty" << std::endl;
		return -1;
	}
}

void decToBin(int number) {
	if (number > 1)
	{
		push(number % 2);
		decToBin(number / 2);
	}
	else
	{
		push(number);
		while (cursor != -1)
		{
			std::cout << pop();
		}
		std::cout << std::endl;
	}
}
#pragma endregion

#pragma region Очередь
#define Type char

Type Queue[SIZE];
int first = 0;
int end = -1;
int itemss = 0;

boolean enqueue(Type data) {
	if (itemss == SIZE)
	{
		std::cout << "Queue is full" << std::endl;
		return false;
	}
	if (end == SIZE - 1)
		end = -1;
	Queue[++end] = data;
	itemss++;
	return	true;
}

Type dequeue() {
	if (itemss == 0) {
		std::cout << "Queue is empty" << std::endl;
		return -1;
	}
	else {
		char tmp = Queue[first++];
		first %= SIZE; //когда first будет == size => first == 0
		itemss--;
		return tmp;
	}
}
#pragma endregion

#pragma region Очередь с приоритетом


#define SZ 10
typedef struct {
	int prioritete;
	int data;
} Node;

Node* arr[SZ];
int head; // Индекс головы очереди
int tail; // Индекс конца очереди
int items;// Индекс количества элементов

void init() {
	for (size_t i = 0; i < SZ; i++)
		arr[i] = NULL;
	head = 0;
	tail = 0;
	items = 0;
}

/// <summary>
/// Функция приоритетного заполнения
/// </summary>
/// <param name="pr">очередь</param>
/// <param name="dat">данные</param>
void insPR(int prioritete, int data) {
	Node* node = new Node;//создаем новый элемент типа Node;
	node->data = data;
	node->prioritete = prioritete;
	//Элемент готов для очереди
	if (items == SZ)
	{
		std::cout << "Queue is full" << std::endl;
		return;
	}
	else {
		if (items == 0) {
			arr[++tail] = node;
			items++;
		}
		else
		{
			int i = 0;
			int idx = 0;
			int flag = 0; //Указывает н место вставки полученных на вход значений
			Node* tmp;
			for (i = head; i < tail; i++)
			{
				idx = i % SZ;
				if (arr[idx]->prioritete < prioritete) //Если приоритет у полученного значения выше чем у Node
					// то увеличиваем индекс, иначе выходим из цикла
					idx++;
				else
					break;
			}
			flag = idx % SZ;
			//все элементы на которые указывает флаг нужно сместить вправо
			i++; //idx == i из за for, сместим i правее
			while (i <= tail)
			{
				idx = i % SZ;
				tmp = arr[idx];
				arr[idx] = arr[flag];
				arr[flag] = tmp;
				i++;
			}
			arr[flag] = node;
			items++;
			tail++;
		}
	}
}


/// <summary>
/// Функция заполнения без приоритета
/// </summary>
/// <param name="pr">очередь</param>
/// <param name="dat">данные</param>
void ins(int prioritete, int data) {
	Node* node = new Node;//создаем новый элемент типа Node;
	node->data = data;
	node->prioritete = prioritete;
	//Элемент готов для очереди
	if (items == SZ)
	{
		std::cout << "Queue is full" << std::endl;
		return;
	}
	//if (tail == SZ - 1) //Обнуляем конец очереди, так как добавляем мы все подряд и следить за индексом tail нужно
	//	tail = -1;
	int idx = tail++ % SZ;
	arr[idx] = node;
	items++;
}

/// <summary>
/// Функция удаления без приоритета
/// </summary>
/// <returns>Данные из списка</returns>
Node* remSimple() {
	if (items == 0)
		return NULL;
	else
	{
		int idx = head++ % SZ;
		Node* tmp = arr[idx];
		arr[idx] = NULL;
		items--;
		return tmp;
	}
}

/// <summary>
/// Функция удаления с приоритетом
/// </summary>
/// <returns>Приоритетные данные из списка</returns>
Node* rem() {
	if (items == 0)
		return NULL;
	else
	{
		int i = 1;
		int idx = 0; //Указывает на место самого приоритетного элемента
		Node* max = arr[0];

		for (; i < items; i++)
		{
			if (max->prioritete < arr[i]->prioritete) {
				max = arr[i];
				idx = i;
			}
		}
		arr[idx] = arr[--items];
		arr[items] = NULL;
		return max;
	}
}

/// <summary>
/// Функция - печать очереди
/// </summary>
void printQueue() {
	std::cout << '[';
	for (size_t i = 0; i < SZ; i++)
	{
		if (arr[i] == NULL)
			std::cout << "[* *]";
		else
		{
			std::cout << '[' << arr[i]->prioritete << ", " << arr[i]->data << "] ";
		}
	}
	std::cout << ']' << std::endl;
}

#pragma endregion
*/


#pragma region Односвязные списки
/// <summary>
/// Структура узла односвязного списка
/// </summary>
typedef struct Knot {
	int date;
	struct Knot* next;
}Knot;

/// <summary>
/// Структура односвязного списка
/// </summary>
typedef struct List {
	Knot* head;
	int size;
}List;

/// <summary>
/// Инициализация нового списка
/// </summary>
/// <param name="lst">Указатель на список</param>
void initList(List* lst) {
	lst->head = NULL;
	lst->size = 0;
}

/// <summary>
/// Добавление нового элемента
/// </summary>
/// <param name="lst">Указатель на список</param>
/// <param name="data">Новый элемент</param>
void insertList(List* lst, int data) {
	Knot* newKnot = new Knot;
	newKnot->date = data;
	newKnot->next = NULL;

	Knot* current = lst->head;
	if (current == NULL) {
		lst->head = newKnot;
		lst->size++;
		return;
	}
	else {
		while (current->next != NULL)
			current = current->next;
		current->next = newKnot;
		lst->size++;
	}
}

/// <summary>
/// Удаление элементов из связного списка
/// </summary>
/// <param name="lst">ссылка на головной элемент и кол-во</param>
/// <param name="data">данные которые надо удалить</param>
/// <returns>данные которые надо удалить</returns>
Knot* rm(List* lst, int data) {
	Knot* current = lst->head;
	Knot* parent = NULL;
	if (current == NULL) return NULL;
	while (current->next != NULL && current->date != data) {
		parent = current;
		current = current->next;
	}
	if (current->date != data) return NULL;
	if (current == lst->head) {
		lst->head = current->next;
		lst->size--;
		return current;
	}
	parent->next = current->next;
	lst->size--;
	return current;
}

/// <summary>
/// Функция копирования односвязного листа
/// </summary>
/// <param name="Lst">Указатель на список который надо скопировать</param>
/// <returns>Скопированный список</returns>
List* copyList(List* lst) {
	List* newLst = new List; //создаем новый лист который пойдет на выход...
	initList(newLst);
	Knot* current = lst->head; //получаем первый элемент старого списка и проверяем его на NULL...
	if (current == NULL) return NULL;
	//Проходим по каждому элементу старого списка, забираем оттуда значение и передаем в функцию
	//вставки, так же передаем туда ссылку на новый список, это гарантирует что все новые элементы
	//будет независимы
	while (current->next != NULL) {
		insertList(newLst, current->date);
		current = current->next;
	}
	return newLst;
}

/// <summary>
/// Функция проверки отсортирован ли односвязный список
/// </summary>
/// <param name="lst">Указатель на список</param>
/// <returns>Результат проверки</returns>
bool sortList(List* lst) {
	Knot* current = lst->head; //получаем первый элемент старого списка и проверяем его на NULL...
	if (current == NULL) return NULL;
	int tmp = 0; //Временная переменная для хранения предыдущего значения 
	//( в двусвязном списке она не нужна т.к. есть ссылка на предыдущее значение)
	bool retUP = true; //Отсортирован по возрастанию
	bool retDown = true; //Отсортирован по убыванию
	tmp = current->date; //Первую итерацию делаем вручную
	current = current->next;
	//Проходим по каждому элементу старого списка
	while (current->next != NULL) {
		if (!(tmp <= current->date && retUP))
			retUP = false;
		if (!(tmp >= current->date && retDown))
			retDown = false;
		tmp = current->date;
		current = current->next;
	}
	return (retUP || retDown);
}

void printKnot(Knot* k) {
	if (k == NULL) {
		std::cout << "[]";
		return;
	}
	std::cout << '[' << k->date << ']';
}

void printList(List* lst) {
	Knot* current = lst->head;
	if (current == NULL) printKnot(current);
	else
	{
		do {
			printKnot(current);
			current = current->next;
		} while (current != NULL);
	}
	std::cout << "Size: " << lst->size << std::endl;
}
#pragma endregion

#pragma region Двусвязные списки

/// <summary>
/// Структура узла двусвязного списка 
/// </summary>
typedef struct Node {
	char data;
	struct Node* next;
	struct Node* previously;
}Node;

/// <summary>
/// Структура двусвязного списка
/// </summary>
typedef struct DuoList {
	Node* head;
	Node* tail;
	int size;
}DuoList;

/// <summary>
/// Инициализация двусвязного списка
/// </summary>
/// <param name="lst"></param>
void init(DuoList* lst) {
	lst->head = NULL;
	lst->tail = NULL;
	lst->size = 0;
}

/// <summary>
/// Добавление элементов в голову списка
/// </summary>
/// <param name="lst">Ссылка на лист</param>
/// <param name="data">Данные для добавления</param>
void pushFront(DuoList* lst, char data) {
	Node* current = new Node;
	current->data = data;
	current->next = lst->head; //т.к. мы добавляем к "голове" то следующий элемент будет тот,
	// что до этого был в голове списка, а предыдущий должен быть NULL, т.к. мы теперь голова
	current->previously = NULL;
	if (lst->head != NULL) lst->head->previously = current;
	// Если есть головной элемент, то добавим ему указатель на новый
	if (lst->tail == NULL) lst->tail = current;
	// Если нет конца списка(список пуск) укажем что новый элемент - конец списка
	lst->head = current;
	lst->size++;
}

/// <summary>
/// Добавление элементов в хвост списка
/// </summary>
/// <param name="lst">Ссылка на список</param>
/// <param name="data">Данные для добавления</param>
void pushBack(DuoList* lst, char data) {
	Node* current = new Node;
	current->data = data;
	current->previously = lst->tail; //т.к. мы добавляем к "хвосту" то предыдущий элемент будет тот,
	// что до этого был в конце списка, а следующий должен быть NULL, т.к. мы теперь конец
	current->next = NULL;
	if (lst->tail != NULL) lst->tail->next = current;
	// Если есть "хвостовой" элемент, то добавим ему указатель на новый(следующий)
	if (lst->head == NULL) lst->head = current;
	// Если нет начала списка(список пуск) укажем что новый элемент - начало списка
	lst->tail = current;
	lst->size++;
}

Node* rm(DuoList* lst, int data) {
	Node* current = lst->head;
	Node* parent = NULL;
	if (current == NULL) return NULL;
	while (current->next != NULL && current->data != data) {
		parent = current;
		current = current->next;
	}
	if (current->data != data) return NULL;
	if (current == lst->head) {
		lst->head = current->next;
		current->next->previously = NULL;
		lst->size--;
		return current;
	}
	parent->next = current->next;
	lst->size--;
	return current;
}

/// <summary>
/// Удаление элемента с начала списка
/// </summary>
/// <param name="lst">ссылка на список</param>
/// <returns>Результат удаления</returns>
Node* remFront(DuoList* lst) {
	if (lst->head == NULL) return NULL; //Проверим не пустой ли список
	Node* tmp = lst->head; //Скопируем голову во временную переменную 
	lst->head = lst->head->next; //Переместим указатель головы списка на следующий за головой элемент
	if (lst->head != NULL) lst->head->previously = NULL; //Проверим список на пустоту, мало-ли след. элемента нет
	// Если все таки есть то удалим у него ссылку на старую голову (previously)
	if (tmp == lst->tail) lst->tail = NULL; // Если старая голова была еще и последним элементом в списке,
	// то обнуляем указатель на хвост
	lst->size--;
	return tmp;
}

/// <summary>
/// Удаление элемента с конца списка
/// </summary>
/// <param name="lst">Ссылка на список</param>
/// <returns>Результат удаления</returns>
Node* remBack(DuoList* lst) {
	if (lst->tail == NULL) return NULL; //Проверим не пустой ли список
	Node* tmp = lst->tail; //Скопируем хвостовой элемент во временную переменную 
	lst->tail = lst->tail->previously; //Переместим указатель хвоста списка на предыдущий хвостовой элемент
	if (lst->tail != NULL) lst->tail->next = NULL; //Проверим список на пустоту, мало-ли предыдущего элемента нет
	// Если все таки есть то удалим у него ссылку на старый хвостовой элемент (next)
	if (tmp == lst->head) lst->head = NULL; // Если хвостовой элемент был еще и первым элементом в списке,
	// то обнуляем указатель на голову
	lst->size--;
	return tmp;
}

void printNode(Node* k) {
	if (k == NULL) {
		std::cout << "Null";
		return;
	}
	std::cout << '"' << k->data << '"';
}

void printDuoList(DuoList* lst) {
	Node* current = lst->head;
	if (current == NULL) printNode(current);
	else
	{
		do {
			printNode(current);
			current = current->next;
		} while (current != NULL);
	}
	std::cout << "Size: " << lst->size << std::endl;
}



DuoList* initSquence() {
	int length = 0;
	std::cout << "Enter size of bracket sequence " << std::endl;
	std::cin >> length; // Длина выражения
	std::cout << std::endl << "Enter bracket sequence " << std::endl;
	DuoList* Seq = new DuoList; // Создается новый двусвязный список
	init(Seq);
	char input; // Переменная для ввода выражения
	bool flag = false;  // Флаг для поиска скобок в выражении
	char reference[] = { '(',')' ,'{' ,'}' ,'[' ,']' }; //Массив включающий в себя все виды скобок из условия
	//Цикл для ввода данных от пользователя
	for (size_t i = 0; i < length; i++)
	{
		std::cin >> input; // получаем на вход символ
		// проходим по всему массиву искомых значений если что то нашли сразу ставим флаг и выходим из цикла
		for (size_t j = 0; j < 6; j++) {
			if (input == reference[j]) {
				flag = true;
				break;
			}
		}
		//если были скобки пишем их в двусвязный список
		if (flag) pushBack(Seq, input);
	}
	return Seq;
}

/// <summary>
/// Вспомогательная функция для сравнния
/// </summary>
/// <param name="word"></param>
/// <returns></returns>
int equals(char word) {
	if (word > 0x42) return 0x02;
	return 0x01;
}

bool sosedi(DuoList* lst, Node* front = NULL) {
	Node* nextFront = front->next;//Переменная для чтения значения второго после головы списка
	bool flag;
	if (lst->head == NULL || nextFront == NULL) return false;
	if (front->data == (nextFront->data - equals(nextFront->data)))
	{
		front->previously->next = nextFront->next;
		nextFront->next->previously = front->previously;
		delete front;
		delete nextFront;
		return true;
	}
	else {
		flag = sosedi(lst, nextFront);
		return flag;
	}
}

bool bracketSequence(DuoList* Seq, Node* old = NULL) {
	Node* front = 0; //Переменная для чтения значений с головы списка
	Node* nextFront = 0; //Переменная для чтения значения второго после головы списка
	Node* back = 0;  //Переменная для записи значений с хвоста списка
	Node* previouslyBack = 0; //Переменная для чтения значения второго перед хвостом списка
	//Если в списке нечетное количество элементов то какой то пары скобок не будет возвращаем ложь
	if (Seq->size % 2 != 0) return false;
	int flag = true; // по умолчанию считаем что последовательность верная
	//Забираем значения из списка пока он не кончиться
	while (Seq->head != NULL) {
		/*front = Seq->head; // СОхраняем без удаления ! ссылку на начало и след элемент
		nextFront = front->next;

		//Если они равны то убираем их и
		if (front->data == (nextFront->data - equals(nextFront->data))) {
			remFront(Seq);
			remFront(Seq);
			return bracketSequence(Seq);
		}
		else {
			back = ;
			previouslyBack = Seq->tail->previously;
			if (back->data == (previouslyBack->data - equals(previouslyBack->data))) {
				remBack(Seq);
				remBack(Seq);
				return bracketSequence(Seq);
			}
			else {
				if (front->data == (back->data - equals(back->data))) {
					remFront(Seq);
					remBack(Seq);
					return bracketSequence(Seq);
				}
				else return false;
			}
		}
		front = remFront(Seq);
		nextFront = front->next;
		if ((old != NULL) && (old->data == (front->data - equals(front->data)))) {
			old = NULL;
			return true;
		}
		else {
			if (nextFront == NULL) return false;
			if (front->data == (nextFront->data - equals(nextFront->data))) {
				remFront(Seq);
				continue;
			}
			else {
				flag = bracketSequence(Seq, front);
				/*if (front->data != (nextFront->data - equals(nextFront->data))) {

				}
				else {

				else flag = false;

			}
		}*/
		front = Seq->head;
		nextFront = front->next;
		if (front->data != (nextFront->data - equals(nextFront->data))) {
			flag = sosedi(Seq, front);
		}
		else {
			remFront(Seq);
			remFront(Seq);
		}
		if (flag == false) { return false; }
	}
	return flag;
}

#pragma endregion

#pragma region Цикличиские списки

Knot cyrcleKnot;
List cyrcleList;

void insCyrcle(List* lst, int data) {
	Knot* cyrcle = new Knot;
	cyrcle->date = data;
	cyrcle->next = lst->head;

	Knot* current = lst->head;
	if (current == NULL) {
		lst->head = cyrcle;
		cyrcle->next = lst->head;
		return;
	}
	else {
		while (current->next != lst->head) current = current->next;
		current->next = cyrcle;
	}
}

Knot* remCyrcle(List* lst, int data) {
	Knot* current = lst->head;
	Knot* parent = NULL;
	if (current == NULL) return NULL;
	while (current->next != NULL && current->date != data) {
		parent = current;
		current = current->next;
	}
	if (current->date != data) return NULL;
	if (current == lst->head) {
		if (current->next == lst->head) { //Если в списке один элемент
			lst->head = NULL;
			lst->size--;
			return current;
		}
		else {
			Knot* tmp = current;
			while (current->next != lst->head) current = current->next;
			lst->head = tmp->next;
			current->next = lst->head;
			lst->size--;
			return tmp;
		}
	}
	parent->next = current->next;
	lst->size--;
	return current;
}

void printCyrcle(List* lst) {
	Knot* current = lst->head;
	if (current == NULL) printKnot(current);
	else
	{
		do {
			printKnot(current);
			current = current->next;
		} while (current != lst->head);
	}
	std::cout << "Size: " << lst->size << std::endl;
}

#pragma endregion

#pragma region Стэк

/// <summary>
/// Структура узла односвязного списка
/// </summary>
typedef struct NodeStack {
	T data;
	struct NodeStack* next;
}NodeStack;

/// <summary>
/// Структура односвязного списка
/// </summary>
typedef struct ListStack {
	NodeStack* head;
	int size;
}ListStack;

/// <summary>
/// Инициализация нового списка
/// </summary>
/// <param name="lst">Указатель на список</param>
void initList(ListStack* lst) {
	lst->head = NULL;
	lst->size = 0;
}

boolean push(ListStack* stack, T value) {
	NodeStack* tmp = new NodeStack;
	if (tmp == NULL) {
		std::cout << "Stack overflow" << std::endl;
		return false;
	}
	tmp->data = value;
	tmp->next = stack->head;
	stack->head = tmp;
	stack->size++;
	return true;
}

T pop(ListStack* stack) {
	if (stack->size == 0) {
		std::cout << "Stack is empty" << std::endl;
		return -1;
	}
	NodeStack* tmp = stack->head;
	T data = tmp->data;
	stack->head = stack->head->next;
	stack->size--;
	delete tmp;
	return data;
}

#pragma endregion

#pragma region Очередь на основе двусвязного списка

/// <summary>
/// Структура узла очереди
/// </summary>
typedef struct NodeQueue {
	T data;
	struct NodeQueue* next;
	struct NodeQueue* previously;
}NodeQueue;

/// <summary>
/// Структура очереди
/// </summary>
typedef struct Queue {
	NodeQueue* head;
	NodeQueue* tail;
	int size;
}QueueList;

/// <summary>
/// Инициализация очереди
/// </summary>
/// <param name="queue"></param>
void init(QueueList* queue) {
	queue->head = NULL;
	queue->tail = NULL;
	queue->size = 0;
}

/// <summary>
/// Добавление элементов в очередь
/// </summary>
/// <param name="lst">Ссылка на список</param>
/// <param name="data">Данные для добавления</param>
boolean enqueue(QueueList* lst, T data) {
	NodeQueue* tmp = new NodeQueue;
	if (tmp == NULL) return false; //Памяти нет!!!
	tmp->data = data;
	tmp->previously = lst->tail; //т.к. мы добавляем к "хвосту" то предыдущий элемент будет тот,
	// что до этого был в конце списка, а следующий должен быть NULL, т.к. мы теперь конец
	tmp->next = NULL;
	if (lst->tail != NULL) lst->tail->next = tmp;
	// Если есть "хвостовой" элемент, то добавим ему указатель на новый(следующий)
	if (lst->head == NULL) lst->head = tmp;
	// Если нет начала списка(список пуск) укажем что новый элемент - начало списка
	lst->tail = tmp;
	lst->size++;
	return true;
}

/// <summary>
/// Удаление элемента элементов из очереди
/// </summary>
/// <param name="lst">ссылка на очереди</param>
/// <returns>Результат удаления</returns>
T dequeue(QueueList* lst) {
	if (lst->head == NULL || lst->size == 0) return -1; //Проверим не пустой ли список
	NodeQueue* tmp = lst->head; //Скопируем голову во временную переменную 
	T data = lst->head->data;
	lst->head = lst->head->next; //Переместим указатель головы списка на следующий за головой элемент
	if (lst->head != NULL) lst->head->previously = NULL; //Проверим список на пустоту, мало-ли след. элемента нет
	// Если все таки есть то удалим у него ссылку на старую голову (previously)
	if (tmp == lst->tail) lst->tail = NULL; // Если старая голова была еще и последним элементом в списке,
	// то обнуляем указатель на хвост
	delete tmp;
	lst->size--;
	return data;
}


#pragma endregion


//Удалять узлы нужно при возврате значений, т.е. возвращать данные а структуры удалять...

int main()
{
	//decToBin(11);
	/*int i = 0;
	while (i<5)
	{
		enqueue('a');
		enqueue('b');
		enqueue('c');
		enqueue('d');
		enqueue('e');
		enqueue('f');
		while (items > 0)
		{
			std::cout << dequeue();
		}
		std::cout << std::endl;
		i++;
	}

	init();
	ins(1, 11);
	ins(3, 22);
	ins(4, 33);
	ins(2, 44);
	ins(3, 55);
	ins(4, 66);
	ins(5, 77);
	ins(1, 88);
	ins(2, 99);
	ins(6, 100);
	ins(8, 111);
	printQueue();
	for (size_t i = 0; i < 7; i++)
	{
		Node* n = rem();
		std::cout << '{' << n->prioritete << ", " << n->data << "} ";
	}
	printQueue();*/

	List* lst = new List;
	initList(lst);
	printList(lst);
	insertList(lst, 9);
	printList(lst);
	insertList(lst, 8);
	insertList(lst, 7);
	insertList(lst, 6);
	insertList(lst, 5);
	insertList(lst, 4);
	printList(lst);
	printKnot(rm(lst, 3));	std::cout << "<- Remove knot" << std::endl;
	printList(lst);
	List* copyRight = copyList(lst);
	printList(copyRight);
	printKnot(rm(copyRight, 11));	std::cout << "<- Remove knot from Copy List" << std::endl;
	std::cout << "Copy List" << std::endl;
	printList(copyRight);
	std::cout << "Origin list" << std::endl;
	printList(lst);
	std::cout << "Sorted list?" << sortList(copyRight);
	DuoList* sqe = initSquence();
	printDuoList(sqe);
	std::cout << "Correct? " << bracketSequence(sqe);
	return 0;

}