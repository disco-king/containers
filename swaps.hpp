#pragma once
// #include "./vector/vector.hpp"

namespace ft
{

template <typename T>
void swap(T &lhs, T &rhs)
{
	T buff = lhs;
	lhs = rhs;
	rhs = buff;
}

}

namespace std
{

template <class T, class Allocator>
void swap(ft::vector<T, Allocator> &x, ft::vector<T, Allocator> &y)
{
	x.swap(y);
}

}