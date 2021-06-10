#pragma once
#define T int
#define true 1 == 1
#define false 1 != 1
typedef int boolean;

#pragma region Односвязные списки
/// <summary>
/// Структура узла односвязного списка
/// </summary>
typedef struct Knot {
	int date;
	char name;
	struct Knot* next;
}Knot;

typedef struct NodeOneLink {
	int data;
	struct NodeOneLink* next;
}NodeOneLink;
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
void init(List* lst);

/// <summary>
/// Добавление нового элемента
/// </summary>
/// <param name="lst">Указатель на список</param>
/// <param name="data">Новый элемент</param>
void insertList(List* lst, int data, char name);

/// <summary>
/// Удаление элементов из связного списка
/// </summary>
/// <param name="lst">ссылка на головной элемент и кол-во</param>
/// <param name="data">данные которые надо удалить</param>
/// <returns>данные которые надо удалить</returns>
Knot* rm(List* lst, int data);

/// <summary>
/// Функция копирования односвязного листа
/// </summary>
/// <param name="Lst">Указатель на список который надо скопировать</param>
/// <returns>Скопированный список</returns>
List* copyList(List* lst);

/// <summary>
/// Функция проверки отсортирован ли односвязный список
/// </summary>
/// <param name="lst">Указатель на список</param>
/// <returns>Результат проверки</returns>
bool sortList(List* lst);

void printKnot(Knot* k);

void printList(List* lst);
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

void init(DuoList* lst);
void pushFront(DuoList* lst, char data);
void pushBack(DuoList* lst, char data);
Node* rm(DuoList* lst, int data);
Node* remFront(DuoList* lst);
Node* remBack(DuoList* lst);
void printNode(NodeOneLink* k);
void printDuoList(DuoList* lst);
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

void init(ListStack* lst);

boolean push(ListStack* stack, T value);

T pop(ListStack* stack);

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
void init(QueueList* queue);

/// <summary>
/// Добавление элементов в очередь
/// </summary>
/// <param name="lst">Ссылка на список</param>
/// <param name="data">Данные для добавления</param>
boolean enqueue(QueueList* lst, T data);

/// <summary>
/// Удаление элемента элементов из очереди
/// </summary>
/// <param name="lst">ссылка на очереди</param>
/// <returns>Результат удаления</returns>
T dequeue(QueueList* lst);
#pragma endregion

#pragma region Динамические массивы

/// <summary>
/// Функция выделяет память под двумерный массив 
/// </summary>
/// <param name="row">размер строк</param>
/// <param name="col">размер столбцов</param>
/// <returns>возвращаем ссылку на фрагмент выдленной памяти</returns>
int** init2Array(int col, int row);

char** char2Array(int col, int row);

/// <summary>
///  Функция для очистки памяти
/// </summary>
/// <param name="arr">массив который надо удалить</param>
void clear2Araay(int** arr);

/// <summary>
/// Функция - заполнение массива конкретными значениями
/// </summary>
/// <param name="matrix"> ссылка на массив</param>
/// <param name="cols">количество колонок</param>
/// <param name="row">количество строк</param>
/// <param name="leghtAgrs">длина аргументов массива</param>
/// <param name="">Аргументы массива</param>
void setLineValues(int** matrix, int cols, int row, int leghtAgrs, ...);

void print2dArray(int** array, int row, int col);

void print2dCharArray(char** array, int row, int col);

void print1dCharArray(char* arr, int row);

void print1dArray(int* arr, int row);

void quickSort(int* data, int const len);

void fillIntRandom(int* array, int size, int border);

int get2dInt(int** matrix, int row, int col);

void set2dInt(int** matrix, int row, int col, int num);

void init1dArrayNull(int* arr, int size);

void init2dArrayNum(int** arr, int row, int col, int num);

void print2dmatrix(int** array, int row, int col);

void insertionSort(int data[], int lenD);
#pragma endregion
