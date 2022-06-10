#include <iostream>
#include "tree.hpp"
#include "pair_tree.hpp"


int main(int argc, char const *argv[])
{
	// { //adding, iters and printing
		// ft::Tree<int> t;

		// t.addValue(3);
		// t.addValue(1);
		// t.addValue(5);
		// t.addValue(6);
		// t.addValue(7);
		// t.addValue(8);
		// t.addValue(9);

		// t.printTree();
		// t.graphicPrint();

		// std::cout << '\n';

		// // ft::Tree<int>::reverse_iterator bi = t.rbegin();
		// // ft::Tree<int>::reverse_iterator ei = t.rend();
		// ft::Tree<int>::iterator bi = t.begin();
		// ft::Tree<int>::iterator ei = t.end();
		// int i = 1;
		// while(bi != ei)
		// {
		// 	std::cout << i << ' ' << *bi << '\n';
		// 	++bi;
		// 	++i;
		// }

		// ft::Tree<int>::Node * np = t.findValue(3);

		// if(np)
		// 	std::cout << "found value " << np->val << '\n';
	// }

	// { // adding, removing, emptiness 
		// ft::Tree<int> t;
		// t.addValue(3);
		// std::cout << "added 3\n";
		// t.removeValue(3);
		// std::cout << "removed 3\n";
		// t.removeValue(3);
		// std::cout << "second try\n";
		// t.addValue(3);
		// std::cout << "added 3\n";

		// ft::Tree<int>::Node * np = t.findValue(3);
		// if(np)
		// 	std::cout << "found value " << np->val << '\n';
	// // }

	// { // adding, removing and iters
	// 	ft::Tree<int>::iterator bi = t.begin();
	// 	ft::Tree<int>::iterator ei = t.end();
	// 	int i = 1;
	// 	while(bi != ei)
	// 	{
	// 		std::cout << i << ' ' << *bi << '\n';
	// 		++bi;
	// 		++i;
	// 	}
	// 	std::cout << '\n';
	// 	for(int i = 0; i < 10; i++)
	// 		t.removeValue(i);
	// 	for(int i = 0; i < 10; i++)
	// 		t.addValue(i);
	// 	ft::Tree<int>::reverse_iterator br = t.rbegin();
	// 	ft::Tree<int>::reverse_iterator er = t.rend();
	// 	i = 1;
	// 	while(br != er)
	// 	{
	// 		std::cout << i << ' ' << *br << '\n';
	// 		++br;
	// 		++i;
	// 	}
	// // }

	// // { // size, empty, max_size
	// 	ft::Tree<int> t;
	// 	std::cout << "size " << t.size() << '\n';
	// 	std::cout << "empty " << t.empty() << '\n';
	// 	for(int i = 0; i < 10; i++)
	// 	{
	// 		t.addValue(i);
	// 		std::cout << t.size() << '\n';
	// 	}
	// 	std::cout << "empty " << t.empty() << '\n';
	// 	std::cout << "max " << t.max_size() << '\n';
	// }
	
	// {
		// ft::Tree<int> t;
		// std::cout << std::boolalpha << (t.begin() == t.end()) << '\n';
		// std::cout << std::boolalpha << (t.rbegin() == t.rend()) << '\n';
	// }

	// {
		ft::PairTree<int, int> t;

		t.addValue(ft::make_pair(1, 3));
		t.addValue(ft::make_pair(2, 4));
		t.addValue(ft::make_pair(3, 1));


		ft::PairTree<int, int>::iterator bi = t.begin();
		// ft::PairTree<int, int>::iterator ei = t.end();
		// int i = 1;
		// while(bi != ei)
		// {
		// 	std::cout << i << ' ' << bi->first << '\n';
		// 	++bi;
		// 	++i;
		// }

		// ft::PairTree<int, int>::Node * np = t.findValue(ft::make_pair(3, 0));

		// if(np)
		// 	std::cout << "found value:\n"
		// 	<< "1st " << np->val.first
		// 	<< " 2nd " << np->val.second << '\n';
	// }

			return 0;
}