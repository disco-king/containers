#pragma once

#include "iterator.hpp"


namespace ft
{



template <typename T>
class treeIterator : public iterator<bidirectional_iterator_tag, T>
{

private:
	typedef typename Tree<T>::Node Node;
	Node *n_ptr;

public:
	typedef typename iterator<bidirectional_iterator_tag, T>::iterator_category iterator_category;
	typedef typename iterator<bidirectional_iterator_tag, T>::difference_type difference_type;
	typedef typename iterator<bidirectional_iterator_tag, T>::value_type value_type;
	typedef typename iterator<bidirectional_iterator_tag, T>::pointer pointer;
	typedef typename iterator<bidirectional_iterator_tag, T>::reference reference;

	explicit treeIterator(Node *ptr = 0) : n_ptr(ptr) {};

	treeIterator& operator=(treeIterator const &src) {
		n_ptr = src.n_ptr;
		return *this;
	}

	treeIterator& operator++() {
		n_ptr = n_ptr->t_ptr->successor(n_ptr);
		return *this;
	}
	
	treeIterator operator++(int) {
		treeIterator retval = *this;
		++(*this);
		return retval;
	}

	treeIterator& operator--() {
		n_ptr = n_ptr->t_ptr->predecessor(n_ptr);
		return *this;
	}

	treeIterator operator--(int) {
		treeIterator retval = *this;
		--(*this);
		return retval;
	}

	operator vectorIterator<const T> () const
	{ return (vectorIterator<const T>(this->n_ptr)); }

	reference operator*() const { return n_ptr->val; }
	pointer operator->() const { return &(this->operator*()); }
};

template <typename T, typename U>
bool operator==(const treeIterator<T> &lhs,
				const treeIterator<U> &rhs)
{return &(*lhs) == &(*rhs);}

template <typename T>
bool operator==(const treeIterator<T> &lhs,
				const treeIterator<T> &rhs)
{return &(*lhs) == &(*rhs);}

template <typename T, typename U>
bool operator!=(const treeIterator<T> &lhs,
				const treeIterator<U> &rhs)
{return &(*lhs) != &(*rhs);}

template <typename T>
bool operator!=(const treeIterator<T> &lhs,
				const treeIterator<T> &rhs)
{return &(*lhs) != &(*rhs);}

}