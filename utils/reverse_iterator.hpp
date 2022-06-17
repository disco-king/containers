#pragma once

#include "iterator.hpp"

namespace ft
{

template <typename Iter>
class reverse_iterator
{

protected:
	Iter iter;

public:
	typedef Iter iterator_type;
	typedef typename iterator_traits<Iter>::iterator_category iterator_category;
	typedef typename iterator_traits<Iter>::value_type value_type;
	typedef typename iterator_traits<Iter>::difference_type difference_type;
	typedef typename iterator_traits<Iter>::pointer pointer;
	typedef typename iterator_traits<Iter>::reference reference;

	reverse_iterator() : iter() {};
	reverse_iterator(iterator_type src) : iter(src) {};
	template< class U >
	reverse_iterator( const reverse_iterator<U>& other ) : iter(other.base()){};
	iterator_type base() const { return iter; }

	reverse_iterator& operator=(reverse_iterator const &src) {
		iter = src.iter;
		return *this;
	}
	
	reverse_iterator& operator++() {iter--; return *this;}
	reverse_iterator operator++(int) {reverse_iterator retval = *this; --iter; return retval;}
	reverse_iterator& operator--() {iter++; return *this;}
	reverse_iterator operator--(int) {reverse_iterator retval = *this; ++iter; return retval;}

	operator reverse_iterator<const Iter> () const
	{ return (reverse_iterator<const Iter>(this->ptr)); }

	reference operator*() const { Iter ret = iter; return *(--ret); }
	pointer operator->() const { return &(this->operator*()); }

};

template <typename T, typename U>
bool operator==(const reverse_iterator<T> &lhs,
			const reverse_iterator<U> &rhs)
{ return &(*lhs) == &(*rhs); }

template <typename T>
bool operator==(const reverse_iterator<T> &lhs,
				const reverse_iterator<T> &rhs)
{ return &(*lhs) == &(*rhs); }

template <typename T, typename U>
bool operator!=(const reverse_iterator<T> &lhs,
				const reverse_iterator<U> &rhs)
{ return &(*lhs) != &(*rhs);}

template <typename T>
bool operator!=(const reverse_iterator<T> &lhs,
				const reverse_iterator<T> &rhs)
{ return &(*lhs) != &(*rhs);}

template <typename Iter>
class ra_reverse_iterator : public reverse_iterator<Iter>
{

public:
	ra_reverse_iterator() : reverse_iterator<Iter>() {};
	ra_reverse_iterator(Iter src) : reverse_iterator<Iter>(src) {};
	template< class U >
	ra_reverse_iterator( const ra_reverse_iterator<U>& other )
	{ this->iter = other.base(); };


	ra_reverse_iterator operator+(ptrdiff_t val) {
		ra_reverse_iterator ret;
		ret.iter = this->iter - val;
		return ret;
	}

	ptrdiff_t operator-(ra_reverse_iterator other) {
		ptrdiff_t ret;
		ret = this->iter + other.iter;
		return ret;
	}

	ra_reverse_iterator operator-(ptrdiff_t val) {
		ra_reverse_iterator ret;
		ret.iter = this->iter + val;
		return ret;
	}

	ra_reverse_iterator operator+=(ptrdiff_t val) { this->iter-=val; return *this;}
	ra_reverse_iterator operator-=(ptrdiff_t val) { this->iter+=val; return *this;}
};

template <typename T, typename U>
bool operator>(const ra_reverse_iterator<T> &lhs,
				const ra_reverse_iterator<U> &rhs)
{ return &(*lhs) < &(*rhs); }

template <typename T>
bool operator>(const ra_reverse_iterator<T> &lhs,
				const ra_reverse_iterator<T> &rhs)
{ return &(*lhs) < &(*rhs); }

template <typename T, typename U>
bool operator<(const ra_reverse_iterator<T> &lhs,
				const ra_reverse_iterator<U> &rhs)
{return &(*lhs) > &(*rhs);}

template <typename T>
bool operator<(const ra_reverse_iterator<T> &lhs,
				const ra_reverse_iterator<T> &rhs)
{return &(*lhs) > &(*rhs);}

template <typename T, typename U>
bool operator>=(const ra_reverse_iterator<T> &lhs,
				const ra_reverse_iterator<U> &rhs)
{return &(*lhs) <= &(*rhs);}

template <typename T>
bool operator>=(const ra_reverse_iterator<T> &lhs,
				const ra_reverse_iterator<T> &rhs)
{return &(*lhs) <= &(*rhs);}

template <typename T, typename U>
bool operator<=(const ra_reverse_iterator<T> &lhs,
				const ra_reverse_iterator<U> &rhs)
{return &(*lhs) >= &(*rhs);}

template <typename T>
bool operator<=(const ra_reverse_iterator<T> &lhs,
				const ra_reverse_iterator<T> &rhs)
{return &(*lhs) >= &(*rhs);}


}