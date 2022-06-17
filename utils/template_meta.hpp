#pragma once

#include <cstddef>
// #include <uchar.h>

namespace ft
{

template< bool B, class T = void >
struct enable_if {};

template<class T>
struct enable_if<true, T>
{
	typedef T type;
};

template <bool B, typename T, typename F>
struct conditional {};

template <typename T, typename F>
struct conditional<true, T, F>
{
	typedef T type;
};

template <typename T, typename F>
struct conditional<false, T, F>
{
	typedef F type;
};

template <class T, class U>
struct is_same { const static bool value = false; };

template <class T>
struct is_same<T, T> { const static bool value = true; };

template <typename T>
struct is_pointer { static const bool value = false; };

template <typename T>
struct is_pointer<T*>{ static const bool value = true; };

template <typename T>
struct remove_cv 
{
	typedef T type;
};

template <typename T>
struct remove_cv<const T> { typedef T type; };

template <typename T>
struct remove_cv<volatile T> { typedef T type; };

template <typename T>
struct remove_cv<const volatile T> { typedef T type; };


template<class T, bool v>
struct integral_constant {
	static const bool value = v;
	typedef T value_type;
	typedef integral_constant type;
	operator value_type() const { return value; }
};

template <class T>
struct is_integral: public ft::integral_constant<T, false> {};

template <>
struct is_integral<bool> : public ft::integral_constant<bool, true> {};

template <>
struct is_integral<char> : public ft::integral_constant<bool, true> {};

template <>
struct is_integral<signed char> : public ft::integral_constant<bool, true> {};

template <>
struct is_integral<unsigned char> : public ft::integral_constant<bool, true> {};

template <>
struct is_integral<wchar_t> : public ft::integral_constant<bool, true> {};

template <> struct
is_integral<char16_t> : public ft::integral_constant<bool, true> {};

template <>
struct is_integral<char32_t> : public ft::integral_constant<bool, true> {};

template <>
struct is_integral<short> : public ft::integral_constant<bool, true> {};

template <>
struct is_integral<unsigned short> : public ft::integral_constant<bool, true> {};

template <>
struct is_integral<int> : public ft::integral_constant<bool, true> {};

template <>
struct is_integral<unsigned int> : public ft::integral_constant<bool, true> {};

template <>
struct is_integral<long> : public ft::integral_constant<bool, true> {};

template <>
struct is_integral<unsigned long> : public ft::integral_constant<bool, true> {};

template <>
struct is_integral<long long> : public ft::integral_constant<bool, true> {};

template <>
struct is_integral<unsigned long long>	: public ft::integral_constant<bool, true> {};

}