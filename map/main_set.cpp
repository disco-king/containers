#include <map>
#include <vector>
#include <set>
#include "map.hpp"
#include "set.hpp"
#include <string>
#include <iostream>
// #include "/Users/fmalphit/timer/Timer.hpp"
// #include <Timer.hpp>

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

template <class T, class C>
void fillSet(_set<T, C> &mp) {
	mp.insert(16);
	mp.insert(8);
	mp.insert(23);
	mp.insert(7);
	mp.insert(19);
	mp.insert(29);
	mp.insert(41);
	mp.insert(4);
	mp.insert(11);
}

int main(int argc, char const *argv[])
{

	{// default constructor and insert check
		_set<int> s;

		for (int i = 0; i < 5; i++)
			s.insert(i);

		_set<int>::iterator it = s.begin();
		while(it != s.end())
		{
			std::cout << *it << ' ';
			++it;
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

		// _set<int>::const_iterator ci3 = s.begin();
		// _set<int>::const_iterator i2 = s.begin();
		// std::cout << std::boolalpha << (ci2 == i2) << '\n';

		// for(_set<int>::iterator ei = s.end(); ci2 != ei; ++ci2)
		// {
		// 	std::cout << *ci2 << ' ';
		// 	++ci2;
		// }
		// std::cout << '\n';
	}

	{
		// std::vector<int> v;

		// _set<int, std::greater<int>> st;
		// fillSet(st);
		// for (typename _set<int>::iterator it = st.begin(); it != st.end(); it++) { v.push_back(*it); } 
		// print_vec(v);
		// for (typename _set<int>::iterator it = --st.end(); it != st.begin(); it--) { v.push_back(*it); }
		// _set<int, std::greater<int> > st1;
		// fillSet(st1);
		// v.push_back(*(st1.begin()));
		// st1.erase(41);
		// v.push_back(*(st1.begin()));
		// st1.erase(29);
		// v.push_back(*(st1.begin()));
		// _set<int, std::greater<int> > st2;
		// st2.insert(3);
		// v.push_back(*(st2.begin()));
		// st2.erase(3);
		// if (st2.begin() == st2.end())
		// 	v.push_back(1);
		// _set<int, std::plus<int> > st3;
		// fillSet(st3);
		// for (typename _set<int>::iterator it = st3.begin(); it != st3.end(); it++) { v.push_back(*it); }
		// for (typename _set<int>::iterator it = --st3.end(); it != st3.begin(); it--) { v.push_back(*it); }
		// _set<int, std::minus<int> > st4;
		// fillSet(st4);
		// for (typename _set<int>::iterator it = st4.begin(); it != st4.end(); it++) { v.push_back(*it); }
		// for (typename _set<int>::iterator it = --st4.end(); it != st4.begin(); it--) { v.push_back(*it); }
		// _set<int, std::greater_equal<int> > st5;
		// fillSet(st5);
		// for (typename _set<int>::iterator it = st5.begin(); it != st5.end(); it++) { v.push_back(*it); }
		// for (typename _set<int>::iterator it = --st5.end(); it != st5.begin(); it--) { v.push_back(*it); }
		// _set<int, std::multiplies<int> > st6;
		// fillSet(st6);
		// for (typename _set<int>::iterator it = st6.begin(); it != st6.end(); it++) { v.push_back(*it); }
		// for (typename _set<int>::iterator it = --st6.end(); it != st6.begin(); it--) { v.push_back(*it); }
		// _set<int, std::bit_xor<int> > st7;
		// fillSet(st7);
		// for (typename _set<int>::iterator it = st7.begin(); it != st7.end(); it++) { v.push_back(*it); }
		// for (typename _set<int>::iterator it = --st7.end(); it != st7.begin(); it--) { v.push_back(*it); }
		// std::set<int, std::logical_and<int> > st8;
		// fillSet(st8);
		// for (typename std::set<int>::iterator it = st8.begin(); it != st8.end(); it++) { v.push_back(*it); }
		// for (typename std::set<int>::iterator it = --st8.end(); it != st8.begin(); it--) { v.push_back(*it); }

		// v.push_back(st1.size());
		// print_vec(v);
	}

	return 0;
}

