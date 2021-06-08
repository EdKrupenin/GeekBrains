#include <iostream>
#include "Resource/Lesson9-10.h"
typedef int K;
typedef int htIndex;

int htSize; // глобальный размер хэш таблицы

/// <summary>
/// Расчет индекса в хэш таблице (массива)
/// </summary>
/// <param name="data">Ключ</param>
/// <returns>Искомый индес</returns>
htIndex hash(T data) {
	return data % htSize;
}

/// <summary>
/// Добавление элементов в хэш-таблицу
/// </summary>
/// <param name="table">Ссылка на массив сос списками</param>
/// <param name="data">ключ</param>
/// <returns>Результат операции</returns>
boolean insertNode(Knot** table, K data) {
	Knot* p;  //Указтель на новый узел в который будт записан переданный ключ
	Knot* p0; //Указатель на старую голову спискка к кторой будет добавлен новй узел

	htIndex bucket = hash(data); //Индекс хэш таблицы
	p = new Knot;
	if (p == NULL) {
		std::cout << "Out of memory\n";
		return false;
	}
	//Указатель на текущую голову списка
	p0 = table[bucket];
	table[bucket] = p; //Запишем новую голову
	p->next = p0;      //Припишем хвост новой голову
	p->date = data;	   // Запишем данные в новую голову
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
	//если нашли дату то вернем узел, иначе вернем нул
	return p;
}

void deleteKnot(Knot** table, K data) {

}

int main()
{

	std::cout << "Hello World!\n";
}
