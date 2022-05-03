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

	size_t new_cap = n > cap * 2 ? n : cap * 2;
	T *new_array = alloc.allocate(new_cap);
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
	cap = new_cap;
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
	sz = i;
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

template <typename T, typename Allocator>
void ft::vector<T, Allocator>::swap( ft::vector<T, Allocator>& other )
{
	T *swap_array = array;
	array = other.array;
	other.array = swap_array;

	size_t swap_num = sz;
	sz = other.sz;
	other.sz = swap_num;

	swap_num = cap;
	cap = other.cap;
	other.cap = swap_num;
}

template <typename T, typename Allocator>
Allocator ft::vector<T, Allocator>::get_allocator() const
{
	return alloc;
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::iterator
ft::vector<T, Allocator>::erase (iterator position)
{
	ptrdiff_t dist = distance(begin(), position);

	if(position + 1 == end())
		alloc.destroy(&(*position));
	else
	{
		iterator fin = end();
		for (; position + 1 != fin; position++)
		{
			alloc.destroy(&(*position));
			alloc.construct(&(*position), *(position + 1));
		}
		alloc.destroy(&(*position));
	}
	sz--;
	return begin() + dist;
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::iterator
ft::vector<T, Allocator>::erase (iterator first, iterator last)
{
	ptrdiff_t dist = distance(begin(), first);
	ptrdiff_t jump = distance(first, last);

	iterator fin = end();
	for (; first < fin; first++)
	{
		alloc.destroy(&(*first));
		if(first + jump < fin)
			alloc.construct(&(*first), *(first + jump));
	}
	sz -= jump;
	return begin() + dist;
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::iterator
ft::vector<T, Allocator>::insert( iterator pos, const T& value )
{
	iterator ret;
	if (sz < cap)
	{
		ret = end();
		iterator arr_end = ret;
		for (; ret >= pos; ret--)
		{
			if(ret != arr_end)
				alloc.destroy(&(*ret));
			if(ret > pos)
				alloc.construct(&(*ret), *(ret - 1));
			else
				alloc.construct(&(*ret), value);
			if (ret == arr_end)
				sz++;
		}
	}
	else
	{
		T *new_arr = alloc.allocate(cap * 2);
		size_t pos_index = ft::distance(begin(), pos);
		size_t i;
		try
		{
			for (i = 0; i < pos_index; i++)
				alloc.construct(new_arr + i, array[i]);
			alloc.construct(new_arr + i, value);
			for (i += 1; i <= sz; i++)
				alloc.construct(new_arr + i, array[i - 1]);
		}
		catch(...)
		{
			for (size_t j = 0; j < i; j++)
				alloc.destroy(new_arr + j);
			alloc.deallocate(new_arr, cap * 2);
			throw;
		}
		for (size_t j = 0; j < sz; j++)
			alloc.destroy(new_arr + j);
		alloc.deallocate(array, cap);
		array = new_arr;
		cap = sz * 2;
		sz += 1;
		ret = begin() + pos_index;
	}
	return ret;
}

template <typename T, typename Allocator>
void ft::vector<T, Allocator>::insert( iterator pos, size_type count, const T& value )
{
	if(!count)
		return;
	if (sz + count <= cap)
	{
		iterator iter = end() + count - 1;
		iterator arr_end = end();
		for (; iter >= pos; iter--)
		{
			if(iter < arr_end)
				alloc.destroy(&(*iter));
			if(iter > pos + (count - 1))
				alloc.construct(&(*iter), *(iter - count));
			else
				alloc.construct(&(*iter), value);
			if(iter >= arr_end)
				sz++;
		}
	}
	else
	{
		T *new_arr = alloc.allocate(sz + count);
		size_t pos_index = ft::distance(begin(), pos);
		size_t i;
		try
		{
			for (i = 0; i < pos_index; i++)
				alloc.construct(new_arr + i, array[i]);
			for(; i < pos_index + count; i++)
				alloc.construct(new_arr + i, value);
			for (; i < sz + count; i++)
				alloc.construct(new_arr + i, array[i - count]);
		}
		catch(...)
		{
			for (size_t j = 0; j < i; j++)
				alloc.destroy(new_arr + j);
			alloc.deallocate(new_arr, cap * 2);
			throw;
		}
		clear();
		alloc.deallocate(array, cap);
		array = new_arr;
		sz = i;
		cap = i;
	}
}

template <typename T, typename Allocator>
template< class InputIt >
typename ft::enable_if<!ft::is_integral<InputIt>::value>::type
ft::vector<T, Allocator>::insert ( iterator pos, InputIt first, InputIt last )
{
	size_t count = ft::distance(first, last);
	if(!count)
		return;
	last--;
	if (sz + count <= cap)
	{
		iterator iter = end() + count - 1;
		iterator arr_end = end();
		for (; iter >= pos; iter--)
		{
			if(iter < arr_end)
				alloc.destroy(&(*iter));
			if(iter > pos + (count - 1))
				alloc.construct(&(*iter), *(iter - count));
			else
			{
				alloc.construct(&(*iter), *last);
				last--;
			}
			if(iter >= arr_end)
				sz++;
		}
	}
	else
	{
		T *new_arr = alloc.allocate(sz + count);
		size_t pos_index = ft::distance(begin(), pos);
		size_t i;
		try
		{
			for (i = 0; i < pos_index; i++)
				alloc.construct(new_arr + i, array[i]);
			for(; i < pos_index + count; i++)
			{
				alloc.construct(new_arr + i, *first);
				first++;
			}
			for (; i < sz + count; i++)
				alloc.construct(new_arr + i, array[i - count]);
		}
		catch(...)
		{
			for (size_t j = 0; j < i; j++)
				alloc.destroy(new_arr + j);
			alloc.deallocate(new_arr, cap * 2);
			throw;
		}
		clear();
		alloc.deallocate(array, cap);
		array = new_arr;
		sz = i;
		cap = i;
	}
}