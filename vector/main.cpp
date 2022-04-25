#include "vector.hpp"
#include <vector>
#include <iostream>

struct Thing{
public:
	int i;
	std::string p;
	Thing():i(6), p("foo"){};
};

int main(int argc, char const *argv[])
{
	ft::vector<int> v(6, 15);

	ft::vector<int>::iterator i = v.begin();
	ft::vector<int>::iterator e = v.end();

	return 0;
}

// int main()
// {
// 	vector<int> vec;

// 	// for(int i = 0; i < 10; i++)
// 	// {
// 	// 	vec.push_back(i);
// 	// 	std::cout << "added " << i
// 	// 	<< " size: " << vec.size()
// 	// 	<< " capacity " << vec.capacity()
// 	// 	<< '\n';
// 	// }

// 	std::cout << "size " << vec.size()
// 	<< " capacity " << vec.capacity() << '\n';
	
// 	for (int i = 0; i < 5; i++)
// 		vec.push_back(i);

// 	std::cout << "size " << vec.size()
// 	<< " capacity " << vec.capacity() << '\n';
	
// 	vec.resize(15);

// 	std::cout << "size " << vec.size()
// 	<< " capacity " << vec.capacity() << '\n';

// 	vec.push_back(8);
// 	vec.pop_back();

// 	std::cout << "size " << vec.size()
// 	<< " capacity " << vec.capacity() << '\n';
// }
