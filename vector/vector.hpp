#pragma once

#include <iostream>
#include <cstddef>

template <typename T, typename Allocator = std::allocator<T> >
class vector
{

private:
	T * array;
	size_t sz;
	size_t cap;
	Allocator alloc;

public:

	typedef T value_type;
	typedef Allocator allocator_type;
	typedef typename allocator_type::reference reference;
	typedef typename allocator_type::const_reference const_reference;
	typedef typename allocator_type::pointer pointer;
	typedef typename allocator_type::const_pointer const_pointer;
	typedef ptrdiff_t difference_type;
	typedef size_t size_type;

	explicit vector (const allocator_type& alloc = allocator_type());
	explicit vector (size_type n, const value_type& val = value_type(),
						const allocator_type& alloc = allocator_type());
	// vector (const vector& src);
/*	template <class InputIterator>
		vector (InputIterator first, InputIterator last,
			const allocator_type& alloc = allocator_type());*/

	void resize (size_type n, value_type val = value_type());
	size_type size() const { return sz; };
	size_type capacity() const { return cap; };
	size_type max_size() const { return alloc.max_size(); };
	bool empty() const { return sz ? 1 : 0; };
	

	reference at (size_type n){
		if(n < 0 || n >= size)
			throw std::out_of_range("out of range\n");
		return array[n];
	};
	
	const_reference at (size_type n) const{
		if(n < 0 || n >= size)
			throw std::out_of_range("out of range\n");
		return array[n];
	};
	reference front() { return array[0]; };
	const_reference front() const { return array[0]; };
	reference back() { return array[sz - 1]; };
	const_reference back() const { return array[sz - 1]; };
	reference operator[] (size_type n) { return array[n]; };
	const_reference operator[] (size_type n) const { return array[n]; };
};

#include "vector.tpp"