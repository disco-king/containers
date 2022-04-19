#pragma once

#include <iostream>
#include <vector>

namespace ft{
template <typename T, typename Container = std::vector<T> >
class stack
{

private:

	Container c;

public:

	explicit stack(const Container& ctnr = Container());

	bool empty() const;
	size_t size() const;
	T& top();
	const T& top() const;
	void push (const T& val);
	void pop();
};
}

#include "stack.tpp"