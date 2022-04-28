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
	VEC_TYPE<int> vec2(5, 1);
	VEC_TYPE<int> vec1 = vec2;

	for(VEC_TYPE<int>::iterator i = vec1.begin(); i < vec1.end(); i++)
		std::cout << *i << ' ';
	std::cout << '\n';
	std::cout << "size " << vec1.size()
	<< " capacity " << vec1.capacity() << '\n';

	vec1.pop_back();
	vec2 = vec1;

	for(VEC_TYPE<int>::iterator i = vec2.begin(); i < vec2.end(); i++)
		std::cout << *i << ' ';
	std::cout << '\n';
	std::cout << "size " << vec2.size()
	<< " capacity " << vec2.capacity() << '\n';

}


// int main()
// {
// 	VEC_TYPE<int> vec1(5, 1);
// 	VEC_TYPE<int> vec2(3, 2);

// 	for(VEC_TYPE<int>::iterator i = vec1.begin(); i < vec1.end(); i++)
// 		std::cout << *i << ' ';
// 	std::cout << '\n';
// 	std::cout << "size " << vec1.size()
// 	<< " capacity " << vec1.capacity() << '\n';

// 	// vec1.assign(vec2.begin(), vec2.end());
// 	// vec1.assign(3, 2);
// 	vec1.assign(10, 2);

// 	for(VEC_TYPE<int>::iterator i = vec1.begin(); i < vec1.end(); i++)
// 		std::cout << *i << ' ';
// 	std::cout << '\n';
// 	std::cout << "size " << vec1.size()
// 	<< " capacity " << vec1.capacity() << '\n';
// }

// int main()
// {
// 	VEC_TYPE<int> vec;

// 	std::cout << "size " << vec.size()
// 	<< " capacity " << vec.capacity() << '\n';
	
// 	for (int i = 0; i < 5; i++)
// 		vec.push_back(i);

// 	for(VEC_TYPE<int>::iterator i = vec.begin(); i < vec.end(); i++)
// 		std::cout << *i << ' ';
// 	std::cout << '\n';
// 	std::cout << "size " << vec.size()
// 	<< " capacity " << vec.capacity() << '\n';
	
// 	vec.resize(15, 3);

// 	for(VEC_TYPE<int>::iterator i = vec.begin(); i < vec.end(); i++)
// 		std::cout << *i << ' ';
// 	std::cout << '\n';
// 	std::cout << "size " << vec.size()
// 	<< " capacity " << vec.capacity() << '\n';

// 	vec.resize(5, 3);

// 	for(VEC_TYPE<int>::iterator i = vec.begin(); i < vec.end(); i++)
// 		std::cout << *i << ' ';
// 	std::cout << '\n';
// 	std::cout << "size " << vec.size()
// 	<< " capacity " << vec.capacity() << '\n';
// }


// int main()
// {
// 	VEC_TYPE<std::string> v;

// 	v.push_back("str1");
// 	v.push_back("str2");
// 	v.push_back("str3");

// 	VEC_TYPE<std::string>::iterator begin = v.begin();
// 	VEC_TYPE<std::string>::iterator end = v.end();

// 	std::cout << ft::distance(begin, end) << std::endl;
// }