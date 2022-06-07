#pragma once

#include <iostream>
#include <cmath>
#include "utils.hpp"
// #include "treeIterator.hpp"

namespace ft
{

#define RED true
#define BLACK false

template <typename T>
class treeIterator;

template <typename T, typename Comp = std::less<T>>
class Tree
{

public:
	typedef T value_type;
	typedef Comp comparator;
	typedef ptrdiff_t difference_type;
	typedef size_t size_type;
	typedef treeIterator<T> iterator;
	typedef treeIterator<const T> const_iterator;

	struct Node{
		Tree *t_ptr;
		Node *p;
		Node *left;
		Node *right;
		T val;
		bool color;

		Node(Tree *tp, T val = T(), Node *ptr = 0): t_ptr(tp),
		p(ptr), left(ptr), right(ptr), val(val), color(RED) {}
	};

private:
	friend class ft::treeIterator<T>;
	Node *root;
	Node * const nil;
	int height;

	Node *addNode(Node *head, T val, int depth);
	void insertFixup(Node *n);
	void deleteFixup(Node *n);
	void printNodes(Node *head);
	void printLevel(Node *head, int level, int depth);
	Node *treeMinimum(Node *head);
	Node *treeMaximum(Node *head);
	void transplant(Node *prev_n, Node * new_n);
	void updateHeight();
	void clearNodes(Node *head);

public:
	Tree() : root(0), height(0), nil(new Node(this)){
		nil->color = BLACK;
	}
	~Tree(){
		clearNodes(root);
		delete nil;
	}

	int maxHeight(Node *head, int depth);
	void addValue(T val);
	void removeValue(T val);
	Node *findValue(T val);
	void printTree();
	void graphicPrint();
	Node *successor(Node *x);
	Node *predecessor(Node *x);
	void rotateLeft(Node *x);
	void rotateRight(Node *x);

	int getHeight(){ return height; }
	Node *getRoot(){ return root; }
	Node *getMin(){ return treeMinimum(root); }
	Node *getMax(){ return treeMaximum(root); }
	void checkPars(Node *head);

	iterator begin() { return iterator(treeMinimum(root)); }
	iterator end() { return iterator(nil); }
};

template <typename T, typename Comp>
void Tree<T, Comp>::insertFixup(Node *x)
{
	Node *y;
	while(x->p->color == RED)
	{
		if(x->p == x->p->p->left)
		{
			y = x->p->p->right;
			if(y->color == RED)
			{
				y->color = BLACK;
				x->p->color = BLACK;
				y->p->color = RED;
				x = x->p->p;
			}
			else
			{
				if(x == x->p->right)
					rotateLeft(x = x->p);
				x->p->color = BLACK;
				x->p->p->color = RED;
				rotateRight(x->p->p);
			}
		}
		else
		{
			y = x->p->p->left;
			if(y->color == RED)
			{
				y->color = BLACK;
				x->p->color = BLACK;
				y->p->color = RED;
				x = x->p->p;
			}
			else
			{
				if(x == x->p->left)
					rotateRight(x = x->p);
				x->p->color = BLACK;
				x->p->p->color = RED;
				rotateLeft(x->p->p);
			}
		}
	}
	root->color = BLACK;
}

template <typename T, typename Comp>
void Tree<T, Comp>::rotateLeft(Node *x)
{
	Node *y = x->right;
	x->right = y->left;
	if(y->left != nil)
		y->left->p = x;

	y->p = x->p;
	if(y->p == nil)
		root = y;
	else if(x == x->p->left)
		y->p->left = y;
	else
		y->p->right = y;
	x->p = y;
	y->left = x;
	updateHeight();
}

template <typename T, typename Comp>
void Tree<T, Comp>::rotateRight(Node *x)
{
	Node *y = x->left;
	x->left = y->right;
	if(y->right != nil)
		y->right->p = x;

	y->p = x->p;
	if(y->p == nil)
		root = y;
	else if(x == x->p->left)
		y->p->left = y;
	else
		y->p->right = y;
	x->p = y;
	y->right = x;
	updateHeight();
}

template <typename T, typename Comp>
void Tree<T, Comp>::updateHeight()
{
	int h = maxHeight(root, 0);
	if(h != height)
		height = h;
}

template <typename T, typename Comp>
int Tree<T, Comp>::maxHeight(Node *head, int depth)
{
	if(head == nil)
		return depth - 1;
	if(head->right == nil)
		return maxHeight(head->left, depth + 1);
	if(head->left == nil)
		return maxHeight(head->right, depth + 1);

	int left = maxHeight(head->left, depth + 1);
	int right = maxHeight(head->right, depth + 1);
	return (left > right) ? left : right;
}

template <typename T, typename Comp>
typename Tree<T, Comp>::Node *Tree<T, Comp>::addNode(Node *n, T val, int depth)
{
	if(val < n->val)
	{
		if(n->left == nil)
		{
			height = (++depth > height) ? depth : height;
			n->left = new Node(this, val, nil);
			n->left->p = n;
			return n->left;
		}
		return addNode(n->left, val, depth + 1);
	}
	else
	{
		if(n->right == nil)
		{
			height = (++depth > height) ? depth : height;
			n->right = new Node(this, val, nil);
			n->right->p = n;
			return n->right;
		}
		return addNode(n->right, val, depth + 1);
	}
}

template <typename T, typename Comp>
void Tree<T, Comp>::addValue(T val)
{
	if(!root)
	{
		root = new Node(this, val, nil);
		root->color = BLACK;
	}
	else
		insertFixup(addNode(root, val, 0));
}

template <typename T, typename Comp>
typename Tree<T, Comp>::Node *Tree<T, Comp>::findValue(T val)
{
	if(root == nil)
		return root;

	Node *n = root;
	while (n != nil)
	{
		if(val == n->val)
			break;
		if(comparator(val, n->val))
			n = n->left;
		else
			n = n->right;
	}
	return n;
}

template <typename T, typename Comp>
void Tree<T, Comp>::transplant(Node *prev_n, Node * new_n)
{
	if(prev_n->p == nil)
		root = new_n;
	else if(prev_n == prev_n->p->left)
		prev_n->p->left = new_n;
	else
		prev_n->p->right = new_n;
	new_n->p = prev_n->p;
}

template <typename T, typename Comp>
void Tree<T, Comp>::removeValue(T val)
{
	Node *n = findValue(val);
	if(n == nil)
		return;
	Node *repl;
	bool orig_color = n->color;

	if(n->right == nil)
	{
		repl = n->left;
		transplant(n, n->left);
	}
	else if(n->left == nil)
	{
		repl = n->right;
		transplant(n, n->right);
	}
	else
	{
		Node *subs = treeMinimum(n->right);
		orig_color = subs->color;
		repl = subs->right;
		if(subs->p == n)
			repl->p = subs;
		else
		{
			transplant(subs, subs->right);
			subs->right = n->right;
			subs->right->p = subs;
		}
		transplant(n, subs);
		subs->left = n->left;
		subs->left->p = subs;
		subs->color = n->color;
	}

	delete n;
	if(orig_color == BLACK)
		deleteFixup(repl);
	updateHeight();
}

template <typename T, typename Comp>
void Tree<T, Comp>::deleteFixup(Node *n)
{
	Node *s;
	while(n != root && n->color == BLACK)
	{
		if(n == n->p->left)
		{
			s = n->p->right;
			if(s->color == RED)
			{
				s->color = BLACK;
				s->p->color = RED;
				rotateLeft(s->p);
				s = n->p->right;
			}
			if(s->left->color == BLACK && s->right->color == BLACK)
			{
				s->color = RED;
				n = n->p;
			}
			else
			{
				if(s->right->color == BLACK)
				{
					s->left->color = BLACK;
					s->color = RED;
					rotateRight(s);
					s = n->p->right;
				}
				s->color = n->p->color;
				n->p->color = BLACK;
				s->right->color = BLACK;
				rotateLeft(n->p);
				n = root;
			}
		}
		else
		{
			s = n->p->left;
			if(s->color == RED)
			{
				s->color = BLACK;
				s->p->color = RED;
				rotateRight(s->p);
				s = n->p->left;
			}
			if(s->left->color == BLACK && s->right->color == BLACK)
			{
				s->color = RED;
				n = n->p;
			}
			else
			{
				if(s->left->color == BLACK)
				{
					s->right->color = BLACK;
					s->color = RED;
					rotateLeft(s);
					s = n->p->left;
				}
				s->color = n->p->color;
				n->p->color = BLACK;
				s->left->color = BLACK;
				rotateRight(n->p);
				n = root;
			}
		}
	}
	n->color = BLACK;
}

template <typename T, typename Comp>
void Tree<T, Comp>::printNodes(Node *head)
{
	if(head->left != nil)
		printNodes(head->left);
	std::cout << head->val << ' ';
	if(head->right != nil)
		printNodes(head->right);
}

template <typename T, typename Comp>
void Tree<T, Comp>::printTree()
{
	printNodes(root);
	std::cout << "\n";
}

template <typename T, typename Comp>
typename Tree<T, Comp>::Node *Tree<T, Comp>::treeMinimum(Node *head)
{
	if(head->left == nil)
		return head;
	
	return treeMinimum(head->left);
}

template <typename T, typename Comp>
typename Tree<T, Comp>::Node *Tree<T, Comp>::treeMaximum(Node *head)
{
	if(head->right == nil)
		return head;
	
	return treeMaximum(head->right);
}

int width(int num)
{
	if(!num)
		return 1;
	int count = 0;
	if (num < 0)
	{
		num *= -1;
		count++;
	}
	while(num > 0)
	{
		num /= 10;
		count++;
	}
	return count;
}

template <typename T, typename Comp>
void Tree<T, Comp>::printLevel(typename Tree<T, Comp>::Node *head, int level, int depth)
{
	if(depth != level)
	{
		if(head->left != nil)
			printLevel(head->left, level, depth + 1);
		else
			printLevel(0, depth + 1, depth + 1);
		if(head->right != nil)
			printLevel(head->right, level, depth + 1);
		else
			printLevel(0, depth + 1, depth + 1);
		return;
	}
	int pad = pow(2, height - depth + 1) - 1;
	int num_width = pad + 1 - (head ? width(head->val) : 1);
	for (size_t i = 0; i < num_width; i++)
		std::cout << ' ';
	if(head)
		std::cout << head->val << (head->color ? 'r' : 'b');
	else
		std::cout << ' ' << ' ';
	for (size_t i = 0; i < pad; i++)
		std::cout << ' ';
}

template <typename T, typename Comp>
void Tree<T, Comp>::graphicPrint()
{
	for (int i = 0; i <= height; i++)
	{
		printLevel(root, i, 0);
		std::cout << '\n' << '\n';
	}
}

template <typename T, typename Comp>
typename Tree<T, Comp>::Node *Tree<T, Comp>::successor(Node *x)
{
	if(x->right != nil)
		return treeMinimum(x->right);
	Node *y = x;
	while(y != nil && x != y->left)
	{
		x = y;
		y = y->p;
	}
	return y;
}

template <typename T, typename Comp>
typename Tree<T, Comp>::Node *Tree<T, Comp>::predecessor(Node *x)
{
	if(x->left != nil)
		return treeMaximum(x->left);
	Node *y = x;
	while(y != nil && x != y->right)
	{
		x = y;
		y = y->p;
	}
	return y;
}

template <typename T, typename Comp>
void Tree<T, Comp>::checkPars(Node *head)
{
	if(head == nil)
		return;
	std::cout << "path to root for " << head->val << ": ";
	head = head->p;
	while(head != nil)
	{
		std::cout << head->val << ' ';
		head = head->p;
	}
	std::cout << "\nroot reached\n";
}

template <typename T, typename Comp>
void Tree<T, Comp>::clearNodes(Node *head)
{
	if(head == nil)
		return;
	if(head->left != nil)
		clearNodes(head->left);
	if(head->right != nil)
		clearNodes(head->right);
	delete head;
}

template <typename T>
class treeIterator : public iterator<bidirectional_iterator_tag, T>
{

private:
	typedef typename Tree<T>::Node Node;
	Node *n_ptr;

public:
	typedef typename iterator<bidirectional_iterator_tag, T>::iterator_category iterator_category;
	typedef typename iterator<bidirectional_iterator_tag, T>::difference_type difference_type;
	typedef typename iterator<bidirectional_iterator_tag, T>::value_type value_type;
	typedef typename iterator<bidirectional_iterator_tag, T>::pointer pointer;
	typedef typename iterator<bidirectional_iterator_tag, T>::reference reference;

	explicit treeIterator(Node *ptr = 0) : n_ptr(ptr) {};

	treeIterator& operator=(treeIterator const &src) {
		n_ptr = src.n_ptr;
		return *this;
	}

	treeIterator& operator++() {
		n_ptr = n_ptr->t_ptr->successor(n_ptr);
		return *this;
	}
	
	treeIterator operator++(int) {
		treeIterator retval = *this;
		++(*this);
		return retval;
	}

	treeIterator& operator--() {
		n_ptr = n_ptr->t_ptr->predecessor(n_ptr);
		return *this;
	}

	treeIterator operator--(int) {
		treeIterator retval = *this;
		--(*this);
		return retval;
	}

	operator vectorIterator<const T> () const
	{ return (vectorIterator<const T>(this->n_ptr)); }

	reference operator*() const { return n_ptr->val; }
	pointer operator->() const { return &(this->operator*()); }
};

template <typename T, typename U>
bool operator==(const treeIterator<T> &lhs,
				const treeIterator<U> &rhs)
{return &(*lhs) == &(*rhs);}

template <typename T>
bool operator==(const treeIterator<T> &lhs,
				const treeIterator<T> &rhs)
{return &(*lhs) == &(*rhs);}

template <typename T, typename U>
bool operator!=(const treeIterator<T> &lhs,
				const treeIterator<U> &rhs)
{return &(*lhs) != &(*rhs);}

template <typename T>
bool operator!=(const treeIterator<T> &lhs,
				const treeIterator<T> &rhs)
{return &(*lhs) != &(*rhs);}


}