#pragma once

namespace ft
{

template <typename T1, typename T2>
class pair
{
public:
	typedef T1 first_type;
	typedef T2 second_type;

	first_type first;
	second_type second;

	pair() : first(), second() {};
	
	pair( const T1& x, const T2& y ) : first(x), second(y)
	{}
	
	template< class U1, class U2 >
	pair( const pair<U1, U2>& p ) : first(p.first), second(p.second)
	{}

	pair& operator=( const pair& other )
	{
		first = other.first;
		second = other.second;
		return *this;
	}
};

template <typename T1, typename T2>
pair<T1, T2> make_pair(T1 first, T2 second)
{
	return pair<T1, T2>(first, second);
}

template <typename T1, typename T2>
bool operator== (pair<T1, T2> const & p1, pair<T1, T2> const & p2)
{
	return (p1.first == p2.first && p1.second == p2.second);
}

template <typename T1, typename T2>
bool operator!= (pair<T1, T2> const & p1, pair<T1, T2> const & p2)
{
	return !(p1 == p2);
}

template <typename T1, typename T2>
bool operator< (pair<T1, T2> const & p1, pair<T1, T2> const & p2)
{
	return (p1.first < p2.first
			|| (!(p2.first < p1.first) && p1.second < p2.second));
}

template <typename T1, typename T2>
bool operator> (pair<T1, T2> const & p1, pair<T1, T2> const & p2)
{
	return p2 < p1;
}

template <typename T1, typename T2>
bool operator>= (pair<T1, T2> const & p1, pair<T1, T2> const & p2)
{
	return !(p1 < p2);
}

template <typename T1, typename T2>
bool operator<= (pair<T1, T2> const & p1, pair<T1, T2> const & p2)
{
	return !(p2 < p1);
}



}