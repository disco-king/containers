#include "vector.hpp"
#include <vector>
#include <iterator>
#include <algorithm>
#include <iostream>
#include </Users/fmalphit/timer/Timer.hpp>

#define TYPE ft::vector

template <typename T>
void print_vec(T const &vec)
{
	std::cout << "size " << vec.size() << ' '
	<< " capacity " << vec.capacity() << '\n';
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << ' ';
	std::cout << '\n';
}

int main()//checking iterator to const conversion
{
	TYPE<int> v(5, 1);

	TYPE<int>::iterator i = v.begin();
	TYPE<int>::const_iterator ci = i;
	TYPE<int>::iterator e = v.end();

	// i = ci;
	ci = i;
	for(; ci < e; ci++)
		std::cout << *ci << ' ';
	std::cout << '\n';
	return 0;
}


// int main() //checking assign
// {
// 	{
// 		TYPE<int> v1(5, 1);
// 		TYPE<int> v2(3, 7);

// 		print_vec(v1);
// 		std::cout << std::endl;

// 		v1.assign(v2.begin(), v2.end());
// 		print_vec(v1);
// 		std::cout << std::endl;

// 		v1.assign(10, 9);
// 		print_vec(v1);
// 	}

// 	std::cout << std::endl;

// 	{
// 		TYPE<char> characters;

// 		characters.assign(5, 'a');
// 		print_vec(characters);

// 		const TYPE<char> extra(6, 'b');//problem with const
// 		characters.assign(extra.begin(), extra.end());
// 		print_vec(characters);
// 	}
// }

// int main()//checking value constructor
// {
// 	// TYPE<std::string> v(5, "string");
// 	TYPE<int> v(5, 1);

// 	print_vec(v);
// }

// int main()//checking compares
// {
// 	TYPE<int> v1(10, 3);
// 	TYPE<int> v2(3, 5);

// 	print_vec(v1);
// 	v1 = v2;
// 	print_vec(v2);
// }

// int main()//checking compares
// {
// 	TYPE<int> v1, v2;

// 	for (size_t i = 0; i < 5; i++)
// 	{
// 		v1.push_back(i+1);
// 		v2.push_back(i+1);
// 	}

// 	v1.push_back(15);

// 	std::cout << "eq " << std::boolalpha << (v1 == v2) << '\n';
// 	std::cout << "ne " << std::boolalpha << (v1 != v2) << '\n';
// 	std::cout << "gt " << std::boolalpha << (v1 > v2) << '\n';
// 	std::cout << "lt " << std::boolalpha << (v1 < v2) << '\n';
// 	std::cout << "ge " << std::boolalpha << (v1 >= v2) << '\n';
// 	std::cout << "le " << std::boolalpha << (v1 <= v2) << '\n';
	
// 	std::cout << "\nv1 ";
// 	print_vec(v1);
// 	std::cout << "v2 ";
// 	print_vec(v2);

// 	return 0;
// }

// int main()//checking resize
// {
// 	TYPE<int> v;
// 	v.assign(9900, 1);
// 	v.resize(5000);
// 	std::cout << "size: " << v.size()
// 	<< " capacity: " << v.capacity() << '\n';

// 	v.reserve(5000);
// 	v.resize(7000);
// 	std::cout << "size: " << v.size()
// 	<< " capacity: " << v.capacity() << '\n';

// 	v.resize(15300);
// 	std::cout << "size: " << v.size()
// 	<< " capacity: " << v.capacity() << '\n';

// 	v.push_back(v[65]);
// 	std::cout << "size: " << v.size()
// 		<< " capacity: " << v.capacity() << '\n';
// 	return 0;
// }


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
// 	TYPE<std::string> v1;
// 	TYPE<std::string> v2;

// 	v1.push_back("s1");
// 	v1.push_back("s2");
// 	v1.push_back("s3");

// 	v2.push_back("s4");
// 	v2.push_back("s5");
// 	v2.push_back("s6");

// 	// for (int i = 0; i < 5; i++)
// 	// 	v1.push_back(i+1);
// 	// for (int i = -1; i > -6; i--)
// 	// 	v2.push_back(i);

// 	std::cout << "size " << v1.size() << ' '
// 	<< " capacity " << v1.capacity() << '\n';
// 	for (TYPE<std::string>::const_iterator i = v1.begin(); i != v1.end(); i++)
// 		std::cout << *i << ' ';
// 	std::cout << '\n';

// 	TYPE<std::string>::iterator i = v1.end();
// 	v1.insert(i, v2.end(), v2.begin());
// 	// v1.insert(i, 10, -1);
// 	// v1.insert(v1.begin() + 2, 0);

// 	std::cout << "size " << v1.size() << ' '
// 	<< " capacity " << v1.capacity() << '\n';
// 	for (TYPE<std::string>::const_iterator i = v1.begin(); i != v1.end(); i++)
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
// 	TYPE<std::string> v1;
// 	std::string s = "foo bar";
// 	for (size_t i = 0; i < 5; i++)
// 	{
// 		v1.push_back(s);
// 		std::cout << "size " << v1.size()
// 		<< " capacity " << v1.capacity() << '\n';
// 	}

// 	print_vec(v1);
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
// 	std::cout << "iterators: " << *i1 << " " << *i2 << '\n';
// 	for (TYPE<std::string>::iterator i = i1; i < v1.end(); i++)
// 		std::cout << *i << ' ';
// 	std::cout << '\n';
// 	for (TYPE<std::string>::iterator i = i2; i < v2.end(); i++)
// 		std::cout << *i << ' ';
// 	std::cout << '\n';
	
// 	v1.swap(v2);

// 	std::cout << "references: " << ref1 << " " << ref2 << '\n';
// 	std::cout << "iterators: " << *i1 << " " << *i2 << '\n';
// 	for (TYPE<std::string>::iterator i = i1; i < v2.end(); i++)
// 		std::cout << *i << ' ';
// 	std::cout << '\n';
// 	for (TYPE<std::string>::iterator i = i2; i < v1.end(); i++)
// 		std::cout << *i << ' ';
// 	std::cout << '\n';
	
// }

// #define _ratio 10000
// #define _vector TYPE

// int main(int argc, char const *argv[])//checking swap
// {
// 	Timer<> t;

//     std::vector<int> v;
//     TYPE<int> vector;
//     vector.assign(1100 * _ratio, 11);
//     _vector<int> tmp(500 * _ratio, 5), tmp2(1000 * _ratio, 10), tmp3(1500 * _ratio, 15), tmp4(3000 * _ratio, 30);

// 	t.start();

//     v.push_back(vector[2]);
//     v.push_back(vector.size());
//     v.push_back(vector.capacity());
//     vector.swap(tmp);
//     v.push_back(vector[2]);
//     v.push_back(vector.size());
//     v.push_back(vector.capacity());
//     vector.swap(tmp3);
//     v.push_back(vector[2]);
//     v.push_back(vector.size());
//     v.push_back(vector.capacity());
//     std::swap(vector, tmp2);
//     v.push_back(vector[2]);
//     v.push_back(vector.size());
//     v.push_back(vector.capacity());
//     std::swap(vector, tmp4);
//     v.push_back(vector[2]);
//     v.push_back(vector.size());
//     v.push_back(vector.capacity());

// 	t.finish();

// 	t.printTime(0);
// 	print_vec(v);
//     return 0;
// }

