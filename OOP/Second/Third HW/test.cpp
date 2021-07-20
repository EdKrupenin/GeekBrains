#include "pch.h"
#include <math.h>
#include <corecrt_math_defines.h>

/*
3.Создать класс: Fraction (дробь). Дробь имеет числитель и знаменатель (например, 3/7 или 9/2). Предусмотреть, чтобы знаменатель не был равен 0.
Перегрузить:
	математические бинарные операторы (+, -, *, /) для выполнения действий с дробями
	унарный оператор (-)
	логические операторы сравнения двух дробей (==, !=, <, >, <=, >=).
Примечание: Поскольку операторы < и >=, > и <= — это логические противоположности, попробуйте перегрузить один через другой.
Продемонстрировать использование перегруженных операторов.

4. Создать класс Card, описывающий карту в игре БлэкДжек. У этого класса должно быть три поля: масть, значение карты и положение карты (вверх лицом или рубашкой).
Сделать поля масть и значение карты типом перечисления (enum). Положение карты - тип bool. Также в этом классе должно быть два метода:
метод Flip(), который переворачивает карту, т.е. если она была рубашкой вверх, то он ее поворачивает лицом вверх, и наоборот.
метод GetValue(), который возвращает значение карты, пока можно считать, что туз = 1.*/



/* 1. Создать абстрактный класс Figure(фигура).Его наследниками являются классы Parallelogram(параллелограмм) и Circle(круг).
Класс Parallelogram — базовый для классов Rectangle(прямоугольник), Square(квадрат), Rhombus(ромб).
Для всех классов создать конструкторы.Для класса Figure добавить чисто виртуальную функцию area() (площадь).
Во всех остальных классах переопределить эту функцию, исходя из геометрических формул нахождения площади.*/

class Figure {
public:
	Figure() {}
	virtual ~Figure() {}
	virtual double Area() = 0;
};

class Parallelogram : public Figure {
protected:
	int p_a{ 0 };
	int p_b{ 0 };
	int height{ 0 };
public:
	Parallelogram(int a, int b, int h) : Figure(), p_a(a), p_b(b), height(h) {}
	virtual ~Parallelogram() {}
	virtual double Area() override
	{
		return (p_b * height);
	}
};

class Circle : public Figure {
	int c_radius{ 0 };
public:
	Circle(int r) : Figure(), c_radius(r) {}
	virtual ~Circle() {}
	virtual double Area() override
	{
		return pow(c_radius, 2) * M_PI;
	}
};

class Rectangle : public Parallelogram {

public:
	Rectangle(int a, int b) : Parallelogram(a, b, a) {}
	~Rectangle() {}
};

class Square : public Parallelogram {
public:
	Square(int a) : Parallelogram(a, a, a) {}
	~Square() {}
};

class Rhombus : public Parallelogram {
public:
	Rhombus(int a, int h) : Parallelogram(a, a, h) {}
	~Rhombus() {}
};

TEST(TestCaseName, Geometry) {
	Rhombus* rh = new Rhombus(3, 5);
	Rectangle* r = new Rectangle(2, 4);
	Square* s = new Square(5);
	Parallelogram* p = new Parallelogram(3, 5, 2);
	Circle* c = new Circle(8);
	EXPECT_EQ(s->Area(), 25);
	EXPECT_EQ(rh->Area(), 15);
	EXPECT_EQ(r->Area(), 8);
	EXPECT_EQ(p->Area(), 10);
	EXPECT_TRUE(c->Area());
}

/*
2. Создать класс Car (автомобиль) с полями company (компания) и model (модель). Классы-наследники: PassengerCar (легковой автомобиль) и Bus (автобус).
От этих классов наследует класс Minivan (минивэн). Создать конструкторы для каждого из классов, чтобы они выводили данные о классах.
Создать объекты для каждого из классов и посмотреть, в какой последовательности выполняются конструкторы.
Обратить внимание на проблему «алмаз смерти».
Примечание: если использовать виртуальный базовый класс, то объект самого "верхнего" базового класса создает самый "дочерний" класс.
*/

class Car {
	std::string c_company{};
	std::string c_model{};
public:
	Car(std::string company, std::string model) : c_company(company), c_model(model) {
		std::cout << "Company is " << c_company << ", Model is " << c_model << std::endl;
	}
	virtual ~Car() {
		c_company.clear();
		c_model.clear();
	}
};

class PassengerCar : virtual Car{
public:
	PassengerCar(std::string company, std::string model) : Car(company, model) {
		std::cout << "Type car is PassengerCar" << std::endl;
	}
	~PassengerCar(){}
};

class Bus : virtual Car {

};

class Minivan : PassengerCar, Bus {

};
