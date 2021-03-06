#pragma once


#include "../utils/iterator.hpp"
#include "tree.hpp"


namespace ft
{

template <bool Bool, typename TreeType>
class TreeIterator : public ft::iterator<std::bidirectional_iterator_tag, typename TreeType::value_type>
{

protected:
	template <typename Tr>
	friend class Tree;
	typedef typename TreeType::Nodeptr Nodeptr;
	Nodeptr nptr;
	Nodeptr base() { return nptr; }

public:
	typedef TreeIterator iterator_type;
	typedef typename ft::conditional<Bool,
									typename TreeType::value_type,
									const typename TreeType::value_type>::type v_type;
	typedef typename ft::iterator<std::bidirectional_iterator_tag,
						v_type>::iterator_category iterator_category;
	typedef typename ft::iterator<std::bidirectional_iterator_tag,
						v_type>::difference_type difference_type;
	typedef typename ft::iterator<std::bidirectional_iterator_tag,
						v_type>::value_type value_type;
	typedef typename ft::iterator<std::bidirectional_iterator_tag,
							value_type>::pointer pointer;
	typedef typename ft::iterator<std::bidirectional_iterator_tag,
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
		nptr = TreeType::successor(nptr);
		return *this;
	}
	
	TreeIterator operator++(int) {
		TreeIterator retval = *this;
		++(*this);
		return retval;
	}

	TreeIterator& operator--() {
		nptr = 	TreeType::predecessor(nptr);
		return *this;
	}

	TreeIterator operator--(int) {
		TreeIterator retval = *this;
		--(*this);
		return retval;
	}

	operator TreeIterator<false, TreeType>() const
	{ return (TreeIterator<false, TreeType>(this->nptr)); }

	reference operator*() const { return TreeType::value(nptr); }
	pointer operator->() const { return &(**this); }
};

}