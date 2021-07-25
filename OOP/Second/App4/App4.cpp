#include  "ArrayInt.h"
#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
	std::vector<int> vector = { 1,2,34,58,7,9,8,8,9,8 };
	std::cout << "Count value = " << vector.size() << std::endl;
	std::set<int> unique(vector.begin(), vector.end());
	std::cout << "Unique value = " << unique.size() << std::endl;
	
	auto arr = ArrayInt(5);
	arr[0] = 5;
	arr[1] = 4;
	arr[2] = 7;
	arr[3] = 9;
	arr[4] = 13;
	arr.print();
	arr.sort();
	arr.pop_front();
	arr.pop_back();
	arr.print();
	
	return 0;
}
