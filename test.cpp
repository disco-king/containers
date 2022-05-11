#include <iostream>
#include <vector>
#include "vector/vector.hpp"


int main(int argc, char const *argv[])
{
	std::vector<int> v1, v2;

	for (size_t i = 0; i < 5; i++)
	{
		v1.push_back(i);
		v2.push_back(i);
	}

	// v1.at(3) = 6;
	v1.pop_back();

	std::cout << "eq " << (v1 == const_cast<std::vector<int>const &>(v2)) << '\n';
	std::cout << "ne " << (v1 != v2) << '\n';
	std::cout << "lt " << (v1 < v2) << '\n';
	std::cout << "gt " << (v1 > v2) << '\n';
	std::cout << "le " << (v1 <= v2) << '\n';
	std::cout << "ge " << (v1 >= v2) << '\n';
	
	return 0;
}
