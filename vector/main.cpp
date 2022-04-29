#include "vector.hpp"
#include <vector>
#include <algorithm>
#include <iostream>

#define VEC_TYPE ft::vector

// int main(int argc, char const *argv[])
// {
// 	VEC_TYPE<int> v;
// 	v.push_back(1);
// 	v.push_back(2);
// 	v.push_back(3);
// 	VEC_TYPE<int>::iterator i = v.begin() + 2;
// 	std::cout << ft::distance(v.begin(), i) << '\n';
// 	std::cout << *i << '\n';
// 	return 0;
// }


int main() //checking insert
{
	VEC_TYPE<int> v1;
	VEC_TYPE<int> v2;

	// v1.push_back("s1");
	// v1.push_back("s2");
	// v1.push_back("s3");

	for (size_t i = 0; i < 10; i++)
		v1.push_back(i+1);
	for (size_t i = -1; i > -6; i--)
		v2.push_back(i);

	std::cout << "size " << v1.size() << ' '
	<< " capacity " << v1.capacity() << '\n';
	for (VEC_TYPE<int>::const_iterator i = v1.begin(); i != v1.end(); i++)
		std::cout << *i << ' ';
	std::cout << '\n';

	VEC_TYPE<int>::iterator i = v1.begin();
	v1.insert(i, 3, 8);
	// v1.insert(v1.begin() + 1, 0);

	std::cout << "size " << v1.size() << ' '
	<< " capacity " << v1.capacity() << '\n';
	for (VEC_TYPE<int>::const_iterator i = v1.begin(); i != v1.end(); i++)
		std::cout << *i << ' ';
	std::cout << '\n';
	// for (size_t i = 0; i < v1.capacity(); i++)
	// 	std::cout << v1[i] << ' ';
	// std::cout << '\n';
}

// int main () //checking erase and iterators
// {
// 	VEC_TYPE<int> myvector;

// 	// set some values (from 1 to 10)
// 	for (int i=1; i<=10; i++) myvector.push_back(i);

// 	// erase the 6th element
// 	VEC_TYPE<int>::const_iterator iter = myvector.erase(myvector.begin() + 9);

// 	std::cout << "size " << myvector.size()
// 	<< " capacity " << myvector.capacity() << '\n';
// 	std::cout << "myvector contains:";
// 	for (unsigned i=0; i<myvector.size(); ++i)
// 		std::cout << ' ' << myvector[i];
// 	std::cout << '\n';

// 	VEC_TYPE<int>::iterator iter2 = myvector.end();
// 	if(iter == iter2)
// 		std::cout << "ret correct\n";
// 	else
// 		std::cout << "ret " << *iter << '\n';
	
// 	// erase the first 3 elements:
// 	// myvector.erase (myvector.end() - 3, myvector.end());

// 	// std::cout << "size " << myvector.size()
// 	// << " capacity " << myvector.capacity() << '\n';
// 	// std::cout << "myvector contains:";
// 	// for (unsigned i=0; i<myvector.size(); ++i)
// 	// 	std::cout << ' ' << myvector[i];
// 	// std::cout << '\n';

// 	return 0;
// }


// int main() //checking push_back
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

// int main() //checking swap
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
