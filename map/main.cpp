#include <map>
#include <string>
#include <iostream>

int main(int argc, char const *argv[])
{
	// std::map<int, std::string> m;

	// std::pair<std::map<std::string, int>::iterator, bool> p;
	// p = m.insert(std::pair<std::string, int>("str1", 1));
	// std::cout << p.first->first << ' ' << p.first->second << '\n';

	// m.insert(std::pair<int, std::string>(1, "str1"));
	// std::map<int, std::string>::iterator i = m.find(1);
	// std::cout << i->first << ' ' << i->second << '\n';

	// std::cout << m[1] << '\n';



	std::map<int, float> m;

	float f = 500;

	m[1] = 501;
	m[1] = 502;
	// m.insert(std::pair<int, float>(1, f + 1));
	// m.insert(std::pair<int, float>(1, f + 2));

	std::cout << m[1] << " count " << m.count(1) << '\n';

	// for(int i = 1; i <= 20; i++)
	// 	m.insert(std::pair<int, float>(i, f + i));

	// for(int i = 1; i <= 20; i++)
	// 	std::cout << m[i] << ' ';
	// std::cout << '\n';



	// for(int i = 1; i <= 20; i++)
	// 	m[i] = f + i;

	// std::map<int, float>::reverse_iterator i = m.rbegin();
	// for(; i != m.rend(); i++)
	// 	std::cout << i->first << ' ' << i->second << '\n';
	return 0;
}

