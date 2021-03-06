#include "vector.hpp"

template <typename T, typename Allocator>
ft::vector<T, Allocator>::vector(const typename vector<T,
							Allocator>::allocator_type& alloc) :
sz(0), cap(0), array(0), alloc(alloc){}

template <typename T, typename Allocator>
ft::vector<T, Allocator>::~vector()
{
	clear();
	alloc.deallocate(array, cap);
}

template <typename T, typename Allocator>
ft::vector<T, Allocator>::vector(size_type n, const value_type& val,
							const allocator_type& alloc) :
sz(0), cap(0), array(0), alloc(alloc)
{
	T *new_arr = create_array(limits(0, n, 0), n, &val);
	array = new_arr;
	sz = n;
	cap = n;
}

template <typename T, typename Allocator>
template <class InputIt>
ft::vector<T, Allocator>::vector (typename enable_if<!is_integral<InputIt>::value, InputIt>::type first,
									InputIt last,
									const allocator_type& alloc) :
sz(0), cap(0), array(0), alloc(alloc)
{
	assign(first, last);
}

template <typename T, typename Allocator>
ft::vector<T, Allocator>::vector (const vector& src) :
array(0), sz(0), cap(0)
{
	assign(src.begin(), src.end());
}

template <typename T, typename Allocator>
ft::vector<T, Allocator>& ft::vector<T, Allocator>::operator=
( const ft::vector<T, Allocator>& src )
{
	ft::vector<T, Allocator> copy(src);
	swap(copy);
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

	T *new_array = create_array(limits(sz, n, 0), new_cap, &val);

	array = new_array;
	sz = n;
	cap = new_cap;
}

template <typename T, typename Allocator>
void ft::vector<T, Allocator>::reserve (size_type n)
{
	if(n <= cap)
		return;

	T *new_array = create_array(limits(sz, 0, 0), n, reinterpret_cast<T *>(0));
	array = new_array;
	sz = cap;
	cap = n;
}

template <typename T, typename Allocator>
void ft::vector<T, Allocator>::push_back (const value_type& val)
{
	if (!array)
	{
		array = alloc.allocate(1);
		cap = 1;
	}
	else if(sz == cap)
		reserve(sz * 2);
	try { alloc.construct(array + sz, val); }
	catch(...) {}
	++sz;
}

template <typename T, typename Allocator>
void ft::vector<T, Allocator>::pop_back ()
{
	alloc.destroy(array + sz);
	--sz;
}

template <typename T, typename Allocator>
template <class InputIterator>
typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type
ft::vector<T, Allocator>::assign (InputIterator first, InputIterator last)
{
	size_t number = ft::distance(first, last);

	clear();
	T *buff_arr;
	size_t new_cap;
	if(number > cap)
		new_cap = (number > cap * 2) ? number : cap * 2;
	else
		new_cap = 0;

	try
	{
		buff_arr = create_array(limits(0, number, 0), new_cap, first);
	}
	catch(...)
	{
		sz = 0;
		throw;
	}

	sz = number;
	array = buff_arr;
	if(new_cap)
		cap = new_cap;
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
	ft::swap(array, other.array);
	ft::swap(sz, other.sz);
	ft::swap(cap, other.cap);
	ft::swap(alloc, other.alloc);
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
	ptrdiff_t dist = ft::distance(begin(), position);

	if(position + 1 == end())
		alloc.destroy(&(*position));
	else
	{
		T *end_p = &(*end());
		T *pos = &(*position);
		try
		{
			for (; pos + 1 != end_p; ++pos)
			{
				alloc.destroy(pos);
				alloc.construct(pos, *(pos + 1));
			}
			alloc.destroy(pos);
		}
		catch(...)
		{
			sz = ft::distance(begin(), iterator(pos++));
			for(; pos != end_p; ++pos)
				alloc.destroy(pos);
			throw;
		}
	}
	sz--;
	return begin() + dist;
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::iterator
ft::vector<T, Allocator>::erase (iterator first, iterator last)
{
	ptrdiff_t dist = ft::distance(begin(), first);
	ptrdiff_t jump = ft::distance(first, last);

	T *end_p = &(*end());
	T *pos = &(*first);
	try
	{
		for (; pos < end_p; ++pos)
		{
			alloc.destroy(pos);
			if(pos + jump < end_p)
				alloc.construct(pos, *(pos + jump));
		}
	}
	catch(...)
	{
		sz = ft::distance(begin(), iterator(pos++));
		for(; pos != end_p; ++pos)
			alloc.destroy(pos);
		throw;
	}
	sz -= jump;
	return begin() + dist;
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::iterator
ft::vector<T, Allocator>::insert( iterator pos, const T& value )
{
	ptrdiff_t diff = pos - begin();
	insert(pos, 1, value);
	return begin() + diff;
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
		try
		{
			for (; iter >= pos; --iter)
			{
				if(iter < arr_end)
					alloc.destroy(&(*iter));
				if(iter > pos + (count - 1))
					alloc.construct(&(*iter), *(iter - count));
				else
					alloc.construct(&(*iter), value);
			}
		}
		catch(...)
		{
			if(iter < arr_end)
				sz = ft::distance(begin(), iter++);
			for(; iter < arr_end + count; ++iter)
					alloc.destroy(&(*iter));
			throw;
		}
		sz += count;
		return;
	}

	size_t new_cap = (sz + count) > cap * 2 ? (sz + count) : cap * 2;
	size_t old_sz = sz;
	size_t pos_index = ft::distance(begin(), pos);
	T *new_arr = create_array(limits(pos_index, pos_index + count, count),
								new_cap, &value);
	array = new_arr;
	sz = old_sz + count;
	cap = new_cap;
}

template <typename T, typename Allocator>
template< class InputIt >
typename ft::enable_if<!ft::is_integral<InputIt>::value>::type
ft::vector<T, Allocator>::insert ( iterator pos, InputIt first, InputIt last )
{
	size_t count = ft::distance(first, last);
	if(!count)
		return;
	if (sz + count <= cap)
	{
		last--;
		iterator iter = end() + count - 1;
		iterator arr_end = end();
		try
		{
			for (; iter >= pos; --iter)
			{
				if(iter < arr_end)
					alloc.destroy(&(*iter));
				if(iter > pos + (count - 1))
					alloc.construct(&(*iter), *(iter - count));
				else
				{
					alloc.construct(&(*iter), *last);
					--last;
				}
			}
		}
		catch(...)
		{
			if(iter < arr_end)
				sz = ft::distance(begin(), iter++);
			for(; iter < arr_end + count; ++iter)
					alloc.destroy(&(*iter));
			throw;
		}
		sz += count;
		return;
	}

	size_t new_cap = (sz + count) > cap * 2 ? (sz + count) : cap * 2;
	size_t old_sz = sz;
	size_t pos_index = ft::distance(begin(), pos);
	T *new_arr = create_array(limits(pos_index, pos_index + count, count),
								new_cap, first);
	array = new_arr;
	sz = old_sz + count;
	cap = new_cap;
}

template <typename T, typename Allocator>
template <typename Iter>
typename ft::enable_if<!ft::is_pointer<Iter>::value>::type
ft::vector<T, Allocator>::construct_value(T* arr, size_t &i, size_t lim, Iter iter)
{
	for(; i < lim; i++)
		alloc.construct(arr + i, *iter++);
}

template <typename T, typename Allocator>
void ft::vector<T, Allocator>::construct_value(T* arr, size_t &i, size_t lim, T const *val)
{
	for(; i < lim; i++)
		alloc.construct(arr + i, *val);
}

template <typename T, typename Allocator>
template <typename Arg>
T *ft::vector<T, Allocator>::create_array(limits lims, size_t size, Arg val)
{
	T * new_arr;
	if (size)
		new_arr = alloc.allocate(size);
	else
		new_arr = array;
	
	size_t i;
	try
	{
		for (i = 0; i < lims.l1; i++)
			alloc.construct(new_arr + i, array[i]);
		construct_value(new_arr, i, lims.l2, val);
		for (; i < sz + lims.count; i++)
			alloc.construct(new_arr + i, array[i - lims.count]);
	}
	catch(...)
	{
		for (size_t j = 0; j < i; j++)
			alloc.destroy(new_arr + j);
		if(size)
			alloc.deallocate(new_arr, size);
		throw;
	}

	if(size && array)
	{
		clear();
		alloc.deallocate(array, cap);
	}
	return new_arr;
}