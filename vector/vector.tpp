#include "vector.hpp"

template <typename T, typename Allocator>
vector<T, Allocator>::vector(const typename vector<T,
							Allocator>::allocator_type& alloc) :
alloc(alloc), sz(0), cap(0){}

template <typename T, typename Allocator>
vector<T, Allocator>::vector(size_type n, const value_type& val,
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

// template <typename T, typename Allocator>
// template <class InputIterator>
// vector<T, Allocator>::vector (InputIterator first, InputIterator last, const allocator_type& alloc) :
// alloc(alloc)
// {}

// template <typename T, typename Allocator>
// vector<T, Allocator>::vector (const vector& src)
// {
// 	/*there will be code*/
// }

template <typename T, typename Allocator>
void vector<T, Allocator>::resize (size_type n, value_type val)
{//start here tomorrow
	new_array = this->alloc.allocate(n);
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