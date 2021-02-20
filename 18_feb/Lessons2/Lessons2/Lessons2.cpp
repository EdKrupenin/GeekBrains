// Lessons2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

void AREA(char** pole, int size, int operand) {
	/// <summary>
	/// 
	/// </summary>
	/// <param name="pole">Место куда будем писать</param>
	/// <param name="size">Размер поля</param>
	/// <param name="operand">Тип операции над полем</param>
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			switch (operand)
			{
			case 1:
				pole[i][j] = ' ';
				break;
			case 2:
				if ((j % 2 != 0) && (i % 2 == 0)) pole[i][j] = '|';
				if ((j % 2 == 0) && (i % 2 != 0)) pole[i][j] = '-';
				if ((j % 2 != 0) && (i % 2 != 0)) pole[i][j] = '+';
				break;
			case 3:
				std::cout << pole[i][j];
				break;
			default:
				break;
			}
		}
		if (operand == 3) std::cout << std::endl;

	}
}

char** array_create(size_t a, size_t b) {
	/// <summary>
	/// Функция выделяет память под двумерный массив  на котором будет происходить игра
	/// </summary>
	/// <param name="a">размер i</param>
	/// <param name="b">размер j</param>
	/// <returns>возвращаем ссылку на фрагмент выдленной памяти</returns>
	char** pole = new char* [a]; //выделяем память на 5 ссылок
	pole[0] = new char[a * b];   //выделяем в первой ячейке память под весь массив
	for (size_t i = 1; i != a; i++) {
		pole[i] = pole[i - 1] + b; // переписываем ссылки на участки памяти
	}
	// Приемущество данного подхода оператор new вызывается всего лишь два раза, независимо от размерности массива
	return pole;
}

void free_memory(char** pole, size_t a, size_t b) {
	delete[] pole[0];
	delete[] pole;
}

enum Simbols : char
{
	zero = 'o',
	grawe = 'х',
	nothing = ' '
};

typedef enum Simbols simbol;

simbol* array_simbols(size_t size) {
	return new simbol[size];
}

void clear_array_simbols(simbol* arr, size_t size) {
	delete[] arr;
}

/// <summary>
/// Структура описывающая игрока
/// </summary>
typedef struct player {
	char name[8] = "Игрок О";
	int move : 1; // право хода
	simbol figures; //Чем игрок будет играть
	int win : 1; // Флаг победы
	int lost : 1; //Флаг поражения
	int x;	//Координаты х куда ходить
	int y;	//Координаты y куда ходить
};

typedef struct area {
	player one;
	player two;
	//TODO: Вывод выбора координыт
	char koordinathy[9] = { '0','1','2','3','4','5','6','7','8' };
	char pastMoves[9] = { 9 };
	void firstStep() {
		/// <summary>
		/// Процедура опредления первого хода...
		/// </summary>
		/// <param name="one">Первый игрок</param>
		/// <param name="two">Второй игрок</param>
		int random = rand() % 10;
		one.name[6] = '1';
		two.name[6] = '2';
		if (random > 5) {
			one.figures = grawe;
			one.move = 1;
			two.figures = zero;
			two.move = 0;
			std::cout << "Ходит " << one.name;
		}
		else
		{
			two.figures = grawe;
			two.move = 1;
			one.figures = zero;
			one.move = 0;
			std::cout << "Ходит " << two.name;
		}
		/*for (size_t i = 0; i < 9; i++)
		{
			koordinathy[i] = i + 32;
		}*/
	}
	void go(player gamer, char** area, char koordinata) {
		switch (koordinata)
		{
		case '0':
			area[0][0] = gamer.figures;
			break;
		case '1':
			area[0][2] = gamer.figures;
			break;
		case '2':
			area[0][4] = gamer.figures;
			break;
		case '3':
			area[2][0] = gamer.figures;
			break;
		case '4':
			area[2][2] = gamer.figures;
			break;
		case '5':
			area[2][4] = gamer.figures;
			break;
		case '6':
			area[4][0] = gamer.figures;
			break;
		case '7':
			area[4][2] = gamer.figures;
			break;
		case '8':
			area[4][4] = gamer.figures;
			break;
		default:
			break;
		}
		gamer.move = 0;
	}
	bool check(player gamer, char** area) {
		if ((area[0][0] == gamer.figures && area[0][2] == gamer.figures && area[0][4] == gamer.figures) ||
			(area[0][0] == gamer.figures && area[2][0] == gamer.figures && area[4][0] == gamer.figures) ||
			(area[0][0] == gamer.figures && area[2][2] == gamer.figures && area[4][4] == gamer.figures) ||
			(area[0][2] == gamer.figures && area[2][2] == gamer.figures && area[4][2] == gamer.figures) ||
			(area[0][4] == gamer.figures && area[2][4] == gamer.figures && area[4][4] == gamer.figures) ||
			(area[0][4] == gamer.figures && area[2][2] == gamer.figures && area[4][0] == gamer.figures) ||
			(area[2][0] == gamer.figures && area[2][2] == gamer.figures && area[2][4] == gamer.figures) ||
			(area[4][0] == gamer.figures && area[4][2] == gamer.figures && area[4][4] == gamer.figures))
		{
			gamer.win;
			return true;
		}
		return false;
	}
	bool movePlay(char** area, size_t size, char koordinata) {
		if (one.move == -1) {
			go(one, area, koordinata);
			AREA(area, size, 3);
			if (check(one, area)) {
				two.lost = 1;
				std::cout << "Победил " << one.name << std::endl;
				return false;
			}
		}
		if (two.move == -1) {
			go(two, area, koordinata);
			AREA(area, size, 3);
			if (check(two, area)) {
				one.lost = 1;
				std::cout << "Победил " << two.name << std::endl;
				return false;
			}
		}
		one.move = (one.move == -1) ? 0 : 1;
		two.move = (two.move == -1) ? 0 : 1;;
		return true;
	}
	};

	int main()
	{
		setlocale(LC_CTYPE, "Russian");
		//1 е здание
		int i1 = 0;
		long int li = 0;
		char word = 65; //A
	//	float fff = 3.14;
		double d = 2.54455;
		int i[2] = { 0 };
		bool b = true; // 1 или 0
		volatile int A = 0; // запрещает компилятору оптимизироать операции над данным числом
		extern int f; //f будет принимать значения переменных из другого файла
		static int g; // для стуктурного программирования!!! закрыл доступ к переменной из вне.

		//Задание 2
		simbol player1, player2;
		player1 = zero;
		player2 = grawe;
		std::cout << player1 << std::endl;
		std::cout << player2 << std::endl;
		const int size = 5;
		simbol* mass = array_simbols(size);
		for (size_t i = 0; i < size; i++) {
			mass[i] = (i % 2 == 0) ? zero : grawe;
		}
		for (size_t i = 0; i < size; i++) {
			std::cout << mass[i] << std::endl;
		}

		char** pole = array_create(size, size); // Выделил память под массив - поле для игры
		/// <summary>
		/// <param name = "operand = 1">Обнулим< / param>
		/// <param name = "operand = 2">Заполним сетку< / param>
		/// <param name = "operand = 3">Вывод на экран< / param>
		/// </summary>
		AREA(pole, size, 1);
		AREA(pole, size, 2);
		AREA(pole, size, 3);
		area igra;
		igra.firstStep();
		/*for (size_t i = 0; i < 9; i++)
		{
			std::cout << igra.koordinathy[i]<<' ';
		}
		std::cout << std::endl;
		std::cout << igra.one.figures;*/
		bool cirkle = true;
		int counter = 0;
		char koorditata = ' ';
		while (cirkle && counter < 9)
		{
			bool proverka = true;
			std::cout << std::endl << "Выбери координату из списка, и напиши ее ниже" << std::endl;
			for (size_t i = 0; i < 9; i++)
			{
				std::cout << igra.koordinathy[i] << ' ';

			}
			std::cout << std::endl;
			while (proverka) {
				std::cin >> koorditata;
				for (size_t i = 0; i < 9; i++) {
					if (igra.koordinathy[i] == koorditata) {
						igra.koordinathy[i] = 32;
						proverka = false;
						break;
					}
				}
				if (proverka)
					std::cout << "Такой координаты нет в списке!!! Возможно она уже была!" << std::endl;

			}

			cirkle = igra.movePlay(pole, size, koorditata);
			counter++;
		}
		clear_array_simbols(mass, size);
		free_memory(pole, size, size);
		return 0;
	}

	// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
	// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

	// Советы по началу работы 
	//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
	//   2. В окне Team Explorer можно подключиться к системе управления версиями.
	//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
	//   4. В окне "Список ошибок" можно просматривать ошибки.
	//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
	//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
