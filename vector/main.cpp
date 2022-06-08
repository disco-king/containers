#include "vector.hpp"
#include <vector>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <Timer.hpp>

#define _vector ft::vector
#define _ratio 1000

template <typename T>
void print_vec(T const &vec)
{
	std::cout << "size " << vec.size() << ' '
	<< " capacity " << vec.capacity() << '\n';
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << ' ';
	std::cout << '\n';
}

// int main()// checking access funcs
// {
// 	_vector<int> v;

// 	for (size_t i = 0; i < 10; i++)
// 		v.push_back(i);

// 	std::cout << "front " << v.front() << '\n';
// 	std::cout << "back " << v.back() << '\n';

// 	std::cout << "at 5 " << v.at(5) << '\n';

// 	try
// 	{
// 		std::cout << "at 10 " << v.at(10) << '\n';
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
	
// 	return 0;
// }


// int main() //checking pop_back
// {
// 	_vector<int> v(5, 1);

// 	std::cout << v.size() << '\n';
// 	while (v.size())
// 	{
// 		v.pop_back();
// 		std::cout << v.size() << '\n';
// 	}
	
// }

// int main()//checking iterators
// {
// 	_vector<int> v(1000, 1);
// 	ft::vector<int>::iterator b = v.begin();
// 	ft::vector<int>::iterator e = v.begin() + 1;

// 	std::cout << *b << '\n';
// 	std::cout << *(e - 1) << '\n';
// 	return 0;
// }


// int main()//checking constructors
// {
// 	Timer<> t;
// 	std::vector<int> v;
// 	// std::vector<int> vector(100, 5);
// 	// _vector<int> tmp0(vector);
// 	_vector<int> tmp(1000000, 4), tmp2(1000000, 5);
// 	tmp = tmp2;
// 	_vector<int> tmp3(tmp);
// 	t.start();
// 	_vector<int> tmp4(tmp.begin(), tmp.end());
// 	t.finish();
// 	v.push_back(tmp4.size());
// 	v.push_back(tmp4.capacity());
// 	v.push_back(tmp[2]);
// 	v.push_back(tmp3[2]);
// 	v.push_back(tmp4[2]);
// 	try { _vector<int> tmp5(-1, -1); }
// 	catch (std::exception &e) { v.push_back(1); }
// 	print_vec(v);
// 	t.printTime();
// 	return 0;
// }

// int main()//checking iterator to const conversion
// {
// 	_vector<int> v(5, 1);

// 	_vector<int>::iterator i = v.begin();
// 	_vector<int>::const_iterator ci = v.begin();
// 	_vector<int>::iterator e = v.end();

// 	// i = ci;
// 	ci = i;
// 	for(; ci < e; ci++)
// 		std::cout << *ci << ' ';
// 	std::cout << '\n';
// 	return 0;
// }


// int main() //checking assign
// {
// 	{
// 		_vector<int> v1(5, 1);
// 		_vector<int> v2(3, 7);

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
// 		_vector<char> characters;

// 		characters.assign(5, 'a');
// 		print_vec(characters);

// 		const _vector<char> extra(6, 'b');
// 		_vector<char>::const_iterator it = extra.begin();
// 		characters.assign(extra.begin(), extra.end());
// 		print_vec(characters);
// 	}
// }

// int main()//checking value constructor
// {
// 	// _vector<std::string> v(5, "string");
// 	_vector<int> v(5, 1);

// 	print_vec(v);
// }

// int main()//checking compares
// {
// 	_vector<int> v1(10, 3);
// 	_vector<int> v2(3, 5);

// 	print_vec(v1);
// 	v1 = v2;
// 	print_vec(v2);
// }

// int main()//checking compares
// {
// 	_vector<int> v1, v2;

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
// 	{
// 		_vector<int> v;
// 		v.assign(9900, 1);
// 		v.resize(5000);
// 		std::cout << "size: " << v.size()
// 		<< " capacity: " << v.capacity() << '\n';

// 		v.reserve(5000);
// 		v.resize(7000);
// 		std::cout << "size: " << v.size()
// 		<< " capacity: " << v.capacity() << '\n';

// 		v.resize(15300);
// 		std::cout << "size: " << v.size()
// 		<< " capacity: " << v.capacity() << '\n';

// 		v.push_back(v[65]);
// 		std::cout << "size: " << v.size()
// 			<< " capacity: " << v.capacity() << '\n';
// 		return 0;
// 	}
// 	{
// 		std::vector<int> v;
// 		Timer<float, MILLI> t;
// 		_vector<int> vector;
// 		vector.assign(9900 * _ratio, 1);
// 		t.start();
// 		vector.resize(5000 * _ratio);
// 		vector.reserve(5000 * _ratio);
// 		v.push_back(vector.size());
// 		v.push_back(vector.capacity());
// 		vector.resize(7000 * _ratio);
// 		v.push_back(vector.size());
// 		v.push_back(vector.capacity());
// 		vector.resize(15300 * _ratio, int());
// 		v.push_back(vector.size());
// 		v.push_back(vector.capacity());
// 		v.push_back(vector[65]);
// 		t.finish();
// 		t.printTime();
// 		print_vec(v);
// 	}
// }


// int main() //checking reverse iterators
// {
// 	_vector<int> v;
// 	v.push_back(1);
// 	v.push_back(2);
// 	v.push_back(3);

// 	_vector<int>::iterator i = v.end();
// 	_vector<int>::const_reverse_iterator rbegin = _vector<int>::reverse_iterator(i);
// 	_vector<int>::reverse_iterator rend = v.rend() - 1;
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
// 	_vector<std::string> v1;
// 	_vector<std::string> v2;

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

// 	print_vec(v1);

// 	_vector<std::string>::iterator i = v1.end();
// 	v1.insert(i, v2.begin(), v2.end());
// 	// v1.insert(i, 10, -1);
// 	// v1.insert(i, 10, "ins");
// 	// v1.insert(v1.begin() + 2, 0);
// 	// v1.insert(v1.begin() + 2, "ins");

// 	print_vec(v1);
// }

// int main () //checking erase and iterators
// {
// 	_vector<int> myvector;

// 	// set some values (from 1 to 10)
// 	for (int i=1; i<=10; i++) myvector.push_back(i);

// 	// erase the Xth *iement
// 	_vector<int>::const_iterator iter = myvector.erase(myvector.begin() + 9);

// 	std::cout << "size " << myvector.size()
// 	<< " capacity " << myvector.capacity() << '\n';
// 	std::cout << "myvector contains:";
// 	for (unsigned i=0; i<myvector.size(); ++i)
// 		std::cout << ' ' << myvector[i];
// 	std::cout << '\n';

// 	_vector<int>::iterator iter2 = myvector.end();
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
// 	_vector<std::string> v1;
// 	std::string s = "foo bar";
// 	for (size_t i = 0; i < 5; i++)
// 	{
// 		v1.push_back(s);
// 		std::cout << "size " << v1.size()
// 		<< " capacity " << v1.capacity() << '\n';
// 	}

// // 	print_vec(v1);
// // }

int main() //checking swap
{
	_vector<std::string> v1;
	v1.push_back("s1");
	v1.push_back("s2");
	v1.push_back("s3");
	_vector<std::string> v2;
	v2.push_back("s4");
	v2.push_back("s5");

	_vector<std::string>::iterator i1 = v1.begin();
	_vector<std::string>::iterator i2 = v2.begin();

	std::string const & ref1 = v1.back();
	std::string const & ref2 = v2.back();

	std::cout << "references: " << ref1 << " " << ref2 << '\n';
	std::cout << "iterators: " << *i1 << " " << *i2 << '\n';
	for (_vector<std::string>::iterator i = i1; i < v1.end(); i++)
		std::cout << *i << ' ';
	std::cout << '\n';
	for (_vector<std::string>::iterator i = i2; i < v2.end(); i++)
		std::cout << *i << ' ';
	std::cout << '\n';
	
	v1.swap(v2);

	std::cout << "references: " << ref1 << " " << ref2 << '\n';
	std::cout << "iterators: " << *i1 << " " << *i2 << '\n';
	for (_vector<std::string>::iterator i = i1; i < v2.end(); i++)
		std::cout << *i << ' ';
	std::cout << '\n';
	for (_vector<std::string>::iterator i = i2; i < v1.end(); i++)
		std::cout << *i << ' ';
	std::cout << '\n';
	
}

// int main(int argc, char const *argv[])//checking swap
// {
// 	Timer<float, MICRO> t;

//     std::vector<int> v;
//     _vector<int> vector;
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

// int main()//checking erase
// {
// 	_vector<int> v(1000 * _ratio, 5);
// 	Timer<float, MILLI> t;

// 	std::cout << "size " << v.size()
// 	<< " capacity " << v.capacity() << '\n';

// 	t.start();
// 	v.erase(v.begin() + 50 * _ratio);
// 	t.finish();
// 	t.printTime(0, "single ");

// 	std::cout << "size " << v.size()
// 	<< " capacity " << v.capacity() << '\n';

// 	t.start();
// 	v.erase(v.begin() + 300 * _ratio, v.begin() + 700 * _ratio);
// 	t.finish();
// 	t.printTime(0, "range ");

// 	std::cout << "size " << v.size()
// 	<< " capacity " << v.capacity() << '\n';
// }


