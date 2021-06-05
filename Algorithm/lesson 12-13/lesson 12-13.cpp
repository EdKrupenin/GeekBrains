#include <iostream>
#include <fstream>

#define true 1 == 1
#define false 1 != 1
typedef int boolean;
const int fiftytree = 50;
const int countKnot = 10;
std::ifstream file;

#pragma region Бинарное дерево

/// <summary>
/// Узел дерева
/// </summary>
typedef struct Knot {
	int key;
	int size;
	struct Knot* left;
	struct Knot* right;
	//Knot(int k) { key = k; left = right = 0; size = 1; }
} TreeKnot;

/// <summary>
/// 
/// </summary>
/// <param name="t">Дерево в которое необходимо вставить новый элемент</param>
/// <param name="data">Значение ключа нового элемента</param>
/// <returns></returns>
TreeKnot* treeInstrt(TreeKnot* t, int data) {
	//Создаем новый узел дерева, ссылки нулевые т.к. это будет "лист" дерева
	TreeKnot* newKnot = new TreeKnot{ data,1, NULL, NULL };
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
		std::cout << root->key << " ";
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
			2     5     7      null
		   / \   / \   / \    /  \
		  3   4  6  7 10 11  null  null
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
		std::cout << root->key << " ";
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
		std::cout << root->key << " ";
	}
}

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
		file >> x;
		nL = n / 2;		//Слева будет на один элемент больше т.к. 
		nR = n - nL - 1; //мы уже работаем с одним узлом из множества n
		newKnot = new TreeKnot{ x,1, balancedTree(nL), balancedTree(nR) };
	}
	return newKnot;
}

/// <summary>
/// Построение дерева в массиве
/// </summary>
/// <param name="arr">Указатель на массив</param>
/// <param name="newIndex">Индекс добавляемого элемента</param>
/// <param name="size">Размер массива</param>
void buildTree(int* arr, int newIndex, int size) {
	int maxIndex = newIndex; //Индекс максимального элемента из сравниваемых родителя и потомков
	int newElement = arr[newIndex]; //Значение добавляемого элемента
	while (true) {
		int child = newIndex * 2 + 1; //Левый потомок
		//Если рассчитанный потомок не уходит за пределы массива сравниваем его с родителем
		if ((child < size) && (arr[child] > newElement))
			maxIndex = child;
		child = newIndex * 2 + 2; //Правый потомок
		if ((child < size) && (arr[child] > arr[maxIndex]))
			maxIndex = child;
		if (maxIndex == newIndex) break; // если мы и были максимумом то выходим...
		arr[newIndex] = arr[maxIndex];
		arr[maxIndex] = newElement;
		newIndex = maxIndex;
	}
}

/// <summary>
/// Пузырьковая сортировка
/// </summary>
/// <param name="arr"></param>
/// <param name="size"></param>
void heapSort(int* arr, int size) {
	//Берем половину массива т.к. попадем четко в последний узел с листами и уже их будем сравнивать
	for (int i = size / 2 - 1; i >= 0; --i)
		buildTree(arr, i, size); //За один раз поставит нужный элемент в нужное место, по этому надо вызывать столько раз сколько элементов мы будем добавлять, т.е. половину массива
	//Пока в дереве не останется один элемент будем менять местами нулевой и последний элемент
	//Оставшийся "узел" будет минимальный элементом массива 
	while (size > 1) {
		--size;
		int firstElem = arr[0];
		arr[0] = arr[size];
		arr[size] = firstElem;
		buildTree(arr, 0, size); //Корень дерева в качестве добавляемого элемента, т.е. теперь сверху вниз будет спуск
	}
}
#pragma endregion

#pragma region HomeWork 12
/// <summary>
/// Рекурсивный поиск значения в дереве
/// </summary>
/// <param name="root">Ссылка на корень дерева</param>
/// <param name="key">Искомый ключ</param>
/// <returns>Результат поиска успех или провал</returns>
boolean binSearch(TreeKnot* root, int key) {
	if (root == NULL) return false;
	if (root->key == key) return true;
	//Если искомый ключ(который ищем) больше корневого ключа на данном этапе то идем вправо
	if (root->key < key) return binSearch(root->right, key);
	//Иначе влево
	else return binSearch(root->left, key);
	//будем так ходить до NULL или до положительного результата
}

/// <summary>
/// считаем все узлы до предпоследнего уровня включительно
/// </summary>
/// <param name="root">Ссылка на корень дерева</param>
/// <param name="count">Ссылка на int счетчик</param>
void countKnots(TreeKnot* root, int& count) {
	//Если есть корень и у него есть хотя бы 1 наследник считаем его
	if (root != NULL && (root->left != NULL || root->right != NULL)) {
		countKnots(root->left, count);
		count++;
		countKnots(root->right, count);
	}
}

/// <summary>
/// Проверка сбалансировано дерево или нет
/// </summary>
/// <param name="root"></param>
/// <returns>Ответ да ил нет</returns>
boolean isBalancedTree(TreeKnot* root) {
	int countL = 0;
	int countR = 0;
	countKnots(root->left, countL);
	countKnots(root->right, countR);
	//Если кол-во узлов удовлетворяет условию баланса
	if (countL == countR || countL - 1 == countR) return true;
	else return false;
}

/// <summary>
/// обертка для поля size, работает с пустыми деревьями (t=NULL)
/// </summary>
/// <param name="p">Ссылка на корень</param>
/// <returns>Размер элементов за корнем</returns>
int getsize(TreeKnot* p)
{
	if (!p) return 0;
	return p->size;
}

/// <summary>
/// установление корректного размера дерева
/// </summary>
/// <returns>Возвращает размер дерева</returns>
void fixsize(TreeKnot* p)
{
	p->size = getsize(p->left) + getsize(p->right) + 1;
}

/// <summary>
/// Считаем кол-во узлов в дереве
/// </summary>
/// <param name="root"></param>
/// <param name="count"></param>
void CountKnot(TreeKnot* root, int& count) {
	if (root != NULL) {
		CountKnot(root->left, count);
		count++;
		CountKnot(root->right, count);
	}
}

/// <summary>
/// Функция вставки в дерево, с подсчетом его размера
/// </summary>
/// <returns></returns>
TreeKnot* ins(TreeKnot* root, int key)
{
	if (root == NULL)
		return new TreeKnot{ key,1,NULL,NULL };
	if (key < root->key)
		root->left = ins(root->left, key);
	else
		root->right = ins(root->right, key);
	fixsize(root);
	return root;
}

/// <summary>
/// Подсчитывает процент сбалансированных деревьев
/// </summary>
/// <param name="arr"></param>
/// <returns></returns>
double isBalancedOfFiftyTree(TreeKnot* arr) {
	int countBalance = 0;
	for (size_t i = 0; i < 50; i++)
	{
		TreeKnot* currentTree = new TreeKnot{ rand(),1,NULL,NULL };
		for (size_t i = 0; i < countKnot; i++)
		{
			currentTree = ins(currentTree, rand());
		}
		arr[i] = *currentTree;
		if (isBalancedTree(currentTree)) countBalance++;
		/*std::cout << "Is balanced " << i << " tree ?" << (isBalancedTree(currentTree) ? "True" : "False") << std::endl;*/
	}
	return (double)countBalance * 100 / fiftytree;
	/*В ходе многочисленных экскрементов было установлено что при количестве узлов 10 процент сбалансированных - 12%*/
}
#pragma endregion

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
	std::cout << "8 in Tree = " << (binSearch(tree, 8) ? "True" : "False") << std::endl;
	std::cout << "100 in Tree = " << (binSearch(tree, 100) ? "True" : "False") << std::endl;
	int countTree = 0;
	std::cout << "Is Tree balanced ? " << (isBalancedTree(tree) ? "True" : "False") << std::endl;

	deleteKnot(tree, 5); //листовой
	printTree(tree);
	std::cout << std::endl;
	std::cout << "Is Tree balanced ? " << (isBalancedTree(tree) ? "True" : "False") << std::endl;
	deleteKnot(tree, 19); //два наследника
	printTree(tree);
	std::cout << std::endl;
	std::cout << "Is Tree balanced ? " << (isBalancedTree(tree) ? "True" : "False") << std::endl;
	deleteKnot(tree, 8); //один наследник с ключом 9
	printTree(tree);
	std::cout << std::endl;
	std::cout << "Is Tree balanced ? " << (isBalancedTree(tree) ? "True" : "False") << std::endl;
	preOrderTravels(tree);
	std::cout << std::endl;
	inOrderTravels(tree);
	std::cout << std::endl;
	postOrderTravals(tree);
	std::cout << std::endl;
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
	std::cout << std::endl;

	TreeKnot fiftyTree[fiftytree];
	std::cout << "Percent is balanced Tree = " << isBalancedOfFiftyTree(fiftyTree);

	int arr[countKnot];
	for (int i = 0; i < countKnot; i++)
		arr[i] = rand() % 50 + 1;
	for (int i = 0; i < countKnot; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
	heapSort(arr, countKnot);
	for (int i = 0; i < countKnot; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
#pragma endregion
	return 0;
}