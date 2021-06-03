﻿#include <iostream>
#include <fstream>
#define true 1 == 1
#define false 1 != 1
typedef int boolean;
std::ifstream file;

#pragma region Бинарное дерево

/// <summary>
/// Узел дерева
/// </summary>
typedef struct Knot {
	int key;
	struct Knot* left;
	struct Knot* right;
} TreeKnot;

/// <summary>
/// 
/// </summary>
/// <param name="t">Дерево в которое необходимо вставить новый элемент</param>
/// <param name="data">Значение ключа нового элемента</param>
/// <returns></returns>
TreeKnot* treeInstrt(TreeKnot* t, int data) {
	//Создаем новый узел дерева, ссылки нулевые т.к. это будет "лист" дерева
	TreeKnot* newKnot = new TreeKnot{ data, NULL, NULL };
	//Поиск вставки
	TreeKnot* current = t; //Текущий узел при поиске
	TreeKnot* parent = t;  //Родительский узел, что бы сообщить родителю о появлении наследника
	//Если корень дерева пустой то корнем станет новый узел
	if (current == NULL) t = newKnot;
	else {
		while (current->key != data) //Поскольку нет данных на каком шаге найдется место для листа
		{
			parent = current;
			if (current->key > data) {
				current = current->left;
				if (current == NULL) {
					parent->left = newKnot;
					return t;
				}
			}
			else {
				current = current->right;
				if (current == NULL) {
					parent->right = newKnot;
					return t;
				}
			}

		}
	}
	return t;
}

/// <summary>
/// Сначала печатаем корень, затем открываем скобку и
/// рекурсивно выводим наследников или null через ',', потом закрываем скобку
/// </summary>
/// <param name="root">Ссылка на дерево</param>
void printTree(TreeKnot* root)
{
	if (root) {
		std::cout << root->key;
		if (root->left || root->right) {
			std::cout << '(';
			if (root->left)	printTree(root->left);
			else std::cout << "NULL";
			std::cout << ',';
			if (root->right) printTree(root->right);
			else std::cout << "NULL";
			std::cout << ')';
		}
	}
}

/// <summary>
/// Ищет самый подходящий узел который можно будет подставить на место "current"
/// </summary>
/// <param name="current">Переданный узел для поиска места</param>
/// <returns>узел который подходит для вставки</returns>
TreeKnot* getSeccesor(TreeKnot* knot) {
	TreeKnot* current = knot->right;   //Некий наилучший на данный момет элемент (самый подходящий)
	TreeKnot* parent = knot;           //Родительский текущий узел, что бы перезаписать родителю наследника
	TreeKnot* s = knot;				   //Текущий узел 
	while (current != NULL) {
		//Пройдем до упора по левой ветке дерева
		parent = s;
		s = current;
		current = current->left;
	}
	//Нашли наиболее подходящий узел, говорим его родителю
	if (s != knot->right) {
		parent->left = s->right; //Наследник переезжет, но все что было справо от него остаеться родителю
		//"сохраняем правую ветку найденого элемента у родителя"
		s->right = knot->right;  //Отдать правой ссылке найденого узла все что было у удаляемого...
		//"в найденый узел переписываем правую ветку удаляемого элемента"
	}
	return s;
}

/// <summary>
/// Удаление узла дерева
/// </summary>
/// <param name="root">Сслыка на дерево</param>
/// <param name="key">Ключ(значение) удаляемого элемента</param>
/// <returns>Результат удаления, получилось или нет</returns>
boolean deleteKnot(TreeKnot* root, int key) {
	TreeKnot* current = root;   //Текущий узел при поиске
	TreeKnot* parent = root;    //Родительский узел, что бы перезаписать родителю наследника
	boolean isLeftChild = true; //Отметка являться ли узел левым или правым потомком своего родителя
	while (current->key != key) //Поскольку нет данных на каком шаге найдется удаляемый ключ
	{
		parent = current;
		if (key < current->key) {
			current = current->left;
			isLeftChild = true;
		}
		else {
			current = current->right;
			isLeftChild = false;
		}
		// Если мы переместились в пустоту то такого ключа нет...
		if (current == NULL) return false;
	}
	//Так или иначе мы нашли место ключа который надо удалить
	if (current->left == NULL && current->right == NULL) {
		// Если current - корень дерева удалим дерево...
		if (current == root)
			root = NULL;
		//Если current - левый то удаляем у родителя ссылку на левый лист
		else if (isLeftChild)
			parent->left = NULL;
		//Если current - правый то удаляем у родителя ссылку на правый лист
		else parent->right = NULL;
	}
	// Если два наследника, то как со связным списком
	// Удаляемый узел справа или слева от родителя,
	// и у удаляемого узла может быть справа или слева потомки
	else if (current->right == NULL) { //Если правая ссылка удаляемого элемента пустая
		//то забираем все что было в левой части
		if (isLeftChild)
			//Если current слева то в левую ссылку родителя пишем то,
			//что было в левой ссылке удаляемого элемента
			parent->left = current->left;
		else
			//Если current справа то в правую ссылку родителя пишем то,
			//что было в правой ссылке удаляемого элемента
			parent->right = current->left;
	}
	else if (current->left == NULL) { //Если левая ссылка удаляемого элемента пустая
		//то забираем все что было в правой части
		if (isLeftChild)
			//Если current слева то в левую ссылку родителя пишем то,
			//что было в левой ссылке удаляемого элемента
			parent->left = current->right;
		else
			//Если current справа то в правую ссылку родителя пишем то,
			//что было в правой ссылке удаляемого элемента
			parent->right = current->right;
	}
	//Удаление узла содержащий полный набор...
	else {
		TreeKnot* successor = getSeccesor(current);
		//Ищем наиболее подходящую замену для удаляемого узла смотри функцию...
		if (current == root) //Если узел - корень, то
			root = successor; // в корень записываем наболее подходящий узел
		else if (isLeftChild) //Если узел находиться в левой части, то
			parent->left = successor; //в левую ветку предка удаляемого узла пишем
									  //ссылку на наиболее подходящий узел
		else
			//Если находиться в правой части, в правую ветку предка удаляемого узла пишем
			parent->right = successor; //ссылку на наиболее подходящий узел
		//Отдадим найденому узлу все что было слева от удаляемого узла
		successor->left = current->left;
		//"В найденый элемент запищем левую ветку удаляемого элемента"
	}
	delete current;
	return true;

}

/// <summary>
/// Гарантированно пройдем дерево посетив каждый узел по одному разу...
/// Центр - лево - право, используется для копирования деревьев
/// </summary>
/// <param name="root"></param>
void preOrderTravels(TreeKnot* root) {
	if (root) {
		std::cout << root->key << std::endl;
		preOrderTravels(root->left);
		preOrderTravels(root->right);
	}
	/*			     0
				   /    \
				  /      \
				 /        \
				/          \
			   1            8
			 /   \       /     \
			2     5     9      12
		   / \   / \   / \    /  \
		  3   4  6  7 10 11  13  14
	*/
}

/// <summary>
/// Левая ветка - корень - правая ветка
/// Если надо обойти двоичное дерево в порядке возрастания узлов...
/// </summary>
/// <param name="root"></param>
void inOrderTravels(TreeKnot* root) {
	if (root) {
		preOrderTravels(root->left);
		std::cout << root->key << std::endl;
		preOrderTravels(root->right);
	}
}

/// <summary>
/// Левая ветка, правая ветка, корень
/// Используют для полного удаления дерева
/// </summary>
/// <param name="root"></param>
void postOrderTravals(TreeKnot* root) {
	if (root) {
		preOrderTravels(root->left);
		preOrderTravels(root->right);
		std::cout << root->key << std::endl;
	}
}
#pragma endregion

/// <summary>
/// Построение сбалансированного дерева из n узлов
/// </summary>
/// <param name="n">Количество узлов</param>
/// <returns>Сбалансированное дерево</returns>
TreeKnot* balancedTree(int n) {
	TreeKnot* newKnot;
	int x;
	int nL; //Кол-во элементов в левой части дерева
	int nR; //Кол-во элементов в правой части дерева

	if (n == 0) return NULL; //Дошли до "дна" возвращаем указатель на пустоту
	else { //Заполняем данными дерево и
		   //посчитать корнем насколько большого дерева станет данный узел
		file>>x;
		nL = n / 2;		//Слева будет на один элемент больше т.к. 
		nR = n - nL - 1; //мы уже работаем с одним узлом из множества n
		newKnot = new TreeKnot{ x, balancedTree(nL), balancedTree(nR) };
	}
	return newKnot;
}

int main()
{
#pragma region Бинарное дерево
	//Выделять память не нужно, но нужно зафиксировать корень дерева
	TreeKnot* tree = new TreeKnot{ 10, NULL, NULL };
	treeInstrt(tree, 10);
	treeInstrt(tree, 8);
	treeInstrt(tree, 19);
	treeInstrt(tree, 5);
	treeInstrt(tree, 9);
	treeInstrt(tree, 16);
	treeInstrt(tree, 21);
	printTree(tree);
	std::cout << std::endl;

	deleteKnot(tree, 5); //листовой
	printTree(tree);
	std::cout << std::endl;
	deleteKnot(tree, 19); //два наследника
	printTree(tree);
	std::cout << std::endl;
	deleteKnot(tree, 8); //один наследник с ключом 9
	printTree(tree);
	std::cout << std::endl;
	inOrderTravels(tree);
	TreeKnot* balanceTree = NULL;
	file.open("balance.txt");
	if (!file.is_open()) {
		std::cout << "Can't open file!!!" << std::endl;
		return 1;
	}
	const int count = 15; //Количество элементов в файле
	balanceTree = balancedTree(count);
	file.close();
	printTree(balanceTree);
#pragma endregion
	return 0;
}