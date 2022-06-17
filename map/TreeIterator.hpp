#pragma once


#include "../iterator.hpp"
#include "tree.hpp"


namespace ft
{

template <bool Bool, typename Tree>
class TreeIterator : public ft::iterator<ft::bidirectional_iterator_tag, typename Tree::value_type>
{

protected:
	typedef typename Tree::Nodeptr Nodeptr;
	Nodeptr nptr;

public:
	Nodeptr base() { return nptr; }
	typedef typename ft::conditional<Bool,
									typename Tree::value_type,
									const typename Tree::value_type>::type v_type;
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

	template <bool B, typename OtherTree>
	friend class TreeIterator;

	template <bool B, typename OtherTree>
	TreeIterator(TreeIterator<B, OtherTree> const &src) :
	nptr(reinterpret_cast<Nodeptr>(src.nptr)) {};

	TreeIterator& operator=(TreeIterator const &src) {
		nptr = src.nptr;
		return *this;
	}

	bool operator==(TreeIterator const &x) const { return (nptr == x.nptr); }
	bool operator!=(TreeIterator const &x) const { return (nptr != x.nptr); }

	TreeIterator& operator++() {
		nptr = Tree::successor(nptr);
		return *this;
	}
	
	TreeIterator operator++(int) {
		TreeIterator retval = *this;
		++(*this);
		return retval;
	}

	TreeIterator& operator--() {
		nptr = Tree::predecessor(nptr);
		return *this;
	}

	TreeIterator operator--(int) {
		TreeIterator retval = *this;
		--(*this);
		return retval;
	}

	operator TreeIterator<false, Tree>() const
	{ return (TreeIterator<false, Tree>(this->nptr)); }

	reference operator*() const { return Tree::value(nptr); }
	pointer operator->() const { return &(**this); }
};

}