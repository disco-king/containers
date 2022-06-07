#pragma once

#include "iterator.hpp"

namespace ft
{

template <typename Iter>
class reverse_iterator
{

private:
	Iter iter;

public:
	typedef Iter iterator_type;
	typedef typename ft::iterator_traits<Iter>::iterator_category iterator_category;
	typedef typename ft::iterator_traits<Iter>::value_type value_type;
	typedef typename ft::iterator_traits<Iter>::difference_type difference_type;
	typedef typename ft::iterator_traits<Iter>::pointer pointer;
	typedef typename ft::iterator_traits<Iter>::reference reference;

	reverse_iterator() : iter() {};
	reverse_iterator(iterator_type src) : iter(src) {};
	template< class U >
	reverse_iterator( const reverse_iterator<U>& other ) : iter(other.base()){};
	iterator_type base() const { return iter; }

	typename enable_if<is_same<iterator_category,
					random_access_iterator_tag>::value,
					reverse_iterator&>::type
	operator=(reverse_iterator const &src) {
		iter = src.iter;
		return *this;
	}
	typename enable_if<is_same<iterator_category,
					random_access_iterator_tag>::value,
					reverse_iterator>::type
	operator+(ptrdiff_t val) {
		reverse_iterator ret;
		ret.iter = iter - val;
		return ret;
	}

	typename enable_if<is_same<iterator_category,
					random_access_iterator_tag>::value,
					ptrdiff_t>::type
	operator-(reverse_iterator other) {
		ptrdiff_t ret;
		ret = iter + other.iter;
		return ret;
	}

	typename enable_if<is_same<iterator_category,
					random_access_iterator_tag>::value,
					reverse_iterator>::type
	operator-(ptrdiff_t val) {
		reverse_iterator ret;
		ret.iter = iter + val;
		return ret;
	}

	typename enable_if<is_same<iterator_category,
					random_access_iterator_tag>::value,
					reverse_iterator>::type
	operator+=(ptrdiff_t val) { iter-=val; return *this;}

	typename enable_if<is_same<iterator_category,
					random_access_iterator_tag>::value,
					reverse_iterator>::type
	operator-=(ptrdiff_t val) { iter+=val; return *this;}
	
	reverse_iterator& operator++() {iter--; return *this;}
	reverse_iterator operator++(int) {reverse_iterator retval = *this; --(*this); return retval;}
	reverse_iterator& operator--() {iter++; return *this;}
	reverse_iterator operator--(int) {reverse_iterator retval = *this; ++(*this); return retval;}

	operator reverse_iterator<const Iter> () const
	{ return (reverse_iterator<const Iter>(this->ptr)); }

	reference operator*() const { return *(iter - 1); }
	pointer operator->() const { return &(this->operator*()); }

};

template <typename T, typename U>
typename enable_if<is_same<typename reverse_iterator<T>::iterator_category,
				random_access_iterator_tag>::value &&
				is_same<typename reverse_iterator<U>::iterator_category,
				random_access_iterator_tag>::value,
				bool>::type
operator==(const reverse_iterator<T> &lhs,
			const reverse_iterator<U> &rhs)
{ return &(*lhs) == &(*rhs); }

template <typename T>
typename enable_if<is_same<typename reverse_iterator<T>::iterator_category,
				random_access_iterator_tag>::value,
				bool>::type
operator==(const reverse_iterator<T> &lhs,
				const reverse_iterator<T> &rhs)
{ return &(*lhs) == &(*rhs); }

template <typename T, typename U>
typename enable_if<is_same<typename reverse_iterator<T>::iterator_category,
				random_access_iterator_tag>::value &&
				is_same<typename reverse_iterator<U>::iterator_category,
				random_access_iterator_tag>::value,
				bool>::type
operator>(const reverse_iterator<T> &lhs,
				const reverse_iterator<U> &rhs)
{ return &(*lhs) < &(*rhs); }

template <typename T>
typename enable_if<is_same<typename reverse_iterator<T>::iterator_category,
				random_access_iterator_tag>::value,
				bool>::type
operator>(const reverse_iterator<T> &lhs,
				const reverse_iterator<T> &rhs)
{ return &(*lhs) < &(*rhs); }

template <typename T, typename U>
typename enable_if<is_same<typename reverse_iterator<T>::iterator_category,
				random_access_iterator_tag>::value &&
				is_same<typename reverse_iterator<U>::iterator_category,
				random_access_iterator_tag>::value,
				bool>::type
operator<(const reverse_iterator<T> &lhs,
			const reverse_iterator<U> &rhs)
{return &(*lhs) > &(*rhs);}

template <typename T>
typename enable_if<is_same<typename reverse_iterator<T>::iterator_category,
				random_access_iterator_tag>::value,
				bool>::type
operator<(const reverse_iterator<T> &lhs,
				const reverse_iterator<T> &rhs)
{return &(*lhs) > &(*rhs);}

template <typename T, typename U>
typename enable_if<is_same<typename reverse_iterator<T>::iterator_category,
				random_access_iterator_tag>::value &&
				is_same<typename reverse_iterator<U>::iterator_category,
				random_access_iterator_tag>::value,
				bool>::type
operator>=(const reverse_iterator<T> &lhs,
			const reverse_iterator<U> &rhs)
{return &(*lhs) <= &(*rhs);}

template <typename T>
typename enable_if<is_same<typename reverse_iterator<T>::iterator_category,
				random_access_iterator_tag>::value,
				bool>::type
operator>=(const reverse_iterator<T> &lhs,
				const reverse_iterator<T> &rhs)
{return &(*lhs) <= &(*rhs);}

template <typename T, typename U>
typename enable_if<is_same<typename reverse_iterator<T>::iterator_category,
				random_access_iterator_tag>::value &&
				is_same<typename reverse_iterator<U>::iterator_category,
				random_access_iterator_tag>::value,
				bool>::type
operator<=(const reverse_iterator<T> &lhs,
				const reverse_iterator<U> &rhs)
{return &(*lhs) >= &(*rhs);}

template <typename T>
typename enable_if<is_same<typename reverse_iterator<T>::iterator_category,
				random_access_iterator_tag>::value,
				bool>::type
operator<=(const reverse_iterator<T> &lhs,
				const reverse_iterator<T> &rhs)
{return &(*lhs) >= &(*rhs);}

template <typename T, typename U>
typename enable_if<is_same<typename reverse_iterator<T>::iterator_category,
				random_access_iterator_tag>::value &&
				is_same<typename reverse_iterator<U>::iterator_category,
				random_access_iterator_tag>::value,
				bool>::type
operator!=(const reverse_iterator<T> &lhs,
				const reverse_iterator<U> &rhs)
{ return &(*lhs) != &(*rhs);}

template <typename T>
typename enable_if<is_same<typename reverse_iterator<T>::iterator_category,
				random_access_iterator_tag>::value,
				bool>::type
operator!=(const reverse_iterator<T> &lhs,
				const reverse_iterator<T> &rhs)
{ return &(*lhs) != &(*rhs);}

}