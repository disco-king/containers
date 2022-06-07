#pragma once

#include "iterator.hpp"

namespace ft{
template <typename T>
class vectorIterator: public iterator<random_access_iterator_tag, T>
{

private:
	T *ptr;

public:
	typedef typename iterator<random_access_iterator_tag, T>::iterator_category iterator_category;
	typedef typename iterator<random_access_iterator_tag, T>::difference_type difference_type;
	typedef typename iterator<random_access_iterator_tag, T>::value_type value_type;
	typedef typename iterator<random_access_iterator_tag, T>::pointer pointer;
	typedef typename iterator<random_access_iterator_tag, T>::reference reference;

	explicit vectorIterator(T *ptr = 0) : ptr(ptr) {}

	vectorIterator& operator=(vectorIterator const &src) {
		ptr = src.ptr;
		return *this;
	}

	vectorIterator operator+(ptrdiff_t val) const {
		vectorIterator ret;
		ret.ptr = ptr + val;
		return ret;
	}

	ptrdiff_t operator-(vectorIterator other) const {
		ptrdiff_t ret;
		ret = ptr - other.ptr;
		return ret;
	}

	vectorIterator operator-(ptrdiff_t val) const {
		vectorIterator ret;
		ret.ptr = ptr - val;
		return ret;
	}

	vectorIterator operator+=(ptrdiff_t val) { ptr+=val; return *this;}
	vectorIterator operator-=(ptrdiff_t val) { ptr-=val; return *this;}
	vectorIterator& operator++() {ptr++; return *this;}
	vectorIterator operator++(int) {vectorIterator retval = *this; ++(*this); return retval;}
	vectorIterator& operator--() {ptr--; return *this;}
	vectorIterator operator--(int) {vectorIterator retval = *this; --(*this); return retval;}

	operator vectorIterator<const T> () const
	{ return (vectorIterator<const T>(this->ptr)); }

	reference operator*() const { return *ptr; }
	pointer operator->() const { return &(this->operator*()); }
};

template <typename T, typename U>
bool operator==(const vectorIterator<T> &lhs,
				const vectorIterator<U> &rhs)
{return &(*lhs) == &(*rhs);}

template <typename T>
bool operator==(const vectorIterator<T> &lhs,
				const vectorIterator<T> &rhs)
{return &(*lhs) == &(*rhs);}

template <typename T, typename U>
bool operator>(const vectorIterator<T> &lhs,
				const vectorIterator<U> &rhs)
{return &(*lhs) > &(*rhs);}

template <typename T>
bool operator>(const vectorIterator<T> &lhs,
				const vectorIterator<T> &rhs)
{return &(*lhs) > &(*rhs);}

template <typename T, typename U>
bool operator<(const vectorIterator<T> &lhs,
				const vectorIterator<U> &rhs)
{return &(*lhs) < &(*rhs);}

template <typename T>
bool operator<(const vectorIterator<T> &lhs,
				const vectorIterator<T> &rhs)
{return &(*lhs) < &(*rhs);}

template <typename T, typename U>
bool operator>=(const vectorIterator<T> &lhs,
				const vectorIterator<U> &rhs)
{return &(*lhs) >= &(*rhs);}

template <typename T>
bool operator>=(const vectorIterator<T> &lhs,
				const vectorIterator<T> &rhs)
{return &(*lhs) >= &(*rhs);}

template <typename T, typename U>
bool operator<=(const vectorIterator<T> &lhs,
				const vectorIterator<U> &rhs)
{return &(*lhs) <= &(*rhs);}

template <typename T>
bool operator<=(const vectorIterator<T> &lhs,
				const vectorIterator<T> &rhs)
{return &(*lhs) <= &(*rhs);}

template <typename T, typename U>
bool operator!=(const vectorIterator<T> &lhs,
				const vectorIterator<U> &rhs)
{return &(*lhs) != &(*rhs);}

template <typename T>
bool operator!=(const vectorIterator<T> &lhs,
				const vectorIterator<T> &rhs)
{return &(*lhs) != &(*rhs);}


}