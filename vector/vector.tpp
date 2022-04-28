#include "vector.hpp"

template <typename T, typename Allocator>
ft::vector<T, Allocator>::vector(const typename vector<T,
							Allocator>::allocator_type& alloc) :
alloc(alloc), sz(0), cap(0), array(0){}

template <typename T, typename Allocator>
ft::vector<T, Allocator>::~vector()
{
	clear();
	alloc.deallocate(array, cap);
}

template <typename T, typename Allocator>
ft::vector<T, Allocator>::vector(size_type n, const value_type& val,
							const allocator_type& alloc) :
alloc(alloc)
{
	array = this->alloc.allocate(n);
	size_t i;
	try
	{
		for(i = 0; i < n; i++)
			this->alloc.construct(array + i, val);
	}
	catch(const std::exception& e)
	{
		for(size_t j = 0; j < i; j++)
			this->alloc.destroy(array + j);
		this->alloc.deallocate(array, n);
		sz = 0;
		throw;
	}
	sz = n;
	cap = n;
}

template <typename T, typename Allocator>
template <class InputvectorIterator>
ft::vector<T, Allocator>::vector (InputvectorIterator first,
									InputvectorIterator last,
									const allocator_type& alloc) :
array(0), sz(0), cap(0), alloc(alloc)
{
	assign(first, last);
}

template <typename T, typename Allocator>
ft::vector<T, Allocator>::vector (const vector& src) :
array(0), sz(0), cap(0)
{
	*this = src;
}

template <typename T, typename Allocator>
ft::vector<T, Allocator>& ft::vector<T, Allocator>::operator=
( const ft::vector<T, Allocator>& src )
{
	assign(src.begin(), src.end());
	return *this;
}


template <typename T, typename Allocator>
void ft::vector<T, Allocator>::clear()
{
	for (size_t i = 0; i < sz; i++)
		alloc.destroy(array + i);
	sz = 0;
}

template <typename T, typename Allocator>
void ft::vector<T, Allocator>::resize (size_type n, value_type val)
{
	size_t i;
	if(n <= cap)
	{
		for (i = n; i < sz; i++)
			alloc.destroy(array + i);
		try
		{
			for (i = sz; i < n; i++)
				alloc.construct(array + i, val);
		}
		catch(...)
		{
			for(size_t j = sz; j < i; j++)
				alloc.destroy(array + j);
			throw;
		}
		sz = n;
		return;
	}

	T *new_array = alloc.allocate(n);
	try
	{
		for(i = 0; i < sz; i++)
			alloc.construct(new_array + i, array[i]);
		for(; i < n; i++)
			alloc.construct(new_array + i, val);
	}
	catch(const std::exception& e)
	{
		for(size_t j = 0; j < i; j++)
			alloc.destroy(new_array + j);
		alloc.deallocate(new_array, n);
		throw;
	}
	clear();
	alloc.deallocate(array, cap);
	array = new_array;
	sz = n;
	cap = n;
}

template <typename T, typename Allocator>
void ft::vector<T, Allocator>::reserve (size_type n)
{
	if(n <= cap)
		return;

	T *new_array = alloc.allocate(n);
	size_t i;
	try
	{
		for(i = 0; i < sz; i++)
			alloc.construct(new_array + i, array[i]);
	}
	catch(...)
	{
		for(size_t j = 0; j < i; j++)
			alloc.destroy(new_array + j);
		alloc.deallocate(new_array, n);
		throw;
	}
	clear();
	alloc.deallocate(array, cap);
	array = new_array;
	cap = n;
}

template <typename T, typename Allocator>
void ft::vector<T, Allocator>::push_back (const value_type& val)
{
	if (!array)
	{
		array = alloc.allocate(1);
		alloc.construct(array, val);
		sz = cap = 1;
		return;
	}
	if(sz == cap)
		reserve(sz * 2);
	alloc.construct(array + sz, val);
	sz++;
}

template <typename T, typename Allocator>
void ft::vector<T, Allocator>::pop_back ()
{
	alloc.destroy(array + sz);
	sz--;
}

template <typename T, typename Allocator>
template <class InputIterator>
typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type
ft::vector<T, Allocator>::assign (InputIterator first, InputIterator last)
{
	ptrdiff_t number = last - first;
	size_t i;

	clear();

	if(number > cap)
	{
		if(array != 0)
			alloc.deallocate(array, cap);
		cap = 0;
		array = alloc.allocate(number);
		cap = number;
	}

	try
	{
		for (i = 0; i < number; i++)
		{
			alloc.construct(array + i, *first);
			first++;
		}
		sz = i;
	}
	catch(...)
	{
		clear();
		sz = 0;
		throw;
	}
}

template <typename T, typename Allocator>
void ft::vector<T, Allocator>::assign (size_type n, const value_type& val)
{
	clear();
	resize(n, val);
}
