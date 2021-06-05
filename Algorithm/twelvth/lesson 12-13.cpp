#include <iostream>
#include <fstream>
#include "Resource/Lesson9-10.h"

#define true 1 == 1
#define false 1 != 1
typedef int boolean;
const int fiftytree = 50;
const int countKnot = 10;
std::ifstream file;

const int n = 6; //Количество вершин графа...
//Матрица смежности
int matrix[n][n] = {
	//   a,b,c,d,e,f
		{0,1,1,0,0,0}, //a
		{0,0,0,1,1,1}, //b
		{0,0,0,0,0,1}, //c
		{1,0,0,0,0,0}, //d
		{0,0,0,0,0,0}, //e
		{0,0,0,0,1,0}, //f
};
int visited[n] = { 0 }; //Массив посещенных вершин
int refernce[n] = { 0 };

#pragma region Обход в глубину
/// <summary>
/// переходы на глубину
/// </summary>
/// <param name="st"></param>
void depthTravers(int st) {
	int guidingStar;
	std::cout << "You were here - " << char(0x61 + st) << " ";
	visited[st] = 1;
	
	//Проверяем связи "ребра" с другими вершинами
	for (guidingStar = 0; guidingStar < n; guidingStar++) {
		if (matrix[st][guidingStar] && visited[guidingStar] != 1) {
			depthTravers(guidingStar);
		}
			
	}
}

/// <summary>
/// Проход в глубину c использованием Stack
/// </summary>
/// <param name="matrix">Матрица смежности</param>
/// <param name="start">Точка старта</param>
/// <param name="size">Количество вершин графа (размер матрицы)</param>
void depthTraversStack(int** matrix, int start, const int size) {
	//Создаем и инициализируем стэк
	ListStack* stackTravers = new ListStack;
	init(stackTravers);
	//Создаем и обнуляем массив посещений
	int* visiteD = new int[size];
	init1dArrayNull(visiteD, size);
	//Записываем в очередь стартовую точку
	push(stackTravers, start);
	while (stackTravers->size > 0) {
		int index = pop(stackTravers); //забираем узел с вершины стэка
		if (visiteD[index] == 1) continue; //если там были то берем следующий
		visiteD[index] = 1; // отмечаемся что мы тут были
		std::cout << "You were here - " << char(0x61 + index) << " ";
		//Смотрим куда можно пойти из вершины index по строке матрицы смежности...
		for (size_t i = 0; i < size; i++)
		{
			//Забираем значение массива в строке index в колонке i
			if (get2dInt(matrix, index, i) == 1 && visiteD[i] == 0)
				//Если мы там еще не были пушим в стэк
				push(stackTravers, i);
		}
	}
	//Если рекурсия идет в прямом порядке то стэк - в обратном в данном случае начинаем с С
	//Закончиться когда все вершины будут посещены
	delete[] visiteD;
}
#pragma endregion

#pragma region Обход в ширину
/// <summary>
/// Обход в ширину на основе очереди и цикла while
/// </summary>
/// <param name="matrix">Матрица смежности</param>
/// <param name="start">Точка старта</param>
/// <param name="size">Количество вершин графа (размер матрицы)</param>
void widthTravers(int** matrix, int start, const int size) {
	//Создаем и инициализируем очередь
	QueueList* queueTravers = new QueueList;
	init(queueTravers);
	//Создаем и обнуляем массив посещений
	int* visiteD = new int[size];
	init1dArrayNull(visiteD, size);
	//Записываем в очередь стартовую точку
	enqueue(queueTravers, start);
	while (queueTravers->size > 0) {
		int index = dequeue(queueTravers);
		if (visiteD[index] == 1) continue;
		visiteD[index] = 1;
		std::cout << "You were here - " << char(0x61 + index) << " ";
		for (size_t i = 0; i < size; i++)
		{
			//Забираем значение массива в строке index в колонке i
			if (get2dInt(matrix, index, i) == 1 && visiteD[i] == 0){
				//Если там 1 (значит есть связь и мы там не были то welcome
				enqueue(queueTravers, i);
			}
			//считаем количество ссылок на смежные вершины
			if (get2dInt(matrix, index, i) == 1) refernce[index] += 1;
		}
	}
	//Закончиться когда все вершины будут посещены
	delete[] visiteD;
}
#pragma endregion

#pragma region Поиск кратчайшего пути в графе
const int WIDTH = 10;
const int HEIGTH = 8;
const int OBSTACLE = -1; //препятствие
const int BLANK = -2;    //пустая ячейка

//Хранение координат точек пути
int pointX[HEIGTH * WIDTH]; // Данный размер обусловлен тем,
int pointY[HEIGTH * WIDTH]; //что никогда не известно какой длины будет путь

int len; // длина пути

/// <summary>
/// Функция поиска пути 
/// </summary>
/// <param name="grid">Поле</param>
/// <param name="sx">Координата X стартовой точки</param>
/// <param name="sy">Координата Y стартовой точки</param>
/// <param name="ex">Координата X финишной точки</param>
/// <param name="ey">Координата Y финишной точки</param>
/// <returns></returns>
int lee(int** grid, int sx, int sy, int ex, int ey) {
	// Данные массивы дают возможность в 4х направлениях просматривать смежные ячейки
	int dx[4] = { 1,0,-1,0 }; //Они хранят смещение относительно текущей точки по осям ХУ
	int dy[4] = { 0,1,0,-1 };
	//Взяв из каждого массива i-й элемент получим направление по которому будем смотреть на ячейку
	/*
			0,-1
			 |
	 -1,0 - 0,0 - 1,0
			 |
			0,1
	*/
	//Счетчики циклов при проходе по рабочему полю
	int x = 0;
	int y = 0;
	int vector; //Возможные варианты смещения относительно текущей точки
	int distance = 0; //Номер шага волны(то что пишем в ячейку)
	int stop; //Признак невозможности прохода(когда кончились узлы)

	if (grid[sy][sx] == OBSTACLE || grid[ey][ex] == OBSTACLE)
		return 0; //Если одна из точек лежит на препятствии
	grid[sy][sx] = 0; //Начало (этап распространения волны)
	do {
		stop = true;
		for (y = 0; y < HEIGTH; ++y) {
			for (x = 0; x < WIDTH; ++x) {
				//Если ху = шагу волны накатываем новый
				if (grid[y][x] == distance) {
					for (vector = 0; vector < 4; vector++) {
						int nextX = x + dx[vector];
						int nextY = y + dy[vector];
						if (nextX >= 0 && nextX < WIDTH &&
							nextY >= 0 && nextY < HEIGTH &&
							grid[nextY][nextX] == BLANK) {
							stop = false;
							grid[nextY][nextX] = distance + 1;
						}
					}
				}
			}
		}
		distance++;
	} while (!stop && grid[ey][ex] == BLANK);

	//Если вышли по флагу то конечная точка не достижима
	if (grid[ey][ex] == BLANK) return 0;

	//(Этап поиска пути)
	len = grid[ey][ex];
	//Конечная точка - текущая
	x = ex;
	y = ey;
	//Восстанавливать будем пока значение волны больше 0
	while (distance > 0)
	{
		pointX[distance] = x;
		pointY[distance] = y;
		distance--;
		for (vector = 0; vector < 4; ++vector) {
			int nextX = x + dx[vector];
			int nextY = y + dy[vector];
			if (nextX >= 0 && nextX < WIDTH &&
				nextY >= 0 && nextY < HEIGTH &&
				grid[nextY][nextX] == distance) {
				y = nextY;
				x = nextX;
			}
		}
	}
	return len;
}

#pragma endregion

#pragma region Полустепень захода
/// <summary>
/// Подсчет полу степеней захода графа с использованием матрицы смежностей
/// </summary>
/// <param name="matrix">Матрица смежностей</param>
/// <param name="ref">Массив со степенями</param>
/// <param name="size">Размер матрицы смежностей</param>
void step(int** matrix, int* ref, int size) {
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (matrix[i][j] == 1) ref[i] += 1;
		}
	}
	//bucketSort(ref, n);
}

/// <summary>
/// Подсчет степеней вершин смежных со стартовой точкой
/// </summary>
/// <param name="matrix">Матрица смежностей</param>
/// <param name="lst">Список смежных вершин</param>
/// <param name="start">стартовая точка</param>
/// <param name="size">размер матрицы</param>
void listAdj(int** matrix, List* lst,int start, int size) {
	int step = 0; //кол-во ссылок на смежную вершину
	for (int i = 0; i < size; i++)
	{
		if (matrix[start][i] == 1) {
			for (int j = 0; j < size; j++)
			{
				if (matrix[i][j] == 1) step++;
			}
			insertList(lst, step, char(0x61 + i));
			step = 0;
		} 
		
	}
	sortList(lst);
}

#pragma endregion

int main()
{
	depthTravers(0);
	init1dArrayNull(visited, n);
	std::cout << std::endl;
	std::cout << std::endl;

	int** trevers = init2Array(n, n);
	setLineValues(trevers, n, n, n * n,
	  //a  b  c  d  e  f
		1, 1, 1, 0, 0, 1, //a
		0, 1, 0, 1, 1, 1, //b
		0, 0, 1, 0, 0, 1, //c
		1, 0, 0, 1, 0, 0, //d
		0, 0, 0, 0, 1, 0, //e
		0, 0, 0, 0, 1, 1);//f
	print2dmatrix(trevers, n, n);
	init1dArrayNull(refernce, n);
	widthTravers(trevers, 0, n);
	std::cout << std::endl;
	print1dArray(refernce, n);
	std::cout << std::endl;
	std::cout << std::endl;

	depthTraversStack(trevers, 0, n);
	std::cout << std::endl;
	std::cout << std::endl;

	int* refer = new int[n];
	init1dArrayNull(refer, n);
	step(trevers, refer, n);
	quickSort(refer,n);
	print1dArray(refer, n);

	List* lst = new List;
	init(lst);
	listAdj(trevers, lst,0,n);
	printList(lst);
	std::cout << std::endl;
	std::cout << std::endl;

	return 0;
}