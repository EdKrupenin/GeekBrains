// HW5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

template <typename Type>
class Pair1
{
	Type p_l_value{};
	Type p_r_value{};
public:
	Pair1(Type lValue, Type rValue) : p_l_value(lValue), p_r_value(rValue)
	{}
	Type first() const
	{
		return p_l_value;
	}
	Type second() const
	{
		return p_r_value;
	}
};

template <class lType, class rType>
class Pair
{
	lType p_l_value{};
	rType p_r_value{};
public:
	Pair(lType lValue, rType rValue) : p_l_value(lValue), p_r_value(rValue)
	{}
	lType first() const
	{
		return p_l_value;
	}
	rType second() const
	{
		return p_r_value;
	}
};

template<typename  Type>
class StringValuePair : public Pair<std::string, Type>
{
public:
	StringValuePair(std::string s_string, Type value): Pair<std::string,int>(s_string,value) {}
};


int main()
{
    Pair1<int> p1(6, 9);
    std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    const Pair1<double> p2(3.4, 7.8);
    std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

	Pair<int, double> p3(6, 7.8);
    std::cout << "Pair: " << p3.first() << ' ' << p3.second() << '\n';

	const Pair<double, int> p4(3.4, 5);
    std::cout << "Pair: " << p4.first() << ' ' << p4.second() << '\n';
	
	const StringValuePair<int> svp2("Amazing", 7);
	std::cout << "Pair: " << svp2.first() << ' ' << svp2.second() << '\n';

	
	return 0;
}
