#include <iostream>
#include "stack.hpp"
#include <stack>


int main()
{
	ft::stack<int> s1, s2;

	// s1.push(1);
	// // s2.push(1);
	// s1.push(2);
	// s2.push(2);
	// s1.push(4);
	// s2.push(4);

	// std::cout << "eq " << std::boolalpha << (s1 == s2) << '\n';
	// std::cout << "ne " << std::boolalpha << (s1 != s2) << '\n';
	// std::cout << "gt " << std::boolalpha << (s1 > s2) << '\n';
	// std::cout << "ge " << std::boolalpha << (s1 >= s2) << '\n';
	// std::cout << "lt " << std::boolalpha << (s1 < s2) << '\n';
	// std::cout << "le " << std::boolalpha << (s1 <= s2) << '\n';
	
	std::cout << "s1 empty " << std::boolalpha << s1.empty() << '\n';
	s1.push(1);
	std::cout << "s1 not empty " << std::boolalpha << s1.empty() << '\n';

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
