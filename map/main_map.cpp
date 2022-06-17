#include <map>
#include <set>
#include "map.hpp"
#include "set.hpp"
#include <string>
#include <iostream>

#define ns ft
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

	// {
	// 	_map<int, int> m1;
	// 	_map<int, int> m2;

	// 	for (int i = 0; i < 5; i++)
	// 		m1[i] = i;
	// 	for (int i = 3; i < 7; i++)
	// 		m2[i] = i;

	// 	m1.insert(m2.begin(), m2.end());

	// 	_map<int, int>::iterator it;
	// 	for (int i = 0; i < 7; i++)
	// 	{
	// 		it = m1.find(i);
	// 		std::cout << "it.first: " << it->first
	// 		<< " it.second " << it->second << '\n';
	// 	}

	// }

	{
		_map<int, int> m;

		for(int i = 0; i < 10; i++)
			m[i] = i * 1000;

		try
		{
			for(int i = 0; i < 11; i++)
				std::cout << m.at(i) << '\n';
		}
		catch(std::exception const &e)
		{
			std::cout << e.what() << '\n';
		}
	}

	return 0;
}

