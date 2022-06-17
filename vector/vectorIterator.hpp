#pragma once

#include "../utils/iterator.hpp"

namespace ft{

template <typename T>
class VectorIterator: public iterator<std::random_access_iterator_tag, T>
{

private:
	T *ptr;

public:
	typedef VectorIterator iterator_type;
	typedef typename iterator<std::random_access_iterator_tag, T>::iterator_category iterator_category;
	typedef typename iterator<std::random_access_iterator_tag, T>::difference_type difference_type;
	typedef typename iterator<std::random_access_iterator_tag, T>::value_type value_type;
	typedef typename iterator<std::random_access_iterator_tag, T>::pointer pointer;
	typedef typename iterator<std::random_access_iterator_tag, T>::reference reference;

	explicit VectorIterator(T *ptr = 0) : ptr(ptr) {}

	VectorIterator& operator=(VectorIterator const &src) {
		ptr = src.ptr;
		return *this;
	}

	VectorIterator operator+(ptrdiff_t val) const {
		VectorIterator ret;
		ret.ptr = ptr + val;
		return ret;
	}

	ptrdiff_t operator-(VectorIterator other) const {
		ptrdiff_t ret;
		ret = ptr - other.ptr;
		return ret;
	}

	VectorIterator operator-(ptrdiff_t val) const {
		VectorIterator ret;
		ret.ptr = ptr - val;
		return ret;
	}

	VectorIterator operator+=(ptrdiff_t val) { ptr+=val; return *this;}
	VectorIterator operator-=(ptrdiff_t val) { ptr-=val; return *this;}
	VectorIterator& operator++() {ptr++; return *this;}
	VectorIterator operator++(int) {VectorIterator retval = *this; ++(*this); return retval;}
	VectorIterator& operator--() {ptr--; return *this;}
	VectorIterator operator--(int) {VectorIterator retval = *this; --(*this); return retval;}

	operator VectorIterator<const T> () const
	{ return (VectorIterator<const T>(this->ptr)); }

	reference operator*() const { return *ptr; }
	pointer operator->() const { return &(this->operator*()); }
};

template <typename T, typename U>
bool operator==(const VectorIterator<T> &lhs,
				const VectorIterator<U> &rhs)
{return &(*lhs) == &(*rhs);}

template <typename T>
bool operator==(const VectorIterator<T> &lhs,
				const VectorIterator<T> &rhs)
{return &(*lhs) == &(*rhs);}

template <typename T, typename U>
bool operator>(const VectorIterator<T> &lhs,
				const VectorIterator<U> &rhs)
{return &(*lhs) > &(*rhs);}

template <typename T>
bool operator>(const VectorIterator<T> &lhs,
				const VectorIterator<T> &rhs)
{return &(*lhs) > &(*rhs);}

template <typename T, typename U>
bool operator<(const VectorIterator<T> &lhs,
				const VectorIterator<U> &rhs)
{return &(*lhs) < &(*rhs);}

template <typename T>
bool operator<(const VectorIterator<T> &lhs,
				const VectorIterator<T> &rhs)
{return &(*lhs) < &(*rhs);}

template <typename T, typename U>
bool operator>=(const VectorIterator<T> &lhs,
				const VectorIterator<U> &rhs)
{return &(*lhs) >= &(*rhs);}

template <typename T>
bool operator>=(const VectorIterator<T> &lhs,
				const VectorIterator<T> &rhs)
{return &(*lhs) >= &(*rhs);}

template <typename T, typename U>
bool operator<=(const VectorIterator<T> &lhs,
				const VectorIterator<U> &rhs)
{return &(*lhs) <= &(*rhs);}

template <typename T>
bool operator<=(const VectorIterator<T> &lhs,
				const VectorIterator<T> &rhs)
{return &(*lhs) <= &(*rhs);}

template <typename T, typename U>
bool operator!=(const VectorIterator<T> &lhs,
				const VectorIterator<U> &rhs)
{return &(*lhs) != &(*rhs);}

template <typename T>
bool operator!=(const VectorIterator<T> &lhs,
				const VectorIterator<T> &rhs)
{return &(*lhs) != &(*rhs);}


}