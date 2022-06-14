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
		// std::map<int, float> m;

		// float f = 500;

		// m.insert(m.end(), std::make_pair(1, 501));
		// // m[1] = 501;
		// m[2] = 502;
		// m[3] = 503;

		// std::cout << m[1] << " count " << m.count(1) << '\n';

		// std::map<int, float>::iterator it = m.find(3);
		// it = m.insert(it, std::make_pair(4, 504));

		// std::cout << "res 1st " << it->first << " res 2nd " << it->second << '\n';

		// std::map<int, float>::iterator i = m.begin();
		// for(; i != m.end(); i++)
		// {
		// 	i->second -= 1;
		// 	std::cout << i->first << ' ' << i->second << '\n';
		// }
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

	{
		// std::set<int> s1;
		// std::set<int> s2;

		// for (int i = 1; i < 6; i++)
		// {
		// 	if(i % 2)
		// 		s1.insert(i);
		// 	else
		// 		s2.insert(i);
		// }

		// std::set<int>::iterator it1 = s1.begin();
		// std::set<int>::iterator it2 = s2.begin();

		// std::cout << "s1 size: " << s1.size() << " begin: " << *it1 << " contents: ";
		// for (std::set<int>::iterator i = s1.begin(); i != s1.end(); ++i)
		// 	std::cout << *i << ' ';
		// std::cout << '\n';
		// std::cout << "s2 size: " << s2.size() << " begin: " << *it2 << " contents: ";
		// for (std::set<int>::iterator i = s2.begin(); i != s2.end(); ++i)
		// 	std::cout << *i << ' ';
		// std::cout << '\n';

		// s1.swap(s2);

		// std::cout << "s1 size: " << s1.size() << " begin: " << *it1 << " contents: ";
		// for (std::set<int>::iterator i = s1.begin(); i != s1.end(); ++i)
		// 	std::cout << *i << ' ';
		// std::cout << '\n';
		// std::cout << "s2 size: " << s2.size() << " begin: " << *it2 << " contents: ";
		// for (std::set<int>::iterator i = s2.begin(); i != s2.end(); ++i)
		// 	std::cout << *i << ' ';
		// std::cout << '\n';
	}

	{
		std::set<int> s1;
		std::set<int> s2;

		for (int i = 1; i < 6; i++)
		{
			if(i % 2)
				s1.insert(i);
			else
				s2.insert(i);
		}

		std::set<int>::iterator it1 = s1.begin();
		std::set<int>::iterator it2 = s2.begin();

		std::cout << "first " << *it1 << " size " << s1.size() << '\n';
		std::cout << "second " << *it2 << " size " << s2.size() << '\n';
		
		for (std::set<int>::iterator i = it1; i != s1.end(); ++i)
			std::cout << *i << ' ';
		std::cout << '\n';
		for (std::set<int>::iterator i = it2; i != s2.end(); ++i)
			std::cout << *i << ' ';
		std::cout << '\n';

		s1.swap(s2);
		
		std::cout << "first " << *it1 << " size " << s2.size() << '\n';
		std::cout << "second " << *it2 << " size " << s1.size() << '\n';

		for (std::set<int>::iterator i = it1; i != s2.end(); ++i)
			std::cout << *i << ' ';
		std::cout << '\n';
		for (std::set<int>::iterator i = it2; i != s1.end(); ++i)
			std::cout << *i << ' ';
		std::cout << '\n';
	}


	return 0;
}

