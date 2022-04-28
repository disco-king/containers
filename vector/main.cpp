#include "vector.hpp"
#include <vector>
#include <iostream>

#define VEC_TYPE ft::vector

struct Thing{
public:
	int i;
	std::string p;
	Thing():i(6), p("foo"){};
};

int main()
{
	VEC_TYPE<int> v1;

	for (size_t i = 0; i < 5; i++)
	{
		v1.push_back(i);
		std::cout << i << " size " << v1.size()
		<< " capacity " << v1.capacity()
		<< " first " << v1.front() << '\n';
	}


	for (size_t i = 0; i < v1.size(); i++)
		std::cout << v1[i] << ' ';
	std::cout << '\n';
	VEC_TYPE<int>::iterator i = v1.begin() + 2;
	(*i)++;
	std::cout << *i << '\n';
	for (size_t i = 0; i < v1.size(); i++)
		std::cout << v1[i] << ' ';
	std::cout << '\n';
}



// int main()
// {
// 	VEC_TYPE<int> v1;

// 	for (size_t i = 0; i < 3; i++)
// 	{
// 		v1.push_back(i);
// 	}

// 	std::cout << "size " << v1.size() << ' '
// 	<< " capacity " << v1.capacity() << '\n';
// 	for (VEC_TYPE<int>::const_iterator i = v1.begin(); i != v1.end(); i++)
// 		std::cout << *i << ' ';
// 	std::cout << '\n';
// }

// int main()
// {
// 	VEC_TYPE<std::string> v1;
// 	v1.push_back("s1");
// 	v1.push_back("s2");
// 	v1.push_back("s3");
// 	VEC_TYPE<std::string> v2;
// 	v2.push_back("s4");
// 	v2.push_back("s5");

// 	VEC_TYPE<std::string>::iterator i1 = v1.begin();
// 	VEC_TYPE<std::string>::iterator i2 = v2.begin();

// 	for (VEC_TYPE<std::string>::iterator i = i1; i < v1.end(); i++)
// 		std::cout << *i << ' ';
// 	std::cout << '\n';
// 	for (VEC_TYPE<std::string>::iterator i = i2; i < v2.end(); i++)
// 		std::cout << *i << ' ';
// 	std::cout << '\n';
	
// 	v1.swap(v2);

// 	for (VEC_TYPE<std::string>::iterator i = i1; i < v2.end(); i++)
// 		std::cout << *i << ' ';
// 	std::cout << '\n';
// 	for (VEC_TYPE<std::string>::iterator i = i2; i < v1.end(); i++)
// 		std::cout << *i << ' ';
// 	std::cout << '\n';
	
// }

// int main()
// {
// 	VEC_TYPE<int> v1;
// 	VEC_TYPE<int> v2;

// 	for (size_t i = 0; i < 10; i++)
// 		v1.push_back(i+1);
// 	for (size_t i = -1; i > -6; i--)
// 		v2.push_back(i);

// 	std::cout << "size " << v1.size() << ' '
// 	<< " capacity " << v1.capacity() << '\n';
// 	for (VEC_TYPE<int>::const_iterator i = v1.begin(); i != v1.end(); i++)
// 		std::cout << *i << ' ';
// 	std::cout << '\n';

// 	VEC_TYPE<int>::iterator i = v1.begin() + 5;
// 	v1.insert(i, 10, 0);

// 	std::cout << "size " << v1.size() << ' '
// 	<< " capacity " << v1.capacity() << '\n';
// 	for (VEC_TYPE<int>::const_iterator i = v1.begin(); i != v1.end(); i++)
// 		std::cout << *i << ' ';
// 	std::cout << '\n';
// }