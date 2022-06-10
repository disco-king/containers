#pragma once

#include "tree.hpp"

namespace ft
{

template <typename Key,
			typename Value,
			typename Comp = std::less<Key>,
			typename Alloc = std::allocator<ft::pair<Key, Value>>>
class PairTree : public Tree<ft::pair<Key, Value>, std::less<Key>, Alloc>
{
public:
	typedef ft::pair<Key, Value> pair;
	typedef Comp key_compare;
	typedef Alloc allocator_type;

protected:
	// virtual bool isLess(pair const & lhs, pair const & rhs)
	// { return Tree<pair, key_compare, Alloc>::comp_obj(lhs.first, rhs.first); }

public:
	PairTree() : Tree<pair, key_compare, allocator_type>() {};

};

}