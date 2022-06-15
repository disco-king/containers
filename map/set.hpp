#pragma once

#include "tree.hpp"


namespace ft
{

template <typename K, typename Comp, typename Alloc>
class set_traits
{
public:
	typedef K key_type;
	typedef K value_type;
	typedef typename Alloc::template rebind<value_type>::other allocator_type;
	typedef Comp key_compare;
	typedef key_compare value_compare;

	struct Kfn{
		const key_type& operator() (const value_type& v) const
		{ return v; }
	};

	set_traits() : comp() {}
	set_traits(key_compare const & comp) : comp(comp) {}

	key_compare comp;
};

template <typename K,
			typename Comp = std::less<K>,
			typename Alloc = std::allocator<K> >
class set : public Tree<set_traits<K, Comp, Alloc> >
{

public:
	typedef set<K, Comp, Alloc> Type;
	typedef Tree<set_traits<K, Comp, Alloc> > Base;
	typedef K key_type;
	typedef Comp key_compare;
	typedef typename Base::value_compare value_compare;
	typedef typename Base::allocator_type allocator_type;
	typedef typename Base::size_type size_type;
	typedef typename Base::difference_type difference_type;
	typedef typename Base::pointer pointer;
	typedef typename Base::const_pointer const_pointer;
	typedef typename Base::reference reference;
	typedef typename Base::const_reference const_reference;
	typedef typename Base::const_iterator iterator;
	typedef typename Base::const_iterator const_iterator;
	typedef typename Base::const_reverse_iterator reverse_iterator;
	typedef typename Base::const_reverse_iterator const_reverse_iterator;
	typedef typename Base::value_type value_type;

	set() : Base(key_compare(), allocator_type()) {}
	
	explicit set(key_compare const &comp) : Base(comp, allocator_type()) {}
	
	set(key_compare const &comp, allocator_type const &alloc) : Base(comp, alloc) {}
	
	template <typename Iter>
	set(Iter first, Iter last) : Base(key_compare(), allocator_type())
	{
		for(; first != last; ++first)
			this->insert(*first);
	}

	template <typename Iter>
	set(Iter first, Iter last, key_compare const &comp) :
	Base(comp, allocator_type())
	{
		for(; first != last; ++first)
			this->insert(*first);
	}

	template <typename Iter>
	set(Iter first, Iter last, key_compare const &comp, allocator_type const &alloc) :
	Base(comp, alloc)
	{
		for(; first != last; ++first)
			this->insert(*first);
	}

	set( const set& other ) : Base(other)
	{};

};

// template <typename T>
// bool operator==(ft::set<T> const &lhs, ft::set<T> const &rhs)
// {
// 	if(lhs.size() != rhs.size())
// 		return false;
// 	return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
// }

// template <typename T>
// bool operator!=(ft::set<T> const &lhs, ft::set<T> const &rhs)
// {
// 	return !(lhs == rhs);
// }

// template <typename T>
// bool operator>(ft::set<T> const &lhs, ft::set<T> const &rhs)
// {
// 	return (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
// }

// template <typename T>
// bool operator<(ft::set<T> const &lhs, ft::set<T> const &rhs)
// {
// 	return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
// }

// template <typename T>
// bool operator>=(ft::set<T> const &lhs, ft::set<T> const &rhs)
// {
// 	return ( lhs > rhs || lhs == rhs);
// }

// template <typename T>
// bool operator<=(ft::set<T> const &lhs, ft::set<T> const &rhs)
// {
// 	return (lhs < rhs || lhs == rhs);
// }

}