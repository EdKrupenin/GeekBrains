#include "pch.h"
#include <math.h>
#include <corecrt_math_defines.h>

/*
3.������� �����: Fraction (�����). ����� ����� ��������� � ����������� (��������, 3/7 ��� 9/2). �������������, ����� ����������� �� ��� ����� 0.
�����������:
	�������������� �������� ��������� (+, -, *, /) ��� ���������� �������� � �������
	������� �������� (-)
	���������� ��������� ��������� ���� ������ (==, !=, <, >, <=, >=).
����������: ��������� ��������� < � >=, > � <= � ��� ���������� �����������������, ���������� ����������� ���� ����� ������.
������������������ ������������� ������������� ����������.

4. ������� ����� Card, ����������� ����� � ���� ��������. � ����� ������ ������ ���� ��� ����: �����, �������� ����� � ��������� ����� (����� ����� ��� ��������).
������� ���� ����� � �������� ����� ����� ������������ (enum). ��������� ����� - ��� bool. ����� � ���� ������ ������ ���� ��� ������:
����� Flip(), ������� �������������� �����, �.�. ���� ��� ���� �������� �����, �� �� �� ������������ ����� �����, � ��������.
����� GetValue(), ������� ���������� �������� �����, ���� ����� �������, ��� ��� = 1.*/



/* 1. ������� ����������� ����� Figure(������).��� ������������ �������� ������ Parallelogram(��������������) � Circle(����).
����� Parallelogram � ������� ��� ������� Rectangle(�������������), Square(�������), Rhombus(����).
��� ���� ������� ������� ������������.��� ������ Figure �������� ����� ����������� ������� area() (�������).
�� ���� ��������� ������� �������������� ��� �������, ������ �� �������������� ������ ���������� �������.*/

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
2. ������� ����� Car (����������) � ������ company (��������) � model (������). ������-����������: PassengerCar (�������� ����������) � Bus (�������).
�� ���� ������� ��������� ����� Minivan (�������). ������� ������������ ��� ������� �� �������, ����� ��� �������� ������ � �������.
������� ������� ��� ������� �� ������� � ����������, � ����� ������������������ ����������� ������������.
�������� �������� �� �������� ������ ������.
����������: ���� ������������ ����������� ������� �����, �� ������ ������ "��������" �������� ������ ������� ����� "��������" �����.
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
