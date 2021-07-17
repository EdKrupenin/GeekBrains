// hw_OOP.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <vector>

/*
Создать класс Person (человек) с полями: имя, возраст, пол и вес.
Определить методы переназначения имени, изменения возраста и веса.
Создать производный класс Student (студент), имеющий поле года обучения.
Определить методы переназначения и увеличения этого значения.
Создать счетчик количества созданных студентов.
В функции main() создать несколько студентов.
По запросу вывести определенного человека.
*/
class Person {
	std::string p_name{ 0 };
	int p_age = 0;
	char p_gender = 0;
	float p_weight = 0;
public:
	Person(std::string name, int age, char gender, float weight)
		: p_name(name), p_age(age), p_gender(gender), p_weight(weight)
	{}

	void setName(std::string name) {
		this->p_name = name;
	}
	void setAge(int age) {
		this->p_age = age;
	}
	void setWeight(float weight) {
		this->p_weight = weight;
	}

	std::string getName() const {
		return p_name;
	}

	int getAge() const
	{
		return p_age;
	}

	float getWeight() const {
		return p_weight;
	}

	char getGender() const {
		return p_gender;
	}
};

class Student : public Person {
	int s_year = 0;
public:
	static int countStudent;
	Student(std::string name, int age, char gender, float weight, int year)
		: Person(name, age, gender, weight), s_year(year)
	{
		countStudent++;
	}
	void setYear(int year) {
		this->s_year = year;
	}

	void upYear() {
		this->s_year++;
	}

	int getYear() const
	{
		return s_year;
	}

	static void studentCount() {
		std::cout << "Student count - " << countStudent << std::endl;
	}

	void printInfo() const
	{
		std::cout << "Name: " << getName() << ", Age: " << getAge() << ", Gender: " << getGender() <<
			", Weight: " << getWeight() << ", Year of study: " << getYear() << std::endl;
	}
};
int Student::countStudent = 0;
/*
 Создать классы Apple (яблоко) и Banana (банан), которые наследуют класс Fruit (фрукт).
 У Fruit есть две переменные-члена: name (имя) и color (цвет).
 Добавить новый класс GrannySmith, который наследует класс Apple.
 */
class Fruit
{
	std::string f_name;
	std::string f_color;
public:
	Fruit(std::string name, std::string color)
		: f_name(name), f_color(color)
	{}

	void setName(std::string name) {
		this->f_name = name;
	}

	void setColor(std::string color) {
		this->f_color = color;
	}

	std::string getName() const {
		return f_name;
	}

	std::string getColor() const {
		return f_color;
	}
};
class Apple : public Fruit
{
public:
	Apple(std::string color) : Fruit("apple", color) {}
};

class Banana : public Fruit
{
public:
	Banana() : Fruit("banana", "Yellow") {}
};

class GrannySmith : public Apple
{
public:
	GrannySmith() : Apple("green")
	{
		setName("Granny Smith apple");
	}
};

/*
 Изучить правила игры в Blackjack. Подумать, как написать данную игру на С++,
 используя объектно-ориентированное программирование.
 Сколько будет классов в программе? Какие классы будут базовыми, а какие производными?
 Продумать реализацию игры с помощью классов и записать результаты.
 */

class Cards {};

class Chip
{
	int c_count = 0;
	int c_denomination = 0;
public:
	Chip(int count, int denomination):c_count(count), c_denomination(denomination)
	{}

	
};

 //A set of player's or dealer's cards.
class Hand
{
	std::vector<Cards> h_Cards;
public:
	Hand() {}
	/*События раздачи "новой руки"
	Событие добора карты
	событие остановки добора
	*/
	~Hand()
	{
		h_Cards.clear();
	}
};

//Playing at the table against the casino.
class Player
{
	std::initializer_list<Chip> p_chips;
	Hand* p_hand = new Hand();
public:
	Player()
	{
		//заполняем информацию о фишках...
	}
};

//A casino worker acting as a deck card reader.
class Dealer : public Player
{};


//Tracking by the player the location of the cards during the game,
class Tracking{/*"Движок игры"
	события добавления карт игроку и диллеру
	математика карт игрока и диллера (набрали 21 - вышли)*/};
//A complete "game cycle"
class Shuffle : public Tracking
{
	/*Подсчсет очков у играющих
	 * выход по событию поступившему от игрока или диллера
	 * распределение ставок
	 * по сути главный класс игры который содержит в себе движок
	 * классы относящиеся к игрокам, такаие как фишки и карты - второстепенные.
	 */
};



class Game{};

int main()
{
	auto S1 = new Student("Felix", 22, 'm', 75, 4);
	auto S2 = new Student("Fredric", 18, 'm', 60, 1);
	auto S3 = new Student("Karl", 20, 'm', 75, 2);
	S3->printInfo();
	Student::studentCount();

	/*2*/
	Apple a("red");
	Banana b;
	GrannySmith c;

	std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
	std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

	/*3*/
}
