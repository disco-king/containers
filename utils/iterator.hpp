#pragma once

#include "template_meta.hpp"
#include <cstddef>
#include <iterator>

namespace ft
{

template <class Category, class T, class Distance = ptrdiff_t,
	class Pointer = T*, class Reference = T&>
class iterator {

public:
	typedef T value_type;
	typedef Distance difference_type;
	typedef Pointer pointer;
	typedef Reference reference;
	typedef Category iterator_category;

};

class input_iterator_tag { };

class output_iterator_tag { };

class forward_iterator_tag : public input_iterator_tag { };

class bidirectional_iterator_tag : public forward_iterator_tag { };

class random_access_iterator_tag : public bidirectional_iterator_tag { };

template <typename IterType>
typename ft::enable_if<
ft::is_same<typename IterType::iterator_category,
			random_access_iterator_tag>::value,
			ptrdiff_t>::type
distance(IterType first, IterType last)
{
	return &(*last) - &(*first);
}

template <typename IterType>
typename ft::enable_if<
!ft::is_same<typename IterType::iterator_category,
			random_access_iterator_tag>::value,
			ptrdiff_t>::type
distance(IterType first, IterType last)
{
	ptrdiff_t ret = 0;
	while(first != last)
	{
		ret++;
		first++;
	}
	return ret;
}

template< class Iter >
struct iterator_traits
{
	typedef typename Iter::difference_type difference_type;
	typedef typename Iter::value_type value_type;
	typedef typename Iter::pointer pointer;
	typedef typename Iter::reference reference;
	typedef typename Iter::iterator_category iterator_category;
};

template< class T >
struct iterator_traits<T*>
{
	typedef ptrdiff_t difference_type;
	typedef T value_type;
	typedef T* pointer;
	typedef T& reference;
	typedef random_access_iterator_tag iterator_category;
};

template< class T >
struct iterator_traits<const T*>
{
	typedef ptrdiff_t difference_type;
	typedef const T value_type;
	typedef const T* pointer;
	typedef const T& reference;
	typedef random_access_iterator_tag iterator_category;
};

}
