#pragma once

#include <iostream>
#include "../vector/vector.hpp"

namespace ft{
template <typename T, typename Container = ft::vector<T> >
class stack
{

protected:

	Container c;

public:

	typedef size_t size_type;
	typedef T value_type;
	typedef Container container_type;

	explicit stack(const Container& ctnr = Container());

	bool empty() const;
	size_type size() const;
	T& top();
	const T& top() const;
	void push (const T& val);
	void pop();

	template <class U, class Cont>
	friend bool operator== ( stack<U, Cont> const & lhs, stack<U, Cont> const & rhs);
	template <class U, class Cont>
	friend bool operator!= (stack<U, Cont> const & lhs, ft::stack<U, Cont> const & rhs);
	template <class U, class Cont>
	friend bool operator> (stack<U, Cont> const & lhs, ft::stack<U, Cont> const & rhs);
	template <class U, class Cont>
	friend bool operator>= (stack<U, Cont> const & lhs, ft::stack<U, Cont> const & rhs);
	template <class U, class Cont>
	friend bool operator< (stack<U, Cont> const & lhs, ft::stack<U, Cont> const & rhs);
	template <class U, class Cont>
	friend bool operator<= (stack<U, Cont> const & lhs, ft::stack<U, Cont> const & rhs);

};
template <class T, class Container>
bool operator== (ft::stack<T, Container> const & lhs, ft::stack<T, Container> const & rhs)
{
	return lhs.c == rhs.c;
}

template <typename T, typename Container>
bool operator!= (ft::stack<T, Container> const & lhs, ft::stack<T, Container> const & rhs)
{
	return lhs.c != rhs.c;
}

template <typename T, typename Container>
bool operator> (ft::stack<T, Container> const & lhs, ft::stack<T, Container> const & rhs)
{
	return lhs.c > rhs.c;
}

template <typename T, typename Container>
bool operator>= (ft::stack<T, Container> const & lhs, ft::stack<T, Container> const & rhs)
{
	return lhs.c >= rhs.c;
}

template <typename T, typename Container>
bool operator< (ft::stack<T, Container> const & lhs, ft::stack<T, Container> const & rhs)
{
	return lhs.c < rhs.c;
}

template <typename T, typename Container>
bool operator<= (ft::stack<T, Container> const & lhs, ft::stack<T, Container> const & rhs)
{
	return lhs.c <= rhs.c;
}

}

#include "stack.tpp"