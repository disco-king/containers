#pragma once

#include "../iterator.hpp"
#include "tree.hpp"


template <typename T>
class TreeIterator : public iterator<bidirectional_iterator_tag, T>
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

	explicit TreeIterator(Node *ptr = 0) : n_ptr(ptr) {};

	TreeIterator& operator=(TreeIterator const &src) {
		n_ptr = src.n_ptr;
		return *this;
	}

	TreeIterator& operator++() {
		n_ptr = n_ptr->t_ptr->successor(n_ptr);
		return *this;
	}
	
	TreeIterator operator++(int) {
		TreeIterator retval = *this;
		++(*this);
		return retval;
	}

	TreeIterator& operator--() {
		n_ptr = n_ptr->t_ptr->predecessor(n_ptr);
		return *this;
	}

	TreeIterator operator--(int) {
		TreeIterator retval = *this;
		--(*this);
		return retval;
	}

	operator TreeIterator<const T> () const
	{ return (TreeIterator<const T>(this->n_ptr)); }

	reference operator*() const { return n_ptr->val; }
	pointer operator->() const { return &(this->operator*()); }
};

template <typename T, typename U>
bool operator==(const TreeIterator<T> &lhs,
				const TreeIterator<U> &rhs)
{return &(*lhs) == &(*rhs);}

template <typename T>
bool operator==(const TreeIterator<T> &lhs,
				const TreeIterator<T> &rhs)
{return &(*lhs) == &(*rhs);}

template <typename T, typename U>
bool operator!=(const TreeIterator<T> &lhs,
				const TreeIterator<U> &rhs)
{return &(*lhs) != &(*rhs);}

template <typename T>
bool operator!=(const TreeIterator<T> &lhs,
				const TreeIterator<T> &rhs)
{return &(*lhs) != &(*rhs);}
