#pragma once

namespace ft{
template <typename T, typename Allocator> class vector;
}

#include "../utils.hpp"
#include <memory>
#include <iterator>
#include <cstdlib>

namespace ft
{

template <typename T, typename Allocator = std::allocator<T> >
class vector
{

public:
	typedef T value_type;
	typedef Allocator allocator_type;
	typedef typename allocator_type::reference reference;
	typedef typename allocator_type::const_reference const_reference;
	typedef typename allocator_type::pointer pointer;
	typedef typename allocator_type::const_pointer const_pointer;
	typedef ptrdiff_t difference_type;
	typedef size_t size_type;
	typedef ft::random_access_iterator<T> iterator;
	typedef ft::random_access_iterator<const T> const_iterator;
	typedef ft::reverse_iterator<iterator> reverse_iterator;
	typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

private:
	size_t sz;
	size_t cap;
	T * array;
	Allocator alloc;

	struct limits { 
		size_t l1;
		size_t l2;
		size_t count;
		limits(int l1, int l2, int count) : l1(l1), l2(l2), count(count) {}
	};

	template <typename Iter>
	typename ft::enable_if<!ft::is_pointer<Iter>::value>::type
	construct_value(T* arr, size_t &i, size_t lim, Iter iter);
	void construct_value(T* arr, size_t &i, size_t lim, T const *val);
	template <typename Arg>
	T *create_array(limits lims, size_t size, Arg val);

public:

	explicit vector (const allocator_type& alloc = allocator_type());
	explicit vector (size_type n, const value_type& val = value_type(),
						const allocator_type& alloc = allocator_type());
	~vector();
	vector (const vector& src);
	template <class InputIt>
	vector (typename enable_if<!is_integral<InputIt>::value, InputIt>::type first,
			InputIt last,
		const allocator_type& alloc = allocator_type());

	template <class InputIterator>
	typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type
	assign (InputIterator first, InputIterator last);
	void assign (size_type n, const value_type& val);
	void swap( vector& other );
	void reserve (size_type n);
	void resize (size_type n, value_type val = value_type());
	void clear();
	iterator erase (iterator position);
	iterator erase (iterator first, iterator last);
	iterator insert( iterator pos, const T& value );
	void insert( iterator pos, size_type count, const T& value );
	template< class InputIt >
	typename ft::enable_if<!ft::is_integral<InputIt>::value>::type
	insert( iterator pos, InputIt first, InputIt last );
	void push_back (const value_type& val);
	void pop_back();
	allocator_type get_allocator() const;

	size_type size() const { return sz; };
	size_type capacity() const { return cap; };
	size_type max_size() const { return alloc.max_size(); };
	bool empty() const { return (sz == 0); };
	

	reference at (size_type n){
		if(n >= sz)
			throw std::out_of_range("out of range");
		return array[n];
	};
	
	const_reference at (size_type n) const{
		if(n >= sz)
			throw std::out_of_range("out of range");
		return array[n];
	};

	vector& operator=( const vector& src );
	T* data() { return array; };
	const T* data() const { return array; };
	reference front() { return array[0]; };
	const_reference front() const { return array[0]; };
	reference back() { return array[sz - 1]; };
	const_reference back() const { return array[sz - 1]; };
	reference operator[] (size_type n) { return array[n]; };
	const_reference operator[] (size_type n) const { return array[n]; };

	iterator begin() {return iterator(array);};
	iterator end() {return iterator(array + sz);};
	const_iterator begin() const {return const_iterator(array);};
	const_iterator end() const {return const_iterator(array + sz);};
	reverse_iterator rbegin() {return reverse_iterator(end());};
	reverse_iterator rend() {return reverse_iterator(begin());};
	const_reverse_iterator rbegin() const {return const_reverse_iterator(end());};
	const_reverse_iterator rend() const {return const_reverse_iterator(begin());};
};

template <typename T>
bool operator==(ft::vector<T> const &lhs, ft::vector<T> const &rhs)
{
	if(lhs.size() != rhs.size())
		return false;
	return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
}

template <typename T>
bool operator>=(ft::vector<T> const &lhs, ft::vector<T> const &rhs)
{
	return
		(ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end())
		|| lhs == rhs);
}

template <typename T>
bool operator<=(ft::vector<T> const &lhs, ft::vector<T> const &rhs)
{
	return 
		(ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())
		|| lhs == rhs);
}

template <typename T>
bool operator>(ft::vector<T> const &lhs, ft::vector<T> const &rhs)
{
	return
		(ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
}

template <typename T>
bool operator<(ft::vector<T> const &lhs, ft::vector<T> const &rhs)
{
	return 
		(ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

template <typename T>
bool operator!=(ft::vector<T> const &lhs, ft::vector<T> const &rhs)
{
	return !(lhs == rhs);
}

}

#include "vector.tpp"