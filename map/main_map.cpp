#include <map>
#include <set>
#include "map.hpp"
#include "set.hpp"
#include <string>
#include <iostream>

#define ns std
#define _set ns::set
#define _map ns::map

int main(int argc, char const *argv[])
{
	{
		// _map<int, std::string> m;

		// ns::pair<_map<int, std::string>::iterator, bool> p;
		// p = m.insert(ns::pair<int, std::string>(1, "str1"));
		// std::cout << p.first->first << ' ' << p.first->second << '\n';

		// // m.insert(ns::pair<int, std::string>(1, "str1"));
		// // _map<int, std::string>::iterator i = m.find(1);
		// // std::cout << i->first << ' ' << i->second << '\n';

		// std::cout << "string by key 1: " << m[1] << '\n';
	}

	{
		// _map<int, float> m;

		// float f = 500;

		// m.insert(m.end(), std::make_pair(1, 501));
		// // m[1] = 501;
		// m[2] = 502;
		// m[3] = 503;

		// std::cout << m[1] << " count " << m.count(1) << '\n';

		// _map<int, float>::iterator it = m.find(3);
		// it = m.insert(it, std::make_pair(4, 504));

		// std::cout << "res 1st " << it->first << " res 2nd " << it->second << '\n';

		// _map<int, float>::iterator i = m.begin();
		// for(; i != m.end(); i++)
		// {
		// 	i->second -= 1;
		// 	std::cout << i->first << ' ' << i->second << '\n';
		// }
	}

	{
		// _map<int, int> m1;
		// _map<int, int> m2;

		// for (int i = 0; i < 5; i++)
		// 	m1[i] = i;
		// for (int i = 3; i < 7; i++)
		// 	m2[i] = i;

		// m1.insert(m2.begin(), m2.end());

		// _map<int, int>::iterator it;
		// for (int i = 0; i < 7; i++)
		// {
		// 	it = m1.find(i);
		// 	std::cout << "it.first: " << it->first
		// 	<< " it.second " << it->second << '\n';
		// }

	}

	{
		// _set<int> s;

		// for (int i = 0; i < 5; i++)
		// 	s.insert(i);

		// _set<int>::iterator it = s.begin();
		// while(it != s.end())
		// {
		// 	std::cout << *it << ' ';
		// 	++it;
		// }
		// std::cout << '\n';
	}

	{
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

		// std::cout << "s1 size: " << s1.size() << " begin: " << *it1 << " contents: ";
		// for (_set<int>::iterator i = s1.begin(); i != s1.end(); ++i)
		// 	std::cout << *i << ' ';
		// std::cout << '\n';
		// std::cout << "s2 size: " << s2.size() << " begin: " << *it2 << " contents: ";
		// for (_set<int>::iterator i = s2.begin(); i != s2.end(); ++i)
		// 	std::cout << *i << ' ';
		// std::cout << '\n';

		// s1.swap(s2);

		// std::cout << "s1 size: " << s1.size() << " begin: " << *it1 << " contents: ";
		// for (_set<int>::iterator i = s1.begin(); i != s1.end(); ++i)
		// 	std::cout << *i << ' ';
		// std::cout << '\n';
		// std::cout << "s2 size: " << s2.size() << " begin: " << *it2 << " contents: ";
		// for (_set<int>::iterator i = s2.begin(); i != s2.end(); ++i)
		// 	std::cout << *i << ' ';
		// std::cout << '\n';
	}

	{
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

	{
		_set<int> src;

		for (int i = 0; i < 5; i++)
			src.insert(i);

		_set<int> s(src);

		_set<int>::iterator it = s.begin();
		while(it != s.end())
		{
			std::cout << *it << ' ';
			++it;
		}
		std::cout << '\n';
	}

	return 0;
}
