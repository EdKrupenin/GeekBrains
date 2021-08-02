#include "pch.h"
#include <math.h>
#include  <numeric>
#include <corecrt_math_defines.h>

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

class PassengerCar : public virtual Car {
public:
	PassengerCar(std::string company, std::string model) : Car(company, model) {
		std::cout << "Type car is PassengerCar" << std::endl;
	}
	~PassengerCar() {}
};

class Bus : public virtual Car {
public:
	Bus(std::string company, std::string model) : Car(company, model) {
		std::cout << "Type cat is a Bus" << std::endl;
	}
	~Bus() {}
};

class Minivan : public PassengerCar, public Bus {
public:
	Minivan(std::string company, std::string model) : Car(company, model), PassengerCar(company, model), Bus(company, model)
	{}
};

TEST(TestCaseName, TestCar) {
	Minivan* car = new Minivan("Ford", "C-Max");
	delete car;
}


/* 3.������� �����: Fraction (�����). ����� ����� ��������� � ����������� (��������, 3/7 ��� 9/2). �������������, ����� ����������� �� ��� ����� 0.
�����������:
	�������������� �������� ��������� (+, -, *, /) ��� ���������� �������� � �������
	������� �������� (-)
	���������� ��������� ��������� ���� ������ (==, !=, <, >, <=, >=).
����������: ��������� ��������� < � >=, > � <= � ��� ���������� �����������������, ���������� ����������� ���� ����� ������.
������������������ ������������� ������������� ����������.*/

class Fraction
{
	int	f_numerator{ 0 };
	int f_denominator{ 0 };
public:
	Fraction(int numerator, int denominator) {
		try {
			if (denominator == 0)
				throw "Devide by zero";
		}
		catch (...) {
			std::cout << "Devide by zero" << std::endl;
		}
	}
	friend Fraction operator+ (const Fraction& f1, const Fraction& f2);
	friend Fraction operator+ (int num, const Fraction& f2);
	friend Fraction operator+ (const Fraction& f1, int num);
	friend Fraction operator- (const Fraction& f1, const Fraction& f2);
	friend Fraction operator- (int num, const Fraction& f2);
	friend Fraction operator- (const Fraction& f1, int num);
	friend Fraction operator* (const Fraction& f1, const Fraction& f2);
	friend Fraction operator* (int num, const Fraction& f2);
	friend Fraction operator* (const Fraction& f1, int num);
	friend Fraction operator/ (const Fraction& f1, const Fraction& f2);
	friend Fraction operator/ (int num, const Fraction& f2);
	friend Fraction operator/ (const Fraction& f1, int num);

	friend bool operator == (const Fraction& f1, const Fraction& f2);
	friend bool operator == (int num, const Fraction& f2);
	friend bool operator == (const Fraction& f1, int num);
	friend bool operator != (const Fraction& f1, const Fraction& f2);
	friend bool operator != (int num, const Fraction& f2);
	friend bool operator != (const Fraction& f1, int num);
	friend bool operator != (const Fraction& f1, const Fraction& f2);
	friend bool operator != (int num, const Fraction& f2);
	friend bool operator != (const Fraction& f1, int num);
	friend bool operator >= (const Fraction& f1, const Fraction& f2);
	friend bool operator >= (int num, const Fraction& f2);
	friend bool operator >= (const Fraction& f1, int num);
	friend bool operator <= (const Fraction& f1, const Fraction& f2);
	friend bool operator <= (int num, const Fraction& f2);
	friend bool operator <= (const Fraction& f1, int num);
	friend bool operator > (const Fraction& f1, const Fraction& f2);
	friend bool operator > (int num, const Fraction& f2);
	friend bool operator > (const Fraction& f1, int num);
	friend bool operator < (const Fraction& f1, const Fraction& f2);
	friend bool operator < (int num, const Fraction& f2);
	friend bool operator < (const Fraction& f1, int num);

	Fraction operator- () const {
		return Fraction(-f_numerator, f_denominator);
	}

};

Fraction operator+(const Fraction& f1, const Fraction& f2)
{
	int f_lcm = std::lcm(f1.f_denominator, f2.f_denominator);
	int f_numerator = (f1.f_numerator * f_lcm / f1.f_denominator) + (f2.f_numerator * f_lcm / f2.f_denominator);
	return Fraction(f_numerator, f_lcm);
}

Fraction operator+(int num, const Fraction& f2)
{
	return Fraction((num * f2.f_denominator) + f2.f_numerator, f2.f_denominator);
}

Fraction operator+(const Fraction& f1, int num)
{
	return num + f1;
}

Fraction operator-(const Fraction& f1, const Fraction& f2)
{
	int f_lcm = std::lcm(f1.f_denominator, f2.f_denominator);
	int f_numerator = (f1.f_numerator * f_lcm / f1.f_denominator) - (f2.f_numerator * f_lcm / f2.f_denominator);
	return Fraction(f_numerator, f_lcm);
}

Fraction operator-(int num, const Fraction& f2)
{
	return Fraction((num * f2.f_denominator) - f2.f_numerator, f2.f_denominator);
}

Fraction operator-(const Fraction& f1, int num)
{
	return Fraction(f1.f_numerator - (num * f1.f_denominator), f1.f_denominator);
}

Fraction operator*(const Fraction& f1, const Fraction& f2)
{
	return Fraction(f1.f_numerator * f2.f_numerator, f1.f_denominator * f2.f_denominator);
}

Fraction operator*(int num, const Fraction& f2)
{
	return Fraction(num * f2.f_numerator, f2.f_denominator);
}

Fraction operator*(const Fraction& f1, int num)
{
	return num * f1;
}

Fraction operator/(const Fraction& f1, const Fraction& f2)
{
	int f_numerator = f1.f_numerator * f2.f_denominator;
	int f_denominator = f1.f_denominator * f2.f_numerator;
	int gcd = std::gcd(f_numerator, f_denominator);
	return Fraction(f_numerator / gcd, f_denominator / gcd);
}

Fraction operator/(int num, const Fraction& f2)
{
	return Fraction(num, 1) / f2;
}

Fraction operator/(const Fraction& f1, int num)
{
	return f1 / Fraction(num, 1);
}

bool operator==(const Fraction& f1, const Fraction& f2)
{
	int f_lcm = std::lcm(f1.f_denominator, f2.f_denominator);
	bool f_equal = ((f1.f_numerator * f_lcm / f1.f_denominator) == (f2.f_numerator * f_lcm / f2.f_denominator)) ? true : false;
	return f_equal;
}

bool operator==(int num, const Fraction& f2)
{
	return Fraction(num, 1) == f2;
}

bool operator==(const Fraction& f1, int num)
{
	return f1 == Fraction(num, 1);
}

bool operator!=(const Fraction& f1, const Fraction& f2)
{
	return ((f1 == f2) ? false : true);
}

bool operator!=(int num, const Fraction& f2)
{
	return Fraction(num, 1) != f2;
}

bool operator!=(const Fraction& f1, int num)
{
	return f1 != Fraction(num, 1);
}

bool operator>=(const Fraction& f1, const Fraction& f2)
{
	return ((f1 < f2) ? false : true);
}

bool operator>=(int num, const Fraction& f2)
{
	return Fraction(num, 1) >= f2;
}

bool operator>=(const Fraction& f1, int num)
{
	return f1 >= Fraction(num, 1);
}

bool operator<=(const Fraction& f1, const Fraction& f2)
{
	return ((f1 > f2) ? false : true);
}

bool operator<=(int num, const Fraction& f2)
{
	return Fraction(num, 1) <= f2;
}

bool operator<=(const Fraction& f1, int num)
{
	return f1 <= Fraction(num, 1);
}

bool operator>(const Fraction& f1, const Fraction& f2)
{
	int f_lcm = std::lcm(f1.f_denominator, f2.f_denominator);
	bool f_equal = ((f1.f_numerator * f_lcm / f1.f_denominator) > (f2.f_numerator * f_lcm / f2.f_denominator)) ? true : false;
	return f_equal;
}

bool operator>(int num, const Fraction& f2)
{
	return Fraction(num, 1) > f2;
}

bool operator>(const Fraction& f1, int num)
{
	return f1 > Fraction(num, 1);
}

bool operator<(const Fraction& f1, const Fraction& f2)
{
	int f_lcm = std::lcm(f1.f_denominator, f2.f_denominator);
	bool f_equal = ((f1.f_numerator * f_lcm / f1.f_denominator) < (f2.f_numerator * f_lcm / f2.f_denominator)) ? true : false;
	return f_equal;
}

bool operator<(int num, const Fraction& f2)
{
	return Fraction(num, 1) < f2;
}

bool operator<(const Fraction& f1, int num)
{
	return f1 < Fraction(num, 1);
}

TEST(TestCaseName, MathTest) {
	Fraction* number = new Fraction(3, 0);
	Fraction* number1 = new Fraction(3, 4);
	Fraction* number2 = new Fraction(5, 9);
	EXPECT_TRUE(number1 > number2);
	EXPECT_FALSE(number1 == number2);
	delete number1;
	delete number2;
}

/*4. ������� ����� Card, ����������� ����� � ���� ��������. � ����� ������ ������ ���� ��� ����: �����, �������� ����� � ��������� ����� (����� ����� ��� ��������).
������� ���� ����� � �������� ����� ����� ������������ (enum). ��������� ����� - ��� bool. ����� � ���� ������ ������ ���� ��� ������:
����� Flip(), ������� �������������� �����, �.�. ���� ��� ���� �������� �����, �� �� �� ������������ ����� �����, � ��������.
����� GetValue(), ������� ���������� �������� �����, ���� ����� �������, ��� ��� = 1.*/
 enum class c_suit :int
{
	HEART,
	CLUB,
	DIAMOND,
	SPADE,
};

 enum class c_value : int
 {
	 ace = 1,
	 two = 2,
	 three = 3,
	 four = 4,
	 five = 5,
	 six = 6,
	 seven = 7,
	 eight = 8,
	 nine = 9,
	 ten = 10,
	 jack = 10,
	 queen = 10,
	 king = 10
 };

class Card {
	c_suit suitCard;
	c_value valueCard;
	bool conditionCard;
public:
	Card(c_suit Suit, c_value Value) : suitCard(Suit), valueCard(Value), conditionCard(false) {

	}
	void Flip() {
		conditionCard = !(conditionCard);
	}
	int GetValue() const {
		return valueCard;
	}
};