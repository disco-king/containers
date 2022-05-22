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
	
	pair( const T1& x, const T2& y )
	{
		first = x;
		second = y;
	};
	
	template< class U1, class U2 >
	pair( const pair<U1, U2>& p )
	{
		first = p.first;
		second = p.second;
	}

	pair& operator=( const pair& other )
	{
		first = other.first;
		second = other.second;
	}
};

}