#include "stack.hpp"

template <typename T, typename Container>
ft::stack<T, Container>::stack(const Container& ctnr)
{
	c = ctnr;
}

template <typename T, typename Container>
bool ft::stack<T, Container>::empty() const
{
	return c.empty();
}

template <typename T, typename Container>
typename ft::stack<T, Container>::size_type
ft::stack<T, Container>::size() const
{
	return c.size();
}

template <typename T, typename Container>
T& ft::stack<T, Container>::top()
{
	return c.back();
}

template <typename T, typename Container>
const T& ft::stack<T, Container>::top() const
{
	return c.back();
}

template <typename T, typename Container>
void ft::stack<T, Container>::push (const T& val)
{
	c.push_back(val);
}

template <typename T, typename Container>
void ft::stack<T, Container>::pop()
{
	c.pop_back();
}
