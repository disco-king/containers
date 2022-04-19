#include <iostream>
#include "stack.hpp"
#include <stack>


int main()
{
	ft::stack<int> stack;

	for (size_t i = 0; i < 100; i++)
	{
		stack.push(i);
	}
	
	std::cout << "top " << stack.top() << '\n';
	std::cout << "size " << stack.size() << '\n';
	stack.pop();
	std::cout << "top " << stack.top() << '\n';
	std::cout << "size " << stack.size() << '\n';

	return 0;
}
