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

// template <typename T, typename Allocator>
// template <class InputIterator>
// ft::vector<T, Allocator>::vector (InputIterator first, InputIterator last, const allocator_type& alloc) :
// alloc(alloc)
// {
// 	array = alloc.allocate(last - first);
// 	for (; first < last; first++)

// }

// template <typename T, typename Allocator>
// ft::vector<T, Allocator>::vector (const vector& src)
// {
// 	/*there will be code*/
// }

template <typename T, typename Allocator>
void ft::vector<T, Allocator>::clear()
{
	for (size_t i = 0; i < sz; i++)
		alloc.destroy(array + i);
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
class ft::vector<T, Allocator>::iterator : public ft::iterator<
ft::random_access_iterator_tag, T, std::ptrdiff_t, T*, T&>
{

private:
	T *ptr;

public:
	explicit iterator(T *ptr = 0) : ptr(ptr) {}
	iterator& operator=(iterator const &src) {ptr = src.ptr; return *this;}
	iterator operator+(size_t val) {
		iterator ret;
		ret.ptr = ptr + val;
		return ret;
	}
	iterator operator-(size_t val) {
		iterator ret;
		ret.ptr = ptr - val;
		return ret;
	}
	iterator operator+=(size_t val) { ptr+=val; return *this;}
	iterator operator-=(size_t val) { ptr-=val; return *this;}
	iterator& operator++() {ptr++; return *this;}
	iterator operator++(int) {iterator retval = *this; ++(*this); return retval;}
	iterator& operator--() {ptr++; return *this;}
	iterator operator--(int) {iterator retval = *this; --(*this); return retval;}
	bool operator<(iterator const &other) const {return ptr < other.ptr;}
	bool operator>(iterator const &other) const {return ptr > other.ptr;}
	bool operator<=(iterator const &other) const {return ptr <= other.ptr;}
	bool operator>=(iterator const &other) const {return ptr >= other.ptr;}
	bool operator==(iterator other) const {return ptr == other.ptr;}
	bool operator!=(iterator other) const {return ptr != other.ptr;}
	reference operator*() const {return *ptr;}
};

// template <typename T, typename Allocator>
// class ft::vector<T, Allocator>::const_iterator : public ft::vector<T, Allocator>::iterator
// {

// public:
// 	operator iterator() {return *this; }
// 	const_reference operator*() const {return *ptr;}
// };