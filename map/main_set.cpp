#include <map>
#include <set>
#include "map.hpp"
#include "set.hpp"
#include <string>
#include <iostream>
#include "/Users/fmalphit/timer/Timer.hpp"

#define ns ft
#define _set ns::set
#define _map ns::map

template <typename T>
void print_vec(T const &vec)
{
	std::cout << "size " << vec.size() << ' '
	<< " capacity " << vec.capacity() << '\n';
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << ' ';
	std::cout << '\n';
}

int main(int argc, char const *argv[])
{

	{// default constructor and insert check
		_set<int, std::less<int>, std::allocator<int> > s;

		for (int i = 0; i < 5; i++)
			s.insert(i);

		_set<int, std::less<int>, std::allocator<int> >::reverse_iterator it = s.rend();
		while(it != s.rbegin())
		{
			it--;
			std::cout << *it << ' ';
		}
		std::cout << '\n';
	}

	{//copy constructor check
		// _set<int> src;

		// for (int i = 0; i < 7; i++)
		// 	src.insert(i);

		// _set<int> s(src);

		// _set<int>::iterator it = s.begin();
		// while(it != s.end())
		// {
		// 	std::cout << *it << ' ';
		// 	++it;
		// }
		// std::cout << '\n';
	}

	{// iterator range constructor check
		// _set<int> src;
		// Timer<float, MILLI> t;

		// for (int i = 0; i < 10; i++)
		// 	src.insert(i);

		// t.start();
		// // _set<int> s = _set<int>(src.rbegin(), src.rend());
		// _set<int> s;
		// s.insert(src.rbegin(), src.rend());
		// t.finish();

		// t.printTime();
		// if(s.size() < 20)
		// {
		// 	_set<int>::iterator it = s.begin();
		// 	while(it != s.end())
		// 	{
		// 		std::cout << *it << ' ';
		// 		++it;
		// 	}
		// }
		// std::cout << '\n';
		// std::cout << "set size " << s.size() << '\n';
	}

	{// swap check
		// _set<int> s1;
		// _set<int> s2;

		// for (int i = 1; i < 6; i++)
		// {
		// 	if(i % 2)
		// 		s1.insert(i);
		// 	else
		// 		s2.insert(i);
		// }

		// _set<int>::iterator it1 = s1.begin();
		// _set<int>::iterator it2 = s2.begin();

		// std::cout << "first " << *it1 << " size " << s1.size() << '\n';
		// std::cout << "second " << *it2 << " size " << s2.size() << '\n';
		
		// for (_set<int>::iterator i = it1; i != s1.end(); ++i)
		// 	std::cout << *i << ' ';
		// std::cout << '\n';
		// for (_set<int>::iterator i = it2; i != s2.end(); ++i)
		// 	std::cout << *i << ' ';
		// std::cout << '\n';

		// s1.swap(s2);

		// std::cout << "first " << *it1 << " size " << s2.size() << '\n';
		// std::cout << "second " << *it2 << " size " << s1.size() << '\n';

		// for (_set<int>::iterator i = it1; i != s2.end(); ++i)
		// 	std::cout << *i << ' ';
		// std::cout << '\n';
		// for (_set<int>::iterator i = it2; i != s1.end(); ++i)
		// 	std::cout << *i << ' ';
		// std::cout << '\n';
	}

	{// clear check
		// _set<int> s;
		
		// for (int i = 0; i < 10; i++)
		// 	s.insert(i);

		// std::cout << std::boolalpha;

		// std::cout << (s.begin() == s.end()) << ' ' << s.size() << '\n';
		// s.clear();
		// std::cout << (s.begin() == s.end()) << ' ' << s.size() << '\n';
	}

	{// assignment check
		// _set<int> src;

		// for (int i = 0; i < 10; i++)
		// 	src.insert(i);

		// _set<int> s;

		// s = src;

		// _set<int>::iterator it = s.begin();
		// while(it != s.end())
		// {
		// 	std::cout << *it << ' ';
		// 	++it;
		// }
		// std::cout << '\n';
	}

	{// reverse_iterator check
		// std::vector<int> v;
		// _set<int> st;

		// st.insert(5);
		// st.insert(3);
		// st.insert(7);

		// _set<int>::reverse_iterator rit = st.rbegin();
		// _set<int>::reverse_iterator rit2 = st.rend();
		// v.push_back(*rit);
		// rit++;
		// rit2--;
		// v.push_back(*rit);
		// v.push_back(*rit2);
		// rit++;
		// v.push_back(*rit == *rit2);
		// v.push_back(rit == rit2);
		// rit2--;
		// v.push_back(*rit);
		// v.push_back(*rit2);
		// v.push_back(*rit2 > *rit);
		// v.push_back(*rit2 < *rit);
		// v.push_back(*(--rit));
		// v.push_back(*(++rit2));
		// v.push_back(*(rit--));
		// v.push_back(*(rit2++));
		
		// print_vec(v);
	}

	{// comparison checks
		// _set<int> s1;
		// _set<int> s2;

		// for (int i = 1; i < 6; i++)
		// {
		// 	if(i % 2)
		// 		s1.insert(i);
		// 	else
		// 		s2.insert(i);
		// }

		// s1.swap(s2);

		// std::cout << std::boolalpha;

		// std::cout << "eq " << (s1 == s2) << '\n';
		// std::cout << "ne " << (s1 != s2) << '\n';
		// std::cout << "gt " << (s1 > s2) << '\n';
		// std::cout << "lt " << (s1 < s2) << '\n';
		// std::cout << "ge " << (s1 >= s2) << '\n';
		// std::cout << "le " << (s1 <= s2) << '\n';
	}

	{// it to const_it checks
		// _set<int> s;

		// for(int i = 0; i < 10; i++)
		// 	s.insert(i);

		// _set<int>::iterator i = s.begin();
		// _set<int>::const_iterator ci1(i);
		// _set<int>::const_iterator ci2;

		// ci2 = i;

		// while(ci1 != s.end())
		// {
		// 	std::cout << *ci1 << ' ';
		// 	++ci1;
		// }
		// std::cout << '\n';
	}

	return 0;
}

