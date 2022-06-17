#pragma once

#include "tree.hpp"


namespace ft
{

template <typename K, typename T, typename Comp, typename Alloc>
class map_traits
{

public:
	typedef K key_type;
	typedef pair<K, T> value_type;
	typedef typename Alloc::template rebind<value_type>::other allocator_type;
	typedef Comp key_compare;

	struct Kfn{
		const key_type& operator() (const value_type& v) const
		{ return v.first; }
	};

	class value_compare
	{
			friend class map_traits<K, T, Comp, Alloc>;
		public:
			bool operator() (value_type const &x, value_type const &y) const
			{ return comp(x.first, y.first); }
			value_compare(key_compare const &comp) : comp(comp) {};
		protected:
			key_compare comp;
	};

	map_traits() : comp() {}
	map_traits(key_compare const & comp) : comp(comp) {}

	key_compare comp;
};

template <typename K,
			typename T,
			typename Comp = std::less<K>,
			typename Alloc = std::allocator<pair<const K, T> > >
class map : public Tree<map_traits<K, T, Comp, Alloc> >
{

protected:
	typedef typename Tree<map_traits<K, T, Comp, Alloc> >::Pairnb Pairnb;

public:
	typedef map<K, T, Comp, Alloc> Type;
	typedef Tree<map_traits<K, T, Comp, Alloc> > Base;
	typedef K key_type;
	typedef T mapped_type;
	typedef K referent_type;
	typedef Comp key_compare;
	typedef typename Base::value_compare value_compare;
	typedef typename Base::allocator_type allocator_type;
	typedef typename Base::size_type size_type;
	typedef typename Base::difference_type difference_type;
	typedef typename Base::pointer pointer;
	typedef typename Base::const_pointer const_pointer;
	typedef typename Base::reference reference;
	typedef typename Base::const_reference const_reference;
	typedef typename Base::iterator iterator;
	typedef typename Base::const_iterator const_iterator;
	typedef typename Base::reverse_iterator reverse_iterator;
	typedef typename Base::const_reverse_iterator const_reverse_iterator;
	typedef typename Base::value_type value_type;

	map() : Base(key_compare(), allocator_type()) {}
	
	explicit map(key_compare const &comp) : Base(comp, allocator_type()) {}
	
	map(key_compare const &comp, allocator_type const &alloc) : Base(comp, alloc) {}
	
	template <typename Iter>
	map(Iter first, Iter last) : Base(key_compare(), allocator_type())
	{
		for(; first != last; ++first)
			this->insert(*first);
	}

	template <typename Iter>
	map(Iter first, Iter last, key_compare const &comp) :
	Base(comp, allocator_type())
	{
		for(; first != last; ++first)
			this->insert(*first);
	}

	template <typename Iter>
	map(Iter first, Iter last, key_compare const &comp, allocator_type const &alloc) :
	Base(comp, alloc)
	{
		for(; first != last; ++first)
			this->insert(*first);
	}

	map( const map& other ) : Base(other)
	{};

	mapped_type &at(key_type const &k)
	{
		Pairnb p = this->findValue(k);
		if(!p.second)
			throw std::out_of_range("out of range");
		return p.first->value.second;
	}

	mapped_type const &at(key_type const &k) const
	{
		Pairnb p = this->findValue(k);
		if(!p.second)
			throw std::out_of_range("out of range");
		return p.first->value.second;
	}

	mapped_type &operator[] (key_type const &k)
	{
		iterator p = this->insert(value_type(k, mapped_type())).first;
		return p->second;
	}

};

}