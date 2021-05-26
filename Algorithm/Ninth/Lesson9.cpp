#include <iostream>
//--------------------------------------------------------//
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
//-----------------------------------------------------------------------//
#define SZ 10
typedef struct {
	int prioritete;
	int data;
} Node;

Node* arr[SZ];
int head; // Индекс головы очереди
int tail; // Индекс конца очереди
int items;// Индекс кол-ва элементов

void init() {
	for (size_t i = 0; i < SZ; i++)
		arr[i] = NULL;
	head = 0;
	tail = 0;
	items = 0;
}

/// <summary>
/// Функция заполения
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
	/*if (tail == SZ - 1) //Обнуляем конец очереди, так как добавляем мы все подряд и следить за индексом tail нужно
		tail = -1;*/
	int idx = tail++ % SZ;
	arr[idx] = node;
	items++;
}

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
		arr[idx] = arr[--items]; //Перемещаем послдний элемент на место удаленного
		arr[items] = NULL; 		 //удаляем элемент который отдаем
		return max;
	}
}

void printQueue() {
	std::cout << '[';
	for (size_t i = 0; i < SZ; i++)
	{
		if(arr[i] == NULL)
			std::cout << "[* *]";
		else
		{
			std::cout<<'['<<arr[i]->prioritete<<", "<<arr[i]->data<<"] ";
		}
	}
	std::cout <<']'<< std::endl;
}

int main()
{
	decToBin(11);

	init();
	ins(1,11);
	ins(3, 22);
	ins(4, 33);
	ins(2, 44);
	ins(3, 55);
	ins(4, 66);
	ins(5, 77);
	ins(1, 88);
	ins(2, 99);
	ins(6, 100);
	ins(8, 111); // Для проверки переполения очереди
	printQueue();
	for (size_t i = 0; i < 7; i++)
	{
		Node* n = rem();
		std::cout << '{' << n->prioritete << ", " << n->data << "} ";
	}	
	printQueue();

	// Для проверки что правильно отрабатывает пустая очередь
	for (size_t i = 0; i < 4; i++)
	{
		Node* n = rem();
		std::cout << '{' << n->prioritete << ", " << n->data << "} ";
	}	
	printQueue();





	
	
}