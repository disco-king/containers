#include "vector.hpp"
#include <vector>
#include <iterator>
#include <algorithm>
#include <iostream>

#define TYPE ft::vector

int main()//checking resize
{
	TYPE<int> v;
	v.assign(9900, 1);
	v.resize(5000);
	std::cout << "size: " << v.size()
	<< " capacity: " << v.capacity() << '\n';

	v.reserve(5000);
	v.resize(7000);
	std::cout << "size: " << v.size()
	<< " capacity: " << v.capacity() << '\n';

	v.resize(15300);
	std::cout << "size: " << v.size()
	<< " capacity: " << v.capacity() << '\n';

	v.push_back(v[65]);
	std::cout << "size: " << v.size()
		<< " capacity: " << v.capacity() << '\n';
	return 0;
}


// int main() //checking reverse iterators
// {
// 	TYPE<int> v;
// 	v.push_back(1);
// 	v.push_back(2);
// 	v.push_back(3);

// 	TYPE<int>::iterator i = v.end();
// 	TYPE<int>::reverse_iterator rbegin = TYPE<int>::reverse_iterator(i);
// 	TYPE<int>::reverse_iterator rend = v.rend() - 1;
// 	std::cout << "rbegin " << *rbegin << '\n';
// 	std::cout << "rend " << *rend << '\n';
// 	std::cout << "addr1 " << &(*i) << '\n';
// 	std::cout << "addr2 " << &(*rbegin) << '\n';

// 	std::cout << "eq " << (rbegin == rend) << '\n'; 
// 	std::cout << "ne " << (rbegin != rend) << '\n'; 
// 	std::cout << "gt " << (rbegin > rend) << '\n'; 
// 	std::cout << "lt " << (rbegin < rend) << '\n'; 
// 	std::cout << "ge " << (rbegin >= rend) << '\n'; 
// 	std::cout << "le " << (rbegin <= rend) << '\n'; 

// 	rbegin += 2;
// 	rend -= 2;
// 	std::cout << "rbegin " << *rbegin << '\n';
// 	std::cout << "rend " << *rend << '\n';

// 	std::cout << "eq " << (rbegin == rend) << '\n'; 
// 	std::cout << "ne " << (rbegin != rend) << '\n'; 
// 	std::cout << "gt " << (rbegin > rend) << '\n'; 
// 	std::cout << "lt " << (rbegin < rend) << '\n'; 
// 	std::cout << "ge " << (rbegin >= rend) << '\n'; 
// 	std::cout << "le " << (rbegin <= rend) << '\n'; 

// }


// int main() //checking insert
// {
// 	TYPE<int> v1;
// 	TYPE<int> v2;

// 	// v1.push_back("s1");
// 	// v1.push_back("s2");
// 	// v1.push_back("s3");

// 	for (size_t i = 0; i < 5; i++)
// 		v1.push_back(i+1);
// 	for (size_t i = -1; i > -6; i--)
// 		v2.push_back(i);

// 	std::cout << "size " << v1.size() << ' '
// 	<< " capacity " << v1.capacity() << '\n';
// 	for (TYPE<int>::const_iterator i = v1.begin(); i != v1.end(); i++)
// 		std::cout << *i << ' ';
// 	std::cout << '\n';

// 	TYPE<int>::iterator i = v1.end();
// 	v1.insert(i, v2.begin(), v2.end());
// 	// v1.insert(i, 10, -1);
// 	// v1.insert(v1.begin() + 1, 0);

// 	std::cout << "size " << v1.size() << ' '
// 	<< " capacity " << v1.capacity() << '\n';
// 	for (TYPE<int>::const_iterator i = v1.begin(); i != v1.end(); i++)
// 		std::cout << *i << ' ';
// 	std::cout << '\n';
// }

// int main () //checking erase and iterators
// {
// 	TYPE<int> myvector;

// 	// set some values (from 1 to 10)
// 	for (int i=1; i<=10; i++) myvector.push_back(i);

// 	// erase the Xth *iement
// 	TYPE<int>::const_iterator iter = myvector.erase(myvector.begin() + 9);

// 	std::cout << "size " << myvector.size()
// 	<< " capacity " << myvector.capacity() << '\n';
// 	std::cout << "myvector contains:";
// 	for (unsigned i=0; i<myvector.size(); ++i)
// 		std::cout << ' ' << myvector[i];
// 	std::cout << '\n';

// 	TYPE<int>::iterator iter2 = myvector.end();
// 	if(iter == iter2)
// 		std::cout << "ret correct\n";
// 	else
// 		std::cout << "ret " << *iter << '\n';
	
// 	//erase the first (or last) 3 *iements:
// 	myvector.erase (myvector.end() - 3, myvector.end());

// 	std::cout << "size " << myvector.size()
// 	<< " capacity " << myvector.capacity() << '\n';
// 	std::cout << "myvector contains:";
// 	for (unsigned i=0; i<myvector.size(); ++i)
// 		std::cout << ' ' << myvector[i];
// 	std::cout << '\n';

// 	return 0;
// }


// int main() //checking push_back
// {
// 	TYPE<int> v1;

// 	for (size_t i = 0; i < 3; i++)
// 	{
// 		v1.push_back(i);
// 	}

// 	std::cout << "size " << v1.size() << ' '
// 	<< " capacity " << v1.capacity() << '\n';
// 	for (TYPE<int>::const_iterator i = v1.begin(); i != v1.end(); i++)
// 		std::cout << *i << ' ';
// 	std::cout << '\n';
// }

// int main() //checking swap
// {
// 	TYPE<std::string> v1;
// 	v1.push_back("s1");
// 	v1.push_back("s2");
// 	v1.push_back("s3");
// 	TYPE<std::string> v2;
// 	v2.push_back("s4");
// 	v2.push_back("s5");

// 	TYPE<std::string>::iterator i1 = v1.begin();
// 	TYPE<std::string>::iterator i2 = v2.begin();

// 	std::string const & ref1 = v1.back();
// 	std::string const & ref2 = v2.back();

// 	std::cout << "references: " << ref1 << " " << ref2 << '\n';
// 	for (TYPE<std::string>::iterator i = i1; i < v1.end(); i++)
// 		std::cout << *i << ' ';
// 	std::cout << '\n';
// 	for (TYPE<std::string>::iterator i = i2; i < v2.end(); i++)
// 		std::cout << *i << ' ';
// 	std::cout << '\n';
	
// 	v1.swap(v2);

// 	std::cout << "references: " << ref1 << " " << ref2 << '\n';
// 	for (TYPE<std::string>::iterator i = i1; i < v2.end(); i++)
// 		std::cout << *i << ' ';
// 	std::cout << '\n';
// 	for (TYPE<std::string>::iterator i = i2; i < v1.end(); i++)
// 		std::cout << *i << ' ';
// 	std::cout << '\n';
	
// }
