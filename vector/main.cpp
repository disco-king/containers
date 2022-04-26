#include "vector.hpp"
#include <vector>
#include <iostream>

struct Thing{
public:
	int i;
	std::string p;
	Thing():i(6), p("foo"){};
};

int main()
{
	ft::vector<int> vec1(5, 1);
	ft::vector<int> vec2(3, 2);

	for(ft::vector<int>::iterator i = vec1.begin(); i < vec1.end(); i++)
		std::cout << *i << ' ';
	std::cout << '\n';
	std::cout << "size " << vec1.size()
	<< " capacity " << vec1.capacity() << '\n';

	vec1.assign(vec2.begin(), vec2.end());
	// vec1.assign(3, 2);

	for(ft::vector<int>::iterator i = vec1.begin(); i < vec1.end(); i++)
		std::cout << *i << ' ';
	std::cout << '\n';
	std::cout << "size " << vec1.size()
	<< " capacity " << vec1.capacity() << '\n';
}

// int main()
// {
// 	ft::vector<int> vec;

// 	std::cout << "size " << vec.size()
// 	<< " capacity " << vec.capacity() << '\n';
	
// 	for (int i = 0; i < 5; i++)
// 		vec.push_back(i);

// 	for(ft::vector<int>::iterator i = vec.begin(); i < vec.end(); i++)
// 		std::cout << *i << ' ';
// 	std::cout << '\n';
// 	std::cout << "size " << vec.size()
// 	<< " capacity " << vec.capacity() << '\n';
	
// 	vec.resize(15, 3);

// 	for(ft::vector<int>::iterator i = vec.begin(); i < vec.end(); i++)
// 		std::cout << *i << ' ';
// 	std::cout << '\n';
// 	std::cout << "size " << vec.size()
// 	<< " capacity " << vec.capacity() << '\n';

// 	vec.resize(5, 3);

// 	for(ft::vector<int>::iterator i = vec.begin(); i < vec.end(); i++)
// 		std::cout << *i << ' ';
// 	std::cout << '\n';
// 	std::cout << "size " << vec.size()
// 	<< " capacity " << vec.capacity() << '\n';
// }
