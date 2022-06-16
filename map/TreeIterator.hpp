#pragma once


#include "../iterator.hpp"
#include "tree.hpp"


namespace ft
{

template <bool Bool, typename Tr>
class TreeIterator : public ft::iterator<ft::bidirectional_iterator_tag, Tr>
{

protected:
	typedef typename Tree<Tr>::Nodeptr Nodeptr;
	Nodeptr nptr;
	Nodeptr base() const { return nptr; }

public:
	typedef typename ft::conditional<Bool,
									typename Tree<Tr>::value_type,
									const typename Tree<Tr>::value_type>::type v_type;
	typedef typename ft::iterator<ft::bidirectional_iterator_tag,
						v_type>::iterator_category iterator_category;
	typedef typename ft::iterator<ft::bidirectional_iterator_tag,
						v_type>::difference_type difference_type;
	typedef typename ft::iterator<ft::bidirectional_iterator_tag,
						v_type>::value_type value_type;
	typedef typename ft::iterator<ft::bidirectional_iterator_tag,
							value_type>::pointer pointer;
	typedef typename ft::iterator<ft::bidirectional_iterator_tag,
							value_type>::reference reference;

	explicit TreeIterator(Nodeptr ptr = 0) : nptr(ptr) {};

	TreeIterator& operator=(TreeIterator const &src) {
		nptr = src.nptr;
		return *this;
	}

	bool operator==(TreeIterator const &x) const { return (nptr == x.nptr); }
	bool operator!=(TreeIterator const &x) const { return (nptr != x.nptr); }

	TreeIterator& operator++() {
		nptr = Tree<Tr>::successor(nptr);
		return *this;
	}
	
	TreeIterator operator++(int) {
		TreeIterator retval = *this;
		++(*this);
		return retval;
	}

	TreeIterator& operator--() {
		nptr = Tree<Tr>::predecessor(nptr);
		return *this;
	}

	TreeIterator operator--(int) {
		TreeIterator retval = *this;
		--(*this);
		return retval;
	}


	operator TreeIterator<false, Tr>() const
	{ return (TreeIterator<false, Tr>(this->nptr)); }

	reference operator*() const { return Tree<Tr>::value(nptr); }
	pointer operator->() const { return &(**this); }
};

}