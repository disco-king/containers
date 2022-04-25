#pragma once

#include <cstddef>

namespace ft
{
template <class Category, class T, class Distance = ptrdiff_t,
	class Pointer = T*, class Reference = T&>
struct iterator {
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

}
