#include "iterator.hpp"

namespace ft{
template <typename T>
class random_access_iterator: public ft::iterator<ft::random_access_iterator_tag, T>
{

private:
	T *ptr;

public:
	typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category iterator_category;
	typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type difference_type;
	typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type value_type;
	typedef typename ft::iterator<ft::random_access_iterator_tag, T>::pointer pointer;
	typedef typename ft::iterator<ft::random_access_iterator_tag, T>::reference reference;

	explicit random_access_iterator(T *ptr = 0) : ptr(ptr) {}

	random_access_iterator& operator=(random_access_iterator const &src) {
		ptr = src.ptr;
		return *this;
	}

	random_access_iterator operator+(ptrdiff_t val) {
		random_access_iterator ret;
		ret.ptr = ptr + val;
		return ret;
	}

	ptrdiff_t operator-(random_access_iterator other) {
		ptrdiff_t ret;
		ret = ptr - other.ptr;
		return ret;
	}

	random_access_iterator operator-(ptrdiff_t val) {
		random_access_iterator ret;
		ret.ptr = ptr - val;
		return ret;
	}

	random_access_iterator operator+=(ptrdiff_t val) { ptr+=val; return *this;}
	random_access_iterator operator-=(ptrdiff_t val) { ptr-=val; return *this;}
	random_access_iterator& operator++() {ptr++; return *this;}
	random_access_iterator operator++(int) {random_access_iterator retval = *this; ++(*this); return retval;}
	random_access_iterator& operator--() {ptr--; return *this;}
	random_access_iterator operator--(int) {random_access_iterator retval = *this; --(*this); return retval;}

	operator random_access_iterator<const T> () const
	{ return (random_access_iterator<const T>(this->ptr)); }

	// bool operator!=(random_access_iterator other) const {return ptr != other.ptr;}
	// bool operator<(random_access_iterator const &other) const {return ptr < other.ptr;}
	// bool operator>(random_access_iterator const &other) const {return ptr > other.ptr;}
	// bool operator<=(random_access_iterator const &other) const {return ptr <= other.ptr;}
	// bool operator>=(random_access_iterator const &other) const {return ptr >= other.ptr;}

	reference operator*() const { return *ptr; }
	pointer operator->() const { return &(this->operator*()); }
};

template <typename T, typename U>
bool operator==(const ft::random_access_iterator<T> &lhs,
				const ft::random_access_iterator<U> &rhs)
{return &(*lhs) == &(*rhs);}

template <typename T>
bool operator==(const ft::random_access_iterator<T> &lhs,
				const ft::random_access_iterator<T> &rhs)
{return &(*lhs) == &(*rhs);}

template <typename T, typename U>
bool operator>(const ft::random_access_iterator<T> &lhs,
				const ft::random_access_iterator<U> &rhs)
{return &(*lhs) > &(*rhs);}

template <typename T>
bool operator>(const ft::random_access_iterator<T> &lhs,
				const ft::random_access_iterator<T> &rhs)
{return &(*lhs) > &(*rhs);}

template <typename T, typename U>
bool operator<(const ft::random_access_iterator<T> &lhs,
				const ft::random_access_iterator<U> &rhs)
{return &(*lhs) < &(*rhs);}

template <typename T>
bool operator<(const ft::random_access_iterator<T> &lhs,
				const ft::random_access_iterator<T> &rhs)
{return &(*lhs) < &(*rhs);}

template <typename T, typename U>
bool operator>=(const ft::random_access_iterator<T> &lhs,
				const ft::random_access_iterator<U> &rhs)
{return &(*lhs) >= &(*rhs);}

template <typename T>
bool operator>=(const ft::random_access_iterator<T> &lhs,
				const ft::random_access_iterator<T> &rhs)
{return &(*lhs) >= &(*rhs);}

template <typename T, typename U>
bool operator<=(const ft::random_access_iterator<T> &lhs,
				const ft::random_access_iterator<U> &rhs)
{return &(*lhs) <= &(*rhs);}

template <typename T>
bool operator<=(const ft::random_access_iterator<T> &lhs,
				const ft::random_access_iterator<T> &rhs)
{return &(*lhs) <= &(*rhs);}

template <typename T, typename U>
bool operator!=(const ft::random_access_iterator<T> &lhs,
				const ft::random_access_iterator<U> &rhs)
{return &(*lhs) != &(*rhs);}

template <typename T>
bool operator!=(const ft::random_access_iterator<T> &lhs,
				const ft::random_access_iterator<T> &rhs)
{return &(*lhs) != &(*rhs);}


}