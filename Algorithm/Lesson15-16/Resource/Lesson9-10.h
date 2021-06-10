#pragma once
#define T int
#define true 1 == 1
#define false 1 != 1
typedef int boolean;

#pragma region ����������� ������
/// <summary>
/// ��������� ���� ������������ ������
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
/// ��������� ������������ ������
/// </summary>
typedef struct List {
	Knot* head;
	int size;
}List;

/// <summary>
/// ������������� ������ ������
/// </summary>
/// <param name="lst">��������� �� ������</param>
void init(List* lst);

/// <summary>
/// ���������� ������ ��������
/// </summary>
/// <param name="lst">��������� �� ������</param>
/// <param name="data">����� �������</param>
void insertList(List* lst, int data, char name);

/// <summary>
/// �������� ��������� �� �������� ������
/// </summary>
/// <param name="lst">������ �� �������� ������� � ���-��</param>
/// <param name="data">������ ������� ���� �������</param>
/// <returns>������ ������� ���� �������</returns>
Knot* rm(List* lst, int data);

/// <summary>
/// ������� ����������� ������������ �����
/// </summary>
/// <param name="Lst">��������� �� ������ ������� ���� �����������</param>
/// <returns>������������� ������</returns>
List* copyList(List* lst);

/// <summary>
/// ������� �������� ������������ �� ����������� ������
/// </summary>
/// <param name="lst">��������� �� ������</param>
/// <returns>��������� ��������</returns>
bool sortList(List* lst);

void printKnot(Knot* k);

void printList(List* lst);
#pragma endregion

#pragma region ���������� ������
/// <summary>
/// ��������� ���� ����������� ������ 
/// </summary>
typedef struct Node {
	char data;
	struct Node* next;
	struct Node* previously;
}Node;

/// <summary>
/// ��������� ����������� ������
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

#pragma region ����
/// <summary>
/// ��������� ���� ������������ ������
/// </summary>
typedef struct NodeStack {
	T data;
	struct NodeStack* next;
}NodeStack;

/// <summary>
/// ��������� ������������ ������
/// </summary>
typedef struct ListStack {
	NodeStack* head;
	int size;
}ListStack;

void init(ListStack* lst);

boolean push(ListStack* stack, T value);

T pop(ListStack* stack);

#pragma endregion

#pragma region ������� �� ������ ����������� ������
/// <summary>
/// ��������� ���� �������
/// </summary>
typedef struct NodeQueue {
	T data;
	struct NodeQueue* next;
	struct NodeQueue* previously;
}NodeQueue;

/// <summary>
/// ��������� �������
/// </summary>
typedef struct Queue {
	NodeQueue* head;
	NodeQueue* tail;
	int size;
}QueueList;

/// <summary>
/// ������������� �������
/// </summary>
/// <param name="queue"></param>
void init(QueueList* queue);

/// <summary>
/// ���������� ��������� � �������
/// </summary>
/// <param name="lst">������ �� ������</param>
/// <param name="data">������ ��� ����������</param>
boolean enqueue(QueueList* lst, T data);

/// <summary>
/// �������� �������� ��������� �� �������
/// </summary>
/// <param name="lst">������ �� �������</param>
/// <returns>��������� ��������</returns>
T dequeue(QueueList* lst);
#pragma endregion

#pragma region ������������ �������

/// <summary>
/// ������� �������� ������ ��� ��������� ������ 
/// </summary>
/// <param name="row">������ �����</param>
/// <param name="col">������ ��������</param>
/// <returns>���������� ������ �� �������� ��������� ������</returns>
int** init2Array(int col, int row);

char** char2Array(int col, int row);

/// <summary>
///  ������� ��� ������� ������
/// </summary>
/// <param name="arr">������ ������� ���� �������</param>
void clear2Araay(int** arr);

/// <summary>
/// ������� - ���������� ������� ����������� ����������
/// </summary>
/// <param name="matrix"> ������ �� ������</param>
/// <param name="cols">���������� �������</param>
/// <param name="row">���������� �����</param>
/// <param name="leghtAgrs">����� ���������� �������</param>
/// <param name="">��������� �������</param>
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
