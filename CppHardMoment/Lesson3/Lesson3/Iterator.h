#pragma once
#include "Header.h"

class Iterator
{
	std::vector<int> vector_;
	int* _begin;
	int* _end;
public:
	Iterator(std::vector<int>& i_vector);
	int* begin();
	int* end();
	bool operator!=(int* rhs);
	auto operator++() -> int*;
	int operator*();
};

