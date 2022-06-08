#pragma once

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
