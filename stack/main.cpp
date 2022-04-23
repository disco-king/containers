#include <iostream>
#include "stack.hpp"
#include <stack>


int main()
{
	ft::stack<int> s1;
	ft::stack<int> s2;

	s1.push(1);
	// s2.push(1);
	s1.push(2);
	s2.push(5);
	s1.push(4);
	s2.push(4);

	std::cout << "eq " << (s1 == s2) << '\n';
	std::cout << "ne " << (s1 != s2) << '\n';
	std::cout << "gt " << (s1 > s2) << '\n';
	std::cout << "ge " << (s1 >= s2) << '\n';
	std::cout << "lt " << (s1 < s2) << '\n';
	std::cout << "le " << (s1 <= s2) << '\n';
	

	return 0;
}


// int main()
// {
// 	ft::stack<int> stack;

// 	for (size_t i = 0; i < 100; i++)
// 	{
// 		stack.push(i);
// 	}
	
// 	std::cout << "top " << stack.top() << '\n';
// 	std::cout << "size " << stack.size() << '\n';
// 	stack.pop();
// 	std::cout << "top " << stack.top() << '\n';
// 	std::cout << "size " << stack.size() << '\n';

// 	return 0;
// }
