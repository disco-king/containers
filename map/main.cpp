#include <map>
#include <set>
#include <string>
#include <iostream>

int main(int argc, char const *argv[])
{
	{
		// std::map<int, std::string> m;

		// std::pair<std::map<std::string, int>::iterator, bool> p;
		// p = m.insert(std::pair<std::string, int>("str1", 1));
		// std::cout << p.first->first << ' ' << p.first->second << '\n';

		// m.insert(std::pair<int, std::string>(1, "str1"));
		// std::map<int, std::string>::iterator i = m.find(1);
		// std::cout << i->first << ' ' << i->second << '\n';

		// std::cout << m[1] << '\n';
	}

	{
		std::map<int, float> m;

		float f = 500;

		m.insert(m.end(), std::make_pair(1, 501));
		// m[1] = 501;
		m[2] = 502;
		m[3] = 503;

		std::cout << m[1] << " count " << m.count(1) << '\n';

		std::map<int, float>::iterator it = m.find(3);
		it = m.insert(it, std::make_pair(4, 504));

		std::cout << "res 1st " << it->first << " res 2nd " << it->second << '\n';

		std::map<int, float>::reverse_iterator i = m.rbegin();
		for(; i != m.rend(); i++)
			std::cout << i->first << ' ' << i->second << '\n';
	}

	{
		// std::map<int, int> m1;
		// std::map<int, int> m2;

		// for (int i = 0; i < 5; i++)
		// 	m1[i] = i;
		// for (int i = 3; i < 7; i++)
		// 	m2[i] = i;

		// m1.insert(m2.begin(), m2.end());

		// std::map<int, int>::iterator it;
		// for (int i = 0; i < 7; i++)
		// {
		// 	it = m1.find(i);
		// 	std::cout << "it.first: " << it->first
		// 	<< " it.second " << it->second << '\n';
		// }

	}

	{
		// std::set<int> s;

		// for (int i = 0; i < 5; i++)
		// 	s.insert(i);

		// std::set<int>::iterator it = s.begin();
		// while(it != s.end())
		// {
		// 	std::cout << *it << ' ';
		// 	++it;
		// }
		// std::cout << '\n';
	}


	return 0;
}

