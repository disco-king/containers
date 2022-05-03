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

template <class T, class U>
struct is_same { const static bool value = false; };

template <class T>
struct is_same<T, T> { const static bool value = true; };

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

template <class T>
struct is_integral
{
	static const bool value = false;
};

template <>
struct is_integral<bool> { static const bool value = true;};

template <>
struct is_integral<char> { static const bool value = true;};

// template <>
// struct is_integral<char16_t> { static const bool value = true;};

// template <>
// struct is_integral<char32_t> { static const bool value = true;};

template <>
struct is_integral<wchar_t> { static const bool value = true;};

template <>
struct is_integral<short> { static const bool value = true;};

template <>
struct is_integral<int> { static const bool value = true;};

template <>
struct is_integral<long> { static const bool value = true;};

template <>
struct is_integral<long long> { static const bool value = true;};

}