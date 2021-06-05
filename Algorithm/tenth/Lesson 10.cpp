#include <iostream>
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

#pragma endregion

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
/// <param name="word">Символ</param>
/// <returns>Размер смещения по ascii таблице</returns>
int equals(char word) {
	if (word > 0x42) return 0x02;
	return 0x01;
}

/// <summary>
/// Вспомогательная функция поиска пары одинаквых скобок
/// </summary>
/// <param name="word">Символ</param>
/// <returns>Размер смещения по ascii таблице</returns>
bool neighboring (DuoList *lst, Node * front = NULL){
	Node* nextFront = front->next;//Переменная для чтения значения второго после головы списка
	bool flag;
	if (lst->head == NULL || nextFront == NULL) return false; //Если кончился список или остался 1 элемент, то значитмы ничего не нашли - ложь и выход из рекурсии
	if (front->data == (nextFront->data - equals(nextFront->data)))  //Если два соседних элемента равны
	{
		front->previously->next = nextFront->next;  //переписываем ссылки в предыдущем и следущем элементах после этой пары
		nextFront->next->previously = front->previously;
		delete front;                               //удаляем схожие элементы
		delete nextFront;
		return true;                                //выходим из рекурсии возврщая true
	}
	else {										//Если соседние элементы не равны то рекурсивно запускаем эту же функцию, передавая в нее адрес второго элемента
		 flag = neighboring(lst, nextFront);
		 return flag;							//после выхода из рекрсии возвращаем flag
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
		front = Seq->head;  //сслыка на 1 элемент в списке
		nextFront = front->next; // следующий за ним
		if (front->data != (nextFront->data - equals(nextFront->data))) {
			flag = neighboring(Seq, front);
		}
		else{  //если они равны удаляем оба из списка
			remFront(Seq);
			remFront(Seq);
		}
		if (flag == false) { return false; } //если хоть один раз функция сосоедей вернула false - выходим из цикла
	}
	return flag; //возвращаем флаг
}

int main()
{
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
	//Как правильно удалять списки? надо пройти по всем его элементам и вызвать для них delete, а потом для самого списка?
	return 0;

}