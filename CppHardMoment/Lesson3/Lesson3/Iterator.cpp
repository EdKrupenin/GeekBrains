#include "Iterator.h"

Iterator::Iterator(std::vector<int>& i_vector) : vector_(i_vector)
{
	_begin = vector_.empty() ? 0 : &vector_.front();
	_end = _begin + vector_.size();
}

int* Iterator::begin()
{
	return _begin;
}

int* Iterator::end()
{
	return _end;
}

bool Iterator::operator!=(int* rhs)
{
	return (this->_begin != rhs);
}

int* Iterator::operator++()
{
	return this->_begin++;
}

int Iterator::operator*()
{
	return *_begin;
}

